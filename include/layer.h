#ifndef layer_h
#define layer_h

#include "entity.h"
#include "named_object.h"

struct gllc_drawing;
struct gllc_linetype;

struct gllc_layer
{
        struct gllc_nobject _nobj;
        struct gllc_entity_props props;
        struct gllc_entity **ents;
        int entcnt;
        int entcap;
};

struct gllc_layer *gllc_layer_create(struct gllc_drawing *drw, const char *name, const char *color, struct gllc_linetype *linetype, int linewidth);
void gllc_layer_set_entity(struct gllc_layer *layer, struct gllc_entity *ent);
void gllc_layer_unset_entity(struct gllc_layer *layer, struct gllc_entity *ent);

#endif