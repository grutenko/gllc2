#ifndef platform_h
#define platform_h

#include <stdint.h>
#if defined(_WIN32)

#include <windows.h>

#elif defined(__EMSCRIPTEN__)

#include <GLES3/gl3.h> // Для WebGL 2.0 (OpenGL ES 3.0)
#include <emscripten/html5.h>

#elif defined(__linux__)

#include <X11/Xlib.h>
#include <epoxy/egl.h>
#include <epoxy/gl.h>
#include <gtk/gtk.h>
#include <wayland-client.h>
#include <wayland-egl.h>

#endif

#define NW_CONTROL 0x1
#define NW_SHIFT 0x2

struct nw;

struct nw_callback_vtable
{
        void (*ready)(struct nw *w, void *data);
        void (*paint)(struct nw *w, void *data);
        void (*size)(struct nw *w, int width, int height, void *data);
        void (*mouse_move)(struct nw *w, int x, int y, int flags, void *data);
        void (*mouse_click)(struct nw *wn, int x, int y, int mode, int action, int flags, void *data);
        void (*mouse_scroll)(struct nw *wn, int dx, int dy, int flags, void *data);
        void (*mouse_leave)(struct nw *wn, void *data);
};

struct nw_vtable
{
        void (*destroy)(struct nw *nw);
        int (*set_cursor_pos)(struct nw *nw, int x, int y);
        int (*get_cursor_pos)(struct nw *nw, int *x, int *y);
        int (*make_context_current)(struct nw *nw);
        int (*get_size)(struct nw *nw, int *width, int *height);
        int (*set_size)(struct nw *nw, int width, int height);
        int (*swap_buffers)(struct nw *nw);
        int (*dirty)(struct nw *nw);
        int (*show_cursor)(struct nw *nw, int show);
        int (*focus)(struct nw *nw);
        int (*poll_events)(struct nw *nw);
};

struct nw
{
        int type;
        int ready;
#if defined(_WIN32)
        HWND w;
        HDC dc;
        HGLRC glrc;
        struct nw *next;
        struct nw *prev;
#elif defined(__linux__)
        EGLDisplay egl_display;
        EGLContext egl_context;
        EGLConfig egl_config;
        EGLSurface egl_surface;
        GtkGLArea *area;
        Window xwindow;

#endif
        void *data;
        struct nw_callback_vtable *cb_vtable_p;
        struct nw_vtable vtable;
};

#if defined(_WIN32)

int nw_create_win32(struct nw *NW, HWND parent, struct nw_callback_vtable *vtable, void *data);

#elif defined(__EMSCRIPTEN__)

int nw_create_webgl(struct nw *nw, struct nw_callback_vtable *vtable, const char *canvas, void *data);

#elif defined(__linux__)

int nw_create_x11(struct nw *nw, struct nw_callback_vtable *vtable, Display *display, Window parent, void *data);
int nw_create_gtk(struct nw *nw, struct nw_callback_vtable *vtable, GtkWindow *parent, void *data);
int nw_create_wayland(struct nw *nw, struct nw_callback_vtable *vtable, struct wl_surface *surface, void *data);

#endif

void nw_destroy(struct nw *NW);
void nw_get_cursor(struct nw *w, int *x, int *y);
void nw_make_context_current(struct nw *w);
void nw_release_current_context(struct nw *w);
void nw_get_size(struct nw *w, int *width, int *height);
void nw_set_size(struct nw *w, int x, int y, int width, int height);
void nw_swap_buffers(struct nw *w);
void nw_dirty(struct nw *w);
void nw_show_cursor(struct nw *nw, int show);
void nw_focus(struct nw *nw);
void nw_cursor_set_pos(struct nw *nw, int x, int y);
void nw_poll_events(struct nw *nw);

#endif