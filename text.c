#include "text.h"
#include <stdlib.h>
#include <string.h>

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale) {
}

static void destroy(struct gllc_entity *ent) {
  struct gllc_text *pl = (struct gllc_text *)ent;
  if (pl) {
    ds_unit_destroy(pl->u);
    free(pl->text);
    free(pl);
  }
}

static int vertices(struct gllc_entity *ent, double scale, struct ev *ver) {
  return 0;
}

static int selected(struct gllc_entity *ent, int mode, double scale, double x0, double y0, double x1, double y1) {
  return 0;
}

static int clone(struct gllc_entity *ent, struct gllc_entity **clone) {
  if (ent->vtable->type != GLLC_ENT_TEXT)
    return 0;
  struct gllc_text *t = (struct gllc_text *)ent;
  struct gllc_text *nt = malloc(sizeof(struct gllc_text));
  if (!nt)
    return 0;
  memcpy(nt, t, sizeof(struct gllc_text));
  nt->u = ds_unit_clone(t->u);
  nt->text = malloc(strlen(t->text));
  if (!nt->text) {
    free(nt);
    return 0;
  }
  memcpy(nt->text, t->text, strlen(t->text) + 1);
  *clone = (struct gllc_entity *)nt;
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
    .type = GLLC_ENT_POLYLINE,
    .build = build,
    .destroy = destroy,
    .vertices = vertices,
    .selected = selected,
    .picked = picked,
    .bbox = bbox,
    .len = len,
    .clone = clone};

static struct gllc_prop text_props[] = {
    P_END};

static struct gllc_prop *all_props[] = {G_entity_props, text_props, NULL};

struct gllc_text *gllc_text_create(struct gllc_block *block, struct ds_draw *draw, char *text, double x, double y) {
  struct gllc_text *pl = malloc(sizeof(struct gllc_text));
  if (pl) {
    GLLC_ENTITY_INIT(&pl->_ent, block, all_props, &vtable);
    pl->_ent.flags |= GLLC_ENT_FILLED;
    pl->u = ds_unit_create(draw);
    pl->text = malloc(strlen(text) + 1);
    if (pl->text) {
      strcpy(pl->text, text);
    }
    pl->x = x;
    pl->y = y;
  }
  return pl;
}