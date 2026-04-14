#ifndef entity_h
#define entity_h

#include "entity_vertex.h"
#include "glad.h"
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

struct gllc_entity_vtable {
  int type;
  void (*build)(struct gllc_entity *, struct ds_draw *, double scale);
  void (*destroy)(struct gllc_entity *);
  int (*vertices)(struct gllc_entity *, double, struct ev *);
  int (*selected)(struct gllc_entity *, int, double, double, double, double, double);
  int (*picked)(struct gllc_entity *, double, double, double);
  int (*bbox)(struct gllc_entity *, double, double *, double *, double *, double *);
  int (*len)(struct gllc_entity *, double *);
  int (*clone)(struct gllc_entity *, struct gllc_entity **);
};

struct gllc_entity_props {
  int color;
  int fcolor;
  float ltscale;
  struct gllc_linetype *linetype;
};

struct gllc_entity {
  struct gllc_object _obj;
  int flags;
  float falpha;
  float lwidth;
  int order;
  uint64_t ID;
  uint64_t key;
  char ID_hex[16];
  uint64_t unit_ID;
  struct gllc_entity_props props;
  struct gllc_entity_vtable *vtable;
  struct gllc_block *block;
  struct gllc_layer *layer;
  struct gllc_entity *prev;
  struct gllc_entity *next;
};

extern struct gllc_prop G_entity_props[];
extern struct gllc_object_vtable G_entity_obj_vtable;

void _gllc_entity_init(struct gllc_entity *ent, struct gllc_block *block, struct gllc_prop **props, struct gllc_entity_vtable *vtable);

#define GLLC_ENTITY_INIT(E, BLOCK, PROPS, VTABLE) _gllc_entity_init((struct gllc_entity *)(E), (BLOCK), (PROPS), (VTABLE))

#define GLLC_COLOR_RED(C) (((C) >> 16) & 0xFF)
#define GLLC_COLOR_GREEN(C) (((C) >> 8) & 0xFF)
#define GLLC_COLOR_BLUE(C) ((C) & 0xFF)

uint64_t gllc_entity_get_id(struct gllc_entity *ent);
char *gllc_entity_get_id_string(struct gllc_entity *ent);
uint64_t gllc_entity_get_key(struct gllc_entity *ent);
int gllc_entity_set_key(struct gllc_entity *ent, uint64_t key);
int gllc_entity_color(struct gllc_entity *ent);
int gllc_entity_fcolor(struct gllc_entity *ent);
char *gllc_entity_color_string(struct gllc_entity *ent);
int gllc_entity_color_by_layer(struct gllc_entity *ent);
int gllc_entity_color_by_block(struct gllc_entity *ent);
int gllc_entity_set_color_by_layer(struct gllc_entity *ent, int enable);
int gllc_entity_set_color_by_block(struct gllc_entity *ent, int enable);
int gllc_entity_fcolor_by_layer(struct gllc_entity *ent);
int gllc_entity_fcolor_by_block(struct gllc_entity *ent);
int gllc_entity_set_fcolor_by_layer(struct gllc_entity *ent, int enable);
int gllc_entity_set_fcolor_by_block(struct gllc_entity *ent, int enable);
int gllc_entity_is_colori(struct gllc_entity *ent);
int gllc_entity_is_colort(struct gllc_entity *ent);
int gllc_entity_set_colori(struct gllc_entity *ent, int color);
int gllc_entity_set_colort(struct gllc_entity *ent, int color);
int gllc_entity_set_color(struct gllc_entity *ent, int color);
int gllc_entity_is_fcolori(struct gllc_entity *ent);
int gllc_entity_is_fcolort(struct gllc_entity *ent);
int gllc_entity_set_fcolor(struct gllc_entity *ent, int fcolor);
int gllc_entity_set_falpha(struct gllc_entity *ent, float falpha);
float gllc_entity_falpha(struct gllc_entity *ent);
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
int gllc_entity_fcolort(struct gllc_entity *ent);
int gllc_entity_set_fcolori(struct gllc_entity *ent, int ind);
int gllc_entity_set_fcolort(struct gllc_entity *ent, int color);
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

#endif