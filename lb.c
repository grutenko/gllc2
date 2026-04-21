#include "lb.h"
#include "draw.h"

#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846

static inline double LEN(const double v[2]) {
  return sqrt(v[0] * v[0] + v[1] * v[1]);
}

static inline double MIN(double a, double b) {
  return a < b ? a : b;
}

static inline double MAX(double a, double b) {
  return a > b ? a : b;
}

static inline void VEC(double out[2], const double a[2], const double b[2]) {
  out[0] = b[0] - a[0];
  out[1] = b[1] - a[1];
}

static inline void NORM(double v[2]) {
  double l = LEN(v);
  if (l > 0.0) {
    v[0] /= l;
    v[1] /= l;
  }
}

static inline void PERP(double v[2]) {
  double t = v[0];
  v[0] = -v[1];
  v[1] = t;
}

static inline void INV(double v[2]) {
  v[0] = -v[0];
  v[1] = -v[1];
}

static inline double DOT(const double a[2], const double b[2]) {
  return a[0] * b[0] + a[1] * b[1];
}

static inline double CROSS(const double a[2], const double b[2]) {
  return a[0] * b[1] - a[1] * b[0];
}

static inline void VER(struct ds_vertex *v, double *p, double *n, unsigned char *c, double th, double w) {
  v->p[0] = (GLfloat)p[0];
  v->p[1] = (GLfloat)p[1];
  v->n[0] = (GLbyte)(n[0] * 127.0f);
  v->n[1] = (GLbyte)(n[1] * 127.0f);
  v->c[0] = (GLubyte)c[0];
  v->c[1] = (GLubyte)c[1];
  v->c[2] = (GLubyte)c[2];
  v->c[3] = (GLubyte)c[3];
  v->uv[0] = (GLfloat)0.0f;
  v->uv[1] = (GLfloat)0.0f;
  v->th = (GLfloat)th;
}

// строит сегмент круга с центром в p0, радиусом R, центральным вектором n, углом A, и добавляет вершины в массив V и индексы в массив I, начиная с vi и ii соответственно
// увеличивает vi и ii на количество добавленных вершин и индексов соответственно
static inline void ROUND(int cnt, double *p0, double *n, double R, double A, unsigned char *c, double th, struct ds_vertex *V, GLuint *I, int *vi, int *ii) {
  double angle_step = A / (double)cnt;
  double angle = -A / 2.0f;
  double cos_a = cos(-A / 2.0f);
  double sin_a = sin(-A / 2.0f);
  double n0[2];
  // выставляем начальный вектор на парралельно стороне дуги
  n0[0] = n[0] * cos_a - n[1] * sin_a;
  n0[1] = n[0] * sin_a + n[1] * cos_a;
  if (V) {
    VER(&V[0], p0, (double[]){0.0f, 0.0f}, c, th / 2.0f, 0.0f);
  }
  int vi0 = *vi, ii0 = *ii;
  (*vi)++;
  for (int i = 0; i <= cnt; i++) {
    double x = p0[0] + n0[0] * R;
    double y = p0[1] + n0[1] * R;
    if (V) {
      double p[2] = {x, y};
      VER(&V[(*vi) - vi0], p, n0, c, th / 2.0f, 0.0f);
    }
    if (i < cnt) {
      if (I) {
        I[(*ii) - ii0] = vi0;
        I[(*ii) - ii0 + 1] = *vi;
        I[(*ii) - ii0 + 2] = (*vi) + 1;
      }
      (*ii) += 3;
    }
    (*vi)++;
    // поворачиваем ветор к следующей вершине дуги
    angle += angle_step;
    cos_a = cos(angle);
    sin_a = sin(angle);
    n0[0] = n[0] * cos_a - n[1] * sin_a;
    n0[1] = n[0] * sin_a + n[1] * cos_a;
  }
}

