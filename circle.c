#include "circle.h"
#include "draw.h"
#include "entity.h"

#include <stdlib.h>

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale) {
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

static int selected(struct gllc_entity *ent, int mode, double scale, double x0, double y0, double x1, double y1) {
  return 0;
}

static int clone(struct gllc_entity *ent, struct gllc_entity **clone) {
  return 1;
}

static int picked(struct gllc_entity *ent, double scale, double x, double y, double *dis) {
  return 0;
}

static int bbox(struct gllc_entity *ent, double scale, double *xmin, double *ymin, double *xmax, double *ymax) {
  return 0;
}

static int len(struct gllc_entity *ent, double *len) {
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