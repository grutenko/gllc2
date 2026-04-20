#include "object.h"
#include "block.h"

static void destroy(struct gllc_object *obj) {}
static struct gllc_prop props[] = {P_END};
static struct gllc_prop *all_props[] = {props, NULL};
static struct gllc_object_vtable vtable = {
    .destroy = destroy};
static struct g_props_obj {
  struct gllc_object _obj;
} global_props_obj = {
    ._obj = {.props = all_props,
             .vtable = &vtable}};

void gllc_object_init(struct gllc_object *obj, struct gllc_prop **props, struct gllc_object_vtable *vtable) {
  obj->props = props;
  obj->vtable = vtable;
}

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

#define GET(T0, T1, T2)                                                        \
  T2 gllc_prop_get_##T1(struct gllc_object *obj, int prop) {                   \
    struct gllc_prop **props = obj ? obj->props : global_props_obj._obj.props; \
    struct gllc_prop *p = find_prop(props, prop, T0);                          \
    if (p) {                                                                   \
      return p->getter(obj, prop, T0).T1##_;                                   \
    }                                                                          \
    return 0;                                                                  \
  }

GET(T_PROP_BOOL, bool, int)
GET(T_PROP_INT, int, int64_t)
GET(T_PROP_FLOAT, float, double)
GET(T_PROP_STRING, string, char *)
GET(T_PROP_HANDLE, handle, void *)

#define PUT(T0, T1, T2)                                                        \
  int gllc_prop_put_##T1(struct gllc_object *obj, int prop, T2 value) {        \
    struct gllc_prop **props = obj ? obj->props : global_props_obj._obj.props; \
    struct gllc_prop *p = find_prop(props, prop, T0);                          \
    if (p && !p->readonly) {                                                   \
      union gllc_variant v;                                                    \
      v.T1##_ = value;                                                         \
      return p->setter(obj, prop, T0, v);                                      \
    }                                                                          \
    return 0;                                                                  \
  }

PUT(T_PROP_BOOL, bool, int)
PUT(T_PROP_INT, int, int64_t)
PUT(T_PROP_FLOAT, float, double)
PUT(T_PROP_STRING, string, char *)
PUT(T_PROP_HANDLE, handle, void *)

void gllc_object_destroy(struct gllc_object *obj) {
  if (obj->vtable->destroy)
    obj->vtable->destroy(obj);
}