#ifndef block_h
#define block_h

#include "object.h"

#include <stddef.h>

struct gllc_entity;
struct ds_draw;
struct gllc_drawing;
struct sg_cell;

struct gllc_block_batch {
  struct ds_draw *draw;
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
  struct gllc_block_batch inter_batch;
  struct gllc_drawing *drawing;
  double scale;
};

struct gllc_block *gllc_block_create(struct gllc_drawing *drawing, const char *name, double dx, double dy);
void gllc_block_update(struct gllc_block *block);
void gllc_block_destroy(struct gllc_block *block);

#endif