#ifndef named_object_h
#define named_object_h

#include "object.h"
#include <stdint.h>

struct gllc_drawing;

enum {
  GLLC_OBJ_LAYER,
  GLLC_OBJ_LINETYPE,
  GLLC_OBJ_TEXTSTYLE,
  GLLC_OBJ_PNTSTYLE,
  GLLC_OBJ_DIMSTYLE,
  GLLC_OBJ_LINFILL,
  GLLC_OBJ_IMAGE,
  GLLC_OBJ_BLOCK,
  GLLC_OBJ_LAYOUT
};

struct gllc_nobject {
  struct gllc_object _obj;
  uint64_t ID;
  char name[32];
  char descr[64];
  struct gllc_drawing *drawing;
  int type;
  int priority;
  int nrefs;
  void *xdata;
  int xdata_size;
  uint64_t int0;
  uint64_t int1;
  uint64_t int2;
  uint64_t int3;
  double float0;
  double float1;
  double float2;
  double float3;
  struct gllc_nobject *prev;
  struct gllc_nobject *next;
};

void gllc_nobject_init(struct gllc_nobject *nobj, struct gllc_drawing *drawing, struct gllc_prop **props, struct gllc_object_vtable *vtable, int type, const char *name);
void gllc_nobject_destroy(struct gllc_nobject *nobj);

extern struct gllc_prop G_nobject_props[];

#endif