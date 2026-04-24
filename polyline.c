#include "polyline.h"
#include "draw.h"
#include "entity.h"
#include "lb.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline void VEC(double out[2], const double a[2], const double b[2]) {
  out[0] = b[0] - a[0];
  out[1] = b[1] - a[1];
}

static inline double LEN(const double v[2]) {
  return sqrt(v[0] * v[0] + v[1] * v[1]);
}

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale) {
  struct gllc_polyline *pl = (struct gllc_polyline *)ent;
  if (!pl || !draw)
    return;

  int colorint = gllc_entity_color(ent);
  unsigned char color[4] = {RED(colorint), GREEN(colorint), BLUE(colorint), 255};
  double p0[2];
  double p1[2];
  double v0[2];
  p0[0] = pl->pts[pl->cnt - 1].p[0];
  p0[1] = pl->pts[pl->cnt - 1].p[1];
  p1[0] = pl->pts[0].p[0];
  p1[1] = pl->pts[0].p[1];
  VEC(v0, p0, p1);
  int cnt = LEN(v0) < 1e-8 ? pl->cnt - 1 : pl->cnt;
  struct lb_config lb_conf = {
      .v = pl->pts,
      .vcnt = cnt,
      .nroundsegs = 8,
      .closed = (ent->flags & GLLC_ENT_CLOSED) != 0,
      .c = color,
      .mode = LB_MODE_COMPLEX,
      .off = 0,
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
  }
  if (pl->_ent.flags & GLLC_ENT_HOVER) {
    lb_conf.lw += 3.0f;
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
  struct gllc_polyline *pl = (struct gllc_polyline *)ent;
  if (pl) {
    ds_unit_destroy(pl->u);
    free(pl->pts);
    free(pl);
  }
}

static int vertices(struct gllc_entity *ent, double scale, struct ev *ver) {
  struct gllc_polyline *pl = (struct gllc_polyline *)ent;
  if (ver) {
    memmove(ver, pl->pts, sizeof(struct ev) * pl->cnt);
  }
  return pl->cnt;
}

static int selected(struct gllc_entity *ent, int mode, double scale, double x0, double y0, double x1, double y1) {
  struct gllc_line *l = (struct gllc_line *)ent;
  double D, T, S, d[2];
  double n1[2], v1[2];
  double n0[2];
  double v0[2];
  double len;
  double bx0, by0, bx1, by1;
  ent->vtable->bbox(ent, scale, &bx0, &by0, &bx1, &by1);
  int inside = (x0 <= bx0 && x1 >= bx0 && y0 <= by0 && y1 >= by0) && (x0 <= bx1 && x1 >= bx1 && y0 <= by1 && y1 >= by1);
  if (mode == 0) {
    return inside;
  }/*  else {
   if (inside)
      return 1;
    for(int i = 0; i < cnt; i++) {
      
    }
    n0[0] = l->p1[0] - l->p0[0];
    n0[1] = l->p1[1] - l->p0[1];
    v0[0] = n0[0];
    v0[1] = n0[1];
    NORM(n0);
    len = LEN(v0);
    // Ищем сторону прямоугольника, которая пересекает линию, если находим - линия частично выделена
#define TEST(_x0, _y0, _x1, _y1)                        \
  do {                                                  \
    n1[0] = _x1 - _x0;                                  \
    n1[1] = _y1 - _y0;                                  \
    v1[0] = n1[0];                                      \
    v1[1] = n1[1];                                      \
    NORM(n1);                                           \
    d[0] = _x0 - l->p0[0];                              \
    d[1] = _y0 - l->p0[1];                              \
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
*/
  return 1;
}

static int clone(struct gllc_entity *ent, struct gllc_entity **clone) {
  if (ent->vtable->type != GLLC_ENT_POLYLINE)
    return 0;
  struct gllc_polyline *pl = (struct gllc_polyline *)ent;
  struct gllc_polyline *npl = malloc(sizeof(struct gllc_polyline));
  if (!npl)
    return 0;
  memcpy(npl, pl, sizeof(struct gllc_polyline));
  npl->u = ds_unit_clone(pl->u);
  npl->pts = malloc(pl->cap * sizeof(struct ev));
  if (!npl->pts) {
    free(npl);
    return 0;
  }
  memcpy(npl->pts, pl->pts, pl->cnt * sizeof(struct ev));
  *clone = (struct gllc_entity *)npl;
  return 1;
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

static int picked(struct gllc_entity *ent, double scale, double x, double y, double *dis) {
  struct gllc_polyline *pl = (struct gllc_polyline *)ent;
  if (pl->cnt < 2) {
    return 0;
  }
  int i;
  double w;
  if (ent->flags & GLLC_ENT_LW_THIN)
    w = 10.0f * scale;
  else if (ent->flags & GLLC_ENT_LW_SCREEN)
    w = (ent->lwidth + 10.0f) * scale;
  else
    w = ent->lwidth + (10.0f * scale);
  double p0[2], p1[2];
  double v0[2];
  double n0[2], n1[2], d[2];
  double D, Dt, Ds, T, S;
  int cnt = pl->cnt;
  if (!(ent->flags & GLLC_ENT_CLOSED))
    cnt--;
  for (i = 0; i < cnt; i++) {
    int nt = (i >= cnt - 1 && ent->flags & GLLC_ENT_CLOSED) ? 0 : i + 1;
    p0[0] = pl->pts[i].p[0];
    p0[1] = pl->pts[i].p[1];
    p1[0] = pl->pts[nt].p[0];
    p1[1] = pl->pts[nt].p[1];
    n0[0] = p1[0] - p0[0];
    n0[1] = p1[1] - p0[1];
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
    d[0] = x - p0[0];
    d[1] = y - p0[1];
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
  }
  return 0;
}

static int bbox(struct gllc_entity *ent, double scale, double *xmin, double *ymin, double *xmax, double *ymax) {
  struct gllc_polyline *pline = (struct gllc_polyline *)ent;
  double x0, y0, x1, y1;
  int i;
  if (pline->cnt == 0) {
    return 0;
  }
  x0 = pline->pts[0].p[0];
  y0 = pline->pts[0].p[1];
  x1 = pline->pts[0].p[0];
  y1 = pline->pts[0].p[1];
  for (i = 1; i < pline->cnt; i++) {
    if (x0 > pline->pts[i].p[0])
      x0 = pline->pts[i].p[0];
    if (y0 > pline->pts[i].p[1])
      y0 = pline->pts[i].p[1];
    if (x1 < pline->pts[i].p[0])
      x1 = pline->pts[i].p[0];
    if (y1 < pline->pts[i].p[1])
      y1 = pline->pts[i].p[1];
  }
  if (xmin)
    *xmin = x0;
  if (ymin)
    *ymin = y0;
  if (xmax)
    *xmax = x1;
  if (ymax)
    *ymax = y1;
  return 1;
}

static int len(struct gllc_entity *ent, double *len) {
  struct gllc_polyline *pline = (struct gllc_polyline *)ent;
  double l = 0;
  int i;
  for (i = 0; i < pline->cnt - 1; i++) {
    double dx, dy;
    dx = pline->pts[i + 1].p[0] - pline->pts[i].p[0];
    dy = pline->pts[i + 1].p[1] - pline->pts[i].p[1];
    l += sqrt(dx * dx + dy * dy);
  }
  if (ent->flags & GLLC_ENT_CLOSED) {
    double dx, dy;
    dx = pline->pts[0].p[0] - pline->pts[pline->cnt - 1].p[0];
    dy = pline->pts[0].p[1] - pline->pts[pline->cnt - 1].p[1];
    l += sqrt(dx * dx + dy * dy);
  }
  *len = l;
  return 1;
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

static struct gllc_prop pline_props[] = {
    P_END};

static struct gllc_prop *all_props[] = {G_entity_props, pline_props, NULL};

struct gllc_polyline *gllc_polyline_create(struct gllc_block *block, struct ds_draw *draw, int closed, int filled) {
  struct gllc_polyline *pl = malloc(sizeof(struct gllc_polyline));
  if (pl) {
    GLLC_ENTITY_INIT(&pl->_ent, block, all_props, &vtable);
    pl->_ent.flags |= (closed ? GLLC_ENT_CLOSED : 0) | (filled ? GLLC_ENT_FILLED : 0);
    pl->u = ds_unit_create(draw);
    pl->pts = NULL;
    pl->cnt = 0;
    pl->cap = 0;
  }
  return pl;
}

void gllc_pline_add_ver(struct gllc_polyline *pline, double x, double y) {
  if (!pline)
    return;
  if (pline->cap - pline->cnt <= 1) {
    size_t sz = pline->cap ? pline->cap * 2 : 8;
    struct ev *pts = realloc(pline->pts, sz * sizeof(struct ev));
    if (!pts)
      return;
    pline->pts = pts;
    pline->cap = sz;
  }
  pline->pts[pline->cnt].p[0] = x;
  pline->pts[pline->cnt].p[1] = y;
  pline->cnt++;
  gllc_entity_set_modified((struct gllc_entity *)pline, 1);
}