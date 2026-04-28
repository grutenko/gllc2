#include "linebuild.h"
#include "draw.h"
#include "linalg.h"

#include <math.h>
#include <stdio.h>

static inline void ver(struct ds_vertex *v, double *p, double *n, unsigned char *c, double th, double l) {
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
  v->l = (GLfloat)l;
}

static inline void ver_extr(struct ds_vertex *v, double *p0, double *n0, double w, unsigned char *c, double th, double l) {
  double pt[2];
  ADDSCALETO(p0, n0, w, pt);
  ver(v, pt, n0, c, th, l);
}

// строит сегмент круга с центром в p0, радиусом R, центральным вектором n, углом A, и добавляет вершины в массив V и индексы в массив I, начиная с vi и ii соответственно
// увеличивает vi и ii на количество добавленных вершин и индексов соответственно
static inline void arc(int cnt, double *p0, double *n, double R, double A, unsigned char *c, double th, struct ds_vertex *V, GLuint *I, int *vi, int *ii) {
  double angle_step = A / (double)cnt;
  double angle = -A / 2.0f;
  double cos_a = cos(-A / 2.0f);
  double sin_a = sin(-A / 2.0f);
  double n0[2];
  // выставляем начальный вектор на парралельно стороне дуги
  n0[0] = n[0] * cos_a - n[1] * sin_a;
  n0[1] = n[0] * sin_a + n[1] * cos_a;
  ver(&V[0], p0, (double[]){0.0f, 0.0f}, c, th, 0.0f);
  int vi0 = *vi, ii0 = *ii;
  (*vi)++;
  for (int i = 0; i <= cnt; i++) {
    double x = p0[0] + n0[0] * R;
    double y = p0[1] + n0[1] * R;
    double p[2] = {x, y};
    ver(&V[(*vi) - vi0], p, n0, c, th, 0.0f);
    if (i < cnt) {
      I[(*ii) - ii0] = vi0;
      I[(*ii) - ii0 + 1] = *vi;
      I[(*ii) - ii0 + 2] = (*vi) + 1;
      (*ii) += 3;
    }
    (*vi)++;
    // поворачиваем вектор к следующей вершине дуги
    angle += angle_step;
    cos_a = cos(angle);
    sin_a = sin(angle);
    n0[0] = n[0] * cos_a - n[1] * sin_a;
    n0[1] = n[0] * sin_a + n[1] * cos_a;
  }
}

static inline void arc_stats(int cnt, int *vi, int *ii) {
  (*vi) += 2 + cnt;
  (*ii) += 3 * cnt;
}

static inline double cosseg(double *p0, double *p1, double *p2) {
  double v0[2];
  double v1[2];
  VEC(v0, p0, p1);
  VEC(v1, p2, p1);
  NORM(v0);
  NORM(v1);
  return DOT(v0, v1);
}

static inline void perp_seg(double *n0, double *p0, double *p1) {
  VEC(n0, p0, p1);
  NORM(n0);
  PERP(n0);
}

static inline void bisec_seg(double *n0, double *p0, double *p1, double *p2) {
  double v0[2], v1[2];
  if (cosseg(p0, p1, p2) <= -0.99999999f) {
    perp_seg(n0, p0, p2);
    return;
  }
  VEC(v0, p0, p1);
  VEC(v1, p2, p1);
  NORM(v0);
  NORM(v1);
  ADD(n0, v0, v1);
  NORM(n0);
}

static inline int bisec_inv(double *n0, double *n1, double *n2) {
  return CROSS(n2, n0) * CROSS(n2, n1) < 0;
}

static inline double len_seg(double *p0, double *p1) {
  double v0[2];
  VEC(v0, p0, p1);
  return LEN(v0);
}

#define unlikely(x) __builtin_expect(!!(x), 0)

