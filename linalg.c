#include "linalg.h"
#include <stdio.h>

inline double LEN(const double v[static 2]) {
  return sqrt(v[0] * v[0] + v[1] * v[1]);
}

inline void VEC(double out[static 2], const double a[static 2], const double b[static 2]) {
  out[0] = b[0] - a[0];
  out[1] = b[1] - a[1];
}

inline void NORM(double v[static 2]) {
  double l = LEN(v);
  if (l > 0.0) {
    v[0] /= l;
    v[1] /= l;
  } else {
    v[0] = 0.0f;
    v[1] = 0.0f;
  }
}

inline void NORMTO(const double v[static 2], double out[static 2]) {
  double l = LEN(v);
  if (l > 0.0) {
    out[0] = v[0] / l;
    out[1] = v[1] / l;
  } else {
    out[0] = 0.0f;
    out[1] = 0.0f;
  }
}

inline void PERP(double v[static 2]) {
  double t = v[0];
  v[0] = -v[1];
  v[1] = t;
}

inline void PERPTO(const double v[static 2], double out[static 2]) {
  out[0] = -v[1];
  out[1] = v[0];
}

inline void INV(double v[static 2]) {
  v[0] = -v[0];
  v[1] = -v[1];
}

inline void INVTO(const double in[static 2], double out[static 2]) {
  out[0] = -in[0];
  out[1] = -in[1];
}

inline double DOT(const double a[static 2], const double b[static 2]) {
  return a[0] * b[0] + a[1] * b[1];
}

inline double CROSS(const double a[static 2], const double b[static 2]) {
  return a[0] * b[1] - a[1] * b[0];
}

inline void ADD(
    double p[static 2],
    const double p0[static 2],
    const double p1[static 2]) {
  p[0] = p0[0] + p1[0];
  p[1] = p0[1] + p1[1];
}

inline void BISEC(
    double n[static 2],
    const double p0[static 2],
    const double p1[static 2],
    const double p2[static 2]) {
  double v0[2];
  double v1[2];
  VEC(v0, p0, p1);
  VEC(v1, p2, p1);
  NORM(v0);
  NORM(v1);
  ADD(n, v0, v1);
  NORM(n);
}

inline void ROTTO(const double n[static 2], double angle, double out[static 2]) {
  double cosa = cos(angle);
  double sina = sin(angle);
  out[0] = n[0] * cosa - n[1] * sina;
  out[1] = n[0] * sina + n[1] * cosa;
  NORM(out);
}

inline void ROT(double n[static 2], double angle) {
  double out[2];
  ROTTO(n, angle, out);
  n[0] = out[0];
  n[1] = out[1];
}

inline void MULSCAL(double n[static 2], double scal) {
  n[0] *= scal;
  n[1] *= scal;
}

inline int RAYINSECT(
    const double p0[static 2],
    const double n0[static 2],
    const double p1[static 2],
    const double n1[static 2],
    double *pT, double *pS) {
  double D, Dt, Ds, d[2];
  VEC(d, p0, p1);
  D = -n0[0] * n1[1] + n0[1] * n1[0];
  if (D < 1e-8)
    return 0;
  Dt = -n1[1] * d[0] + n1[0] * d[1];
  Ds = n0[0] * d[1] - n0[1] * d[0];
  *pT = Dt / D;
  *pS = Ds / D;
  return 1;
}

inline void ADDSCALETO(
    const double p0[static 2],
    const double n0[static 2],
    double l,
    double p1[static 2]) {
  p1[0] = p0[0] + n0[0] * l;
  p1[1] = p0[1] + n0[1] * l;
}

inline void SET(const double *v0, double *out) {
  out[0] = v0[0];
  out[1] = v0[1];
}