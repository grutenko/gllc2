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

static inline void ADD(double *p, double *p0, double *p1) {
  p[0] = p0[0] + p1[0];
  p[1] = p0[1] + p1[1];
}

// строит сегмент круга с центром в p0, радиусом R, центральным вектором n, углом A, и добавляет вершины в массив V и индексы в массив I, начиная с vi и ii соответственно
// увеличивает vi и ii на количество добавленных вершин и индексов соответственно
static inline void ROUND(int cnt, double *p0, double *n, double R, double A, unsigned char *c, double th, struct ds_vertex *V, GLuint *I, int *vi, int *ii) {
  if (!V || !I) {
    (*vi) += 2 + cnt;
    (*ii) += 3 * cnt;
    return;
  }
  double angle_step = A / (double)cnt;
  double angle = -A / 2.0f;
  double cos_a = cos(-A / 2.0f);
  double sin_a = sin(-A / 2.0f);
  double n0[2];
  // выставляем начальный вектор на парралельно стороне дуги
  n0[0] = n[0] * cos_a - n[1] * sin_a;
  n0[1] = n[0] * sin_a + n[1] * cos_a;
  VER(&V[0], p0, (double[]){0.0f, 0.0f}, c, th / 2.0f, 0.0f);
  int vi0 = *vi, ii0 = *ii;
  (*vi)++;
  for (int i = 0; i <= cnt; i++) {
    double x = p0[0] + n0[0] * R;
    double y = p0[1] + n0[1] * R;
    double p[2] = {x, y};
    VER(&V[(*vi) - vi0], p, n0, c, th / 2.0f, 0.0f);
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

static inline void ROUNDSTATS(int cnt, int *vi, int *ii) {
  (*vi) += 2 + cnt;
  (*ii) += 3 * cnt;
}

static inline int seg_insect(double *p0, double *n0, double *p1, double *n1, double *pT, double *pS) {
  double D, Dt, Ds, d[2];
  d[0] = p1[0] - p0[0];
  d[1] = p1[0] - p0[1];
  D = -n0[0] * n1[1] + n0[1] * n1[0];
  if (D < 1e-8)
    return 0;
  Dt = -n1[1] * d[0] + n1[0] * d[1];
  Ds = n0[0] * d[1] - n0[1] * d[0];
  *pT = Dt / D;
  *pS = Ds / D;
  return 1;
}

void lb_build(struct lb_config *conf, struct ds_vertex *V, GLuint *I, int *Vcnt, int *Icnt) {
  struct ev *_v = conf->v;
  int _vcnt = conf->vcnt;
  double w = conf->lrealw / 2.0f;
  double sw = conf->lw / 2.0f;
  int vi = 0;
  int ii = 0;
  int off = conf->off;
  if (_vcnt <= 1) {
    return;
  } else if (_vcnt == 2) {
    double p0[2], p1[2];
    double lw = conf->lrealw / 2.0f;
    double v0[2];
    double n0[2], n1[2];
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
      double pt[2];
      n0[0] = p0[0] - p1[0];
      n0[1] = p0[1] - p1[1];
      NORM(n0);
      pt[0] = _v[0].p[0];
      pt[1] = _v[0].p[1];
      if (V) {
        ROUND(conf->nroundsegs, pt, n0, w, M_PI, conf->c, conf->lw, &V[vi], &I[ii], &vi, &ii);
      } else {
        ROUNDSTATS(conf->nroundsegs, &vi, &ii);
      }
      n0[0] = p1[0] - p0[0];
      n0[1] = p1[1] - p0[1];
      NORM(n0);
      pt[0] = _v[1].p[0];
      pt[1] = _v[1].p[1];
      if (V) {
        ROUND(conf->nroundsegs, pt, n0, w, M_PI, conf->c, conf->lw, &V[vi], &I[ii], &vi, &ii);
      } else {
        ROUNDSTATS(conf->nroundsegs, &vi, &ii);
      }
    }
  } else {
    if (conf->closed) {
      int mode = conf->mode;
      double p0[2], p1[2], p2[2], p3[2];
      double v0[2], v1[2];
      double n0[2], n1[2], n2[2];
      p0[0] = _v[_vcnt - 1].p[0];
      p0[1] = _v[_vcnt - 1].p[1];
      p1[0] = _v[0].p[0];
      p1[1] = _v[0].p[1];
      p2[0] = _v[1].p[0];
      p2[1] = _v[1].p[1];
      for (int i = 0; i < _vcnt; i++) {
        int ni = (i + 1) % _vcnt;
        int nni = (i + 2) % _vcnt;
        p3[0] = _v[nni].p[0];
        p3[1] = _v[nni].p[1];
        v0[0] = p1[0] - p0[0];
        v0[1] = p1[1] - p0[1];
        v1[0] = p1[0] - p2[0];
        v1[1] = p1[1] - p2[1];
        if (LEN(v1) < 1e-8) {
          p2[0] = p3[0];
          p2[1] = p3[1];
          continue;
        }
        n0[0] = v0[0];
        n0[1] = v0[1];
        n1[0] = -v1[0];
        n1[1] = -v1[1];
        NORM(n0);
        NORM(n1);
        double dotv0 = DOT(n0, n1);
        INV(n1);
        ADD(n0, n0, n1);
        NORM(n0);
        v0[0] = p2[0] - p1[0];
        v0[1] = p2[1] - p1[1];
        v1[0] = p2[0] - p3[0];
        v1[1] = p2[1] - p3[1];
        ADD(n1, v0, v1);
        NORM(n1);
        n2[0] = p2[0] - p1[0];
        n2[1] = p2[0] - p1[0];
        NORM(n2);
        // если сегменты инверированы нужно использовать другой метод индексации
        // чтобы треугольники не были вывернуты
        // Знак CROSS() указывает на сторону поворота относительно сегмента и должен быть одним и тем-же для смежных сегментов
        int _inv = CROSS(n0, n2) * CROSS(n1, n2) > 1e-8;
        if (conf->mode == LB_MODE_COMPLEX) {
          //if (dotv0 > 0.8660254f) {
          //  mode = LB_MODE_BEVEL;
          //} else {
          //  mode = LB_MODE_MITER;
          //}
          mode = LB_MODE_MITER;
        }
        if (mode == LB_MODE_MITER) {
          if (V) {
            double pt[2];
            double nt[2] = {-n0[0], -n0[1]};
            double nt0[2], nt1[2];
            double miter = 1.0 / (sqrt((1.0f - dotv0) / 2.0f));
            nt0[0] = p2[0] - p0[0];
            nt0[1] = p2[1] - p0[1];
            NORM(nt0);
            nt1[0] = -n0[0];
            nt1[1] = -n0[1];
            double T;
            seg_insect(p0, nt0, p1, nt1, NULL, &T);
            pt[0] = p1[0] + nt[0] * w * miter;
            pt[1] = p1[1] + nt[1] * w * miter;
            VER(&V[vi], pt, nt, conf->c, sw * miter, 0.0f);
            INV(nt);
            pt[0] = p1[0] + nt[0] * w * miter;
            pt[1] = p1[1] + nt[1] * w * miter;
            VER(&V[vi + 1], pt, nt, conf->c, sw * miter, 0.0f);
          }
          if (I) {
            int nb = i < _vcnt - 1 ? vi + 2 : 0;
            if (_inv) {
              I[ii] = off + vi + 0;
              I[ii + 1] = off + vi + 1;
              I[ii + 2] = off + nb + 1;
              I[ii + 3] = off + vi + 1;
              I[ii + 4] = off + nb;
              I[ii + 5] = off + nb + 1;
            } else {
              I[ii] = off + vi + 0;
              I[ii + 1] = off + vi + 1;
              I[ii + 2] = off + nb;
              I[ii + 3] = off + vi + 1;
              I[ii + 4] = off + nb + 1;
              I[ii + 5] = off + nb;
            }
          }
          ii += 6;
          vi += 2;
        } else if (mode == LB_MODE_BEVEL) {
          if (V) {
            double pt[2], pt0[2], pt1[2];
            double nt0[2], nt1[2];
            double T;
            nt1[0] = -n0[0];
            nt1[1] = -n0[1];
            pt[0] = p1[0] + nt1[0] * w;
            pt[1] = p1[1] + nt1[1] * w;
            VER(&V[vi], pt, nt1, conf->c, sw, 0.0f);
            nt0[0] = p1[0] - p0[0];
            nt0[1] = p1[1] - p0[1];
            NORM(nt0);
            PERP(nt0);
            nt1[0] = p2[0] - p1[0];
            nt1[1] = p2[1] - p1[1];
            NORM(nt1);
            PERP(nt1);
            if (DOT(n0, nt0) < 0.0f)
              INV(nt0);
            if (DOT(n0, nt1) < 0.0f)
              INV(nt1);
            pt0[0] = pt[0] * nt0[0] * w * 2.0f;
            pt0[0] = pt[1] * nt0[1] * w * 2.0f;
            VER(&V[vi + 1], pt0, nt0, conf->c, sw, 0.0f);
            pt0[0] = pt[0] * nt1[0] * w * 2.0f;
            pt0[0] = pt[1] * nt1[1] * w * 2.0f;
            VER(&V[vi + 2], pt0, nt1, conf->c, sw, 0.0f);
          }
          if (I) {
            int nb = i < _vcnt - 1 ? vi + 3 : 0;
            if (_inv) {
              I[ii] = off + vi + 0;
              I[ii + 1] = off + vi + 1;
              I[ii + 2] = off + vi + 2;
              I[ii + 3] = off + vi + 0;
              I[ii + 4] = off + vi + 2;
              I[ii + 5] = off + nb;
              I[ii + 6] = off + vi + 0;
              I[ii + 7] = off + nb + 1;
              I[ii + 8] = off + nb;
            } else {
              I[ii] = off + vi + 0;
              I[ii + 1] = off + vi + 1;
              I[ii + 2] = off + vi + 2;
              I[ii + 3] = off + vi + 0;
              I[ii + 4] = off + vi + 2;
              I[ii + 5] = off + nb + 1;
              I[ii + 6] = off + vi + 0;
              I[ii + 7] = off + nb;
              I[ii + 8] = off + nb + 1;
            }
          }
          ii += 9;
          vi += 3;
        } else if (mode == LB_MODE_ROUND) {
          if (!V || !I) {
            ROUNDSTATS(conf->nroundsegs, &vi, &ii);
          }
          if (V) {
            //
          }
          if (I) {
            if (_inv) {

            } else {
            }
          }
          vi += 0;
          ii += 6;
        }
        p0[0] = p1[0];
        p0[1] = p1[1];
        p1[0] = p2[0];
        p1[1] = p2[1];
        p2[0] = p3[0];
        p2[1] = p3[1];
      }
    } else {
    }
  }
  *Vcnt = vi;
  *Icnt = ii;
}