#if defined(__linux__) && !defined(__EMSCRIPTEN__)

#include "platform.h"

static void destroy(struct nw *nw)
{
        (void)nw;
}

static int set_cursor_pos(struct nw *nw, int x, int y)
{
        (void)nw;
        (void)x;
        (void)y;
        return 0;
}

static int get_cursor_pos(struct nw *nw, int *x, int *y)
{
        (void)nw;
        if (x)
                *x = 0;
        if (y)
                *y = 0;
        return 0;
}

static int make_context_current(struct nw *nw)
{
        (void)nw;
        return 0;
}

static int get_size(struct nw *nw, int *width, int *height)
{
        (void)nw;
        if (width)
                *width = 0;
        if (height)
                *height = 0;
        return 0;
}

static int set_size(struct nw *nw, int width, int height)
{
        (void)nw;
        (void)width;
        (void)height;
        return 0;
}

static int swap_buffers(struct nw *nw)
{
        (void)nw;
        return 0;
}

static int dirty(struct nw *nw)
{
        (void)nw;
        return 0;
}

static int show_cursor(struct nw *nw, int show)
{
        (void)nw;
        (void)show;
        return 0;
}

static int focus(struct nw *nw)
{
        (void)nw;
        return 0;
}

static int poll_events(struct nw *nw)
{
        (void)nw;
        return 0;
}

int nw_create_wayland(struct nw *nw, struct nw_callback_vtable *vtable, struct wl_surface *surface, void *data)
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
        return 0;
}

#endif