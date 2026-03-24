#ifndef drawing_h
#define drawing_h

#include "object.h"

struct gllc_block;

struct gllc_drawing {
  struct gllc_object _obj;
  struct gllc_block *block_head;
  struct gllc_block *block_tail;
  int block_cnt;
};

struct gllc_drawing *gllc_drawing_create();
struct gllc_block *gllc_drawing_add_block(struct gllc_drawing *drawing, const char *name, double dx, double dy);
void gllc_drawing_destroy(struct gllc_drawing *drawing);

#endif