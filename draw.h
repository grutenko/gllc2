#ifndef draw_h
#define draw_h

#include "glad.h"

struct ds_vertex {
  GLfloat th;
  GLbyte n[2];
  GLubyte uv[2];
  GLubyte c[4];
  GLfloat p[2];
};

#define DS_UNIT_CHESS 0x1

struct ds_unit {
  int flags;
  int id;
  struct ds_draw *draw;
  struct ds_vertex *V;
  GLuint *I;
  GLuint V_cnt;
  GLuint I_cnt;
  GLuint I_cap;
  GLuint V_cap;
  struct ds_unit *next;
  struct ds_unit *prev;
  int order;
  int dirty;
  int geometry_dirty;
};

struct ds_gpu_batch {
  int flags;
  GLuint tex_id;
  GLuint offset;
  GLuint count;
};

struct ds_gpu {
  struct ds_gpu_batch *batches;
  GLuint batch_cnt;
  GLuint batch_cap;
  GLuint VAO;
  GLuint VBO;
  GLuint EBO;
  GLuint VBO_size;
  GLuint EBO_size;
  GLuint VBO_capacity;
  GLuint EBO_capacity;
  struct ds_vertex *V_data;
  GLuint *I_data;
  GLuint V_data_size;
  GLuint I_data_size;
  GLuint V_data_capacity;
  GLuint I_data_capacity;
};

struct ds_draw {
  int dirty;
  int geometry_dirty;
  struct ds_unit *head;
  struct ds_unit *tail;
  int unit_cnt;
};

void ds_attrib_ptr();
struct ds_unit *ds_unit_create(struct ds_draw *draw);
struct ds_vertex *ds_unit_reserve_vertex(struct ds_unit *unit, GLuint cnt);
GLuint *ds_unit_reserve_index(struct ds_unit *unit, GLuint cnt);
void ds_unit_destroy(struct ds_unit *unit);
// In draw_proc
int ds_draw_dirty(struct ds_draw *draw);
void ds_sync(struct ds_draw *draw, struct ds_gpu *gpu);
void ds_draw(struct ds_gpu *gpu, GLuint loc_uFlags);
void ds_draw_clear(struct ds_draw *draw);
void ds_gpu_clear(struct ds_gpu *gpu);
struct ds_unit *ds_unit_clone(struct ds_unit *unit);

#endif