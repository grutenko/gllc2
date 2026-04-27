#ifndef event_h
#define event_h

#include "object.h"

struct gllc_window;
struct gllc_drawing;
struct gllc_block;
struct gllc_entity;

struct gllc_event {
  struct gllc_object _obj;
  int type;
  int appparam1;
  void *appparam2;
  struct gllc_window *window;
  struct gllc_drawing *drawing;
  struct gllc_block *block;
  struct gllc_entity *entity;
  int _int1;
  int _int2;
  int _int3;
  int _int4;
  int _int5;
  double _float1;
  double _float2;
  double _float3;
  double _float4;
  double _float5;
  char *_str1;
  char *_str2;
  char *_str3;
};

typedef void (*gllc_event_proc)(struct gllc_event *evt);

void gllc_event_init(struct gllc_event *event);
void gllc_event_set_proc(int event_type, gllc_event_proc proc, int user_1, void *user_2);
int gllc_event_send(int event_type, struct gllc_event *evt);
void gllc_events_clear();

#endif