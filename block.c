#include "block.h"
#include "circle.h"
#include "draw.h"
#include "entity.h"
#include "named_object.h"
#include "object.h"
#include "polyline.h"
#include "rect.h"
#include "sg.h"

#include <math.h>
#include <profileapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winnt.h>

static struct gllc_prop props[] = {P_END};
static struct gllc_prop *all_props[] = {G_nobject_props, props, NULL};

static void destroy(struct gllc_object *obj) {
  gllc_block_destroy((struct gllc_block *)obj);
}

static struct gllc_object_vtable vtable = {
    .destroy = destroy};

struct gllc_block *gllc_block_create(struct gllc_drawing *drawing, const char *name, double dx, double dy) {
  struct gllc_block *block = malloc(sizeof(struct gllc_block));
  if (block) {
    memset(block, 0, sizeof(struct gllc_block));
    gllc_nobject_init((struct gllc_nobject *)block, drawing, all_props, &vtable, GLLC_OBJ_BLOCK, name);
    block->dx = dx;
    block->dy = dy;
    block->props.color = -1;
    block->props.fcolor = -1;
    block->batch.sg = sg_create(6);
    if (!block->batch.sg) {
      free(block);
      return NULL;
    }
    block->scale = 1.0f;
  }
  return block;
}

void gllc_block_update(struct gllc_block *block) {
  if (!block)
    return;
  int i;
  double x0, y0, x1, y1;
  struct gllc_entity *ent;
  for (i = 0; i < block->batch.bqcnt; i++) {
    ent = block->batch.bq[i];
    ent->vtable->build(ent, &block->batch.draw, block->scale);
    if (gllc_entity_geometry_modified(ent)) {
      ent->vtable->bbox(ent, 1.0f, &x0, &y0, &x1, &y1);
      if (!(ent->flags & GLLC_ENT_INITIAL)) {
        sg_remove(block->batch.sg, ent);
      }
      sg_push(block->batch.sg, ent, x0, y0, x1, y1);
      ent->flags &= ~GLLC_ENT_INITIAL;
    }
    ent->flags &= ~(GLLC_ENT_MODIFIED | GLLC_ENT_GEOMETRY_MODIFIED);
  }
  block->batch.bqcnt = 0;
}

void gllc_block_destroy(struct gllc_block *block) {
  if (!block)
    return;
  struct gllc_entity *ent = block->batch.h;
  while (ent) {
    struct gllc_entity *next = ent->next;
    gllc_entity_destroy(ent);
    ent = next;
  }
  sg_destroy(block->batch.sg);
  ds_draw_clear(&block->batch.draw);
  free(block->batch.bq);
  free(block->batch.hov);
  free(block->batch.sel);
  free(block->batch.fil);
  free(block);
}

static void push_ent(struct gllc_block *block, struct gllc_entity *ent) {
  if (block->batch.h) {
    block->batch.h->next = ent;
    ent->prev = block->batch.t;
    block->batch.t = ent;
  } else {
    block->batch.h = ent;
    block->batch.t = ent;
  }
  block->batch.cnt++;
}

struct gllc_polyline *gllc_block_add_polyline(struct gllc_block *block, int closed, int filled) {
  struct gllc_polyline *pline = gllc_polyline_create(block, &block->batch.draw, closed, filled);
  if (pline) {
    push_ent(block, (struct gllc_entity *)pline);
    gllc_block_put_bq(block, (struct gllc_entity *)pline);
  }
  return pline;
}

struct gllc_circle *gllc_block_add_circle(struct gllc_block *block, double x, double y, double r, int filled) {
  struct gllc_circle *circle = gllc_circle_create(block, &block->batch.draw, x, y, r, filled);
  if (circle) {
    push_ent(block, (struct gllc_entity *)circle);
    gllc_block_put_bq(block, (struct gllc_entity *)circle);
  }
  return circle;
}

