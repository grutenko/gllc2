#include "line.h"
#include "block.h"
#include "entity.h"
#include "lb.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale) {
  struct gllc_line *pl = (struct gllc_line *)ent;
  if (!pl || !draw)
    return;
  int colorint = gllc_entity_color(ent);
  unsigned char color[4] = {RED(colorint), GREEN(colorint), BLUE(colorint), 255};
  struct ev p[2];
  p[0].p[0] = pl->p0[0];
  p[0].p[1] = pl->p0[1];
  p[1].p[0] = pl->p1[0];
  p[1].p[1] = pl->p1[1];
  struct lb_config lb_conf = {
      .v = p,
      .vcnt = 2,
      .nroundsegs = 8,
      .closed = 0,
      .c = color,
      .off = 0,
      .mode = LB_MODE_ROUND
  };
  if (ent->flags & GLLC_ENT_LW_REAL) {
    lb_conf.lw = 1.0f;
    lb_conf.lrealw = gllc_entity_lwidth(ent);
  } else if (ent->flags & GLLC_ENT_LW_SCREEN) {
    lb_conf.lw = gllc_entity_lwidth(ent);
    lb_conf.lrealw = 0.0001f;
  } else {
    lb_conf.lw = 1.0f;
    lb_conf.lrealw = 0.0001f;
    lb_conf.mode = LB_MODE_MITER;
  }
  if (pl->_ent.flags & GLLC_ENT_HOVER) {
    lb_conf.lw += 2.0f;
  }
  int vcnt, icnt;
  // первый вызов для получения количества вершин и индексов
  lb_build(&lb_conf, NULL, NULL, &vcnt, &icnt);
  struct ds_vertex *V = ds_unit_reserve_vertex(pl->u, vcnt);
  GLuint *I = ds_unit_reserve_index(pl->u, icnt);
  if (pl->_ent.flags & GLLC_ENT_HOVER) {
    pl->u->flags = DS_UNIT_CHESS;
  } else {
    pl->u->flags = 0;
  }
  if (V && I) {
    lb_build(&lb_conf, V, I, &vcnt, &icnt);
  }
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

static inline double LEN(const double v[2]) {
  return sqrt(v[0] * v[0] + v[1] * v[1]);
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

static int selected(struct gllc_entity *ent, int mode, double scale, double x0, double y0, double x1, double y1) {
  struct gllc_line *l = (struct gllc_line *)ent;
  double D, T, S, d[2];
  double n1[2], v1[2];
  double n0[2];
  double v0[2];
  double len;
  int inside = (x0 <= l->p0[0] && x1 >= l->p0[0] && y0 <= l->p0[1] && y1 >= l->p0[1]) && (x0 <= l->p1[0] && x1 >= l->p1[0] && y0 <= l->p1[1] && y1 >= l->p1[1]);
  if (mode == 0) {
    return inside;
  } else {
    if (inside)
      return 1;
    n0[0] = l->p1[0] - l->p0[0];
    n0[1] = l->p1[1] - l->p0[1];
    v0[0] = n0[0];
    v0[1] = n0[1];
    NORM(n0);
    len = LEN(v0);
    // Ищем сторону прямоугольника, которая пересекает линию, если находим - линия частично выделена
#define TEST(_x0, _y0, _x1, _y1)                            \
  do {                                                  \
    n1[0] = _x1 - _x0;                                    \
    n1[1] = _y1 - _y0;                                    \
    v1[0] = n1[0];                                      \
    v1[1] = n1[1];                                      \
    NORM(n1);                                           \
    d[0] = _x0 - l->p0[0];                               \
    d[1] = _y0 - l->p0[1];                               \
    D = -n0[0] * n1[1] + n0[1] * n1[0];                 \
    if (D <= 1e-8)                                      \
      continue;                                         \
    T = (-n1[1] * d[0] + n1[0] * d[1]) / D;             \
    S = (n0[0] * d[1] - n0[1] * d[0]) / D;              \
    if (S >= 0 && S <= LEN(v1) && T >= 0 && T <= len) { \
      return 1;                                         \
    }                                                   \
  } while (0)

    TEST(x0, y0, x1, y0);
    TEST(x1, y0, x1, y1);
    TEST(x1, y1, x0, y1);
    TEST(x0, y1, x0, y0);
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
  double v0[2];
  double n0[2], n1[2], d[2];
  double D, Dt, Ds, T, S;
  n0[0] = line->p1[0] - line->p0[0];
  n0[1] = line->p1[1] - line->p0[1];
  v0[0] = n0[0];
  v0[1] = n0[1];
  NORM(n0);
  n1[0] = n0[0];
  n1[1] = n0[1];
  PERP(n1);
  // Решаем уравнение прямых для каждого сегмена: Прямая 1 задана сегментом.
  // Прямая 2 задана точкой клика и перпендикуляром прямой 1
  // Параметр T - позиция на сегменте, Параметр S - расстояние до точки пересечения
  // n0, n1 нормализованые векторы, задающие прямые
  d[0] = x - line->p0[0];
  d[1] = y - line->p0[1];
  D = -n0[0] * n1[1] + n0[1] * n1[0];
  Dt = -n1[1] * d[0] + n1[0] * d[1];
  Ds = n0[0] * d[1] - n0[1] * d[0];
  T = Dt / D;
  S = Ds / D;
  if (T >= 0.0f && T <= LEN(v0) && fabs(S) <= w / 2) {
    if (dis)
      *dis = fabs(S);
    return 1;
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