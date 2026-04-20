#ifndef filling_h
#define filling_h

#include "drawing.h"
#include "named_object.h"

struct gllc_filling_line;

struct gllc_filling {
  struct gllc_nobject _nobj;
  struct gllc_filling_line *lines;
  int lines_cnt;
};

struct gllc_filling *gllc_filling_create(struct gllc_drawing *drawing);
int gllc_filline_add_line(struct gllc_filling *filling, int iline, double dist, double angle, double w);

#endif