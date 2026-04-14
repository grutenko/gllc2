#ifndef polyline_h
#define polyline_h

#include "entity.h"
#include "entity_vertex.h"

struct gllc_polyline {
  struct gllc_entity _ent;
  int cnt;
  int cap;
  uint64_t unit_ID;
  struct ev *pts;
};

struct gllc_polyline *gllc_polyline_create(struct gllc_block *block, struct ds_draw *draw, int closed, int filled);
void gllc_pline_add_ver(struct gllc_polyline *pline, double x, double y);
void gllc_pline_end(struct gllc_polyline *pline);
#endif