struct gllc_entity *gllc_block_pick_ent(struct gllc_block *block, double x, double y) {
  struct gllc_entity *ent = NULL;
  struct sg_cell *cell = sg_pick_cell(block->batch.sg, x, y);
  if (!cell)
    return NULL;
  int i;
  struct gllc_entity **ents = sg_cell_ents(cell);
  int cnt = sg_cell_ents_cnt(cell);
  for (i = 0; i < cnt; i++) {
    if (ents[i]->vtable->picked(ents[i], block->scale, x, y, NULL)) {
      return ents[i];
    }
  }
  return NULL;
}

void gllc_block_sync_gpu(struct gllc_block *block, struct ds_gpu *gpu) {
  if (ds_draw_dirty(&block->batch.draw)) {
    ds_sync(&block->batch.draw, gpu);
  }
}

void gllc_block_put_bq(struct gllc_block *block, struct gllc_entity *ent) {
  if (block->batch.bqcap <= block->batch.bqcnt) {
    size_t sz = block->batch.bqcap ? block->batch.bqcap * 2 : 1024;
    struct gllc_entity **bq = realloc(block->batch.bq, sz * sizeof(struct gllc_entity *));
    if (!bq) {
      return;
    }
    block->batch.bq = bq;
    block->batch.bqcap = sz;
  }
  block->batch.bq[block->batch.bqcnt] = ent;
  block->batch.bqcnt++;
}

void gllc_block_set_scale(struct gllc_block *block, double scale) {
  if (!block)
    return;
  block->scale = scale;
}

static void clear_hover(struct gllc_block *block) {
  int i;
  struct gllc_entity *ent;
  for (i = 0; i < block->batch.hovcnt; i++) {
    ent = block->batch.hov[i];
    ent->flags &= ~GLLC_ENT_HOVER;
    ent->flags |= GLLC_ENT_MODIFIED;
    gllc_block_put_bq(block, ent);
  }
  block->batch.hovcnt = 0;
}

static void push_hover(struct gllc_block *block, struct gllc_entity *ent) {
  if (block->batch.hovcap <= block->batch.hovcnt) {
    size_t sz = block->batch.hovcap ? block->batch.hovcap * 2 : 64;
    struct gllc_entity **hov = realloc(block->batch.hov, sz * sizeof(struct gllc_entity *));
    if (!hov) {
      return;
    }
    block->batch.hov = hov;
    block->batch.hovcap = sz;
  }
  block->batch.hov[block->batch.hovcnt] = ent;
  block->batch.hovcnt++;
}

void gllc_block_ent_hover(struct gllc_block *block, struct gllc_entity *ent, int exclusive) {
  if (exclusive) {
    if (block->batch.hovcnt == 1 && block->batch.hov[0] == ent) {
      return;
    }
    clear_hover(block);
  }
  if (!ent)
    return;
  if (ent->flags & GLLC_ENT_HOVER)
    return;
  ent->flags |= GLLC_ENT_HOVER;
  ent->flags |= GLLC_ENT_MODIFIED;
  gllc_block_put_bq(block, ent);
  push_hover(block, ent);
}

struct gllc_entity *gllc_block_ent_get_filter_at(struct gllc_block *block, int index) {
  if (index < 0 || index >= block->batch.filcnt)
    return NULL;
  return block->batch.fil[index];
}

int gllc_block_ent_get_filter_cnt(struct gllc_block *block) {
  return block->batch.filcnt;
}

static inline void push_filter_ent(struct gllc_block *block, struct gllc_entity *ent) {
  if (block->batch.filcap <= block->batch.filcnt) {
    size_t sz = block->batch.filcap ? block->batch.filcap * 2 : 64;
    struct gllc_entity **fil = realloc(block->batch.fil, sz * sizeof(struct gllc_entity *));
    if (!fil) {
      return;
    }
    block->batch.fil = fil;
    block->batch.filcap = sz;
  }
  block->batch.fil[block->batch.filcnt] = ent;
  block->batch.filcnt++;
}

static inline void _swapf(double *a, double *b) {
  double t = *a;
  *a = *b;
  *b = t;
}

