#ifndef entity_h
#define entity_h

#include "color.h"
#include "entity_vertex.h"

#if defined(_WIN32)
#include "glad.h"
#elif defined(__linux__)
#include <epoxy/gl.h>
#endif
#include "object.h"

struct gllc_block;
struct gllc_layer;
struct ds_draw;
struct gllc_linetype;

#define GLLC_ENT_POLYLINE 0x1
#define GLLC_ENT_TEXT 0x2
#define GLLC_ENT_POINT 0x3
#define GLLC_ENT_RECT 0x4
#define GLLC_ENT_CIRCLE 0x5
#define GLLC_ENT_LINE 0x6
#define GLLC_ENT_ARC 0x7

struct gllc_entity;

#define GLLC_ENT_CLOSED 0x1
#define GLLC_ENT_FILLED 0x2
#define GLLC_ENT_MODIFIED 0x4
#define GLLC_ENT_LOCKED 0x8
#define GLLC_ENT_HIDDEN 0x10
#define GLLC_ENT_INITIAL 0x20
#define GLLC_ENT_SELECTED 0x40
#define GLLC_ENT_GEOMETRY_MODIFIED 0x80
#define GLLC_ENT_LW_REAL 0x100
#define GLLC_ENT_LW_THIN 0x200
#define GLLC_ENT_LW_SCREEN 0x400
#define GLLC_ENT_COLOR_BY_LAYER 0x800
#define GLLC_ENT_COLOR_BY_BLOCK 0x1000
#define GLLC_ENT_FCOLOR_BY_LAYER 0x2000
#define GLLC_ENT_FCOLOR_BY_BLOCK 0x4000
#define GLLC_ENT_HOVER 0x8000
#define GLLC_ENT_FILTER 0x10000

struct gllc_entity_vtable
{
        int type;
        void (*build)(struct gllc_entity *, struct ds_draw *, double scale);
        void (*destroy)(struct gllc_entity *);
        int (*vertices)(struct gllc_entity *, double, struct ev *);
        int (*selected)(struct gllc_entity *, int, double, double, double, double, double);
        int (*picked)(struct gllc_entity *, double, double, double, double *);
        int (*bbox)(struct gllc_entity *, double, double *, double *, double *, double *);
        int (*len)(struct gllc_entity *, double *);
        int (*clone)(struct gllc_entity *, struct gllc_entity **);
};

struct gllc_entity_props
{
        color_t color;
        color_t fcolor;
        char cstrbuffer[12];
        float ltscale;
        float falpha;
        float alpha;
        float lwidth;
        struct gllc_linetype *linetype;
};

struct gllc_entity
{
        struct gllc_object _obj;
        int flags;
        int order;
        int offset;
        uint32_t ID;
        uint32_t key;
        char ID_hex[9];
        double bbox[4];
        struct gllc_entity_props props;
        struct gllc_entity_vtable *vtable;
        struct gllc_block *block;
        struct gllc_layer *layer;
        struct gllc_entity *prev;
        struct gllc_entity *next;
};

extern struct gllc_prop G_entity_props[];
extern struct gllc_object_vtable G_entity_obj_vtable;

void _gllc_entity_init(struct gllc_entity *ent, struct gllc_block *block, struct gllc_prop **props,
                       struct gllc_entity_vtable *vtable);

#define GLLC_ENTITY_INIT(E, BLOCK, PROPS, VTABLE)                                                                      \
        _gllc_entity_init((struct gllc_entity *)(E), (BLOCK), (PROPS), (VTABLE))

