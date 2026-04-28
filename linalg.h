#ifndef linalg_h
#define linalg_h

#include <math.h>

double LEN(const double v[static 2]);
void VEC(double out[static 2], const double a[static 2], const double b[static 2]);
void NORM(double v[static 2]);
void NORMTO(const double v[static 2], double out[static 2]);
void PERP(double v[static 2]);
void PERPTO(const double v[static 2], double out[static 2]);
void INV(double v[static 2]);
void INVTO(const double in[static 2], double out[static 2]);
double DOT(const double a[static 2], const double b[static 2]);
double CROSS(const double a[static 2], const double b[static 2]);
void ADD(double p[static 2], const double p0[static 2], const double p1[static 2]);
void BISEC(double n[static 2], const double p0[static 2], const double p1[static 2], const double p2[static 2]);
void ROTTO(const double n[static 2], double angle, double out[static 2]);
void ROT(double n[static 2], double angle);
void MULSCAL(double n[static 2], double scal);
int RAYINSECT(const double p0[static 2], const double n0[static 2], const double p1[static 2], const double n1[static 2], double *pT, double *pS);
void ADDSCALETO(const double p0[static 2], const double n0[static 2], double l, double p1[static 2]);
void COPY(double *out, const double *v0);

#endif