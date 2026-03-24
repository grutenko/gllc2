#ifndef platform_h
#define platform_h

#if defined(_WIN32)
#include <windows.h>
#endif

struct _gllc_NW;

struct _gllc_NW_vtable {
  void (*paint)(struct _gllc_NW *w, void *data);
  void (*size)(struct _gllc_NW *w, int width, int height, void *data);
  void (*mouse_move)(struct _gllc_NW *w, int x, int y, void *data);
  void (*mouse_click)(struct _gllc_NW *wn, int x, int y, int mode, int action,
                      void *data);
  void (*mouse_scroll)(struct _gllc_NW *wn, int dx, int dy, void *data);
};

struct _gllc_NW {
#if defined(_WIN32)
  HWND w;
  HDC dc;
  HGLRC glrc;
#endif
  void *data;
  struct _gllc_NW_vtable *vtable;
  struct _gllc_NW *next;
  struct _gllc_NW *prev;
};

int _gllc_NW_create(struct _gllc_NW *NW, struct _gllc_NW_vtable *vtable,
                    void *data);
void _gllc_NW_destroy(struct _gllc_NW *NW);
void _gllc_NW_get_cursor(struct _gllc_NW *w, int *x, int *y);
void _gllc_NW_destroy(struct _gllc_NW *w);
void _gllc_NW_make_context_current(struct _gllc_NW *w);
void _gllc_NW_get_size(struct _gllc_NW *w, int *width, int *height);
void _gllc_NW_set_size(struct _gllc_NW *w, int x, int y, int width, int height);
void _gllc_NW_swap_buffers(struct _gllc_NW *w);
void _gllc_NW_dirty(struct _gllc_NW *w);

#endif