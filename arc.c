#include "arc.h"

#include <math.h>
#include <stdlib.h>

#define SEGCNT 32

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale) {
}

static void destroy(struct gllc_entity *ent) {
  struct gllc_arc *arc = (struct gllc_arc *)ent;
  if (arc) {
    ds_unit_destroy(arc->u);
    free(arc);
  }
}

static int vertices(struct gllc_entity *ent, double scale, struct ev *ver) {
  return 0;
}

static int selected(struct gllc_entity *ent, int mode, double scale, double x0, double y0, double x1, double y1) {
  return 0;
}

static int clone(struct gllc_entity *ent, struct gllc_entity **clone) {
  return 0;
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

static struct gllc_prop pline_props[] = {
    P_END};

static struct gllc_prop *all_props[] = {G_entity_props, pline_props, NULL};

struct gllc_arc *gllc_arc_create(struct gllc_block *block, struct ds_draw *draw, double x, double y, double radius, double start_angle, double arc_angle) {
  struct gllc_arc *pl = malloc(sizeof(struct gllc_arc));
  if (pl) {
    GLLC_ENTITY_INIT(&pl->_ent, block, all_props, &vtable);
    pl->_ent.flags |= 0;
    pl->u = ds_unit_create(draw);
    pl->x = x;
    pl->y = y;
    pl->radius = radius;
    pl->arc_angle = arc_angle;
    pl->start_angle = start_angle;
  }
  return pl;
}