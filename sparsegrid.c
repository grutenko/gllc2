#include "sparsegrid.h"
#include "entity.h"

#include <math.h>
#include <profileapi.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define SG_HASH(X_, Y_) sg_hash(X_, Y_)
#define SG_HASHTAB_SHIFT 10
#define SG_HASHTAB_CAP (1 << SG_HASHTAB_SHIFT)

struct sg_cell {
  uint64_t hash;
  struct gllc_entity **ent;
  size_t ent_cap;
  size_t ent_size;
};

struct sg {
  struct sg_cell *b[SG_HASHTAB_CAP];
  int cnt[SG_HASHTAB_CAP];
  int cap[SG_HASHTAB_CAP];
  int shift;
  int x0, y0, x1, y1;
  int total;
};

static inline uint64_t sg_hash_in(int x, int y) {
  uint64_t h = (uint64_t)x * 0x9e3779b1ULL;
  uint64_t yy = (uint64_t)y + 0x85ebca6bULL;
  h ^= yy + (h << 6) + (h >> 2);
  return h;
}

uint64_t sg_hash(int x, int y) {
  return sg_hash_in(x, y);
}

struct sg *sg_create(int shift) {
  struct sg *sg = malloc(sizeof(struct sg));
  if (sg) {
    memset(sg, 0, sizeof(struct sg));
    sg->shift = shift;
  }
  return sg;
}

static inline void _swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

static inline void _swapf(double *a, double *b) {
  double t = *a;
  *a = *b;
  *b = t;
}

int sg_shift(struct sg *sg) {
  return sg->shift;
}

static struct sg_cell *push_cell(struct sg *sg, int x, int y) {
  int i;
  uint64_t H = sg_hash_in(x, y);
  int batch = H & (SG_HASHTAB_CAP - 1);
  int cnt = sg->cnt[batch];
  int cap = sg->cap[batch];
  for (i = 0; i < cnt; i++) {
    if (sg->b[batch][i].hash > H) break;
  }
  if (cap <= cnt) {
    size_t sz = cap ? cap * 2 : 8;
    struct sg_cell *cells = realloc(sg->b[batch], sz * sizeof(struct sg_cell));
    if (!cells)
      return NULL;
    sg->b[batch] = cells;
    sg->cap[batch] = sz;
  }
  memmove(&sg->b[batch][i + 1], &sg->b[batch][i], (sg->cnt[batch] - i) * sizeof(struct sg_cell));
  sg->b[batch][i].hash = H;
  sg->b[batch][i].ent = NULL;
  sg->b[batch][i].ent_cap = 0;
  sg->b[batch][i].ent_size = 0;
  sg->cnt[batch]++;
  if (sg->x0 > x)
    sg->x0 = x;
  if (sg->y0 > y)
    sg->y0 = y;
  if (sg->x1 < x)
    sg->x1 = x;
  if (sg->y1 < y)
    sg->y1 = y;
  sg->total++;
  return &sg->b[batch][i];
}

static int cmp(const void *a, const void *b) {
  uint64_t ha = ((struct sg_cell *)a)->hash;
  uint64_t hb = ((struct sg_cell *)b)->hash;
  return (ha > hb) - (ha < hb);
}

static inline struct sg_cell *cell_at(struct sg *sg, int x, int y) {
  if (sg->total == 0 || sg->x0 > x || sg->x1 < x || sg->y0 > y || sg->y1 < y)
    return NULL;
  uint64_t H = sg_hash_in(x, y);
  int batch = H & (SG_HASHTAB_CAP - 1);
  struct sg_cell *base = sg->b[batch];
  for (int i = 0; i < sg->cnt[batch]; i++) {
    if (base[i].hash == H) {
      return &base[i];
    }
  }
  return NULL;
}

static int cell_push_ent(struct sg_cell *cell, struct gllc_entity *ent) {
  int i;
  for (i = 0; i < cell->ent_size; i++) {
    if (cell->ent[i]->order <= ent->order)
      break;
  }
  if (cell->ent_cap <= cell->ent_size) {
    size_t sz = cell->ent_cap ? cell->ent_cap * 2 : 8;
    struct gllc_entity **ents = realloc(cell->ent, sz * sizeof(struct gllc_entity *));
    if (!ents)
      return 0;
    cell->ent = ents;
    cell->ent_cap = sz;
  }
  memmove(&cell->ent[i + 1], &cell->ent[i], (cell->ent_size - i) * sizeof(struct gllc_entity *));
  cell->ent[i] = ent;
  cell->ent_size++;
  return 1;
}

static void cell_remove_ent(struct sg_cell *cell, struct gllc_entity *ent) {
  int i;
  for (i = 0; i < cell->ent_size; i++) {
    if (cell->ent[i] == ent) {
      memmove(&cell->ent[i], &cell->ent[i + 1], (cell->ent_size - i - 1) * sizeof(struct gllc_entity *));
      cell->ent_size--;
      return;
    }
  }
}

int sg_push(struct sg *sg, struct gllc_entity *ent, double x0, double y0, double x1, double y1) {
  int x, y, i;

  if (x0 > x1)
    _swapf(&x0, &x1);
  if (y0 > y1)
    _swapf(&y0, &y1);

  int cx0 = ((int)floor(x0)) >> sg->shift;
  int cy0 = ((int)floor(y0)) >> sg->shift;
  int cx1 = ((int)floor(x1)) >> sg->shift;
  int cy1 = ((int)floor(y1)) >> sg->shift;

  for (x = cx0; x <= cx1; x++) {
    for (y = cy0; y <= cy1; y++) {
      struct sg_cell *cell = cell_at(sg, x, y);
      if (!cell) {
        cell = push_cell(sg, x, y);
        if (!cell)
          return 0;
      }
      if (!cell_push_ent(cell, ent))
        return 0;
    }
  }
  return 1;
}

void sg_remove(struct sg *sg, struct gllc_entity *ent) {
  int i, j;
  for (i = 0; i < SG_HASHTAB_CAP; i++) {
    for (j = 0; j < sg->cnt[i]; j++) {
      cell_remove_ent(&sg->b[i][j], ent);
    }
  }
}

void sg_remove_all(struct sg *sg) {
  int i, j;
  for (i = 0; i < SG_HASHTAB_CAP; i++) {
    for (j = 0; j < sg->cnt[i]; j++) {
      sg->b[i][j].ent_size = 0;
    }
  }
}

void sg_destroy(struct sg *sg) {
  int i, j;
  for (i = 0; i < SG_HASHTAB_CAP; i++) {
    for (j = 0; j < sg->cnt[i]; j++) {
      free(sg->b[i][j].ent);
    }
    free(sg->b[i]);
  }
  free(sg);
}

struct sg_cell *sg_pick_cell(struct sg *sg, double x, double y) {
  return cell_at(sg, ((int)floor(x)) >> sg->shift, ((int)floor(y)) >> sg->shift);
}

struct gllc_entity **sg_cell_ents(struct sg_cell *cell) {
  return cell->ent;
}

int sg_cell_ents_cnt(struct sg_cell *cell) {
  return cell->ent_size;
}

void sg_bbox(struct sg *sg, double *x0, double *y0, double *x1, double *y1) {
  if (x0)
    *x0 = sg->x0;
  if (y0)
    *y0 = sg->y0;
  if (x1)
    *x1 = sg->x1;
  if (y1)
    *y1 = sg->y1;
}

struct sg_cell *sg_cell_at(struct sg *sg, int x, int y) {
  return cell_at(sg, x, y);
}