#ifndef layer_h
#define layer_h

#include "entity.h"
#include "object.h"


struct gllc_layer {
  struct gllc_object _obj;
  struct gllc_entity_props props;
};

#endif