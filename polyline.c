#include "polyline.h"
#include "draw.h"
#include "entity.h"
#include "line_build.h"
#include "object.h"
#include "tess2/tess2.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static GLfloat *vt = NULL;
static GLuint vtcap = 0;

void gllc_polyline_cleanup() {
  free(vt);
  vt = NULL;
  vtcap = 0;
}

static void build_soft(struct gllc_entity *ent, struct ds_draw *draw, GLfloat scale) {
  int color;
  int i;
  uint8_t c[4];

  struct gllc_polyline *pline = (struct gllc_polyline *)ent;
  if (!pline->unit)
    return;

  color = gllc_entity_fcolor(ent);
  c[0] = GLLC_COLOR_RED(color);
  c[1] = GLLC_COLOR_GREEN(color);
  c[2] = GLLC_COLOR_BLUE(color);
  c[3] = (uint8_t)(pline->_ent.falpha * 255.0f);

  for (i = 0; i < pline->fill_vcnt; i++) {
    pline->unit->V[i].c[0] = c[0];
    pline->unit->V[i].c[1] = c[1];
    pline->unit->V[i].c[2] = c[2];
    pline->unit->V[i].c[3] = c[3];
  }

  if (pline->_ent.flags & GLLC_ENT_HOVER) {
    pline->unit->flags |= DS_UNIT_CHESS;
  } else {
    pline->unit->flags &= ~DS_UNIT_CHESS;
  }

  color = gllc_entity_color(ent);
  c[0] = GLLC_COLOR_RED(color);
  c[1] = GLLC_COLOR_GREEN(color);
  c[2] = GLLC_COLOR_BLUE(color);
  c[3] = 255;

  for (i = pline->fill_vcnt; i < pline->unit->V_cnt; i++) {
    pline->unit->V[i].c[0] = c[0];
    pline->unit->V[i].c[1] = c[1];
    pline->unit->V[i].c[2] = c[2];
    pline->unit->V[i].c[3] = c[3];
  }

  pline->unit->dirty = 1;
  pline->unit->draw->dirty = 1;
}

static void build_all(struct gllc_entity *ent, struct ds_draw *draw, GLfloat scale) {
  int color;
  int i;
  uint8_t c[4];
  int vtotal = 0;
  int itotal = 0;
  TESStesselator *tess;

  struct gllc_polyline *pline = (struct gllc_polyline *)ent;
  if (!pline->unit)
    return;

  if (pline->_ent.flags & GLLC_ENT_HOVER) {
    pline->unit->flags |= DS_UNIT_CHESS;
  } else {
    pline->unit->flags &= ~DS_UNIT_CHESS;
  }
  color = gllc_entity_fcolor(ent);
  c[0] = GLLC_COLOR_RED(color);
  c[1] = GLLC_COLOR_GREEN(color);
  c[2] = GLLC_COLOR_BLUE(color);
  c[3] = (uint8_t)(pline->_ent.falpha * 255.0f);

  if (ent->flags & GLLC_ENT_CLOSED && ent->flags & GLLC_ENT_FILLED) {
    if (vtcap < pline->cnt) {
      GLfloat *nvt = realloc(vt, sizeof(GLfloat) * 2 * pline->cnt);
      if (!nvt) {
        return;
      }
      vt = nvt;
      vtcap = pline->cnt;
    }
    int i;
    for (i = 0; i < pline->cnt; i++) {
      vt[i * 2] = (GLfloat)pline->pts[i].p[0];
      vt[i * 2 + 1] = (GLfloat)pline->pts[i].p[1];
    }
    tess = tessNewTess(NULL);
    if (tess) {
      tessAddContour(tess, 2, vt, sizeof(GLfloat) * 2, pline->cnt);
      if (tessTesselate(tess, TESS_WINDING_POSITIVE, TESS_POLYGONS, 3, 2, NULL)) {
        const float *verts = tessGetVertices(tess);
        int vert_count = tessGetVertexCount(tess);
        int indices_count = tessGetElementCount(tess);
        const int *indices = tessGetElements(tess);
        vtotal += vert_count;
        itotal += indices_count * 3;
        struct ds_vertex *ver_ptr = ds_unit_reserve_vertex(pline->unit, vtotal);
        GLuint *ind_ptr = ds_unit_reserve_index(pline->unit, itotal);
        int i;
        for (i = 0; i < vtotal; i++) {
          ver_ptr[i].p[0] = verts[i * 2];
          ver_ptr[i].p[1] = verts[i * 2 + 1];
          ver_ptr[i].n[0] = 127;
          ver_ptr[i].n[1] = 127;
          ver_ptr[i].c[0] = c[0];
          ver_ptr[i].c[1] = c[1];
          ver_ptr[i].c[2] = c[2];
          ver_ptr[i].c[3] = c[3];
          ver_ptr[i].uv[0] = 0;
          ver_ptr[i].uv[1] = 1;
          ver_ptr[i].thickness = 0.0f;
        }
        for (i = 0; i < itotal; i++) {
          ind_ptr[i] = (GLuint)indices[i];
        }
      }
      tessDeleteTess(tess);
    }
  }
  pline->fill_vcnt = vtotal;
  struct lb lb;
  lb_init(&lb);
  lb.in.closed = (ent->flags & GLLC_ENT_CLOSED) != 0;
  color = gllc_entity_color(ent);
  lb.in.color[0] = GLLC_COLOR_RED(color) / 255.0f;
  lb.in.color[1] = GLLC_COLOR_GREEN(color) / 255.0f;
  lb.in.color[2] = GLLC_COLOR_BLUE(color) / 255.0f;
  lb.in.color[3] = 1.0f;
  lb.in.ioffset = vtotal;
  lb.in.ver_cnt = pline->cnt;
  lb.in.ver = pline->pts;
  if (pline->_ent.flags & GLLC_ENT_LW_REAL) {
    lb.in.weight = pline->_ent.lwidth;
    lb.in.screenweight = 1.0f;
  } else if (pline->_ent.flags & GLLC_ENT_LW_SCREEN) {
    lb.in.weight = 0.001f;
    lb.in.screenweight = pline->_ent.lwidth;
  } else {
    lb.in.weight = 0.001f;
    lb.in.screenweight = 1.0f;
  }
  // Считаем приблизительные значения которые немного больше чем реальные
  // Получается небольшой перерасход по памяти, возможно в будущем исправлю
  lb_stats_miter(&lb);
  struct ds_vertex *ver_ptr = ds_unit_reserve_vertex(pline->unit, vtotal + lb.out.ver_cnt);
  GLuint *ind_ptr = ds_unit_reserve_index(pline->unit, itotal + lb.out.ind_cnt);
  lb.out.ver_ptr = &ver_ptr[vtotal];
  lb.out.ind_ptr = &ind_ptr[itotal];
  lb_build_miter(&lb);
  vtotal += lb.out.ver_cnt;
  itotal += lb.out.ind_cnt;
  // Записываем актуальные после билда
  pline->unit->V_cnt = vtotal;
  pline->unit->I_cnt = itotal;
  pline->unit->dirty = 1;
  pline->unit->draw->dirty = 1;
  pline->unit->geometry_dirty = 1;
  pline->unit->draw->geometry_dirty = 1;
}

