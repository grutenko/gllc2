#ifndef rect_h
#define rect_h

#include "draw.h"
#include "entity.h"

struct gllc_rect {
  struct gllc_entity _ent;
  double p0[0];
  double w;
  double h;
  double angle;
  struct ds_unit *u;
};

struct gllc_rect *gllc_rect_create(struct gllc_block *block, struct ds_draw *draw, double *p, double w, double h, double angle);

#endif