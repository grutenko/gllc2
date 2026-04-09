#include "object.h"
#include "block.h"

static struct gllc_prop *find_prop(struct gllc_prop **props, int prop, int typ) {
  int i, j;
  for (i = 0; props[i]; i++) {
    for (j = 0; props[i][j].prop != -1; j++) {
      if (props[i][j].prop == prop && props[i][j].type == typ) {
        return &props[i][j];
      }
    }
  }
  return NULL;
}

int gllc_prop_get_bool(struct gllc_object *obj, int prop) {
  struct gllc_prop *p = find_prop(obj->props, prop, T_PROP_BOOL);
  if (p) {
    return p->getter(obj, prop, T_PROP_BOOL).bool_;
  }
  return 0;
}

int gllc_prop_get_int(struct gllc_object *obj, int prop) {
  struct gllc_prop *p = find_prop(obj->props, prop, T_PROP_INT);
  if (p) {
    return p->getter(obj, prop, T_PROP_INT).int_;
  }
  return 0;
}

double gllc_prop_get_float(struct gllc_object *obj, int prop) {
  struct gllc_prop *p = find_prop(obj->props, prop, T_PROP_FLOAT);
  if (p) {
    return p->getter(obj, prop, T_PROP_FLOAT).float_;
  }
  return 0;
}

char *gllc_prop_get_string(struct gllc_object *obj, int prop) {
  struct gllc_prop *p = find_prop(obj->props, prop, T_PROP_STRING);
  if (p) {
    return p->getter(obj, prop, T_PROP_STRING).string_;
  }
  return 0;
}

void *gllc_prop_get_handle(struct gllc_object *obj, int prop) {
  struct gllc_prop *p = find_prop(obj->props, prop, T_PROP_HANDLE);
  if (p) {
    return p->getter(obj, prop, T_PROP_HANDLE).handle_;
  }
  return 0;
}

int gllc_prop_put_bool(struct gllc_object *obj, int prop, int value) {
  struct gllc_prop *p = find_prop(obj->props, prop, T_PROP_BOOL);
  if (p && !p->readonly) {
    union gllc_variant v;
    v.bool_ = value;
    return p->setter(obj, prop, T_PROP_BOOL, v);
  }
  return 0;
}

int gllc_prop_put_int(struct gllc_object *obj, int prop, int value) {
  struct gllc_prop *p = find_prop(obj->props, prop, T_PROP_INT);
  if (p && !p->readonly) {
    union gllc_variant v;
    v.int_ = value;
    return p->setter(obj, prop, T_PROP_INT, v);
  }
  return 0;
}

int gllc_prop_put_float(struct gllc_object *obj, int prop, double value) {
  struct gllc_prop *p = find_prop(obj->props, prop, T_PROP_FLOAT);
  if (p && !p->readonly) {
    union gllc_variant v;
    v.float_ = value;
    return p->setter(obj, prop, T_PROP_FLOAT, v);
  }
  return 0;
}

int gllc_prop_put_string(struct gllc_object *obj, int prop, const char *value) {
  struct gllc_prop *p = find_prop(obj->props, prop, T_PROP_STRING);
  if (p && !p->readonly) {
    union gllc_variant v;
    v.string_ = (char *)value;
    return p->setter(obj, prop, T_PROP_STRING, v);
  }
  return 0;
}

int gllc_prop_put_handle(struct gllc_object *obj, int prop, void *value) {
  struct gllc_prop *p = find_prop(obj->props, prop, T_PROP_HANDLE);
  if (p && !p->readonly) {
    union gllc_variant v;
    v.handle_ = value;
    return p->setter(obj, prop, T_PROP_HANDLE, v);
  }
  return 0;
}