#ifndef text_h
#define text_h

#include "draw.h"
#include "entity.h"

struct gllc_text {
  struct gllc_entity _ent;
  char *text;
  double x;
  double y;
  struct ds_unit *u;
};

struct gllc_text *gllc_text_create(struct gllc_block *block, struct ds_draw *draw, char *text, double x, double y);

#endif