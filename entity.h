#ifndef entity_h
#define entity_h

#include "glad.h"
#include "object.h"

struct gllc_block;
struct gllc_layer;
struct gllc_DB;
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

struct gllc_entity_vtable {
  int type;
  void (*build)(struct gllc_entity *, struct gllc_DB *, GLfloat scale);
  void (*destroy)(struct gllc_entity *);
  int (*vertices)(struct gllc_entity *, double, double *);
  int (*selected)(struct gllc_entity *, double, double, double, double, double);
  int (*picked)(struct gllc_entity *, double, double, double);
  int (*bbox)(struct gllc_entity *, double, double *, double *, double *,
              double *);
};

struct gllc_entity_props {
  int color;
  int fcolor;
  struct gllc_linetype *linetype;
};

struct gllc_entity {
  struct gllc_object _obj;
  int flags;
  struct gllc_entity_vtable *vtable;
  struct gllc_block *block;
  struct gllc_layer *layer;
  struct gllc_entity_props props;
  int falpha;
  float ltscale;
  int lwidth;
  struct gllc_entity *prev;
  struct gllc_entity *next;
  int order;
};

#define GLLC_ENTITY_INIT(E, BLOCK, PROPS, VTABLE)

#endif