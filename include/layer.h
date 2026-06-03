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

struct gllc_layer *gllc_layer_create(struct gllc_drawing *drw, const char *name, const char *color,
                                     struct gllc_linetype *linetype, int linewidth);
void gllc_layer_set_entity(struct gllc_layer *layer, struct gllc_entity *ent);
void gllc_layer_unset_entity(struct gllc_layer *layer, struct gllc_entity *ent);
char *gllc_layer_get_color_string(struct gllc_layer *layer);
color_t gllc_layer_get_color(struct gllc_layer *layer);
color_t gllc_layer_get_fcolor(struct gllc_layer *layer);
int gllc_layer_set_color(struct gllc_layer *layer, color_t color);
int gllc_layer_get_colori(struct gllc_layer *layer);
int gllc_layer_set_colori(struct gllc_layer *layer, int index);
int gllc_layer_color_is_index(struct gllc_layer *layer);
color_t gllc_layer_get_colort(struct gllc_layer *layer);
int gllc_layer_color_is_true(struct gllc_layer *layer);
int gllc_layer_locked(struct gllc_layer *layer);
int gllc_layer_set_locked(struct gllc_layer *layer, int locked);
color_t gllc_layer_color(struct gllc_layer *layer);
int gllc_layer_set_color(struct gllc_layer *layer, color_t color);
int gllc_layer_set_color_string(struct gllc_layer *layer, char *color);
int gllc_layer_set_colort(struct gllc_layer *layer, color_t color);
color_t gllc_layer_get_fcolor(struct gllc_layer *layer);
int gllc_layer_set_fcolor(struct gllc_layer *layer, color_t color);
int gllc_layer_get_fcolori(struct gllc_layer *layer);
int gllc_layer_set_fcolori(struct gllc_layer *layer, int index);
int gllc_layer_get_fcolort(struct gllc_layer *layer);
int gllc_layer_set_fcolort(struct gllc_layer *layer, color_t color);
int gllc_layer_set_fcolor_string(struct gllc_layer *layer, char *color);
char *gllc_layer_get_fcolor_string(struct gllc_layer *layer);
int gllc_layer_fcolor_is_index(struct gllc_layer *layer);
int gllc_layer_fcolor_is_true(struct gllc_layer *layer);
int gllc_layer_get_lwidth(struct gllc_layer *layer);
int gllc_layer_set_lwidth(struct gllc_layer *layer, int lwidth);
struct gllc_linetype *gllc_layer_linetype(struct gllc_layer *layer);
int gllc_layer_set_linetype(struct gllc_layer *layer, struct gllc_linetype *linetype);
int gllc_layer_noprint(struct gllc_layer *layer);
int gllc_layer_set_noprint(struct gllc_layer *layer, int noprint);
int gllc_layer_visible(struct gllc_layer *layer);
int gllc_layer_set_visible(struct gllc_layer *layer, int visible);
int gllc_layer_nodlg(struct gllc_layer *layer);
int gllc_layer_set_nodlg(struct gllc_layer *layer, int nodlg);
int gllc_layer_is0(struct gllc_layer *layer);
int gllc_layer_set_is0(struct gllc_layer *layer, int is0);
char *gllc_layer_get_name(struct gllc_layer *layer);
char *gllc_layer_get_description(struct gllc_layer *layer);
int gllc_layer_set_name(struct gllc_layer *layer, const char *name);
int gllc_layer_set_description(struct gllc_layer *layer, const char *description);

#endif // layer_h