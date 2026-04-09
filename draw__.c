#include "draw.h"
#include <stdlib.h>
#include <string.h>

struct ds_unit {
  int flags;
  int modflags;
  GLuint ver_cnt;
  GLuint ind_cnt;
  GLuint ver_cap;
  GLuint ind_cap;
  int order;
  uint64_t ID;
  struct ds_draw *draw;
  struct ds_vertex *ver;
  GLuint *ind;
};

#define HASHTAB_SHIFT 10
#define HASHTAB_CAP (1 << HASHTAB_SHIFT)

#define HASH(ID) (ID & (HASHTAB_CAP - 1))

struct ds_draw {
  struct ds_unit *unit_tab[HASHTAB_CAP];
  int unit_tab_cnt[HASHTAB_CAP];
  int unit_tab_cap[HASHTAB_CAP];
  int unit_last_id;
  int cnt;
  int dirty;
};

struct ds_gpu_batch {
  uint64_t unit_id;
  GLuint flags;
  GLuint offset;
  GLuint count;
};

struct ds_gpu {
  GLuint vao;
  GLuint vbo;
  GLuint ebo;
  GLuint vbo_cnt;
  GLuint ebo_cnt;
  GLuint vbo_cap;
  GLuint ebo_cap;
  GLuint vbo_cache_cap;
  GLuint ebo_cache_cap;
  GLuint batch_cnt;
  struct ds_gpu_batch *batch;
  struct ds_vertex *vbo_cache;
  GLuint *ebo_cache;
};

struct ds_draw *ds_draw_create() {
  struct ds_draw *draw = malloc(sizeof(struct ds_draw));
  if (draw) {
    memset(draw, 0, sizeof(struct ds_draw));
  }
  return draw;
}

struct ds_unit *ds_gen_unit(struct ds_draw *draw) {
  int ID = draw->unit_last_id++;
  int H = HASH(ID);
  int *cap = &draw->unit_tab_cap[H];
  int *cnt = &draw->unit_tab_cnt[H];
  struct ds_unit **tab = &draw->unit_tab[H];

  if (*cap <= *cnt + 1) {
    size_t s = *cap ? *cap * 2 : 8;
    struct ds_unit *ntab = realloc(*tab, s * sizeof(struct ds_unit));
    if (ntab) {
      *tab = ntab;
      *cap = s;
    } else {
      return NULL;
    }
  }

  tab[*cnt]->ID = ID;
  (*cnt)++;

  return tab[*cnt];
}

int ds_unit_reserve(struct ds_unit *u, GLuint vcap, GLuint icap) {
  if (u->ver_cap < vcap) {
    if (vcap < u->ver_cnt) {
      return 0;
    }
    struct ds_vertex *v = realloc(u->ver, vcap * sizeof(struct ds_vertex));
    if (v) {
      u->ver = v;
      u->ver_cap = vcap;
    } else {
      return 0;
    }
  }
  if (u->ind_cap < icap) {
    if (icap < u->ind_cnt) {
      return 0;
    }
    GLuint *i = realloc(u->ver, vcap * sizeof(GLuint));
    if (i) {
      u->ind = i;
      u->ind_cap = icap;
    } else {
      return 0;
    }
  }
  return 1;
}

int ds_unit_flags(struct ds_unit *u) {
  return u->flags;
}

int ds_unit_modflags(struct ds_unit *u) {
  return u->modflags;
}

void ds_unit_set_modified_flags(struct ds_unit *u, int modflags) {
  u->modflags = modflags;
}

void ds_unit_set_flags(struct ds_unit *u, int flags) {
  u->flags = flags;
}

struct ds_vertex *ds_unit_vertices(struct ds_unit *u) {
  return u->ver;
}

GLuint *ds_unit_indices(struct ds_unit *u) {
  return u->ind;
}

int ds_unit_set_cnt(struct ds_unit *u, GLuint vcnt, GLuint icnt) {
  if (vcnt > u->ver_cap) {
    return 0;
  }
  if (icnt > u->ind_cap) {
    return 0;
  }
  u->ver_cnt = vcnt;
  u->ind_cnt = icnt;
  return 1;
}

void ds_unit_get_cnt(struct ds_unit *u, GLuint *vcnt, GLuint *icnt) {
  *vcnt = u->ver_cnt;
  *icnt = u->ind_cnt;
}

void ds_unit_get_capacity(struct ds_unit *u, GLuint *vcap, GLuint *icap) {
  *vcap = u->ver_cap;
  *icap = u->ind_cap;
}

void ds_delete_unit(struct ds_unit *u) {
   
}