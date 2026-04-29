#ifndef object_h
#define object_h

#include <stdint.h>
struct gllc_object;

struct gllc_object_vtable {
  void (*destroy)(struct gllc_object *);
};

union gllc_variant {
  int bool_;
  int64_t int_;
  double float_;
  char *string_;
  void *handle_;
};

enum {
  T_PROP_BOOL = 1,
  T_PROP_INT = 2,
  T_PROP_FLOAT = 3,
  T_PROP_STRING = 4,
  T_PROP_HANDLE = 5
};

struct gllc_prop {
  int prop;
  int type;
  union gllc_variant (*getter)(struct gllc_object *, int, int);
  int (*setter)(struct gllc_object *, int, int, union gllc_variant);
  int readonly;
};

struct gllc_object {
  struct gllc_prop **props;
  struct gllc_object_vtable *vtable;
};

struct g_props_object {
  struct gllc_object _obj;
  char *version;
  char *dirdll;
};

extern struct g_props_object G_props_object;

#define P_BOOL(P, G, S) {(P), T_PROP_BOOL, (G), (S), 0}
#define P_INT(P, G, S) {(P), T_PROP_INT, (G), (S), 0}
#define P_FLOAT(P, G, S) {(P), T_PROP_FLOAT, (G), (S), 0}
#define P_STRING(P, G, S) {(P), T_PROP_STRING, (G), (S), 0}
#define P_HANDLE(P, G, S) {(P), T_PROP_HANDLE, (G), (S), 0}
#define P_BOOL_RO(P, G) {(P), T_PROP_BOOL, (G), 0, 1}
#define P_INT_RO(P, G) {(P), T_PROP_INT, (G), 0, 1}
#define P_FLOAT_RO(P, G) {(P), T_PROP_FLOAT, (G), 0, 1}
#define P_STRING_RO(P, G) {(P), T_PROP_STRING, (G), 0, 1}
#define P_HANDLE_RO(P, G) {(P), T_PROP_HANDLE, (G), 0, 1}
#define P_END {-1, -1, 0, 0, -1}

#define GLLC_OBJECT_INIT(O, PROPS, VTABLE)                             \
  do {                                                                 \
    ((struct gllc_object *)(O))->props = (struct gllc_prop **)(PROPS); \
    ((struct gllc_object *)(O))->vtable = (VTABLE);                    \
  } while (0)

void gllc_object_destroy(struct gllc_object *obj);

int gllc_prop_get_bool(struct gllc_object *obj, int prop);
int64_t gllc_prop_get_int(struct gllc_object *obj, int prop);
double gllc_prop_get_float(struct gllc_object *obj, int prop);
char *gllc_prop_get_string(struct gllc_object *obj, int prop);
void *gllc_prop_get_handle(struct gllc_object *obj, int prop);
int gllc_prop_put_bool(struct gllc_object *obj, int prop, int value);
int gllc_prop_put_int(struct gllc_object *obj, int prop, int64_t value);
int gllc_prop_put_float(struct gllc_object *obj, int prop, double value);
int gllc_prop_put_string(struct gllc_object *obj, int prop, char *value);
int gllc_prop_put_handle(struct gllc_object *obj, int prop, void *value);

#endif