#ifndef window_h
#define window_h

#include "object.h"

struct gllc_window {
  struct gllc_object _obj;
};

struct gllc_window *gllc_window_create(void *p);
void gllc_window_destroy(struct gllc_window *wnd);
#endif