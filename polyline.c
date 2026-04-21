#include "polyline.h"
#include "draw.h"
#include "entity.h"
#include "lb.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale) {
  struct gllc_polyline *pl = (struct gllc_polyline *)ent;
  if (!pl || !draw)
    return;

  unsigned char color[4] = {GLLC_COLOR_RED(ent->props.color), GLLC_COLOR_GREEN(ent->props.color), GLLC_COLOR_BLUE(ent->props.color), 255};
  struct lb_config lb_conf = {
      .v = pl->pts,
      .vcnt = pl->cnt,
      .lw = ent->flags & GLLC_ENT_LW_SCREEN ? ent->lwidth : 1.0f,
      .lrealw = ent->flags & GLLC_ENT_LW_REAL ? ent->lwidth : 0.0001f,
      .nroundsegs = 8,
      .closed = (ent->flags & GLLC_ENT_CLOSED) != 0,
      .c = color,
      .mode = LB_MODE_COMPLEX,
      .off = 0,
  };
  int vcnt, icnt;
  // первый вызов для получения количества вершин и индексов
  lb_build(&lb_conf, NULL, NULL, &vcnt, &icnt);
  struct ds_vertex *V = ds_unit_reserve_vertex(pl->unit, vcnt);
  GLuint *I = ds_unit_reserve_index(pl->unit, icnt);
  if  (pl->_ent.flags & GLLC_ENT_HOVER) {
    pl->unit->flags = DS_UNIT_CHESS;
  } else {
    pl->unit->flags = 0;
  }
  if (V && I) {
    lb_build(&lb_conf, V, I, &vcnt, &icnt);
  }
}

static void destroy(struct gllc_entity *ent) {
  struct gllc_polyline *pl = (struct gllc_polyline *)ent;
  if (pl) {
    ds_unit_destroy(pl->unit);
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
  struct gllc_polyline *pl = (struct gllc_polyline *)ent;
  if (mode == 0) {
    int i;
    for (i = 0; i < pl->cnt; i++) {
      double x = pl->pts[i].p[0];
      double y = pl->pts[i].p[1];
      if (x < x0 || x > x1 || y < y0 || y > y1)
        return 0;
    }
    return 1;
  } else {
  }
  return 1;
}

static int clone(struct gllc_entity *ent, struct gllc_entity **clone) {
  if (ent->vtable->type != GLLC_ENT_POLYLINE)
    return 0;
  struct gllc_polyline *pl = (struct gllc_polyline *)ent;
  struct gllc_polyline *npl = malloc(sizeof(struct gllc_polyline));
  if (!npl)
    return 0;
  npl->unit = ds_unit_clone(pl->unit);
  memcpy(npl, pl, sizeof(struct gllc_polyline));
  npl->pts = malloc(pl->cap * sizeof(struct ev));
  if (!npl->pts) {
    free(npl);
    return 0;
  }
  memcpy(npl->pts, pl->pts, pl->cnt * sizeof(struct ev));
  *clone = (struct gllc_entity *)npl;
  return 1;
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

static int picked(struct gllc_entity *ent, double scale, double x, double y, double *dis) {
  struct gllc_polyline *pl = (struct gllc_polyline *)ent;
  if (pl->cnt < 2) {
    return 0;
  }
  int cnt = 0;
  int i;
  if (ent->flags & GLLC_ENT_CLOSED && pl->cnt > 2) {
    for (i = 0; i < pl->cnt; i++) {
      int ni = i < pl->cnt - 1 ? i + 1 : 0;
      double x1 = pl->pts[i].p[0];
      double y1 = pl->pts[i].p[1];
      double x2 = pl->pts[ni].p[0];
      double y2 = pl->pts[ni].p[1];
      if ((y1 > y) != (y2 > y)) {
        double xint = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
        if (xint > x)
          cnt++;
      }
    }
    if (dis)
      *dis = 0.0f;
    return (cnt & 1) == 1;
  } else {
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
    for (i = 0; i < pl->cnt - 1; i++) {
      p0[0] = pl->pts[i].p[0];
      p0[1] = pl->pts[i].p[1];
      p1[0] = pl->pts[i + 1].p[0];
      p1[1] = pl->pts[i + 1].p[1];
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
    pl->unit = ds_unit_create(draw);
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