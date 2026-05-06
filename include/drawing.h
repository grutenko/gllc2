#ifndef drawing_h
#define drawing_h

#include "layer.h"
#include "named_object.h"
#include "object.h"

struct gllc_block;

struct gllc_drawing {
  struct gllc_object _obj;
  struct gllc_nobject *oh;
  struct gllc_nobject *ot;
  int ocnt;
};

struct gllc_drawing *gllc_drw_create();
struct gllc_block *gllc_drw_add_block(struct gllc_drawing *drawing, const char *name, double dx, double dy);
struct gllc_layer *gllc_drw_add_layer(struct gllc_drawing *drw, const char *name, const char *color, struct gllc_linetype *linetype, int linewidth);
void gllc_drw_destroy(struct gllc_drawing *drawing);
struct gllc_nobject *gllc_drw_get_first_object(struct gllc_drawing *drawing, int objtype);

#endif