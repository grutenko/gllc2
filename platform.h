#ifndef platform_h
#define platform_h

#if defined(_WIN32)
#include <windows.h>
#endif

struct nw;

struct nw_vtable {
  void (*paint)(struct nw *w, void *data);
  void (*size)(struct nw *w, int width, int height, void *data);
  void (*mouse_move)(struct nw *w, int x, int y, void *data);
  void (*mouse_click)(struct nw *wn, int x, int y, int mode, int action, void *data);
  void (*mouse_scroll)(struct nw *wn, int dx, int dy, void *data);
  void (*mouse_leave)(struct nw *wn, void *data);
};

struct nw {
#if defined(_WIN32)
  HWND w;
  HDC dc;
  HGLRC glrc;
#endif
  void *data;
  struct nw_vtable *vtable;
  struct nw *next;
  struct nw *prev;
};

int nw_create(struct nw *NW, void *parent, struct nw_vtable *vtable, void *data);
void nw_destroy(struct nw *NW);
void nw_get_cursor(struct nw *w, int *x, int *y);
void nw_make_context_current(struct nw *w);
void nw_get_size(struct nw *w, int *width, int *height);
void nw_set_size(struct nw *w, int x, int y, int width, int height);
void nw_swap_buffers(struct nw *w);
void nw_dirty(struct nw *w);
void nw_show_cursor(int show);

#endif