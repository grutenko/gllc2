#include "sparse_grid.h"
#include "entity.h"

#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AVL_HEIGHT(node_) ()
#define AVL_LL(node_)
#define AVL_RR(node_)
#define AVL_LR(node_)
#define AVL_RL(node_)

static int push_ent(struct sg_cell **grid, uint64_t hash, struct gllc_entity *ent) {
  int pos;
  int i;
  struct sg_cell **p = grid;
  struct sg_cell *prev = NULL;
  while (*p) {
    prev = *p;
    if ((*p)->hash > hash)
      p = &(*p)->left;
    else if ((*p)->hash < hash)
      p = &(*p)->right;
    else
      break;
  }
  if (!(*p)) {
    *p = (struct sg_cell *)malloc(sizeof(struct sg_cell));
    if (!(*p))
      return 0;

    (*p)->height = 0;
    (*p)->hash = hash;
    (*p)->left = (void *)0ULL;
    (*p)->right = (void *)0ULL;
    (*p)->ent = (void *)0ULL;
    (*p)->ent_cap = 0ULL;
    (*p)->ent_size = 0ULL;
  }
  if ((*p)->ent_cap <= (*p)->ent_size + 1) {
    size_t new_cap = (*p)->ent_cap ? (*p)->ent_cap * 2 : 8;
    struct gllc_entity **new_ent = realloc((*p)->ent, sizeof(struct gllc_entity *) * new_cap);
    if (!new_ent)
      return 0;
    memset(&new_ent[(*p)->ent_cap], 0, sizeof(struct gllc_entity *) * (new_cap - (*p)->ent_cap));
    (*p)->ent = new_ent;
    (*p)->ent_cap = new_cap;
  }
  for (pos = 0; pos < (*p)->ent_size; pos++) {
    if ((*p)->ent[pos]->order <= ent->order)
      break;
  }
  size_t copy_size = (*p)->ent_size - pos;
  memmove(&(*p)->ent[pos + 1], &(*p)->ent[pos], copy_size * sizeof(struct gllc_entity *));
  (*p)->ent[pos] = ent;
  (*p)->ent_size++;
  return 1;
}

static inline void _swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int sg_push(struct sg_cell **grid, struct gllc_entity *ent,
            double bbox_x0, double bbox_y0, double bbox_x1,
            double bbox_y1) {
  int cx0 = ((int)floor(bbox_x0)) >> SG_CELL_SHIFT;
  int cy0 = ((int)floor(bbox_y0)) >> SG_CELL_SHIFT;
  int cx1 = ((int)floor(bbox_x1)) >> SG_CELL_SHIFT;
  int cy1 = ((int)floor(bbox_y1)) >> SG_CELL_SHIFT;

  if (cx0 > cx1)
    _swap(&cx0, &cx1);
  if (cy0 > cy1)
    _swap(&cy0, &cy1);

  int x, y;

  // Вставляем ссылку на элемент во все ячейки входящие в bbox
  for (x = cx0; x <= cx1; x++)
    for (y = cy0; y <= cy1; y++)
      if (!push_ent(grid, SG_HASH(x, y), ent))
        return 0;

  return 1;
}

void sg_remove_all(struct sg_cell **grid) {
  // Быстрое удаление всех элементов из всех ячеек. Просто выставляет количество
  // элементов на 0 для всех ячеек

  if (!grid || !*grid)
    return;

  sg_remove_all(&(*grid)->left);
  sg_remove_all(&(*grid)->right);

  (*grid)->ent_size = 0;
}

void sg_remove(struct sg_cell **grid, struct gllc_entity *ent) {
  assert(grid);

  if (!(*grid))
    return;

  sg_remove(&(*grid)->left, ent);
  sg_remove(&(*grid)->right, ent);

  if ((*grid)->ent_size == 0)
    return;

  int i;
  for (i = 0; i < (*grid)->ent_size; i++)
    if ((*grid)->ent[i] == ent)
      break;

  // Если элемент не найден
  if (i == (*grid)->ent_size)
    return;

  // Смещаем следующие элементы на необходимый к удалению тем самы м удаляя его
  // из массива.
  size_t copy_size = (*grid)->ent_size - 1 - i;
  memmove(&(*grid)->ent[i], &(*grid)->ent[i + 1], copy_size * sizeof(struct gllc_entity *));
  (*grid)->ent_size--;
}

static struct sg_cell *find_cell(struct sg_cell **grid,
                                 uint64_t hash) {
  struct sg_cell *p = *grid;

  while (p) {
    if (p->hash > hash)
      p = p->left;
    else if (p->hash < hash)
      p = p->right;
    else
      break;
  }
  return p;
}

uint64_t sg_hash(int x, int y) {
  uint64_t h = x << 24 | y;
  h ^= h >> 33;
  h *= 0xff51afd7ed558ccdULL;
  h ^= h >> 33;
  return h;
}

struct sg_cell *sg_cell_at(struct sg_cell **grid, int x, int y) {
  return find_cell(grid, SG_HASH(x, y));
}

struct sg_cell *sg_pick_cell(struct sg_cell **grid, double x,
                             double y) {
  // Все ячейки размером 2**N => рассчет индекса ячейки можно сделать бинрным
  // сдвигом на N
  int cx0 = ((int)floor(x)) >> SG_CELL_SHIFT;
  int cy0 = ((int)floor(y)) >> SG_CELL_SHIFT;

  return find_cell(grid, SG_HASH(cx0, cy0));
}

void sg_cleanup(struct sg_cell **grid) {
  if (!grid || !*grid)
    return;

  sg_cleanup(&(*grid)->left);
  sg_cleanup(&(*grid)->right);

  free((*grid)->ent);
  free(*grid);

  *grid = NULL;
}