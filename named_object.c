#include "named_object.h"
#include "litecad.h"
#include "object.h"

#include <stdint.h>
#include <string.h>

static uint64_t last_ID = 0ULL;

#define NO(obj) ((struct gllc_nobject *)(obj))

static union gllc_variant _table_id_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.string_ = NO(obj)->ID_hex;
  return v;
}

static union gllc_variant _table_name_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.string_ = NO(obj)->name;
  return v;
}

static int _table_name_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  strncpy(NO(obj)->name, value.string_, sizeof(NO(obj)->name) - 1);
  NO(obj)->name[sizeof(NO(obj)->name) - 1] = 0;
  return 1;
}

static union gllc_variant _table_descr_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.string_ = NO(obj)->descr;
  return v;
}

static int _table_descr_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  strncpy(NO(obj)->descr, value.string_, sizeof(NO(obj)->descr) - 1);
  NO(obj)->descr[sizeof(NO(obj)->descr) - 1] = 0;
  return 1;
}

static union gllc_variant _table_type_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = NO(obj)->type;
  return v;
}

static union gllc_variant _table_deleted_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = 0;
  return v;
}

static union gllc_variant _table_drw_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = NO(obj)->drawing;
  return v;
}

static union gllc_variant _table_priority_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = NO(obj)->priority;
  return v;
}

static int _table_priority_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->priority = (int)value.int_;
  return 1;
}

static union gllc_variant _table_nrefs_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = NO(obj)->nrefs;
  return v;
}

static union gllc_variant _table_xdatasize_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = NO(obj)->xdata_size;
  return v;
}

static int _table_xdatasize_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->xdata_size = (int)value.int_;
  return 1;
}

static union gllc_variant _table_xdata_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = NO(obj)->xdata;
  return v;
}

static int _table_xdata_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->xdata = value.handle_;
  return 1;
}

static union gllc_variant _table_xstr_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.string_ = (char *)NO(obj)->xdata;
  return v;
}

static int _table_xstr_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->xdata = (void *)value.string_;
  return 1;
}

static union gllc_variant _table_int0_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = NO(obj)->int0;
  return v;
}
static int _table_int0_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->int0 = value.int_;
  return 1;
}

static union gllc_variant _table_int1_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = NO(obj)->int1;
  return v;
}
static int _table_int1_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->int1 = value.int_;
  return 1;
}

static union gllc_variant _table_int2_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = NO(obj)->int2;
  return v;
}
static int _table_int2_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->int2 = value.int_;
  return 1;
}

static union gllc_variant _table_int3_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = NO(obj)->int3;
  return v;
}
static int _table_int3_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->int3 = value.int_;
  return 1;
}

static union gllc_variant _table_int4_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = NO(obj)->int4;
  return v;
}
static int _table_int4_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->int4 = value.int_;
  return 1;
}

static union gllc_variant _table_float0_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = NO(obj)->float0;
  return v;
}
static int _table_float0_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->float0 = value.float_;
  return 1;
}

static union gllc_variant _table_float1_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = NO(obj)->float1;
  return v;
}
static int _table_float1_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->float1 = value.float_;
  return 1;
}

static union gllc_variant _table_float2_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = NO(obj)->float2;
  return v;
}
static int _table_float2_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->float2 = value.float_;
  return 1;
}

static union gllc_variant _table_float3_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = NO(obj)->float3;
  return v;
}
static int _table_float3_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->float3 = value.float_;
  return 1;
}

static union gllc_variant _table_float4_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = NO(obj)->float4;
  return v;
}
static int _table_float4_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  NO(obj)->float4 = value.float_;
  return 1;
}

