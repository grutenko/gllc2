#ifndef point_h
#define point_h

#include "entity.h"

struct gllc_point {
  struct gllc_entity _ent;
  double x;
  double y;
};

struct gllc_point *gllc_point_create(struct gllc_block *block);

#endif