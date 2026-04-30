#include "circle.h"
#include "draw.h"
#include "entbuildutil.h"
#include "entity.h"
#include "linalg.h"

#include <stdlib.h>
#include <string.h>

#define SEGCNT 64

#define CIRCLE(o) ((struct gllc_circle *)(o))

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale) {
  static struct ev pts[SEGCNT + 1];
  double n0[2] = {1.0f, 0.0f};
  double step = (M_PI * 2) / SEGCNT;
  for (int i = 0; i <= SEGCNT; i++) {
    ADDSCALETO(CIRCLE(ent)->p, n0, CIRCLE(ent)->radius, pts[i].p);
    ROT(n0, step);
  }
  if (gllc_entity_geometry_modified(ent)) {
    ds_unit_reset(CIRCLE(ent)->u);
  }
  build_contur(ent, CIRCLE(ent)->u, pts, SEGCNT + 1, 0);
}

static void destroy(struct gllc_entity *ent) {
  struct gllc_circle *c = (struct gllc_circle *)ent;
  if (c) {
    ds_unit_destroy(c->u);
    free(c);
  }
}

static int vertices(struct gllc_entity *ent, double scale, struct ev *ver) {
  return 0;
}

static int bbox(struct gllc_entity *ent, double scale, double *xmin, double *ymin, double *xmax, double *ymax);

static int selected(struct gllc_entity *ent, int mode, double scale, double x0, double y0, double x1, double y1) {
  double bx0, by0, bx1, by1;
  bbox(ent, scale, &bx0, &by0, &bx1, &by1);
  int inside = (x0 <= bx0 && x1 >= bx0 && y0 <= by0 && y1 >= by0) && (x0 <= bx1 && x1 >= bx1 && y0 <= by1 && y1 >= by1);
  if (mode == 0) {
    return inside;
  } else {
    if (inside) {
      return 1;
    }
#define TEST(_x0, _y0, _x1, _y1)                                              \
  do {                                                                        \
    double T, S;                                                              \
    double n0[2], n1[2], len0;                                                \
    VEC(n0, (double[]){_x0, _y0}, (double[]){_x1, _y1});                      \
    len0 = LEN(n0);                                                           \
    NORM(n0);                                                                 \
    PERPTO(n0, n1);                                                           \
    NORM(n1);                                                                 \
    if (RAYINSECT((double[]){_x0, _y0}, n0, CIRCLE(ent)->p, n1, &T, &S)) {    \
      if (fabs(S) <= CIRCLE(ent)->radius && T >= 0 && T <= len0) {            \
        double v0[2], v1[2];                                                  \
        VEC(v0, (double[]){_x0, _y0}, CIRCLE(ent)->p);                        \
        VEC(v1, (double[]){_x1, _y1}, CIRCLE(ent)->p);                        \
        if (LEN(v0) > CIRCLE(ent)->radius || LEN(v1) > CIRCLE(ent)->radius) { \
          return 1;                                                           \
        }                                                                     \
      }                                                                       \
    }                                                                         \
  } while (0)
    TEST(x0, y0, x1, y0);
    TEST(x1, y0, x1, y1);
    TEST(x1, y1, x0, y1);
    TEST(x0, y1, x0, y0);
    TEST(x1, y0, x0, y0);
    TEST(x1, y1, x1, y0);
    TEST(x0, y1, x1, y1);
    TEST(x0, y0, x0, y1);
  }
  return 0;
}

static int clone(struct gllc_entity *ent, struct gllc_entity **clone) {
  struct gllc_circle *l = (struct gllc_circle *)ent;
  struct gllc_circle *nl = malloc(sizeof(struct gllc_circle));
  if (!nl)
    return 0;
  memcpy(nl, l, sizeof(struct gllc_circle));
  nl->u = ds_unit_clone(l->u);
  *clone = (struct gllc_entity *)nl;
  return 1;
}

static int picked(struct gllc_entity *ent, double scale, double x, double y, double *dis) {
  double v0[2];
  double len;
  double w;
  if (ent->flags & GLLC_ENT_LW_THIN)
    w = 10.0f * scale;
  else if (ent->flags & GLLC_ENT_LW_SCREEN)
    w = (ent->lwidth + 10.0f) * scale;
  else
    w = ent->lwidth + (10.0f * scale);
  VEC(v0, CIRCLE(ent)->p, (double[]){x, y});
  len = LEN(v0);
  return len >= CIRCLE(ent)->radius - w && len <= CIRCLE(ent)->radius + w;
}

static int bbox(struct gllc_entity *ent, double scale, double *xmin, double *ymin, double *xmax, double *ymax) {
  double x0, y0, x1, y1;
  if (xmin)
    *xmin = CIRCLE(ent)->p[0] - CIRCLE(ent)->radius;
  if (ymin)
    *ymin = CIRCLE(ent)->p[1] - CIRCLE(ent)->radius;
  if (xmax)
    *xmax = CIRCLE(ent)->p[0] + CIRCLE(ent)->radius;
  if (ymax)
    *ymax = CIRCLE(ent)->p[1] + CIRCLE(ent)->radius;
  return 1;
}

static int len(struct gllc_entity *ent, double *len) {
  return CIRCLE(ent)->radius * 2 * M_PI;
}

static struct gllc_entity_vtable vtable = {
    .type = GLLC_ENT_POLYLINE,
    .build = build,
    .destroy = destroy,
    .vertices = vertices,
    .selected = selected,
    .picked = picked,
    .bbox = bbox,
    .len = len,
    .clone = clone};

static struct gllc_prop circle_props[] = {
    P_END};

static struct gllc_prop *all_props[] = {G_entity_props, circle_props, NULL};

struct gllc_circle *gllc_circle_create(struct gllc_block *block, struct ds_draw *draw, double x, double y, double radius, int filled) {
  struct gllc_circle *c = malloc(sizeof(struct gllc_circle));
  if (c) {
    GLLC_ENTITY_INIT(&c->_ent, block, all_props, &vtable);
    c->_ent.flags |= filled ? GLLC_ENT_FILLED : 0;
    c->u = ds_unit_create(draw);
    c->p[0] = x;
    c->p[1] = y;
    c->radius = radius;
  }
  return c;
}