#include "line_build.h"
#include "draw.h"
#include "glad.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define PI 3.14159265358979323f
#define PI2 1.5707963705062866f

void lb_stats_bevel(struct lb *lb) {
  if (lb->in.closed) {
    lb->out.ver_cnt = lb->in.ver_cnt * 4;
    lb->out.ind_cnt = lb->in.ver_cnt * 18;
  } else {
    lb->out.ver_cnt = lb->in.ver_cnt * 4 - 4;
    lb->out.ind_cnt = lb->in.ver_cnt * 18 - 30;
  }
}

void lb_init(struct lb *lb) {
  memset(lb, 0, sizeof(struct lb));
}

void lb_stats_miter(struct lb *lb) {
  lb->out.ver_cnt = lb->in.ver_cnt * 2;
  lb->out.ind_cnt = (lb->in.ver_cnt + 1) * 6;
}

void lb_stats_round(struct lb *lb) {
}

static inline void _putver(struct ds_vertex *o, int i, uint8_t *c, double *p, double *n, float th) {
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
  double dot = p0[0] * p1[0] + p0[1] * p1[1];
  double len0 = sqrt(p0[0] * p0[0] + p0[1] * p0[1]);
  double len1 = sqrt(p1[0] * p1[0] + p1[1] * p1[1]);
  return acos(dot / (len0 * len1));
}

static inline void _inv(double *n) {
  n[0] = -n[0];
  n[1] = -n[1];
}

static inline double _dot(double *n0, double *n1) {
  return n0[0] * n1[0] + n0[1] * n1[1];
}

static inline double _cross(double *n0, double *n1) {
  return n0[0] * n1[1] - n0[1] * n1[0];
}

