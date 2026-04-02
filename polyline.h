#ifndef polyline_h
#define polyline_h

#include "entity.h"

struct gllc_polyline {
  struct gllc_entity _ent;
  struct ds_unit *unit;
  double *pts;
  size_t cnt;
  size_t cap;
};

struct gllc_polyline *gllc_polyline_create(struct gllc_block *block, int closed, int filled);

void gllc_pline_add_ver(struct gllc_polyline *pline, double x, double y);

#endif