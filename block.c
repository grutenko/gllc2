#include "block.h"
#include "entity.h"
#include "polyline.h"
#include "sparse_grid.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct gllc_block *gllc_block_create(struct gllc_drawing *drawing, const char *name, double dx, double dy) {
  struct gllc_block *block = malloc(sizeof(struct gllc_block));
  if (block) {
    memset(block, 0, sizeof(struct gllc_block));
    block->drawing = drawing;
    block->dx = dx;
    block->dy = dy;
    block->cmn_batch.cnt = 0;
    block->props.color = -1;
    block->props.fcolor = -1;
    strncpy(block->name, name, sizeof(block->name) - 1);
    block->name[sizeof(block->name) - 1] = '\0';
  }
  return block;
}

void gllc_block_update(struct gllc_block *block) {
  if (block) {
    double bbox_x0, bbox_y0, bbox_x1, bbox_y1;
    struct gllc_entity *ent = block->cmn_batch.ent_head;
    for (ent = block->cmn_batch.ent_head; ent; ent = ent->next) {
      if (!(ent->flags & GLLC_ENT_MODIFIED))
        continue;
      ent->vtable->build(ent, &block->cmn_batch.draw, block->scale);
      if (ent->flags & GLLC_ENT_GEOMETRY_MODIFIED) {
        ent->vtable->bbox(ent, 1.0f, &bbox_x0, &bbox_y0, &bbox_x1, &bbox_y1);
        if (!(ent->flags & GLLC_ENT_INITIAL)) {
          sg_remove(&block->cmn_batch.grid, ent);
        }
        sg_push(&block->cmn_batch.grid, ent, bbox_x0, bbox_y0, bbox_x1, bbox_y1);
        ent->flags &= ~GLLC_ENT_INITIAL;
      }
      ent->flags &= ~(GLLC_ENT_MODIFIED | GLLC_ENT_GEOMETRY_MODIFIED);
    }
  }
}

void gllc_block_destroy(struct gllc_block *block) {
  if (block) {
    // Free entities in the block
    struct gllc_entity *ent = block->cmn_batch.ent_head;
    while (ent) {
      struct gllc_entity *next = ent->next;
      gllc_entity_destroy(ent);
      ent = next;
    }
    sg_cleanup(&block->cmn_batch.grid);
    ds_draw_clear(&block->cmn_batch.draw);
    free(block);
  }
}

static void push_ent(struct gllc_block *block, struct gllc_entity *ent) {
  if (block->cmn_batch.ent_tail) {
    block->cmn_batch.ent_tail->next = ent;
    ent->prev = block->cmn_batch.ent_tail;
    block->cmn_batch.ent_tail = ent;
  } else {
    block->cmn_batch.ent_head = ent;
    block->cmn_batch.ent_tail = ent;
  }
  block->cmn_batch.cnt++;
}

struct gllc_polyline *gllc_block_add_polyline(struct gllc_block *block, int closed, int filled) {
  struct gllc_polyline *pline = gllc_polyline_create(block, closed, filled);
  if (pline) {
    push_ent(block, (struct gllc_entity *)pline);
  }
  return pline;
}

struct gllc_entity *gllc_block_pick_ent(struct gllc_block *block, double x, double y) {
  struct gllc_entity *ent = NULL;
  struct sg_cell *cell = sg_pick_cell(&block->cmn_batch.grid, x, y);
  if (!cell)
    return NULL;

  int i;
  for (i = 0; i < cell->ent_size; i++) {
    if (cell->ent[i]->vtable->picked(cell->ent[i], block->scale, x, y))
      return cell->ent[i];
  }

  return NULL;
}

void gllc_block_hover(struct gllc_block *block, struct gllc_entity *ent) {
  if (block->hovered) {
    if (block->hovered == ent)
      return;

    block->hovered->flags &= ~GLLC_ENT_HOVER;
    block->hovered->flags |= GLLC_ENT_MODIFIED;
    block->hovered = NULL;
  }
  if (ent) {
    ent->flags |= GLLC_ENT_HOVER | GLLC_ENT_MODIFIED;
    block->hovered = ent;
  }
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

void gllc_block_hover_multi_by_bbox(struct gllc_block *block, double x0, double y0, double x1, double y1) {
  double bbox1_x0, bbox1_y0, bbox1_x1, bbox1_y1;

  gllc_block_unhover_all(block);

  int cx0 = ((int)floor(x0)) >> SG_CELL_SHIFT;
  int cy0 = ((int)floor(y0)) >> SG_CELL_SHIFT;
  int cx1 = ((int)floor(x1)) >> SG_CELL_SHIFT;
  int cy1 = ((int)floor(y1)) >> SG_CELL_SHIFT;
  int x, y, i, ok;

  if (cx0 > cx1)
    _swap(&cx0, &cx1);
  if (cy0 > cy1)
    _swap(&cy0, &cy1);
  if (x0 > x1)
    _swapf(&x0, &x1);
  if (y0 > y1)
    _swapf(&y0, &y1);

  int cnt = 0;

  // Проходимся по всем ячейкам входящим в bbox и выбираем все элементы для
  // строгой проверки
  for (x = cx0; x <= cx1; x++) {
    for (y = cy0; y <= cy1; y++) {
      cnt++;
      struct sg_cell *cell = sg_cell_at(&block->cmn_batch.grid, x, y);
      if (!cell)
        continue;
      if (cell->ent_size == 0)
        continue;

      for (i = 0; i < cell->ent_size; i++) {
        // В ячейке элементы находятся в соответствии со своим order
        // Но при выделении могут быть области ниже в порядке отрисовки но
        // выходят за пределы bbox такие тоже выделяем Вобще это работает
        // немного неправильно: Мы выделяем все элемены в BBOX независимо от
        // уровня. возможно стоит искать выходы примитива Но это довольно сложно
        // и долго, так что не факт что нужно.

        if (cell->ent[i]->flags & GLLC_ENT_HOVER)
          continue;

        // Bbox Учитывает scale_factor. Объекты в экранных координатах правильно
        // рассчитывают свой Bbox исходя из текущего scale_factor
        if (!cell->ent[i]->vtable->bbox(cell->ent[i], block->scale, &bbox1_x0, &bbox1_y0, &bbox1_x1, &bbox1_y1))
          continue;

        if (bbox1_x0 > bbox1_x1)
          _swapf(&bbox1_x0, &bbox1_x1);
        if (bbox1_y0 > bbox1_y1)
          _swapf(&bbox1_y0, &bbox1_y1);

        // Для select by bbox достаточно просто проверить вхождение в Bbox
        // обьекта.
        if (x1 <= bbox1_x0 || x0 >= bbox1_x1 ||
            y1 <= bbox1_y0 || y0 >= bbox1_y1)
          continue;

        cell->ent[i]->flags |= GLLC_ENT_HOVER | GLLC_ENT_MODIFIED;
      }
    }
  }

  printf("cnt = %d\n", cnt);
}

void gllc_block_unhover_all(struct gllc_block *block) {
  if (block->hovered) {
    block->hovered->flags &= ~GLLC_ENT_HOVER;
    block->hovered->flags |= GLLC_ENT_MODIFIED;
    block->hovered = NULL;
  }
  struct gllc_entity *ent;
  for (ent = block->cmn_batch.ent_head; ent; ent = ent->next) {
    if (ent->flags & GLLC_ENT_HOVER) {
      ent->flags &= ~GLLC_ENT_HOVER;
      ent->flags |= GLLC_ENT_MODIFIED;
    }
  }
}