void lb_build_miter(struct lb *lb) {
  double p0[2], p1[2], p2[2], n0[2], ref[2], d0[2], d1[2], on[2];
  GLuint vi = 0, ii = 0, base = 0;
  struct ev *v = lb->in.ver;
  struct ds_vertex *vout = lb->out.ver_ptr;
  GLuint *iout = lb->out.ind_ptr;
  GLuint th = lb->in.screenweight;
  size_t vc = lb->in.ver_cnt;
  int i, ni, b, nb;

  if (vc <= 1)
    return;

  uint8_t c[4];
  c[0] = (uint8_t)(lb->in.color[0] * 255);
  c[1] = (uint8_t)(lb->in.color[1] * 255);
  c[2] = (uint8_t)(lb->in.color[2] * 255);
  c[3] = (uint8_t)(lb->in.color[3] * 255);

  if (lb->in.closed) {
    if (vc <= 2)
      return;

    p0[0] = v[vc - 1].p[0];
    p0[1] = v[vc - 1].p[1];
    p1[0] = v[0].p[0];
    p1[1] = v[0].p[1];

    {
      double pt[2];
      pt[0] = v[vc - 2].p[0];
      pt[1] = v[vc - 2].p[1];
      d0[0] = p0[0] - pt[0];
      d0[1] = p0[1] - pt[1];
      d1[0] = p1[0] - p0[0];
      d1[1] = p1[1] - p0[1];
      _bisec(pt, p0, p1, n0);
      on[0] = n0[0];
      on[1] = n0[1];
    }

    for (i = 0; i < vc; i++) {
      ni = i < vc - 1 ? i + 1 : 0;
      p2[0] = v[ni].p[0];
      p2[1] = v[ni].p[1];
      d0[0] = p1[0] - p0[0];
      d0[1] = p1[1] - p0[1];
      d1[0] = p2[0] - p1[0];
      d1[1] = p2[1] - p1[1];

      _bisec(p0, p1, p2, n0);
      double cosni = cos(_angle(d0, d1) / 2.0f);
      if (cosni < 0.001f)
        cosni = 0.001f;
      double len = lb->in.weight / cosni / 2.0f;

      b = lb->in.ioffset + vi;
      nb = ni ? b + 2 : lb->in.ioffset;
      printf("%lf\n", _cross(n0, on));

      d0[0] = p1[0] + n0[0] * len;
      d0[1] = p1[1] + n0[1] * len;
      d1[0] = p1[0] - n0[0] * len;
      d1[1] = p1[1] - n0[1] * len;
      iout[ii++] = b;
      iout[ii++] = nb + 1;
      iout[ii++] = b + 1;
      iout[ii++] = b;
      iout[ii++] = nb;
      iout[ii++] = nb + 1;
      _putver(vout, vi++, c, d0, n0, th / cosni);
      _inv(n0);
      _putver(vout, vi++, c, d1, n0, th / cosni);
      p0[0] = p1[0];
      p0[1] = p1[1];
      p1[0] = p2[0];
      p1[1] = p2[1];
      on[0] = n0[0];
      on[1] = n0[1];
    }
  } else {
    d0[0] = v[1].p[0] - v[0].p[0];
    d0[1] = v[1].p[1] - v[0].p[1];
    _perp(d0, n0);
    _inv(n0);
    {
      double nt[2];
      nt[0] = n0[0];
      nt[1] = n0[1];
      p0[0] = v[0].p[0] + nt[0] * (lb->in.weight / 2.0f);
      p0[1] = v[0].p[1] + nt[1] * (lb->in.weight / 2.0f);
      _putver(vout, vi++, c, p0, nt, th);
      _inv(nt);
      p0[0] = v[0].p[0] + nt[0] * (lb->in.weight / 2.0f);
      p0[1] = v[0].p[1] + nt[1] * (lb->in.weight / 2.0f);
      _putver(vout, vi++, c, p0, nt, th);
    }
    iout[ii++] = base;
    iout[ii++] = base + 1;
    iout[ii++] = base + 2;
    iout[ii++] = base;
    iout[ii++] = base + 2;
    iout[ii++] = base + 3;
    on[0] = n0[0];
    on[1] = n0[1];
    p0[0] = v[0].p[0];
    p0[1] = v[0].p[1];
    p1[0] = v[1].p[0];
    p1[1] = v[1].p[1];

    for (i = 1; i < vc - 1; i++) {
      p2[0] = v[i + 1].p[0];
      p2[1] = v[i + 1].p[1];
      d0[0] = p1[0] - p0[0];
      d0[1] = p1[1] - p0[1];
      d1[0] = p2[0] - p1[0];
      d1[1] = p2[1] - p1[1];

      _bisec(p0, p1, p2, n0);
      double cosni = cos(_angle(d0, d1) / 2.0f);
      if (cosni < 0.01f)
        cosni = 0.01f;
      double len = lb->in.weight / cosni / 2.0f;
      _perp(on, ref);
      double c0 = _cross(ref, on);
      double c1 = _cross(ref, n0);

      base = vi;
      {
        double nt[2];
        nt[0] = n0[0];
        nt[1] = n0[1];
        if (c0 * c1 >= 0.0f)
          _inv(nt);
        p0[0] = p1[0] + nt[0] * len;
        p0[1] = p1[1] + nt[1] * len;
        _putver(vout, vi++, c, p0, nt, th / cosni);
        _inv(nt);
        p0[0] = p1[0] + nt[0] * len;
        p0[1] = p1[1] + nt[1] * len;
        _putver(vout, vi++, c, p0, nt, th / cosni);
      }

      if (c0 * c1 >= 0.0f) {
        iout[ii++] = base;
        iout[ii++] = base + 1;
        iout[ii++] = base + 2;
        iout[ii++] = base;
        iout[ii++] = base + 2;
        iout[ii++] = base + 3;
      } else {
        iout[ii++] = base + 0;
        iout[ii++] = base + 1;
        iout[ii++] = base + 3;
        iout[ii++] = base + 1;
        iout[ii++] = base + 2;
        iout[ii++] = base + 3;
      }

      p0[0] = p1[0];
      p0[1] = p1[1];
      p1[0] = p2[0];
      p1[1] = p2[1];
      on[0] = n0[0];
      on[1] = n0[1];
    }

    d0[0] = v[vc - 1].p[0] - v[vc - 2].p[0];
    d0[1] = v[vc - 1].p[1] - v[vc - 2].p[1];
    _perp(d0, n0);
    _perp(on, ref);
    double c0 = _cross(ref, on);
    double c1 = _cross(ref, n0);

    // Оборачиваем
    if (c0 * c1 >= 0.0f)
      _inv(n0);

    base = vi;
    p0[0] = p1[0] + n0[0] * (lb->in.weight / 2.0f);
    p0[1] = p1[1] + n0[1] * (lb->in.weight / 2.0f);
    _putver(vout, vi++, c, p0, n0, th);
    _inv(n0);
    p0[0] = p1[0] + n0[0] * (lb->in.weight / 2.0f);
    p0[1] = p1[1] + n0[1] * (lb->in.weight / 2.0f);
    _putver(vout, vi++, c, p0, n0, th);
  }

  lb->out.ver_cnt = vi;
  lb->out.ind_cnt = ii;
}

void lb_build_round(struct lb *lb) {
}

