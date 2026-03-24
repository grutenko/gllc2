#include "window.h"
#include "alloc.h"
#include "object.h"


#include <string.h>

static void _destroy(struct gllc_object *obj) {}

static struct gllc_prop _props[] = {P_END};
static struct gllc_prop *_all_props[] = {};
static struct gllc_object_vtable _vtable = {
    .destroy = _destroy};

struct gllc_window *gllc_window_create(void *p) {
  struct gllc_window *wnd = XALLOC(sizeof(struct gllc_window));
  if (wnd) {
    memset(wnd, 0, sizeof(struct gllc_window));
    GLLC_OBJECT_INIT(wnd, _all_props, &_vtable);
  }
  return wnd;
}