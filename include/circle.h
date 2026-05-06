#ifndef circle_h
#define circle_h

#include "entity.h"

struct gllc_circle {
  struct gllc_entity _ent;
  double p[2];
  double radius;
  struct ds_unit *u;
};

struct gllc_circle *gllc_circle_create(struct gllc_block *block, struct ds_draw *draw, double x, double y, double radius, int filled);

#endif