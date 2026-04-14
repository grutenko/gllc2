#include "named_object.h"
#include "object.h"
#include <stdint.h>
#include <string.h>

static uint64_t last_ID = 0ULL;

struct gllc_prop G_nobject_props[] = {P_END};

void gllc_nobject_init(struct gllc_nobject *nobj, struct gllc_drawing *drawing, struct gllc_prop **props, struct gllc_object_vtable *vtable, int type, const char *name) {
  memset(nobj, 0, sizeof(struct gllc_nobject));
  GLLC_OBJECT_INIT(nobj, props, vtable);
  strncpy(nobj->name, name, strnlen(name, 31));
  nobj->ID = last_ID++;
}