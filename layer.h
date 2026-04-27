#ifndef layer_h
#define layer_h

#include "entity.h"
#include "named_object.h"

struct gllc_layer {
  struct gllc_nobject _nobj;
  struct gllc_entity_props props;
};

#endif