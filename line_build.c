#include "line_build.h"
#include "draw.h"
#include "glad.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define PI 3.14159265358979323f
#define PI2 1.5707963705062866f

void lb_stats(struct lb *lb) {
  if (lb->in.closed) {
    lb->out.ver_cnt = lb->in.ver_cnt * 4;
    lb->out.ind_cnt = lb->in.ver_cnt * 18;
  } else {
    lb->out.ver_cnt = lb->in.ver_cnt * 4 - 4;
    lb->out.ind_cnt = lb->in.ver_cnt * 18 - 30;
  }
}

static inline void _putver(struct ds_vertex *o, int i, uint8_t *c, double *p, double *n, GLushort th) {
  o[i].p[0] = p[0];
  o[i].p[1] = p[1];
  o[i].n[0] = (GLbyte)(n[0] * 127.0f);
  o[i].n[1] = (GLbyte)(n[1] * 127.0f);
  o[i].c[0] = c[0];
  o[i].c[1] = c[1];
  o[i].c[2] = c[2];
  o[i].c[3] = c[3];
  o[i].uv[0] = 0;
  o[i].uv[1] = 0;
  o[i].thickness = th;
}

static inline void _norm(double *p) {
  double v = sqrt(p[0] * p[0] + p[1] * p[1]);
  p[0] = p[0] / v;
  p[1] = p[1] / v;
}

static inline void _normto(double *p, double *n) {
  double v = sqrt(p[0] * p[0] + p[1] * p[1]);
  n[0] = p[0] / v;
  n[1] = p[1] / v;
}

static inline void _bisec(double *p0, double *p1, double *p2, double *n) {
  double _d2[2];
  _d2[0] = (p1[0] - p0[0]) + (p1[0] - p2[0]);
  _d2[1] = (p1[1] - p0[1]) + (p1[1] - p2[1]);
  _normto(_d2, n);
}

static inline void _perp(double *p0, double *n) {
  double t = p0[0];
  n[0] = -p0[1];
  n[1] = t;
  _norm(n);
}

static inline double _angle(double *p0, double *p1) {
  return acos(p0[0] * p1[0] + p0[1] * p1[1]) / (sqrt(p0[0] * p0[0] + p0[1] * p0[1]) * sqrt(p1[0] * p1[0] + p1[1] * p1[1]));
}

static inline void _inv(double *n) {
  n[0] = -n[0];
  n[1] = -n[1];
}

void lb_build(struct lb *lb) {
  double p0[2], p1[2], p2[2], n0[2], n1[2], n2[2];
  double _d0[2], _d1[2];
  double *v = lb->in.ver;
  struct ds_vertex *vout = lb->out.ver_ptr;
  size_t vc = lb->in.ver_cnt;
  int i, ni;
  GLuint vi = 0, ii = 0;

  if (vc <= 1) return;

  if (lb->in.closed) {
    if (vc <= 2) return;
    p0[0] = v[vc * 2 - 2];
    p0[1] = v[vc * 2 - 1];
    p1[0] = v[0];
    p1[1] = v[1];
    for (i = 0; i < vc; i++) {
      ni = i < vc - 1 ? i + 1 : 0;
      p2[0] = v[ni * 2];
      p2[1] = v[ni * 2 + 1];
      _d0[0] = p1[0] - p0[0];
      _d0[1] = p1[0] - p0[1];
      _d1[0] = p2[0] - p1[0];
      _d1[1] = p2[0] - p1[1];
      _bisec(p0, p1, p2, n0);
      _perp(_d0, n1);
      _perp(_d1, n2);
      if (_angle(n0, n1) > PI2)
        _inv(n1);
      if (_angle(n0, n2) > PI2)
        _inv(n2);
      // n1, n2 - векторы направления для создания фаски
      uint8_t c[4];
      c[0] = (uint8_t)(lb->in.color[0] * 255);
      c[1] = (uint8_t)(lb->in.color[1] * 255);
      c[2] = (uint8_t)(lb->in.color[2] * 255);
      c[3] = (uint8_t)(lb->in.color[3] * 255);
      _putver(vout, vi, c, )
      p0[0] = p1[0];
      p0[1] = p1[1];
      p1[0] = p2[0];
      p1[1] = p2[1];
    }
  }
}