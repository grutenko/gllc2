#ifndef tess_h
#define tess_h

#include "draw.h"
#include "entity_vertex.h"

int tess(struct ev *pts, int cnt, struct ds_vertex *ver, GLuint *indx, int *vercnt, int *indcnt);

#endif