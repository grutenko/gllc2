#include "event.h"
#include "alloc.h"
#include "litecad.h"
#include "object.h"

#include <string.h>

static struct _proc {
  int type;
  gllc_event_proc proc;
  int user_1;
  void *user_2;
  struct _proc *next;
} *_handlers = NULL;

void gllc_event_set_proc(int event_type, gllc_event_proc proc, int user_1, void *user_2) {
  struct _proc **p;
  for (p = &_handlers; *p; p = &(*p)->next) {
    if ((*p)->type == event_type)
      break;
  }
  if (!*p) {
    *p = XALLOC_OBSERVED(sizeof(struct _proc));
    if (!*p) {
      return;
    }
    (*p)->type = event_type;
    (*p)->next = NULL;
  }
  (*p)->proc = proc;
  (*p)->user_1 = user_1;
  (*p)->user_2 = user_2;
}

static union gllc_variant _event_type_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = ((struct gllc_event *)obj)->type;
  return v;
}

static union gllc_variant _event_appprm1_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = ((struct gllc_event *)obj)->appparam1;
  return v;
}

static union gllc_variant _event_appprm2_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = ((struct gllc_event *)obj)->appparam2;
  return v;
}

static union gllc_variant _event_wnd_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = ((struct gllc_event *)obj)->window;
  return v;
}

static union gllc_variant _event_drw_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = ((struct gllc_event *)obj)->drawing;
  return v;
}

static union gllc_variant _event_block_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = ((struct gllc_event *)obj)->block;
  return v;
}

static union gllc_variant _event_entity_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = ((struct gllc_event *)obj)->entity;
  return v;
}

static union gllc_variant _event_int1_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = ((struct gllc_event *)obj)->_int1;
  return v;
}

static int _event_int1_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_event *)obj)->_int1 = value.int_;
  return 1;
}

static union gllc_variant _event_int2_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = ((struct gllc_event *)obj)->_int2;
  return v;
}

static int _event_int2_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_event *)obj)->_int2 = value.int_;
  return 1;
}

static union gllc_variant _event_int3_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = ((struct gllc_event *)obj)->_int4;
  return v;
}

static int _event_int3_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_event *)obj)->_int3 = value.int_;
  return 1;
}

static union gllc_variant _event_int4_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = ((struct gllc_event *)obj)->_int4;
  return v;
}

static int _event_int4_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_event *)obj)->_int4 = value.int_;
  return 1;
}

static union gllc_variant _event_int5_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = ((struct gllc_event *)obj)->_int5;
  return v;
}

static int _event_int5_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_event *)obj)->_int5 = value.int_;
  return 1;
}

static union gllc_variant _event_float1_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = ((struct gllc_event *)obj)->_float1;
  return v;
}

static int _event_float1_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_event *)obj)->_float1 = value.float_;
  return 1;
}

static union gllc_variant _event_float2_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = ((struct gllc_event *)obj)->_float2;
  return v;
}

static int _event_float2_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_event *)obj)->_float2 = value.float_;
  return 1;
}

static union gllc_variant _event_float3_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = ((struct gllc_event *)obj)->_float3;
  return v;
}

static int _event_float3_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_event *)obj)->_float3 = value.float_;
  return 1;
}

static union gllc_variant _event_float4_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = ((struct gllc_event *)obj)->_float4;
  return v;
}

static int _event_float4_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_event *)obj)->_float4 = value.float_;
  return 1;
}

static union gllc_variant _event_float5_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = ((struct gllc_event *)obj)->_float5;
  return v;
}

static int _event_float5_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_event *)obj)->_float4 = value.float_;
  return 1;
}

static union gllc_variant _event_str1_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.string_ = ((struct gllc_event *)obj)->_str1;
  return v;
}

static int _event_str1_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_event *)obj)->_str1 = value.string_;
  return 1;
}
static union gllc_variant _event_str2_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.string_ = ((struct gllc_event *)obj)->_str2;
  return v;
}

static int _event_str2_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_event *)obj)->_str2 = value.string_;
  return 1;
}
static union gllc_variant _event_str3_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.string_ = ((struct gllc_event *)obj)->_str3;
  return v;
}

static int _event_str3_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_event *)obj)->_str3 = value.string_;
  return 1;
}

static struct gllc_prop _props[] = {
    P_INT_RO(LC_PROP_EVENT_TYPE, _event_type_GET),
    P_INT_RO(LC_PROP_EVENT_APPPRM1, _event_appprm1_GET),
    P_HANDLE_RO(LC_PROP_EVENT_APPPRM1, _event_appprm2_GET),
    P_HANDLE_RO(LC_PROP_EVENT_WND, _event_wnd_GET),
    P_HANDLE_RO(LC_PROP_EVENT_DRW, _event_drw_GET),
    P_HANDLE_RO(LC_PROP_EVENT_BLOCK, _event_block_GET),
    P_HANDLE_RO(LC_PROP_EVENT_ENTITY, _event_entity_GET),
    P_INT(LC_PROP_EVENT_INT1, _event_int1_GET, _event_int1_SET),
    P_INT(LC_PROP_EVENT_INT2, _event_int2_GET, _event_int2_SET),
    P_INT(LC_PROP_EVENT_INT3, _event_int3_GET, _event_int3_SET),
    P_INT(LC_PROP_EVENT_INT4, _event_int4_GET, _event_int4_SET),
    P_INT(LC_PROP_EVENT_INT5, _event_int5_GET, _event_int5_SET),
    P_FLOAT(LC_PROP_EVENT_FLOAT1, _event_float1_GET, _event_float1_SET),
    P_FLOAT(LC_PROP_EVENT_FLOAT2, _event_float2_GET, _event_float2_SET),
    P_FLOAT(LC_PROP_EVENT_FLOAT3, _event_float3_GET, _event_float3_SET),
    P_FLOAT(LC_PROP_EVENT_FLOAT4, _event_float4_GET, _event_float4_SET),
    P_FLOAT(LC_PROP_EVENT_FLOAT5, _event_float5_GET, _event_float5_SET),
    P_STRING(LC_PROP_EVENT_STR1, _event_str1_GET, _event_str1_SET),
    P_STRING(LC_PROP_EVENT_STR2, _event_str2_GET, _event_str2_SET),
    P_STRING(LC_PROP_EVENT_STR3, _event_str3_GET, _event_str3_SET),
    P_END};
static struct gllc_prop *_all_props[] = {_props, NULL};
static void _destroy(struct gllc_object *obj) {}
static struct gllc_object_vtable _vtable = {
    .destroy = _destroy};

void gllc_event_init(struct gllc_event *event) {
  memset(event, 0, sizeof(struct gllc_event));

  GLLC_OBJECT_INIT(event, _all_props, &_vtable);
}

static int G_ret_code = 0;

void gllc_event_ret_code(int ret_code) {
  G_ret_code = ret_code;
}

int gllc_event_send(int event_type, struct gllc_event *evt) {
  G_ret_code = 0;
  struct _proc *p;
  for (p = _handlers; p; p = p->next) {
    if (p->type == event_type) {
      evt->appparam1 = p->user_1;
      evt->appparam2 = p->user_2;
      evt->type = event_type;
      p->proc(evt);
      return G_ret_code;
    }
  }
  return G_ret_code;
}