void lb_build(struct lb_config *conf, struct ds_vertex *V, GLuint *I, int *Vcnt, int *Icnt) {
  double p0[2], p1[2], p2[2], p3[2];
  double v0[2], v1[2], v2[2];
  double n0[2], n1[2];
  struct ev *_v = conf->v;
  int _vcnt = conf->vcnt;
  int vi = 0;
  int ii = 0;
  if (conf->vcnt <= 1) {
    return;
  } else if (conf->vcnt == 2) {
    double lw = conf->lrealw / 2.0f;
    p0[0] = _v[0].p[0];
    p0[1] = _v[0].p[1];
    p1[0] = _v[1].p[0];
    p1[1] = _v[1].p[1];
    v0[0] = p1[0] - p0[0];
    v0[1] = p1[1] - p0[1];
    if (LEN(v0) == 0.0f) {
      return;
    }
    n0[0] = p1[0] - p0[0];
    n0[1] = p1[1] - p0[1];
    NORM(n0);
    PERP(n0);
    n1[0] = -n0[0];
    n1[1] = -n0[1];
    if (V) {
      double pt[2];
      pt[0] = p0[0] + n0[0] * lw;
      pt[1] = p0[1] + n0[1] * lw;
      VER(&V[0], pt, n0, conf->c, conf->lw / 2.0f, conf->lrealw);
      pt[0] = p0[0] + n1[0] * lw;
      pt[1] = p0[1] + n1[1] * lw;
      VER(&V[1], pt, n1, conf->c, conf->lw / 2.0f, conf->lrealw);
      pt[0] = p1[0] + n0[0] * lw;
      pt[1] = p1[1] + n0[1] * lw;
      VER(&V[2], pt, n0, conf->c, conf->lw / 2.0f, conf->lrealw);
      pt[0] = p1[0] + n1[0] * lw;
      pt[1] = p1[1] + n1[1] * lw;
      VER(&V[3], pt, n1, conf->c, conf->lw / 2.0f, conf->lrealw);
      I[0] = conf->off + 0;
      I[1] = conf->off + 1;
      I[2] = conf->off + 2;
      I[3] = conf->off + 1;
      I[4] = conf->off + 2;
      I[5] = conf->off + 3;
    }
    vi = 4;
    ii = 6;
    if (conf->mode == LB_MODE_ROUND) {
      double w = conf->lrealw / 2.0f;
      struct ds_vertex *v0;
      double pt[2];
      GLuint *i0;
      n0[0] = p0[0] - p1[0];
      n0[1] = p0[1] - p1[1];
      NORM(n0);
      pt[0] = _v[0].p[0];
      pt[1] = _v[0].p[1];
      if (V) {
        v0 = &V[vi];
        i0 = &I[ii];
      } else {
        v0 = NULL;
        i0 = NULL;
      }
      ROUND(conf->nroundsegs, pt, n0, w, M_PI, conf->c, conf->lw, v0, i0, &vi, &ii);
      n0[0] = p1[0] - p0[0];
      n0[1] = p1[1] - p0[1];
      NORM(n0);
      pt[0] = _v[1].p[0];
      pt[1] = _v[1].p[1];
      if (V) {
        v0 = &V[vi];
        i0 = &I[ii];
      } else {
        v0 = NULL;
        i0 = NULL;
      }
      ROUND(conf->nroundsegs, pt, n0, w, M_PI, conf->c, conf->lw, v0, i0, &vi, &ii);
    }
  } else {
    if (conf->closed) {
      p0[0] = _v[_vcnt - 1].p[0];
      p0[1] = _v[_vcnt - 1].p[1];
      p1[0] = _v[0].p[0];
      p1[1] = _v[0].p[1];
      p2[0] = _v[1].p[0];
      p2[1] = _v[1].p[1];
      p3[0] = _v[2].p[0];
      p3[1] = _v[2].p[1];
    } else {
    }
  }
  *Vcnt = vi;
  *Icnt = ii;
}