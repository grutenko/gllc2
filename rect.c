#include "rect.h"
#include "draw.h"
#include "entity.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale) {
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

struct gllc_rect *gllc_rect_create(struct gllc_block *block, struct ds_draw *draw, double *p, double w, double h, double angle) {
  struct gllc_rect *rect = malloc(sizeof(struct gllc_rect));
  if (rect) {
    GLLC_ENTITY_INIT(rect, block, all_props, &vtable);
    rect->p0[0] = p[0];
    rect->p0[1] = p[1];
    rect->w = w;
    rect->h = h;
    rect->angle = angle;
    rect->u = ds_unit_create(draw);
  }
  return rect;
}