struct gllc_prop G_nobject_props[] = {
    P_STRING_RO(LC_PROP_TABLE_ID, _table_id_GET),
    P_STRING(LC_PROP_TABLE_NAME, _table_name_GET, _table_name_SET),
    P_STRING(LC_PROP_TABLE_DESCR, _table_descr_GET, _table_descr_SET),
    P_INT_RO(LC_PROP_TABLE_TYPE, _table_type_GET),
    P_BOOL_RO(LC_PROP_TABLE_DELETED, _table_deleted_GET),
    P_HANDLE_RO(LC_PROP_TABLE_DRW, _table_drw_GET),
    P_INT(LC_PROP_TABLE_PRIORITY, _table_priority_GET, _table_priority_SET),
    P_INT_RO(LC_PROP_TABLE_NREFS, _table_nrefs_GET),
    P_INT(LC_PROP_TABLE_XDATASIZE, _table_xdatasize_GET, _table_xdatasize_SET),
    P_HANDLE(LC_PROP_TABLE_XDATA, _table_xdata_GET, _table_xdata_SET),
    P_STRING(LC_PROP_TABLE_XSTR, _table_xstr_GET, _table_xstr_SET),
    P_INT(LC_PROP_TABLE_INT0, _table_int0_GET, _table_int0_SET),
    P_INT(LC_PROP_TABLE_INT1, _table_int1_GET, _table_int1_SET),
    P_INT(LC_PROP_TABLE_INT2, _table_int2_GET, _table_int2_SET),
    P_INT(LC_PROP_TABLE_INT3, _table_int3_GET, _table_int3_SET),
    P_INT(LC_PROP_TABLE_INT4, _table_int4_GET, _table_int4_SET),
    P_FLOAT(LC_PROP_TABLE_FLOAT0, _table_float0_GET, _table_float0_SET),
    P_FLOAT(LC_PROP_TABLE_FLOAT1, _table_float1_GET, _table_float1_SET),
    P_FLOAT(LC_PROP_TABLE_FLOAT2, _table_float2_GET, _table_float2_SET),
    P_FLOAT(LC_PROP_TABLE_FLOAT3, _table_float3_GET, _table_float3_SET),
    P_FLOAT(LC_PROP_TABLE_FLOAT4, _table_float4_GET, _table_float4_SET),
    P_END};

static char ID_hex_tab[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

static inline void ID_hexify(uint64_t ID, char *ID_hex) {
  ID_hex[0] = ID_hex_tab[(ID >> 60) & 0xF];
  ID_hex[1] = ID_hex_tab[(ID >> 56) & 0xF];
  ID_hex[2] = ID_hex_tab[(ID >> 52) & 0xF];
  ID_hex[3] = ID_hex_tab[(ID >> 48) & 0xF];
  ID_hex[4] = ID_hex_tab[(ID >> 44) & 0xF];
  ID_hex[5] = ID_hex_tab[(ID >> 40) & 0xF];
  ID_hex[6] = ID_hex_tab[(ID >> 36) & 0xF];
  ID_hex[7] = ID_hex_tab[(ID >> 32) & 0xF];
  ID_hex[8] = ID_hex_tab[(ID >> 28) & 0xF];
  ID_hex[9] = ID_hex_tab[(ID >> 24) & 0xF];
  ID_hex[10] = ID_hex_tab[(ID >> 20) & 0xF];
  ID_hex[11] = ID_hex_tab[(ID >> 16) & 0xF];
  ID_hex[12] = ID_hex_tab[(ID >> 12) & 0xF];
  ID_hex[13] = ID_hex_tab[(ID >> 8) & 0xF];
  ID_hex[14] = ID_hex_tab[(ID >> 4) & 0xF];
  ID_hex[15] = ID_hex_tab[ID & 0xF];
  ID_hex[16] = '\0';
}

void gllc_nobject_init(struct gllc_nobject *nobj, struct gllc_drawing *drawing, struct gllc_prop **props, struct gllc_object_vtable *vtable, int type, const char *name) {
  memset(nobj, 0, sizeof(struct gllc_nobject));
  GLLC_OBJECT_INIT(nobj, props, vtable);
  strncpy(nobj->name, name, strnlen(name, 31));
  nobj->ID = last_ID++;
  ID_hexify(nobj->ID, nobj->ID_hex);
}

void gllc_nobject_destroy(struct gllc_nobject *nobj) {
  gllc_object_destroy((struct gllc_object *)nobj);
}