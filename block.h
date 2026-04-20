#ifndef block_h
#define block_h

#include "draw.h"
#include "entity.h"
#include "named_object.h"

#include <stddef.h>

struct gllc_entity;
struct gllc_drawing;
struct sg_cell;

struct gllc_block_batch {
  struct ds_draw draw;
  struct gllc_entity *h;
  struct gllc_entity *t;
  struct gllc_entity **bq;
  struct sg *sg;
  int cnt;
  int bqcnt;
  int bqcap;
};

struct gllc_block {
  struct gllc_nobject _nobj;
  double dx;
  double dy;
  struct gllc_block_batch batch;
  struct gllc_entity_props props;
  double scale;
};

struct gllc_block *gllc_block_create(struct gllc_drawing *drawing, const char *name, double dx, double dy);
void gllc_block_update(struct gllc_block *block);
void gllc_block_destroy(struct gllc_block *block);
struct gllc_entity *gllc_block_pick_ent(struct gllc_block *block, double x, double y);
struct gllc_polyline *gllc_block_add_polyline(struct gllc_block *block, int closed, int filled);
void gllc_block_sync_gpu(struct gllc_block *block, struct ds_gpu *gpu);
void gllc_block_put_bq(struct gllc_block *block, struct gllc_entity *ent);

#endif