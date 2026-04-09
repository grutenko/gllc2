#ifndef draw_h
#define draw_h

#include "glad.h"

struct ds_vertex {
  GLfloat thickness;
  GLbyte n[2];
  GLubyte uv[2];
  GLubyte c[4];
  GLfloat p[2];
};

struct ds_draw;
struct ds_gpu;
struct ds_unit;

struct ds_unit *ds_gen_unit(struct ds_draw *draw);
int ds_unit_reserve(struct ds_unit *u, GLuint vcap, GLuint icap);
int ds_unit_flags(struct ds_unit *u);
int ds_unit_modified(struct ds_unit *u);
void ds_unit_set_modified_flags(struct ds_unit *u, int modflags);
void ds_unit_set_flags(struct ds_unit *u, int flags);
struct ds_vertex *ds_unit_vertices(struct ds_unit *u);
GLuint *ds_unit_indices(struct ds_unit *u);
int ds_unit_set_cnt(struct ds_unit *u, GLuint vcnt, GLuint icnt);
void ds_unit_get_cnt(struct ds_unit *u, GLuint *vcnt, GLuint *icnt);
void ds_unit_get_capacity(struct ds_unit *u, GLuint *vcap, GLuint *icap);
void ds_delete_unit(struct ds_unit *u);
int ds_draw_modified(struct ds_draw *draw);
struct ds_draw *ds_draw_create();
struct ds_gpu *ds_gpu_create();
void ds_sync(struct ds_draw *draw, struct ds_gpu *gpu);
void ds_draw(struct ds_gpu *gpu);
void ds_draw_destroy(struct ds_draw *draw);
void ds_gpu_destroy(struct ds_gpu *gpu);

#endif