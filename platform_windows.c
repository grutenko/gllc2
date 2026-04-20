#include "glad.h"
#include "platform.h"

#include <stdio.h>
#include <winbase.h>
#include <windows.h>
#include <wingdi.h>
#include <winuser.h>

typedef HGLRC WINAPI wglCreateContextAttribsARB_type(HDC hdc,
                                                     HGLRC hShareContext,
                                                     const int *attribList);
wglCreateContextAttribsARB_type *wglCreateContextAttribsARB;

typedef BOOL WINAPI wglSwapIntervalEXT_type(int interval);

wglSwapIntervalEXT_type *wglSwapIntervalEXT;

#define WGL_CONTEXT_MAJOR_VERSION_ARB 0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB 0x2092
#define WGL_CONTEXT_PROFILE_MASK_ARB 0x9126

#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001

typedef BOOL WINAPI wglChoosePixelFormatARB_type(
    HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList,
    UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
wglChoosePixelFormatARB_type *wglChoosePixelFormatARB;

#define WGL_DRAW_TO_WINDOW_ARB 0x2001
#define WGL_ACCELERATION_ARB 0x2003
#define WGL_SUPPORT_OPENGL_ARB 0x2010
#define WGL_DOUBLE_BUFFER_ARB 0x2011
#define WGL_PIXEL_TYPE_ARB 0x2013
#define WGL_COLOR_BITS_ARB 0x2014
#define WGL_DEPTH_BITS_ARB 0x2022
#define WGL_STENCIL_BITS_ARB 0x2023
#define WGL_SAMPLE_BUFFERS_ARB 0x2041
#define WGL_SAMPLES_ARB 0x2042

#define WGL_FULL_ACCELERATION_ARB 0x2027
#define WGL_TYPE_RGBA_ARB 0x202B

static int init_opengl_extensions(void) {
  WNDCLASSA window_class = {
      .style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
      .lpfnWndProc = DefWindowProcA,
      .hInstance = GetModuleHandle(0),
      .lpszClassName = "Dummy_WGL_djuasiodwa",
  };

  if (!RegisterClassA(&window_class)) {
    fprintf(stderr, "Failed to register dummy OpenGL window.");
    return 0;
  }

  HWND dummy_window = CreateWindowExA(0, window_class.lpszClassName, "Dummy OpenGL Window", 0, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, window_class.hInstance, 0);

  if (!dummy_window) {
    fprintf(stderr, "Failed to create dummy OpenGL window.");
    return 0;
  }

  HDC dummy_dc = GetDC(dummy_window);

  PIXELFORMATDESCRIPTOR pfd = {
      .nSize = sizeof(pfd),
      .nVersion = 1,
      .iPixelType = PFD_TYPE_RGBA,
      .dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
      .cColorBits = 32,
      .cAlphaBits = 8,
      .iLayerType = PFD_MAIN_PLANE,
      .cDepthBits = 24,
      .cStencilBits = 8,
  };

  int pixel_format = ChoosePixelFormat(dummy_dc, &pfd);
  if (!pixel_format) {
    goto _error;
  }
  if (!SetPixelFormat(dummy_dc, pixel_format, &pfd)) {
    goto _error;
  }

  HGLRC dummy_context = wglCreateContext(dummy_dc);
  if (!dummy_context) {
    goto _error;
  }

  if (!wglMakeCurrent(dummy_dc, dummy_context)) {
    goto _error;
  }

  wglCreateContextAttribsARB = (wglCreateContextAttribsARB_type *)wglGetProcAddress("wglCreateContextAttribsARB");
  wglChoosePixelFormatARB = (wglChoosePixelFormatARB_type *)wglGetProcAddress("wglChoosePixelFormatARB");
  wglSwapIntervalEXT = (wglSwapIntervalEXT_type *)wglGetProcAddress("wglSwapIntervalEXT");
  wglMakeCurrent(dummy_dc, 0);
  wglDeleteContext(dummy_context);
  ReleaseDC(dummy_window, dummy_dc);
  DestroyWindow(dummy_window);

  return 1;

_error:
  if (!dummy_window)
    return 0;
  if (dummy_dc)
    ReleaseDC(dummy_window, dummy_dc);
  if (dummy_context)
    wglDeleteContext(dummy_context);
  if (dummy_window)
    DestroyWindow(dummy_window);

  return 0;
}

static HGLRC init_opengl(HDC real_dc) {
  if (!init_opengl_extensions()) {
    return 0;
  }
  int pixel_format_attribs[] = {
      WGL_DRAW_TO_WINDOW_ARB, GL_TRUE, WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
      WGL_DOUBLE_BUFFER_ARB, GL_TRUE, WGL_ACCELERATION_ARB,
      WGL_FULL_ACCELERATION_ARB, WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
      WGL_COLOR_BITS_ARB, 32, WGL_DEPTH_BITS_ARB, 24, WGL_STENCIL_BITS_ARB, 8,
      // WGL_SAMPLE_BUFFERS_ARB, 1, // включаем MSAA
      // WGL_SAMPLES_ARB, 2,        // 4x сглаживание
      0};

  int pixel_format;
  UINT num_formats;
  wglChoosePixelFormatARB(real_dc, pixel_format_attribs, 0, 1, &pixel_format, &num_formats);
  if (!num_formats) {
    fprintf(stderr, "Failed to set the OpenGL 3.3 pixel format.");
    return 0;
  }

  PIXELFORMATDESCRIPTOR pfd;
  DescribePixelFormat(real_dc, pixel_format, sizeof(pfd), &pfd);
  if (!SetPixelFormat(real_dc, pixel_format, &pfd)) {
    fprintf(stderr, "Failed to set the OpenGL 3.3 pixel format.");
    return 0;
  }
  int gl33_attribs[] = {
      WGL_CONTEXT_MAJOR_VERSION_ARB,
      3,
      WGL_CONTEXT_MINOR_VERSION_ARB,
      3,
      WGL_CONTEXT_PROFILE_MASK_ARB,
      WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
      0,
  };

  HGLRC gl33_context = wglCreateContextAttribsARB(real_dc, 0, gl33_attribs);
  if (!gl33_context) {
    fprintf(stderr, "Failed to create OpenGL 3.3 context.");
    return 0;
  }

  if (!wglMakeCurrent(real_dc, gl33_context)) {
    fprintf(stderr, "Failed to activate OpenGL 3.3 rendering context.");
    wglDeleteContext(gl33_context);
    return 0;
  }

  return gl33_context;
}

static struct nw *G_window_head = NULL;
static struct nw *G_window_tail = NULL;

static void push_NW(struct nw *wn) {
  if (!G_window_head)
    G_window_head = wn;

  wn->prev = G_window_tail;
  G_window_tail = wn;
}

static void remove_NW(struct nw *wn) {
  if (wn->prev)
    wn->prev->next = wn->next;
  if (wn->next)
    wn->next->prev = wn->prev;
  if (!wn->prev)
    G_window_head = wn->next;
  if (!wn->next)
    G_window_tail = wn->prev;
}

static LRESULT CALLBACK wndproc(HWND window, UINT msg, WPARAM wparam, LPARAM lparam) {
  LRESULT result = 0;
  PAINTSTRUCT ps;
  static TRACKMOUSEEVENT tme;

  struct nw *w = G_window_head;
  while (w) {
    if (w->w == window)
      break;
    w = w->next;
  }
  switch (msg) {
  case WM_PAINT:
    BeginPaint(window, &ps);
    if (w)
      w->vtable->paint(w, w->data);
    EndPaint(window, &ps);
    return 0;
  case WM_LBUTTONDOWN:
    if (w)
      w->vtable->mouse_click(w, LOWORD(lparam), HIWORD(lparam), 1, 1, w->data);
    return 0;
  case WM_RBUTTONDOWN:
    if (w)
      w->vtable->mouse_click(w, LOWORD(lparam), HIWORD(lparam), 2, 1, w->data);
    return 0;
  case WM_MBUTTONDOWN:
    if (w)
      w->vtable->mouse_click(w, LOWORD(lparam), HIWORD(lparam), 3, 1, w->data);
    return 0;
  case WM_LBUTTONUP:
    if (w)
      w->vtable->mouse_click(w, LOWORD(lparam), HIWORD(lparam), 1, 0, w->data);
    return 0;
  case WM_RBUTTONUP:
    if (w)
      w->vtable->mouse_click(w, LOWORD(lparam), HIWORD(lparam), 2, 0, w->data);
    return 0;
  case WM_MBUTTONUP:
    if (w)
      w->vtable->mouse_click(w, LOWORD(lparam), HIWORD(lparam), 3, 0, w->data);
    return 0;
  case WM_SIZE:
    if (w)
      w->vtable->size(w, LOWORD(lparam), HIWORD(lparam), w->data);
    return 0;
  case WM_MOUSEMOVE:
    if (w)
      w->vtable->mouse_move(w, LOWORD(lparam), HIWORD(lparam), w->data);

    tme.cbSize = sizeof(TRACKMOUSEEVENT);
    tme.dwFlags = TME_LEAVE;
    tme.hwndTrack = window;
    tme.dwHoverTime = 0;
    TrackMouseEvent(&tme);

    return 0;
  case WM_MOUSELEAVE:
    if (w)
      w->vtable->mouse_leave(w, w->data);

    return 0;
  case WM_MOUSEWHEEL:
    if (w)
      w->vtable->mouse_scroll(w, 0, GET_WHEEL_DELTA_WPARAM(wparam) / 120, w->data);
    return 0;
  case WM_MOUSEHWHEEL:
    if (w)
      w->vtable->mouse_scroll(w, GET_WHEEL_DELTA_WPARAM(wparam) / 120, 0, w->data);
    return 0;
  default:
    result = DefWindowProcA(window, msg, wparam, lparam);
    break;
  }

  return result;
}

ATOM wndClass = 0;

int nw_create(struct nw *nw, void *parent, struct nw_vtable *vtable, void *data) {
  memset(nw, 0, sizeof(struct nw));

  if (!wndClass) {
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = wndproc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "GLLCWindowClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    wndClass = RegisterClassEx(&wc);

    if (!wndClass)
      goto _error;
  }

  RECT rc;
  if (!GetClientRect((HWND)parent, &rc)) {
    rc.left = 0;
    rc.top = 0;
    rc.right = 800;
    rc.bottom = 600;
  }

  nw->w = CreateWindowEx(
      0,
      MAKEINTATOM(wndClass),
      "OpenGL Window",
      WS_CHILD | WS_VISIBLE,
      rc.left, rc.top,
      rc.right - rc.left,
      rc.bottom - rc.top,
      (HWND)parent,
      NULL,
      GetModuleHandle(NULL),
      NULL);

  if (!nw->w)
    goto _error;

  nw->dc = GetDC(nw->w);
  nw->glrc = init_opengl(nw->dc);

  if (!nw->glrc)
    goto _error;

  nw->vtable = vtable;
  nw->data = data;

  push_NW(nw);

  return 1;
_error:
  if (!nw)
    return 0;
  if (nw->dc)
    ReleaseDC(nw->w, nw->dc);
  if (nw->glrc)
    wglDeleteContext(nw->glrc);
  if (nw->w)
    DestroyWindow(nw->w);

  return 0;
}

void nw_show_cursor(int show) {
  ShowCursor(show);
}

void nw_destroy(struct nw *w) {
  if (!w)
    return;
  if (w->dc)
    ReleaseDC(w->w, w->dc);
  if (w->glrc)
    wglDeleteContext(w->glrc);
  if (w->w)
    DestroyWindow(w->w);

  remove_NW(w);
}

void nw_dirty(struct nw *w) {
  InvalidateRect(w->w, NULL, TRUE);
}

void nw_set_size(struct nw *w, int x, int y, int width, int height) {
  SetWindowPos(w->w, NULL, x, y, width, height, SWP_NOZORDER);
}

void nw_swap_buffers(struct nw *w) {
  SwapBuffers(w->dc);
}

void nw_make_context_current(struct nw *w) {
  if (w) {
    wglMakeCurrent(w->dc, w->glrc);
  } else {
    wglMakeCurrent(NULL, NULL);
  }
}

void nw_get_size(struct nw *w, int *width, int *height) {
  *width = 0;
  *height = 0;

  RECT rc;
  if (GetClientRect(w->w, &rc)) {
    *width = rc.right - rc.left;
    *height = rc.bottom - rc.top;
  }
}

void nw_get_cursor(struct nw *w, int *x, int *y) {
  POINT p;

  GetCursorPos(&p);
  ScreenToClient((HWND)w->w, &p);

  if (x)
    *x = p.x;
  if (y)
    *y = p.y;
}