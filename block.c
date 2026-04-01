#include "block.h"
#include "entity.h"
#include "polyline.h"

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
    struct gllc_entity *ent = block->cmn_batch.ent_head;
    printf("Updating entity: %p\n", ent);
    while (ent) {
      if (ent->flags & GLLC_ENT_MODIFIED) {
        ent->vtable->build(ent, &block->cmn_batch.draw, block->scale);
        ent->flags &= ~GLLC_ENT_MODIFIED;
      }
      ent = ent->next;
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