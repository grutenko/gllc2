#include "drawing.h"
#include "block.h"

#include <stdlib.h>
#include <string.h>

struct gllc_drawing *gllc_drw_create() {
  struct gllc_drawing *d = malloc(sizeof(struct gllc_drawing));
  if (d) {
    memset(d, 0, sizeof(struct gllc_drawing));
  }
  return d;
}

static void push_block(struct gllc_drawing *drawing, struct gllc_block *block) {
  block->prev = drawing->block_tail;
  block->next = NULL;
  if (drawing->block_tail)
    drawing->block_tail->next = block;
  else
    drawing->block_head = block;
  drawing->block_tail = block;
  drawing->block_cnt++;
}

struct gllc_block *gllc_drw_add_block(struct gllc_drawing *drawing,
                                      const char *name, double dx, double dy) {
  struct gllc_block *block = gllc_block_create(drawing, name, dx, dy);
  if (block) {
    push_block(drawing, block);
  }
  return block;
}

void gllc_drawing_destroy(struct gllc_drawing *drawing) {
  struct gllc_block *block = drawing->block_head;
  while (block) {
    struct gllc_block *next = block->next;
    gllc_block_destroy(block);
    block = next;
  }
  free(drawing);
}