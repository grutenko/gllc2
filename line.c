#include "line.h"
#include "block.h"
#include "draw.h"
#include "entbuildutil.h"
#include "entity.h"
#include "linalg.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

#define LINE(ent) ((struct gllc_line *)(ent))

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale) {
  struct ev pts[] = {
      {LINE(ent)->p0[0], LINE(ent)->p0[1]},
      {LINE(ent)->p1[0], LINE(ent)->p1[1]},
  };
  if (gllc_entity_geometry_modified(ent)) {
    ds_unit_reset(LINE(ent)->u);
  }
  build_contur(ent, LINE(ent)->u, pts, 2, 0);
}

static void destroy(struct gllc_entity *ent) {
  struct gllc_line *line = (struct gllc_line *)ent;
  if (line) {
    ds_unit_destroy(line->u);
    free(line);
  }
}

static int vertices(struct gllc_entity *ent, double scale, struct ev *ver) {
  struct gllc_line *l = (struct gllc_line *)ent;
  if (ver) {
    ver[0].p[0] = l->p0[0];
    ver[0].p[1] = l->p0[1];
    ver[1].p[0] = l->p1[0];
    ver[1].p[1] = l->p1[1];
  }
  return 2;
}

static int selected(struct gllc_entity *ent, int mode, double scale, double x0, double y0, double x1, double y1) {
  struct gllc_line *l = (struct gllc_line *)ent;
  double T, S;
  double n1[2];
  double n0[2];
  double len;
  int inside = (x0 <= l->p0[0] && x1 >= l->p0[0] && y0 <= l->p0[1] && y1 >= l->p0[1]) && (x0 <= l->p1[0] && x1 >= l->p1[0] && y0 <= l->p1[1] && y1 >= l->p1[1]);
  if (mode == 1) {
    if (inside)
      return 1;
    VEC(n0, l->p0, l->p1);
    len = LEN(n0);
    NORM(n0);
    // Ищем сторону прямоугольника, которая пересекает линию, если находим - линия частично выделена
#define TEST(_x0, _y0, _x1, _y1)                                  \
  do {                                                            \
    n1[0] = _x1 - _x0;                                            \
    n1[1] = _y1 - _y0;                                            \
    double lenside = LEN(n1);                                     \
    NORM(n1);                                                     \
    if (RAYINSECT(l->p0, n0, (double[]){_x0, _y0}, n1, &T, &S)) { \
      if (S >= 0 && S <= lenside && T >= 0 && T <= len) {         \
        return 1;                                                 \
      }                                                           \
    }                                                             \
  } while (0)
    TEST(x0, y0, x1, y0);
    TEST(x1, y0, x1, y1);
    TEST(x1, y1, x0, y1);
    TEST(x0, y1, x0, y0);
    TEST(x1, y0, x0, y0);
    TEST(x1, y1, x1, y0);
    TEST(x0, y1, x1, y1);
    TEST(x0, y0, x0, y1);
  } else {
    return inside;
  }
  return 0;
}

static int clone(struct gllc_entity *ent, struct gllc_entity **clone) {
  if (ent->vtable->type != GLLC_ENT_LINE)
    return 0;
  struct gllc_line *l = (struct gllc_line *)ent;
  struct gllc_line *nl = malloc(sizeof(struct gllc_line));
  if (!nl)
    return 0;
  memcpy(nl, l, sizeof(struct gllc_line));
  nl->u = ds_unit_clone(l->u);
  *clone = (struct gllc_entity *)nl;
  return 1;
}

static int picked(struct gllc_entity *ent, double scale, double x, double y, double *dis) {
  struct gllc_line *line = (struct gllc_line *)ent;
  double w;
  if (ent->flags & GLLC_ENT_LW_THIN)
    w = 10.0f * scale;
  else if (ent->flags & GLLC_ENT_LW_SCREEN)
    w = (ent->lwidth + 10.0f) * scale;
  else
    w = ent->lwidth + (10.0f * scale);
  double n0[2], n1[2];
  double T, S, len;
  VEC(n0, line->p0, line->p1);
  len = LEN(n0);
  NORM(n0);
  COPY(n1, n0);
  PERP(n1);
  int rc = RAYINSECT(line->p0, n0, (double[]){x, y}, n1, &T, &S);
  if (rc) {
    if (T >= 0.0f && T <= len && fabs(S) <= w / 2) {
      if (dis)
        *dis = fabs(S);
      return 1;
    }
  }
  return 0;
}

static inline void swapf(double *a, double *b) {
  double t = *a;
  *a = *b;
  *b = t;
}

static int bbox(struct gllc_entity *ent, double scale, double *xmin, double *ymin, double *xmax, double *ymax) {
  double min[2], max[2];
  struct gllc_line *line = (struct gllc_line *)ent;
  min[0] = line->p0[0];
  min[1] = line->p0[1];
  max[0] = line->p1[0];
  max[1] = line->p1[1];
  if (min[0] > max[0])
    swapf(&min[0], &max[0]);
  if (min[1] > max[1])
    swapf(&min[1], &max[1]);
  if (xmin)
    *xmin = min[0];
  if (ymin)
    *ymin = min[1];
  if (xmax)
    *xmax = max[0];
  if (ymax)
    *ymax = max[1];
  return 1;
}

static int len(struct gllc_entity *ent, double *len) {
  struct gllc_line *line = (struct gllc_line *)ent;
  double dx, dy;
  dx = line->p1[0] - line->p0[0];
  dy = line->p1[1] - line->p0[1];
  *len = sqrt(dx * dx + dy * dy);
  return 1;
}

static struct gllc_entity_vtable vtable = {
    .type = GLLC_ENT_LINE,
    .build = build,
    .destroy = destroy,
    .vertices = vertices,
    .selected = selected,
    .picked = picked,
    .bbox = bbox,
    .len = len,
    .clone = clone};

static struct gllc_prop pline_props[] = {
    P_END};

static struct gllc_prop *all_props[] = {G_entity_props, pline_props, NULL};

struct gllc_line *gllc_line_create(struct gllc_block *block, struct ds_draw *draw, double *p0, double *p1) {
  struct gllc_line *pl = malloc(sizeof(struct gllc_line));
  if (pl) {
    GLLC_ENTITY_INIT(&pl->_ent, block, all_props, &vtable);
    pl->u = ds_unit_create(draw);
    pl->p0[0] = p0[0];
    pl->p0[1] = p0[1];
    pl->p1[0] = p1[0];
    pl->p1[1] = p1[1];
  }
  return pl;
}