int gllc_block_ent_filter_rect(struct gllc_block *block, int mode, double x0, double y0, double x1, double y1) {
  for (int i = 0; i < block->batch.filcnt; i++)
    block->batch.fil[i]->flags &= ~GLLC_ENT_FILTER;
  block->batch.filcnt = 0;
  int x, y, i;
  int shift = sg_shift(block->batch.sg);

  if (x0 > x1)
    _swapf(&x0, &x1);
  if (y0 > y1)
    _swapf(&y0, &y1);

  int cx0 = ((int)floor(x0)) >> shift;
  int cy0 = ((int)floor(y0)) >> shift;
  int cx1 = ((int)floor(x1)) >> shift;
  int cy1 = ((int)floor(y1)) >> shift;

  for (x = cx0; x <= cx1; x++) {
    for (y = cy0; y <= cy1; y++) {
      struct sg_cell *cell = sg_cell_at(block->batch.sg, x, y);
      if (!cell)
        continue;
      struct gllc_entity **ents = sg_cell_ents(cell);
      int entcnt = sg_cell_ents_cnt(cell);
      for (i = 0; i < entcnt; i++) {
        if (ents[i]->flags & GLLC_ENT_FILTER)
          continue;
        if (ents[i]->vtable->selected(ents[i], mode, block->scale, x0, y0, x1, y1)) {
          ents[i]->flags |= GLLC_ENT_FILTER;
          push_filter_ent(block, ents[i]);
        }
      }
    }
  }
  return 1;
}

struct gllc_line *gllc_block_add_line(struct gllc_block *block, double *p0, double *p1) {
  struct gllc_line *l = gllc_line_create(block, &block->batch.draw, p0, p1);
  if (l) {
    push_ent(block, (struct gllc_entity *)l);
    gllc_block_put_bq(block, (struct gllc_entity *)l);
  }
  return l;
}

struct gllc_rect *gllc_block_add_rect(struct gllc_block *block, double *p, double w, double h, double angle) {
  struct gllc_rect *r = gllc_rect_create(block, &block->batch.draw, p, w, h, angle);
  if (r) {
    push_ent(block, (struct gllc_entity *)r);
    gllc_block_put_bq(block, (struct gllc_entity *)r);
  }
  return r;
}

static void push_select(struct gllc_block *block, struct gllc_entity *ent) {
  if (block->batch.selcap <= block->batch.selcnt) {
    size_t sz = block->batch.selcap ? block->batch.selcap * 2 : 64;
    struct gllc_entity **sel = realloc(block->batch.sel, sz * sizeof(struct gllc_entity *));
    if (!sel) {
      return;
    }
    block->batch.sel = sel;
    block->batch.filcap = sz;
  }
  block->batch.sel[block->batch.selcnt] = ent;
  block->batch.selcnt++;
}

static void clear_select(struct gllc_block *block) {
  int i;
  struct gllc_entity *ent;
  for (i = 0; i < block->batch.selcnt; i++) {
    ent = block->batch.sel[i];
    ent->flags &= ~GLLC_ENT_SELECTED;
    ent->flags |= GLLC_ENT_MODIFIED;
    gllc_block_put_bq(block, ent);
  }
  block->batch.selcnt = 0;
}

void gllc_block_select(struct gllc_block *block, struct gllc_entity *ent, int exclusive) {
  if (exclusive)
    clear_select(block);
  if (!ent)
    return;
  if (ent->flags & GLLC_ENT_SELECTED)
    return;
  ent->flags |= GLLC_ENT_SELECTED;
  ent->flags |= GLLC_ENT_MODIFIED;
  gllc_block_put_bq(block, ent);
  push_select(block, ent);
}

int gllc_block_get_select_cnt(struct gllc_block *block) {
  return block->batch.selcnt;
}

struct gllc_entity *gllc_block_get_select_at(struct gllc_block *block, int index) {
  if (index < 0 || block->batch.selcnt <= index)
    return NULL;
  return block->batch.sel[index];
}