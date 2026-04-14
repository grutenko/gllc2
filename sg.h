#ifndef gllc_sparse_grid_h
#define gllc_sparse_grid_h

#include <stdint.h>

struct gllc_entity;
struct sg;
struct sg_cell;

uint64_t sg_hash(int x, int y);
struct sg *sg_create(int shift);
int sg_push(struct sg *sg, struct gllc_entity *ent, double bbox_x0, double bbox_y0, double bbox_x1, double bbox_y1);
void sg_remove(struct sg *sg, struct gllc_entity *ent);
void sg_remove_all(struct sg *sg);
struct sg_cell *sg_pick_cell(struct sg *sg, double x, double y);
struct gllc_entity **sg_cell_ents(struct sg_cell *cell);
int sg_cell_ents_cnt(struct sg_cell *cell);
void sg_destroy(struct sg *sg);

#endif