#ifndef gllc_sparse_grid_h
#define gllc_sparse_grid_h

#include "entity.h"

#include <stdint.h>

struct gllc_block_entity;

#define SG_CELL 128
#define SG_CELL_SHIFT 7
#define SG_HASH(X_, Y_) sg_hash(X_, Y_)

struct sg_cell {
  int height;
  uint64_t hash;
  struct gllc_entity **ent;
  size_t ent_cap;
  size_t ent_size;
  struct sg_cell *p;
  struct sg_cell *left;
  struct sg_cell *right;
};

uint64_t sg_hash(int x, int y);
int sg_push(struct sg_cell **grid, struct gllc_entity *ent, double bbox_x0, double bbox_y0, double bbox_x1, double bbox_y1);
void sg_remove(struct sg_cell **grid, struct gllc_entity *ent);
void sg_cleanup(struct sg_cell **grid);
struct sg_cell *sg_pick_cell(struct sg_cell **grid, double x, double y);
struct sg_cell *sg_cell_at(struct sg_cell **grid, int x, int y);
void sg_remove_all(struct sg_cell **grid);

#endif