#ifndef line_h
#define line_h

#include "draw.h"
#include "entity.h"

struct gllc_block;

struct gllc_line {
  struct gllc_entity _ent;
  double p0[2];
  double p1[2];
  struct ds_unit *u;
};

struct gllc_line *gllc_line_create(struct gllc_block *block, struct ds_draw *draw, double *p0, double *p1);

#endif