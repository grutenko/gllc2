#ifndef draw_h
#define draw_h

#include "glad.h"

struct ds_vertex {
  GLfloat p[2];
  GLfloat n[2];
  GLfloat uv[2];
  GLbyte c[4];
};

#define DS_UNIT_DIRTY 0x1

struct ds_unit {
  int flags;
  struct ds_draw *draw;
  struct ds_vertex *V;
  GLuint *I;
  GLuint V_cnt;
  GLuint I_cnt;
  struct ds_unit *next;
  struct ds_unit *prev;
};

struct ds_gpu_unit {
  int flags;
  GLuint tex_id;
  GLuint offset;
  GLuint count;
};

struct ds_gpu {
  struct ds_gpu_unit *units;
  GLuint units_cnt;
  GLuint VAO;
  GLuint VBO;
  GLuint EBO;
  GLuint VBO_size;
  GLuint EBO_size;
  GLuint VBO_capacity;
  GLuint EBO_capacity;
};

#define DS_DRAW_DIRTY 0x1

struct ds_draw {
  int flags;
  struct ds_unit *head;
  struct ds_unit *tail;
  int unit_cnt;
};

struct ds_unit *ds_unit_create(struct ds_draw *draw);
struct ds_vertex *ds_unit_reserve_vertex(struct ds_unit *unit, GLuint cnt);
GLuint ds_unit_reserve_index(struct ds_unit *unit, GLuint cnt);
void ds_unit_destroy(struct ds_unit *unit);
// In draw_proc
void ds_sync(struct ds_draw *draw, struct ds_gpu *gpu);
void ds_draw(struct ds_gpu *gpu);

#endif