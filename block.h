#ifndef block_h
#define block_h

#include "draw.h"
#include "entity.h"
#include "line.h"
#include "named_object.h"

#include <stddef.h>

struct gllc_entity;
struct gllc_drawing;
struct gllc_window;
struct sg_cell;

struct gllc_block {
  struct gllc_nobject _nobj;
  struct gllc_window *wnd;
  double x;
  double y;
  struct ds_draw draw;
  struct gllc_entity *h;
  struct gllc_entity *t;
  struct gllc_entity **bq;
  struct sg *sg;
  int cnt;
  int bqcnt;
  int bqcap;
  struct gllc_entity **sel;
  struct gllc_entity **hov;
  int selcnt;
  int selcap;
  int hovcnt;
  int hovcap;
  struct gllc_entity **fil;
  int filcnt;
  int filcap;
  struct gllc_entity_props props;
  int units;
  int ufscaling;
  double paper_x0;
  double paper_y0;
  double paper_width;
  double paper_height;
  int paper_size;
  int paper_orient;
};

struct gllc_block *gllc_block_create(struct gllc_drawing *drawing, const char *name, double x, double y);
void gllc_block_update(struct gllc_block *block);
void gllc_block_destroy(struct gllc_block *block);

void gllc_block_set_window(struct gllc_block *block, struct gllc_window *window);
struct gllc_entity *gllc_block_pick_ent(struct gllc_block *block, double x, double y, int skiplocked, int skiphidden);
struct gllc_polyline *gllc_block_add_polyline(struct gllc_block *block, int closed, int filled);
struct gllc_line *gllc_block_add_line(struct gllc_block *block, double p0[2], double p1[2]);
struct gllc_arc *gllc_block_add_arc(struct gllc_block *block, double x, double y, double radius, double start_angle, double arc_angle);
struct gllc_circle *gllc_block_add_circle(struct gllc_block *block, double x, double y, double r, int filled);
void gllc_block_sync_gpu(struct gllc_block *block, struct ds_gpu *gpu);
void gllc_block_put_bq(struct gllc_block *block, struct gllc_entity *ent);
void gllc_block_ent_hover(struct gllc_block *block, struct gllc_entity *ent, int exclusive);
struct gllc_entity *gllc_block_ent_get_filter_at(struct gllc_block *block, int index);
int gllc_block_ent_get_filter_cnt(struct gllc_block *block);
int gllc_block_ent_filter_rect(struct gllc_block *block, int mode, double x0, double y0, double x1, double y1, int skiplocked, int skiphidden);
struct gllc_line *gllc_block_add_line(struct gllc_block *block, double *p0, double *p1);
void gllc_block_select(struct gllc_block *block, struct gllc_entity *ent, int exclusive);
int gllc_block_get_select_cnt(struct gllc_block *block);
struct gllc_entity *gllc_block_get_select_at(struct gllc_block *block, int index);
void gllc_block_ent_remove(struct gllc_block *block, struct gllc_entity *ent);
void gllc_block_bbox(struct gllc_block *block, double *x0, double *y0, double *x1, double *y1);
void gllc_block_sel_bbox(struct gllc_block *block, double *x0, double *y0, double *x1, double *y1);
void gllc_block_visbox(struct gllc_block *block, double *x0, double *y0, double *x1, double *y1);
#endif