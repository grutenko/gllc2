#ifndef drawing_h
#define drawing_h

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
void gllc_drw_destroy(struct gllc_drawing *drawing);

#endif