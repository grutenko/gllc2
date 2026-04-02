#include "polyline.h"
#include "draw.h"
#include "entity.h"
#include "line_build.h"
#include "object.h"

#include <stdlib.h>

static void build(struct gllc_entity *ent, struct ds_draw *draw, GLfloat scale) {
  struct gllc_polyline *pline = (struct gllc_polyline *)ent;
  if (pline->cnt < 2) {
    return;
  }
  if (!pline->unit) {
    pline->unit = ds_unit_create(draw);
  }
  struct lb lb;
  lb.in.closed = (ent->flags & GLLC_ENT_CLOSED) != 0;
  int color = gllc_entity_color(ent);
  lb.in.color[0] = GLLC_COLOR_RED(color) / 255.0f;
  lb.in.color[1] = GLLC_COLOR_GREEN(color) / 255.0f;
  lb.in.color[2] = GLLC_COLOR_BLUE(color) / 255.0f;
  lb.in.color[3] = ent->falpha;
  lb.in.ver_cnt = pline->cnt;
  lb.in.ver = pline->pts;
  lb.in.weight = 1.0f;
  // Считаем приблизительные значения которые немного больше чем реальные
  // Получается небольшой перерасход по памяти, возможно в будущем исправлю
  lb_stats(&lb);
  struct ds_vertex *ver_ptr = ds_unit_reserve_vertex(pline->unit, lb.out.ver_cnt);
  GLuint *ind_ptr = ds_unit_reserve_index(pline->unit, lb.out.ind_cnt);
  lb.out.ver_ptr = ver_ptr;
  lb.out.ind_ptr = ind_ptr;
  lb_build(&lb);
  // Записываем актуальные после билда
  pline->unit->V_cnt = lb.out.ver_cnt;
  pline->unit->I_cnt = lb.out.ver_cnt;
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

static int vertices(struct gllc_entity *ent, double scale, double *out) {}

static int selected(struct gllc_entity *ent, double scale, double x1, double y1, double x2, double y2) {
  return 0;
}

static int picked(struct gllc_entity *ent, double scale, double x, double y) {
  return 0;
}

static int bbox(struct gllc_entity *ent, double scale, double *xmin, double *ymin, double *xmax, double *ymax) {
  return 0;
}

static struct gllc_entity_vtable vtable = {
    .type = GLLC_ENT_POLYLINE,
    .build = build,
    .destroy = destroy,
    .vertices = vertices,
    .selected = selected,
    .picked = picked,
    .bbox = bbox,
};

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
      double *new_pts = realloc(pline->pts, new_cap * 2 * sizeof(double));
      if (!new_pts)
        return;
      pline->pts = new_pts;
      pline->cap = new_cap;
    }

    pline->pts[pline->cnt * 2] = x;
    pline->pts[pline->cnt * 2 + 1] = y;
    pline->cnt++;
    pline->_ent.flags |= GLLC_ENT_MODIFIED | GLLC_ENT_GEOMETRY_MODIFIED;
  }
}