void lb_build(struct lb_config *conf, struct ds_vertex *V, GLuint *I, int *Vcnt, int *Icnt) {
  int vi = 0;
  int ii = 0;
  int closed = conf->closed;
  struct ev *vin = conf->v;
  int vcntin = conf->vcnt;
  if (conf->vcnt < 2)
    goto _end;
  if (closed && conf->vcnt == 2)
    closed = 0;
  if (conf->vcnt == 2 && len_seg(vin[0].p, vin[1].p) < 1e-8)
    goto _end;
  if (closed) {
  } else {
    double len = 0.0f;
    double nf[2], nl[2];
    perp_seg(nf, vin[0].p, vin[1].p);
    perp_seg(nl, vin[vcntin - 2].p, vin[vcntin - 1].p);
    for (int i = 0; i < vcntin; i++) {
      int bevel = 0;
      double cosp1 = -1.0f; // cos(180) - по умолчанию дает 1.0f для miter
      double n0[2], n1[2], n2[2];
      VEC(n2, vin[i].p, vin[i + 1].p);
      NORM(n2);
      if (i == 0) {
        n0[0] = nf[0];
        n0[1] = nf[1];
      } else if (i >= vcntin - 1) {
        n0[0] = nl[0];
        n0[1] = nl[1];
      } else {
        if (vcntin > 2) {
          cosp1 = cosseg(vin[i - 1].p, vin[i].p, vin[i + 1].p);
        }
        bisec_seg(n0, vin[i - 1].p, vin[i].p, vin[i + 1].p);
      }
      if (i > 0) {
        double tlen = len_seg(vin[i - 1].p, vin[i].p);
        len += tlen;
      }
      if (i >= vcntin - 2) {
        n1[0] = nl[0];
        n1[1] = nl[1];
      } else {
        bisec_seg(n1, vin[i].p, vin[i + 1].p, vin[i + 2].p);
      }
      if (cosp1 <= 0.866f) {
        if (V) {
          int off = conf->off;
          double miter = 1.0 / sqrt((1.0f - cosp1) / 2.0f);
          double w = conf->lrealw / 2.0f * miter;
          double th = conf->lw / 2.0f * miter;
          double nt[2];
          INVTO(n0, nt);
          if (n0[0] == 0.0f && n0[1] == 0.0f)
            printf("x0 = %lf, y0 = %lf, i = %d, p0[0] = %lf, p0[1] = %lf, p1[0] = %lf, p1[1] = %lf\n", n0[0], n0[1], i, vin[i - 1].p[0], vin[i - 1].p[1], vin[i].p[0], vin[i].p[1]);
          ver_extr(&V[vi], vin[i].p, nt, w, conf->c, th, len);
          ver_extr(&V[vi + 1], vin[i].p, n0, w, conf->c, th, len);
          if (i < vcntin - 1) {
            if (bisec_inv(n0, n1, n2)) {
              I[ii] = off + vi;
              I[ii + 1] = off + vi + 1;
              I[ii + 2] = off + vi + 2;
              I[ii + 3] = off + vi;
              I[ii + 4] = off + vi + 2;
              I[ii + 5] = off + vi + 3;
            } else {
              I[ii] = off + vi;
              I[ii + 1] = off + vi + 1;
              I[ii + 2] = off + vi + 2;
              I[ii + 3] = off + vi + 1;
              I[ii + 4] = off + vi + 2;
              I[ii + 5] = off + vi + 3;
            }
          }
        }
        vi += 2;
        if (i < vcntin - 1) {
          ii += 6;
        }
      } else {
        if (V) {
          if (bisec_inv(n0, n1, n2)) {

          } else {
          }
        }
        vi += 3;
        if (i < vcntin - 1) {
          ii += 9;
        }
      }
    }
    if (conf->lrealw > 0.0001f || conf->lw > 3.0f) {
      int segcnt = conf->nroundsegs;
      if (V) {
        double w = conf->lrealw / 2.0f;
        double th = conf->lw / 2.0f;
        double nt0[2], nt1[2];
        VEC(nt0, vin[1].p, vin[0].p);
        VEC(nt1, vin[vcntin - 2].p, vin[vcntin - 1].p);
        NORM(nt0);
        NORM(nt1);
        arc(segcnt, vin[0].p, nt0, w, M_PI, conf->c, th, &V[vi], &I[ii], &vi, &ii);
        arc(segcnt, vin[vcntin - 1].p, nt1, w, M_PI, conf->c, th, &V[vi], &I[ii], &vi, &ii);
      } else {
        arc_stats(segcnt, &vi, &ii);
        arc_stats(segcnt, &vi, &ii);
      }
    }
  }

_end:
  *Vcnt = vi;
  *Icnt = ii;
}