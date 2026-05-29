#if defined(__linux__) && !defined(__EMSCRIPTEN__)
#include <X11/X.h>
#include "platform.h"

static void destroy(struct nw *nw)
{
        if (!nw)
                return;
        if (nw->egl_display != EGL_NO_DISPLAY)
        {
                eglMakeCurrent(nw->egl_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
                if (nw->egl_context != EGL_NO_CONTEXT)
                        eglDestroyContext(nw->egl_display, nw->egl_context);
                if (nw->egl_surface != EGL_NO_SURFACE)
                        eglDestroySurface(nw->egl_display, nw->egl_surface);
                eglTerminate(nw->egl_display);
        }
        if (nw->xwindow)
                XDestroyWindow((Display *)nw->egl_display, nw->xwindow);
}

static int set_cursor_pos(struct nw *nw, int x, int y)
{
        XWarpPointer((Display *)nw->egl_display, None, nw->xwindow, 0, 0, 0, 0, x, y);
        return 0;
}

static int get_cursor_pos(struct nw *nw, int *x, int *y)
{
        Window root, child;
        int root_x, root_y;
        unsigned int mask;
        XQueryPointer((Display *)nw->egl_display, nw->xwindow, &root, &child, &root_x, &root_y, x, y, &mask);
        return 0;
}

static int make_context_current(struct nw *nw)
{
        if (eglMakeCurrent(nw->egl_display, nw->egl_surface, nw->egl_surface, nw->egl_context))
                return 1;
        return 0;
}

static int get_size(struct nw *nw, int *width, int *height)
{
        XWindowAttributes gwa;
        XGetWindowAttributes((Display *)nw->egl_display, nw->xwindow, &gwa);
        if (width)
                *width = gwa.width;
        if (height)
                *height = gwa.height;
        return 0;
}

static int set_size(struct nw *nw, int width, int height)
{
        XResizeWindow((Display *)nw->egl_display, nw->xwindow, width, height);
        return 0;
}

static int swap_buffers(struct nw *nw)
{
        eglSwapBuffers(nw->egl_display, nw->egl_surface);
        return 0;
}

static int dirty(struct nw *nw)
{
        Display *dpy = (Display *)nw->egl_display;
        XExposeEvent ev = {.type = Expose, .display = (Display *)nw->egl_display, .window = nw->xwindow, .count = 0};
        XLockDisplay(dpy);
        XSendEvent((Display *)nw->egl_display, nw->xwindow, False, ExposureMask, (XEvent *)&ev);
        XFlush(dpy);
        XUnlockDisplay(dpy);
        return 0;
}

static int show_cursor(struct nw *nw, int show)
{
        if (show)
        {
                XUndefineCursor((Display *)nw->egl_display, nw->xwindow);
        }
        else
        {
                Pixmap bm;
                Cursor c;
                XColor black = {0};
                static char data[8] = {0};
                bm = XCreateBitmapFromData((Display *)nw->egl_display, nw->xwindow, data, 8, 8);
                c = XCreatePixmapCursor((Display *)nw->egl_display, bm, bm, &black, &black, 0, 0);
                XDefineCursor((Display *)nw->egl_display, nw->xwindow, c);
                XFreePixmap((Display *)nw->egl_display, bm);
        }
        return 0;
}

static int focus(struct nw *nw)
{
        XSetInputFocus((Display *)nw->egl_display, nw->xwindow, RevertToParent, CurrentTime);
        XRaiseWindow((Display *)nw->egl_display, nw->xwindow);
        return 0;
}

static int poll_events(struct nw *nw)
{
        XEvent ev;
        Display *display = (Display *)nw->egl_display;
        while (XPending(display))
        {
                XNextEvent(display, &ev);
                switch (ev.type)
                {

                case Expose:
                        if (ev.xexpose.count == 0 && nw->cb_vtable_p->paint)
                                nw->cb_vtable_p->paint(nw, nw->data);
                        break;

                case ConfigureNotify:
                        if (nw->cb_vtable_p->size)
                                nw->cb_vtable_p->size(nw, ev.xconfigure.width, ev.xconfigure.height, nw->data);
                        break;

                case MotionNotify:
                        if (nw->cb_vtable_p->mouse_move)
                        {
                                int flags;
                                if ((ev.xmotion.state & ControlMask) != 0)
                                {
                                        flags |= NW_CONTROL;
                                }
                                if ((ev.xmotion.state & ShiftMask) != 0)
                                {
                                        flags |= NW_SHIFT;
                                }
                                nw->cb_vtable_p->mouse_move(nw, ev.xmotion.x, ev.xmotion.y, flags, nw->data);
                        }
                        break;

                case ButtonPress:
                case ButtonRelease: {
                        int flags;
                        if ((ev.xbutton.state & ControlMask) != 0)
                        {
                                flags |= NW_CONTROL;
                        }
                        if ((ev.xbutton.state & ShiftMask) != 0)
                        {
                                flags |= NW_SHIFT;
                        }
                        // Обработка скролла (в X11 колесико — это кнопки 4, 5, 6, 7)
                        if (ev.xbutton.button >= 4 && ev.xbutton.button <= 7)
                        {
                                if (nw->cb_vtable_p->mouse_scroll && ev.type == ButtonPress)
                                {
                                        int dx = 0, dy = 0;
                                        if (ev.xbutton.button == 4)
                                                dy = 1; // Вверх
                                        else if (ev.xbutton.button == 5)
                                                dy = -1; // Вниз
                                        else if (ev.xbutton.button == 6)
                                                dx = -1; // Влево
                                        else if (ev.xbutton.button == 7)
                                                dx = 1; // Вправо

                                        nw->cb_vtable_p->mouse_scroll(nw, dx, dy, flags, nw->data);
                                }
                        }
                        else
                        {
                                // Обычный клик
                                if (nw->cb_vtable_p->mouse_click)
                                {
                                        int mode = ev.xbutton.button; // 1-ЛКМ, 2-СКМ, 3-ПКМ
                                        int action = (ev.type == ButtonPress) ? 1 : 0;
                                        nw->cb_vtable_p->mouse_click(nw, ev.xbutton.x, ev.xbutton.y, mode, action,
                                                                     flags, nw->data);
                                }
                        }
                        break;
                }

                case LeaveNotify:
                        if (nw->cb_vtable_p->mouse_leave)
                                nw->cb_vtable_p->mouse_leave(nw, nw->data);
                        break;
                }
        }
        return 1;
}

int nw_create_x11(struct nw *nw, struct nw_callback_vtable *vtable, Display *display, Window parent, void *data)
{
        nw->data = data;
        nw->cb_vtable_p = vtable;
        nw->vtable.destroy = destroy;
        nw->vtable.dirty = dirty;
        nw->vtable.focus = focus;
        nw->vtable.get_cursor_pos = get_cursor_pos;
        nw->vtable.set_cursor_pos = set_cursor_pos;
        nw->vtable.show_cursor = show_cursor;
        nw->vtable.get_size = get_size;
        nw->vtable.set_size = set_size;
        nw->vtable.make_context_current = make_context_current;
        nw->vtable.swap_buffers = swap_buffers;
        nw->vtable.poll_events = poll_events;
        nw->egl_display = eglGetDisplay((EGLNativeDisplayType)display);
        eglInitialize(nw->egl_display, NULL, NULL);
        EGLint attribs[] = {EGL_RENDERABLE_TYPE,
                            EGL_OPENGL_BIT,
                            EGL_SURFACE_TYPE,
                            EGL_WINDOW_BIT,
                            EGL_RED_SIZE,
                            8,
                            EGL_GREEN_SIZE,
                            8,
                            EGL_BLUE_SIZE,
                            8,
                            EGL_DEPTH_SIZE,
                            24,
                            EGL_NONE};
        EGLint num_configs;
        eglChooseConfig(nw->egl_display, attribs, &nw->egl_config, 1, &num_configs);
        EGLint context_attribs[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};
        eglBindAPI(EGL_OPENGL_API);
        nw->egl_context = eglCreateContext(nw->egl_display, nw->egl_config, EGL_NO_CONTEXT, context_attribs);
        EGLint vid;
        eglGetConfigAttrib(nw->egl_display, nw->egl_config, EGL_NATIVE_VISUAL_ID, &vid);
        XVisualInfo vinfo_template = {.visualid = vid};
        int n;
        XVisualInfo *vinfo = XGetVisualInfo(display, VisualIDMask, &vinfo_template, &n);
        XSetWindowAttributes swa = {
            .colormap = XCreateColormap(display, RootWindow(display, vinfo->screen), vinfo->visual, AllocNone),
            .event_mask = StructureNotifyMask | ExposureMask | KeyPressMask | PointerMotionMask};

        nw->xwindow = XCreateWindow(display, parent, 0, 0, 800, 600, 0, vinfo->depth, InputOutput, vinfo->visual,
                                    CWColormap | CWEventMask, &swa);
        XMapWindow(display, nw->xwindow);
        XFree(vinfo);
        nw->egl_surface =
            eglCreateWindowSurface(nw->egl_display, nw->egl_config, (EGLNativeWindowType)nw->xwindow, NULL);
        long mask = ExposureMask          // для paint
                    | StructureNotifyMask // для size
                    | PointerMotionMask   // для mouse_move
                    | ButtonPressMask     // для mouse_clic
                    | ButtonReleaseMask   // для mouse_click
                    | LeaveWindowMask;    // для mouse_leave
        XSelectInput(display, nw->xwindow, mask);
        if (eglMakeCurrent(nw->egl_display, nw->egl_surface, nw->egl_surface, nw->egl_context) == EGL_FALSE)
        {
                EGLint error = eglGetError();
                printf("EGL Error: 0x%x\n", error);
        }
        nw->cb_vtable_p->ready(nw, data);

        return 1;
}

#endif