#include "polyline.h"
#include "draw.h"
#include "entbuildutil.h"
#include "entity.h"
#include "linalg.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale) {
  int cnt;
  struct gllc_polyline *pl = (struct gllc_polyline *)ent;
  ds_unit_reset(pl->u);
  if (ent->flags & GLLC_ENT_CLOSED) {
    double v0[2];
    VEC(v0, pl->pts[pl->cnt - 1].p, pl->pts[0].p);
    if (LEN(v0) < 1e-8) {
      cnt = pl->cnt - 1;
    } else {
      cnt = pl->cnt;
    }
    if (ent->flags & GLLC_ENT_FILLED) {
      build_filltess(ent, pl->u, pl->pts, cnt);
    }
  } else {
    cnt = pl->cnt;
  }
  build_contur(ent, pl->u, pl->pts, cnt);
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
  struct gllc_polyline *pl = (struct gllc_polyline *)ent;
  double bx0, by0, bx1, by1;
  ent->vtable->bbox(ent, scale, &bx0, &by0, &bx1, &by1);
  int inside = (x0 <= bx0 && x1 >= bx0 && y0 <= by0 && y1 >= by0) && (x0 <= bx1 && x1 >= bx1 && y0 <= by1 && y1 >= by1);
  if (mode == 0) {
    return inside;
  } else {
    if (inside)
      return 1;
    for (int i = 0; i < pl->cnt; i++) {
      int ni;
      if (ent->flags & GLLC_ENT_CLOSED) {
        ni = (i + 1) % pl->cnt;
      } else if (i < pl->cnt - 1) {
        ni = i + 1;
      } else {
        break;
      }
#define TEST(_x0, _y0, _x1, _y1)                            \
  do {                                                      \
    double T, S;                                            \
    double n0[2], n1[2], v0[2], v1[2];                      \
    double p0[2], p1[2], p2[2], p3[2];                      \
    p0[0] = _x0;                                            \
    p0[1] = _y0;                                            \
    p1[0] = _x1;                                            \
    p1[1] = _y1;                                            \
    p2[0] = pl->pts[i].p[0];                                \
    p2[1] = pl->pts[i].p[0];                                \
    p3[0] = pl->pts[ni].p[0];                               \
    p3[1] = pl->pts[ni].p[0];                               \
    VEC(v0, p0, p1);                                        \
    NORMTO(v0, n0);                                         \
    VEC(v1, p2, p3);                                        \
    NORMTO(v1, n1);                                         \
    RAYINSECT(p0, n0, p2, n1, &T, &S);                      \
    if (S >= 0 && S <= LEN(v1) && T >= 0 && T <= LEN(v0)) { \
      return 1;                                             \
    }                                                       \
  } while (0)

      TEST(x0, y0, x1, y0);
      TEST(x1, y0, x1, y1);
      TEST(x1, y1, x0, y1);
      TEST(x0, y1, x0, y0);
    }
  }
  return 0;
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
  double v[2];
  double l = 0;
  int i;
  for (i = 0; i < pline->cnt - 1; i++) {
    VEC(v, pline->pts[i].p, pline->pts[i + 1].p);
    l += LEN(v);
  }
  if (ent->flags & GLLC_ENT_CLOSED) {
    VEC(v, pline->pts[pline->cnt - 1].p, pline->pts[0].p);
    l += LEN(v);
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

void gllc_pline_end(struct gllc_polyline *pline) {
}

int gllc_pline_fit_type(struct gllc_polyline *pline) {
  return 0;
}

int gllc_pline_nvers(struct gllc_polyline *pline) {
  return pline->cnt;
}

float gllc_pline_width(struct gllc_polyline *pline) {
  return 0.0f;
}

int gllc_pline_width_bool(struct gllc_polyline *pline) {
  return 0;
}

float gllc_pline_radius(struct gllc_polyline *pline) {
  return 0.0f;
}

int gllc_pline_radius_bool(struct gllc_polyline *pline) {
  return 0;
}

int gllc_pline_set_width(struct gllc_polyline *pline, float width) {
  return 1;
}

int gllc_pline_set_width_bool(struct gllc_polyline *pline, int width) {
  return 1;
}

int gllc_pline_set_radius(struct gllc_polyline *pline, float radius) {
  return 0;
}

int gllc_pline_set_radius_bool(struct gllc_polyline *pline, int radius) {
  return 0;
}

int gllc_pline_chamfer(struct gllc_polyline *pline) {
  return 0;
}

int gllc_pline_set_chamfer(struct gllc_polyline *pline, int chamfer) {
  return 0;
}

double gllc_pline_area(struct gllc_polyline *pline) {
  return 0.0f;
}

int gllc_pline_cw(struct gllc_polyline *pline) {
  return 0;
}

int gllc_pline_ccw(struct gllc_polyline *pline) {
  return 0;
}

int gllc_pline_hasang0(struct gllc_polyline *pline) {
  return 0;
}

int gllc_pline_set_hasang0(struct gllc_polyline *pline, int hasang2) {
  return 0;
}

int gllc_pline_hasang2(struct gllc_polyline *pline) {
  return 0;
}

int gllc_pline_set_hasang2(struct gllc_polyline *pline, int hasang2) {
  return 0;
}

double gllc_pline_ang0(struct gllc_polyline *pline) {
  return 0;
}

int gllc_pline_set_ang0(struct gllc_polyline *pline, double ang2) {
  return 0;
}

double gllc_pline_ang2(struct gllc_polyline *pline) {
  return 0;
}

int gllc_pline_set_ang2(struct gllc_polyline *pline, double ang2) {
  return 0;
}