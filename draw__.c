#include "draw__.h"
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
  struct ds_unit *t[HASHTAB_CAP];
  int cnt[HASHTAB_CAP];
  int cap[HASHTAB_CAP];
  int last_ID;
  int total;
  int dirty_cnt;
};

struct ds_gpu_unit {
  uint64_t ID;
  GLuint offset;
  GLuint count;
};

struct ds_gpu_batch {
  GLuint vao;
  GLuint vbo;
  GLuint ebo;
  GLuint vbo_cnt;
  GLuint ebo_cnt;
  GLuint vbo_cap;
  GLuint ebo_cap;
  GLuint flags;
  GLuint count;
  GLuint cnt;
  GLuint cap;
  struct ds_gpu_unit *units;
};

struct ds_gpu {
  GLuint vbo_cache_cap;
  GLuint ebo_cache_cap;
  GLuint batch_cnt;
  struct ds_gpu_batch *batch;
  struct ds_vertex *vbo_cache;
  GLuint *ebo_cache;
};

uint64_t ds_unit_id(struct ds_unit *unit) {
  return unit->ID;
}

struct ds_draw *ds_draw_create() {
  struct ds_draw *draw = malloc(sizeof(struct ds_draw));
  if (draw) {
    memset(draw, 0, sizeof(struct ds_draw));
  }
  return draw;
}

static inline uint64_t scramble_id64(uint64_t x) {
  x ^= x >> 30;
  x *= 0xbf58476d1ce4e5b9ULL;
  x ^= x >> 27;
  x *= 0x94d049bb133111ebULL;
  x ^= x >> 31;
  return x;
}

struct ds_unit *ds_gen_unit(struct ds_draw *draw) {
  int ID = scramble_id64(draw->last_ID++);
  int H = HASH(ID);
  int *cap = &draw->cap[H];
  int *cnt = &draw->cnt[H];
  struct ds_unit **tab = &draw->t[H];

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

static inline struct ds_unit *unit_at(struct ds_draw *draw, uint64_t ID) {
  int H = HASH(ID);
  struct ds_unit **tab = &draw->t[H];
  int cnt = draw->cnt[H];
  for (int i = 0; i < cnt; i++) {
    if (tab[i]->ID == ID) {
      return tab[i];
    }
  }
  return NULL;
}

struct ds_unit *ds_lookup_unit(struct ds_draw *draw, uint64_t ID) {
  return unit_at(draw, ID);
}

void ds_delete_unit(struct ds_draw *draw, uint64_t ID) {
  int H = HASH(ID);
  struct ds_unit **tab = &draw->t[H];
  int *cnt = &draw->cnt[H];
  for (int i = 0; i < *cnt; i++) {
    if (tab[i]->ID == ID) {
      free(tab[i]->ver);
      free(tab[i]->ind);
      memmove(&tab[i], &tab[i + 1], (*cnt - i - 1) * sizeof(struct ds_unit *));
      (*cnt)--;
      return;
    }
  }
}

void ds_draw_destroy(struct ds_draw *draw) {
  int i, j;
  for (i = 0; i < HASHTAB_CAP; i++) {
    for (j = 0; j < draw->cnt[i]; j++) {
      free(draw->t[i][j].ver);
      free(draw->t[i][j].ind);
    }
    free(draw->t[i]);
    draw->cnt[i] = 0;
    draw->cap[i] = 0;
  }
  free(draw);
}