uint32_t gllc_entity_get_id(struct gllc_entity *ent);
char *gllc_entity_get_id_string(struct gllc_entity *ent);
uint32_t gllc_entity_get_key(struct gllc_entity *ent);
int gllc_entity_set_key(struct gllc_entity *ent, uint32_t key);
color_t gllc_entity_color(struct gllc_entity *ent);
color_t gllc_entity_fcolor(struct gllc_entity *ent);
char *gllc_entity_color_string(struct gllc_entity *ent);
int gllc_entity_color_by_layer(struct gllc_entity *ent);
int gllc_entity_color_by_block(struct gllc_entity *ent);
int gllc_entity_set_color_by_layer(struct gllc_entity *ent, int enable);
int gllc_entity_set_color_by_block(struct gllc_entity *ent, int enable);
int gllc_entity_fcolor_by_layer(struct gllc_entity *ent);
int gllc_entity_fcolor_by_block(struct gllc_entity *ent);
int gllc_entity_set_fcolor_by_layer(struct gllc_entity *ent, int enable);
int gllc_entity_set_fcolor_by_block(struct gllc_entity *ent, int enable);
char *gllc_entity_get_fcolor_string(struct gllc_entity *ent);
int gllc_entity_set_fcolor_string(struct gllc_entity *ent, char *color);
int gllc_entity_is_colori(struct gllc_entity *ent);
int gllc_entity_is_colort(struct gllc_entity *ent);
int gllc_entity_set_colori(struct gllc_entity *ent, int color);
int gllc_entity_set_colort(struct gllc_entity *ent, color_t color);
int gllc_entity_set_color(struct gllc_entity *ent, color_t color);
int gllc_entity_is_fcolori(struct gllc_entity *ent);
int gllc_entity_is_fcolort(struct gllc_entity *ent);
int gllc_entity_set_fcolor(struct gllc_entity *ent, color_t fcolor);
int gllc_entity_set_falpha(struct gllc_entity *ent, float falpha);
float gllc_entity_falpha(struct gllc_entity *ent);
int gllc_entity_set_alpha(struct gllc_entity *ent, float alpha);
float gllc_entity_alpha(struct gllc_entity *ent);
int gllc_entity_set_ltscale(struct gllc_entity *ent, float ltscale);
int gllc_entity_set_lwidth_mode(struct gllc_entity *ent, int mode);
int gllc_entity_set_lwidth(struct gllc_entity *ent, float lwidth);
float gllc_entity_ltscale(struct gllc_entity *ent);
int gllc_entity_lwidth_mode(struct gllc_entity *ent);
float gllc_entity_lwidth(struct gllc_entity *ent);
int gllc_entity_set_linetype(struct gllc_entity *ent, struct gllc_linetype *linetype);
struct gllc_linetype *gllc_entity_linetype(struct gllc_entity *ent);
int gllc_entity_filled(struct gllc_entity *ent);
int gllc_entity_set_filled(struct gllc_entity *ent, int filled);
int gllc_entity_set_color_by_string(struct gllc_entity *ent, const char *color);
int gllc_entity_colori(struct gllc_entity *ent);
int gllc_entity_fcolori(struct gllc_entity *ent);
color_t gllc_entity_fcolort(struct gllc_entity *ent);
int gllc_entity_set_fcolori(struct gllc_entity *ent, int ind);
int gllc_entity_set_fcolort(struct gllc_entity *ent, color_t color);
int gllc_entity_locked(struct gllc_entity *ent);
int gllc_entity_visible(struct gllc_entity *ent);
int gllc_entity_hidden(struct gllc_entity *ent);
int gllc_entity_set_hidden(struct gllc_entity *ent, int enable);
int gllc_entity_selected(struct gllc_entity *ent);
int gllc_entity_hover(struct gllc_entity *ent);
int gllc_entity_set_hover(struct gllc_entity *ent, int enable);
int gllc_entity_modified(struct gllc_entity *ent);
int gllc_entity_geometry_modified(struct gllc_entity *ent);
int gllc_entity_set_modified(struct gllc_entity *ent, int geometry);
void gllc_entity_destroy(struct gllc_entity *ent);
void gllc_entity_bbox(struct gllc_entity *ent, double scale, double *x0, double *y0, double *x1, double *y1);
void gllc_entity_build(struct gllc_entity *ent, struct ds_draw *draw, double scale);
int gllc_entity_set_layer(struct gllc_entity *ent, struct gllc_layer *layer);
struct gllc_layer *gllc_entity_get_layer(struct gllc_entity *ent);

// В отличии от gllc_entity_(f)color который возвращает цвет записаный в примитиве эти функции вернут цвет который имея в виду BYBLOCK/BYLAYER
color_t gllc_entity_resolv_color(struct gllc_entity *ent);
color_t gllc_entity_resolv_fcolor(struct gllc_entity *ent);

#endif