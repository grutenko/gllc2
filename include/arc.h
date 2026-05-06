#ifndef arc_h
#define arc_h

#include "block.h"
#include "draw.h"
#include "entity.h"

struct gllc_arc {
  struct gllc_entity _ent;
  struct ds_unit *u;
  double x;
  double y;
  double radius;
  double start_angle;
  double arc_angle;
};

struct gllc_arc *gllc_arc_create(struct gllc_block *block, struct ds_draw *draw, double x, double y, double radius, double start_angle, double arc_angle);

#endif