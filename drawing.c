#include "drawing.h"
#include "block.h"
#include "named_object.h"

#include <stdlib.h>
#include <string.h>

struct gllc_drawing *gllc_drw_create() {
  struct gllc_drawing *d = malloc(sizeof(struct gllc_drawing));
  if (d) {
    memset(d, 0, sizeof(struct gllc_drawing));
  }
  return d;
}

static void push_obj(struct gllc_drawing *drawing, struct gllc_nobject *obj) {
  obj->prev = drawing->ot;
  obj->next = NULL;
  if (drawing->ot)
    drawing->ot->next = obj;
  else
    drawing->oh = obj;
  drawing->ot = obj;
  drawing->ocnt++;
}

struct gllc_block *gllc_drw_add_block(struct gllc_drawing *drawing,
                                      const char *name, double dx, double dy) {
  struct gllc_block *block = gllc_block_create(drawing, name, dx, dy);
  if (block) {
    push_obj(drawing, (struct gllc_nobject *)block);
  }
  return block;
}

void gllc_drawing_destroy(struct gllc_drawing *drawing) {
  struct gllc_nobject *nobj = drawing->oh;
  while (nobj) {
    struct gllc_nobject *next = nobj->next;
    gllc_nobject_destroy(nobj);
    nobj = next;
  }
  free(drawing);
}