void lb_build_bevel(struct lb *lb) {
  double p0[2], p1[2], p2[2], n0[2], n1[2], n2[2], _on[2];
  double _d0[2], _d1[2];
  struct ev *v = lb->in.ver;
  GLuint th = lb->in.screenweight;
  struct ds_vertex *vout = lb->out.ver_ptr;
  GLuint *iout = lb->out.ind_ptr;
  size_t vc = lb->in.ver_cnt;
  int i, ni;
  GLuint vi = 0, ii = 0, base = 0;

  if (vc <= 1)
    return;

  if (lb->in.closed) {
    if (vc <= 2)
      return;
    p0[0] = v[vc - 1].p[0];
    p0[1] = v[vc - 1].p[1];
    p1[0] = v[0].p[0];
    p1[1] = v[0].p[1];
    // Рассчитываем перпендикуляр для n - 1 сегмента чтобы правильно рассчитать dot для n = 0
    {
      double pt[2];
      pt[0] = v[vc - 2].p[0];
      pt[1] = v[vc - 2].p[1];
      _d0[0] = p0[0] - pt[0];
      _d0[1] = p0[1] - pt[1];
      _d1[0] = p1[0] - p0[0];
      _d1[1] = p1[1] - p0[1];
      _bisec(pt, p0, p1, n0);
      _perp(_d0, n1);
      _perp(_d1, n2);
      if (_dot(n0, n1) < 0.0f)
        _inv(n1);
      if (_dot(n0, n2) < 0.0f)
        _inv(n2);

      _on[0] = n2[0];
      _on[1] = n2[1];
    }

    for (i = 0; i < vc; i++) {
      ni = i < vc - 1 ? i + 1 : 0;
      p2[0] = v[ni].p[0];
      p2[1] = v[ni].p[1];
      _d0[0] = p1[0] - p0[0];
      _d0[1] = p1[1] - p0[1];
      _d1[0] = p2[0] - p1[0];
      _d1[1] = p2[1] - p1[1];
      _bisec(p0, p1, p2, n0);
      _perp(_d0, n1);
      _perp(_d1, n2);
      if (_dot(n0, n1) < 0.0f)
        _inv(n1);
      if (_dot(n0, n2) < 0.0f)
        _inv(n2);
      // n1, n2 - векторы направления для создания фаски
      uint8_t c[4];
      c[0] = (uint8_t)(lb->in.color[0] * 255);
      c[1] = (uint8_t)(lb->in.color[1] * 255);
      c[2] = (uint8_t)(lb->in.color[2] * 255);
      c[3] = (uint8_t)(lb->in.color[3] * 255);
      _inv(n0);
      base = lb->in.ioffset + vi;
      double cosni = cos(_angle(n1, n2) / 2.0f);
      double len = lb->in.weight / 2.0f * cosni;
      _d0[0] = p1[0] + n0[0] * len;
      _d0[1] = p1[1] + n0[1] * len;

      iout[ii++] = base;
      iout[ii++] = base + 1;
      iout[ii++] = base + 2;

      if (_dot(_on, n1) > 0.0f) {
        _putver(vout, vi++, c, _d0, n0, th * cosni * 2.0f);
        _d1[0] = _d0[0] + n1[0] * (lb->in.weight);
        _d1[1] = _d0[1] + n1[1] * (lb->in.weight);
        _putver(vout, vi++, c, _d1, n1, th * 2.0f);
        int nbase = ni ? base + 3 : lb->in.ioffset;
        iout[ii++] = base;
        iout[ii++] = base + 2;
        iout[ii++] = nbase;
        iout[ii++] = base + 2;
        iout[ii++] = nbase + 1;
        iout[ii++] = nbase;
      } else {
        int nbase = ni ? base + 3 : 0;
        _d1[0] = _d0[0] + n1[0] * (lb->in.weight);
        _d1[1] = _d0[1] + n1[1] * (lb->in.weight);
        _putver(vout, vi++, c, _d1, n1, th * 2.0f);
        _putver(vout, vi++, c, _d0, n0, th * cosni * 2.0f);
        iout[ii++] = base + 1;
        iout[ii++] = base + 2;
        iout[ii++] = nbase + 1;
        iout[ii++] = base + 1;
        iout[ii++] = nbase + 1;
        iout[ii++] = nbase;
      }

      _d1[0] = _d0[0] + n2[0] * (lb->in.weight);
      _d1[1] = _d0[1] + n2[1] * (lb->in.weight);
      _putver(vout, vi++, c, _d1, n2, th * 2.0f);
      p0[0] = p1[0];
      p0[1] = p1[1];
      p1[0] = p2[0];
      p1[1] = p2[1];
      _on[0] = n2[0];
      _on[1] = n2[1];
    }
  }

  lb->out.ver_cnt = vi;
  lb->out.ind_cnt = ii;
}
