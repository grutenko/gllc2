#include "line_build.h"
#include "cglm/include/cglm/vec2.h"
#include "draw.h"
#include "glad.h"

#include <math.h>

void lb_stats(struct lb *lb) {
  if (lb->in.closed) {
    lb->out.ver_cnt = lb->in.ver_cnt * 4;
    lb->out.ind_cnt = lb->in.ver_cnt * 18;
  } else {
    lb->out.ver_cnt = lb->in.ver_cnt * 4 - 4;
    lb->out.ind_cnt = lb->in.ver_cnt * 18 - 30;
  }
}

static inline void set_ver(struct ds_vertex *out, int idx, unsigned char color[4], vec2 p, vec2 n) {
  out[idx].p[0] = p[0];
  out[idx].p[1] = p[1];
  out[idx].n[0] = (GLbyte)(n[0] * 127.0f);
  out[idx].n[1] = (GLbyte)(n[1] * 127.0f);
  out[idx].c[0] = color[0];
  out[idx].c[1] = color[1];
  out[idx].c[2] = color[2];
  out[idx].c[3] = color[3];
  out[idx].uv[0] = 0;
  out[idx].uv[1] = 0;
  out[idx].thickness = 1;
}

static void build_miter_open(struct lb *lb) {}

static void build_bevel_open(struct lb *lb) {}

static void build_miter_closed(struct lb *lb) {}

static void build_bevel_closed(struct lb *lb) {}

void lb_build(struct lb *lb) {
  if (lb->in.flags & LB_MITER) {
    if (lb->in.closed) {
      build_miter_closed(lb);
    } else {
      build_miter_open(lb);
    }
  } else if (lb->in.flags & LB_BEVEL) { 
    if (lb->in.closed) {
      build_bevel_closed(lb);
    } else {
      build_bevel_open(lb);
    }
  }
}