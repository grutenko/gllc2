#include "platform.h"

void nw_destroy(struct nw *nw)
{
        nw->vtable.destroy(nw);
}

void nw_get_cursor(struct nw *nw, int *x, int *y)
{
        nw->vtable.get_cursor_pos(nw, x, y);
}

void nw_make_context_current(struct nw *nw)
{
        nw->vtable.make_context_current(nw);
}

void nw_release_current_context(struct nw *nw) {
  nw->vtable.make_context_current(NULL);
}

void nw_get_size(struct nw *nw, int *width, int *height) {
  nw->vtable.get_size(nw, width, height);
}

void nw_set_size(struct nw *nw, int x, int y, int width, int height)
{
        nw->vtable.set_size(nw, width, height);
}

void nw_swap_buffers(struct nw *nw)
{
        nw->vtable.swap_buffers(nw);
}

void nw_dirty(struct nw *nw)
{
        nw->vtable.dirty(nw);
}

void nw_show_cursor(struct nw *nw, int show)
{
        nw->vtable.show_cursor(nw, show);
}

void nw_focus(struct nw *nw)
{
        nw->vtable.focus(nw);
}

void nw_cursor_set_pos(struct nw *nw, int x, int y)
{
        nw->vtable.set_cursor_pos(nw, x, y);
}

void nw_poll_events(struct nw *nw)
{
        nw->vtable.poll_events(nw);
}