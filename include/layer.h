#ifndef layer_h
#define layer_h

#include "entity.h"
#include "named_object.h"

struct gllc_drawing;
struct gllc_linetype;

#define GLLC_LAYER_VISIBLE 0x1
#define GLLC_LAYER_LOCKED 0x2
#define GLLC_LAYER_0 0x4
#define GLLC_LAYER_NOPRINT 0x8
#define GLLC_LAYER_NODLG 0x10

struct gllc_layer
{
        struct gllc_nobject _nobj;
        int flags;
        struct gllc_entity_props props;
        struct gllc_entity **ents;
        int entcnt;
        int entcap;
};

struct gllc_layer *gllc_layer_create(struct gllc_drawing *drw, const char *name, const char *color, struct gllc_linetype *linetype, int linewidth);
void gllc_layer_set_entity(struct gllc_layer *layer, struct gllc_entity *ent);
void gllc_layer_unset_entity(struct gllc_layer *layer, struct gllc_entity *ent);
char *gllc_layer_get_color(struct gllc_layer *layer);
int gllc_layer_set_color(struct gllc_layer *layer);
int gllc_layer_get_colori(struct gllc_layer *layer);
int gllc_layer_color_is_index(struct gllc_layer *layer);
int gllc_layer_get_colort(struct gllc_layer *layer);
int gllc_layer_color_is_true(struct gllc_layer *layer);


#endif