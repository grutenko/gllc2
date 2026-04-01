#ifndef block_h
#define block_h

#include "object.h"
#include "entity.h"
#include "draw.h"

#include <stddef.h>

struct gllc_entity;
struct gllc_drawing;
struct sg_cell;

struct gllc_block_batch {
  struct ds_draw draw;
  struct gllc_entity *ent_head;
  struct gllc_entity *ent_tail;
  struct sg_cell *grid;
  size_t cnt;
};

struct gllc_block {
  struct gllc_object _obj;
  char name[64];
  double dx;
  double dy;
  struct gllc_block_batch cmn_batch;
  struct gllc_drawing *drawing;
  struct gllc_entity_props props;
  double scale;
  struct gllc_block *next;
  struct gllc_block *prev;
};

struct gllc_block *gllc_block_create(struct gllc_drawing *drawing, const char *name, double dx, double dy);
void gllc_block_update(struct gllc_block *block);
void gllc_block_destroy(struct gllc_block *block);
struct gllc_polyline *gllc_block_add_polyline(struct gllc_block *block, int closed, int filled);

#endif