static void build(struct gllc_entity *ent, struct ds_draw *draw, GLfloat scale) {
  struct gllc_polyline *pline = (struct gllc_polyline *)ent;
  if (pline->cnt < 2)
    return;

  if (!pline->unit)
    pline->unit = ds_unit_create(draw);

  if (ent->flags & GLLC_ENT_GEOMETRY_MODIFIED) {
    build_all(ent, draw, scale);
  } else {
    build_soft(ent, draw, scale);
  }
}

static void destroy(struct gllc_entity *ent) {
  struct gllc_polyline *pline = (struct gllc_polyline *)ent;
  free(pline->pts);
  pline->pts = NULL;
  pline->cnt = 0;
  if (pline->unit) {
    ds_unit_destroy(pline->unit);
    pline->unit = NULL;
  }
}

static int vertices(struct gllc_entity *ent, double scale, double *out) {
  return 0;
}

static int selected(struct gllc_entity *ent, double scale, double x1, double y1, double x2, double y2) {
  return 0;
}

static int picked(struct gllc_entity *ent, double scale, double x, double y) {
  struct gllc_polyline *pl = (struct gllc_polyline *)ent;

  int cnt = 0;
  int i;
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
  return cnt % 2 == 1;
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
  double dx, dy;
  double l = 0;
  int i;
  for (i = 0; i < pline->cnt - 1; i++) {
    dx = pline->pts[i + 1].p[0] - pline->pts[i].p[0];
    dy = pline->pts[i + 1].p[1] - pline->pts[i].p[1];
    l += sqrt(dx * dx + dy * dy);
  }
  if (ent->flags & GLLC_ENT_CLOSED) {
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
    .len = len};

static struct gllc_prop pline_props[] = {P_END};

static struct gllc_prop *all_props[] = {G_entity_props, pline_props, NULL};

struct gllc_polyline *gllc_polyline_create(struct gllc_block *block, int closed, int filled) {
  struct gllc_polyline *pl = malloc(sizeof(struct gllc_polyline));
  if (pl) {
    GLLC_ENTITY_INIT(&pl->_ent, block, all_props, &vtable);
    pl->_ent.flags |= (closed ? GLLC_ENT_CLOSED : 0) | (filled ? GLLC_ENT_FILLED : 0);
    pl->pts = NULL;
    pl->cnt = 0;
    pl->cap = 0;
    pl->unit = NULL;
  }
  return pl;
}

void gllc_pline_add_ver(struct gllc_polyline *pline, double x, double y) {
  if (pline) {
    if (pline->cap - pline->cnt <= 1) {
      size_t new_cap = pline->cap ? pline->cap * 2 : 8;
      struct ev *new_pts = realloc(pline->pts, new_cap * sizeof(struct ev));
      if (!new_pts)
        return;
      pline->pts = new_pts;
      pline->cap = new_cap;
    }
    pline->pts[pline->cnt].p[0] = x;
    pline->pts[pline->cnt].p[1] = y;
    pline->cnt++;
    pline->_ent.flags |= GLLC_ENT_MODIFIED | GLLC_ENT_GEOMETRY_MODIFIED;
  }
}