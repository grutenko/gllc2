#include "rect.h"
#include "draw.h"
#include "entbuildutil.h"
#include "entity.h"
#include "linalg.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define RECT(o) ((struct gllc_rect *)(o))

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale) {
  static struct ev pts[5];
  double n0[2], n1[2];
  if (RECT(ent)->w < 1e-8 || RECT(ent)->h < 1e-8) {
    return;
  }
  n0[0] = RECT(ent)->w / 2;
  n0[1] = RECT(ent)->h / 2;
  double len = LEN(n0);
  NORM(n0);
  ROT(n0, RECT(ent)->angle);
  n1[0] = -n0[0];
  n1[1] = n0[1];
  ADDSCALETO(RECT(ent)->p0, n0, len, pts[0].p);
  ADDSCALETO(RECT(ent)->p0, n1, len, pts[1].p);
  INV(n0);
  INV(n1);
  ADDSCALETO(RECT(ent)->p0, n0, len, pts[2].p);
  ADDSCALETO(RECT(ent)->p0, n1, len, pts[3].p);
  COPY(pts[4].p, pts[0].p);
  if (gllc_entity_geometry_modified(ent)) {
    ds_unit_reset(RECT(ent)->u);
  }
  build_contur(ent, RECT(ent)->u, pts, 5, 0);
}

static void destroy(struct gllc_entity *ent) {
  struct gllc_rect *rect = (struct gllc_rect *)ent;
  if (rect) {
    ds_unit_destroy(rect->u);
    free(rect);
  }
}

static int vertices(struct gllc_entity *ent, double scale, struct ev *ver) {
  return 0;
}

static int selected(struct gllc_entity *ent, int mode, double scale, double x0, double y0, double x1, double y1) {
  return 0;
}

static int clone(struct gllc_entity *ent, struct gllc_entity **clone) {
  if (ent->vtable->type != GLLC_ENT_RECT)
    return 0;
  struct gllc_rect *r = (struct gllc_rect *)ent;
  struct gllc_rect *nr = malloc(sizeof(struct gllc_rect));
  if (!nr)
    return 0;
  memcpy(nr, r, sizeof(struct gllc_rect));
  nr->u = ds_unit_clone(r->u);
  *clone = (struct gllc_entity *)nr;
  return 1;
}

static int picked(struct gllc_entity *ent, double scale, double x, double y, double *dis) {
  return 0;
}

static int bbox(struct gllc_entity *ent, double scale, double *xmin, double *ymin, double *xmax, double *ymax) {
  return 1;
}

static int len(struct gllc_entity *ent, double *len) {
  return 1;
}

static struct gllc_entity_vtable vtable = {
    .type = GLLC_ENT_RECT,
    .build = build,
    .destroy = destroy,
    .vertices = vertices,
    .selected = selected,
    .picked = picked,
    .bbox = bbox,
    .len = len,
    .clone = clone};

static struct gllc_prop rect_props[] = {
    P_END};

static struct gllc_prop *all_props[] = {G_entity_props, rect_props, NULL};

struct gllc_rect *gllc_rect_create(struct gllc_block *block, struct ds_draw *draw, double *p, double w, double h, double angle, int filled) {
  struct gllc_rect *rect = malloc(sizeof(struct gllc_rect));
  if (rect) {
    GLLC_ENTITY_INIT(rect, block, all_props, &vtable);
    rect->_ent.flags |= filled ? GLLC_ENT_FILLED : 0;
    rect->p0[0] = p[0];
    rect->p0[1] = p[1];
    rect->w = w;
    rect->h = h;
    rect->angle = angle;
    rect->u = ds_unit_create(draw);
  }
  return rect;
}