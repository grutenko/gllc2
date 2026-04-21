#include "block.h"
#include "circle.h"
#include "draw.h"
#include "entity.h"
#include "named_object.h"
#include "object.h"
#include "polyline.h"
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
  struct gllc_entity *min_ent = NULL;
  double min_dis = 0.0;
  printf("%d\n", cnt);
  for (i = 0; i < cnt; i++) {
    double dis = 0.0;
    if (ents[i]->vtable->picked(ents[i], block->scale, x, y, &dis)) {
      if (!min_ent || min_dis > dis) {
        min_ent = ents[i];
        min_dis = dis;
      }
    }
  }
  return min_ent;
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
    size_t sz = block->batch.bqcap ? block->batch.bqcap * 2 : 64;
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
  if (exclusive)
    clear_hover(block);
  if (!ent)
    return;
  if (ent->flags & GLLC_ENT_HOVER)
    return;
  ent->flags |= GLLC_ENT_HOVER;
  ent->flags |= GLLC_ENT_MODIFIED;
  gllc_block_put_bq(block, ent);
  push_hover(block, ent);
}