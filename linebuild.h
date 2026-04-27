#ifndef linebuild_h
#define linebuild_h

#include "entity_vertex.h"
#include "glad.h"

struct ds_vertex;

#define LB_MODE_COMPLEX 0
#define LB_MODE_MITER 1
#define LB_MODE_BEVEL 2
#define LB_MODE_ROUND 3
#define LB_ROUND_SEGMENTS 8

struct lb_config {
  int mode;
  double lw;
  double lrealw;
  unsigned char *c;
  struct ev *v;
  int vcnt;
  int closed;
  int nroundsegs;
  int off;
};

void lb_build(struct lb_config *conf, struct ds_vertex *V, GLuint *I, int *Vcnt, int *Icnt);

#endif