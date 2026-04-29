#include "layer.h"
#include <stdlib.h>
#include <string.h>

static struct gllc_prop props[] = {};
static struct gllc_prop *all_props[] = {props, G_nobject_props, NULL};

static void destroy(struct gllc_object *obj) {}

static struct gllc_object_vtable vtable = {
    .destroy = destroy};

struct gllc_layer *gllc_layer_create(struct gllc_drawing *drw, const char *name, const char *color, struct gllc_linetype *linetype, int linewidth) {
  struct gllc_layer *layer = malloc(sizeof(struct gllc_layer));
  if (layer) {
    memset(layer, 0, sizeof(struct gllc_layer));
    gllc_nobject_init((struct gllc_nobject *)layer, drw, all_props, &vtable, GLLC_OBJ_LAYER, name);
  }
  return layer;
}