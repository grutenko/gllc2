#ifndef line_tess_h
#define line_tess_h

#include "entity_vertex.h"
#include "glad.h"

struct ds_vertex;

#define LB_MODE_COMPLEX 0
#define LB_MODE_MITER 1
#define LB_MODE_BEVEL 2
#define LB_MODE_ROUND 3

struct lb_config {
  int mode;
  double lw;
  double lrealw;
  unsigned char c[4];
  struct ev *v;
  int vcnt;
};

void lb_stat(struct lb_config *conf, int *vcnt, int *icnt);
void lb_build(struct lb_config *conf, struct ds_vertex *v, int *vcnt, GLuint *i, int *icnt);

#endif