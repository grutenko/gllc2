#include "draw.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void push_unit(struct ds_draw *draw, struct ds_unit *unit) {
  if (draw->tail) {
    draw->tail->next = unit;
    unit->prev = draw->tail;
    draw->tail = unit;
  } else {
    draw->head = unit;
    draw->tail = unit;
  }
  draw->unit_cnt++;
}

struct ds_unit *ds_unit_create(struct ds_draw *draw) {
  struct ds_unit *unit = malloc(sizeof(struct ds_unit));
  if (unit) {
    unit->flags = 0;
    unit->draw = draw;
    unit->V = NULL;
    unit->I = NULL;
    unit->V_cnt = 0;
    unit->I_cnt = 0;
    unit->V_cap = 0;
    unit->I_cap = 0;
    unit->next = NULL;
    unit->prev = NULL;
    push_unit(draw, unit);
    unit->draw->dirty = 1;
  }
  return unit;
}

struct ds_vertex *ds_unit_reserve_vertex(struct ds_unit *unit, GLuint cnt) {
  if (unit->V_cap < cnt) {
    size_t new_size = cnt;
    struct ds_vertex *new_V = realloc(unit->V, new_size * sizeof(struct ds_vertex));
    if (!new_V) {
      return NULL;
    }
    unit->V = new_V;
    unit->V_cap = new_size;
    unit->V_cnt = new_size;
  }
  unit->draw->dirty = 1;
  return unit->V;
}

GLuint *ds_unit_reserve_index(struct ds_unit *unit, GLuint cnt) {
  if (unit->I_cap < cnt) {
    size_t new_size = cnt;
    GLuint *new_I = realloc(unit->I, new_size * sizeof(GLuint));
    if (!new_I) {
      return NULL;
    }
    unit->I = new_I;
    unit->I_cap = new_size;
    unit->I_cnt = new_size;
  }
  unit->draw->dirty = 1;
  return unit->I;
}

static void remove_unit(struct ds_draw *draw, struct ds_unit *unit) {
  if (unit->prev) {
    unit->prev->next = unit->next;
  } else {
    draw->head = unit->next;
  }
  if (unit->next) {
    unit->next->prev = unit->prev;
  } else {
    draw->tail = unit->prev;
  }
  draw->unit_cnt--;
  draw->dirty = 1;
}

void ds_unit_destroy(struct ds_unit *unit) {
  if (unit) {
    remove_unit(unit->draw, unit);
    free(unit->V);
    free(unit->I);
    free(unit);
  }
}

// In draw_proc
int ds_draw_dirty(struct ds_draw *draw) {
  if (draw) {
    return draw->dirty;
  }
  return 0;
}

static void gl_check_error(const char *file, int line) {
  GLenum err;
  while ((err = glGetError()) != GL_NO_ERROR) {
    const char *err_str = "UNKNOWN";

    switch (err) {
    case GL_INVALID_ENUM:
      err_str = "GL_INVALID_ENUM";
      break;
    case GL_INVALID_VALUE:
      err_str = "GL_INVALID_VALUE";
      break;
    case GL_INVALID_OPERATION:
      err_str = "GL_INVALID_OPERATION";
      break;
    case GL_INVALID_FRAMEBUFFER_OPERATION:
      err_str = "GL_INVALID_FRAMEBUFFER_OPERATION";
      break;
    case GL_OUT_OF_MEMORY:
      err_str = "GL_OUT_OF_MEMORY";
      break;
    }

    fprintf(stderr, "OpenGL error: %s (%s:%d)\n", err_str, file, line);
  }
}

#define GL_CHECK() gl_check_error(__FILE__, __LINE__)

void ds_attrib_ptr() {
  GLuint stride = sizeof(struct ds_vertex);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, stride, (void *)offsetof(struct ds_vertex, p));
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 2, GL_BYTE, GL_TRUE, stride, (void *)offsetof(struct ds_vertex, n));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(2, 2, GL_UNSIGNED_BYTE, GL_TRUE, stride, (void *)offsetof(struct ds_vertex, uv));
  glEnableVertexAttribArray(2);
  glVertexAttribPointer(3, 4, GL_UNSIGNED_BYTE, GL_TRUE, stride, (void *)offsetof(struct ds_vertex, c));
  glEnableVertexAttribArray(3);
  glVertexAttribPointer(4, 1, GL_FLOAT, GL_FALSE, stride, (void *)offsetof(struct ds_vertex, th));
  glEnableVertexAttribArray(4);
}

#ifdef _WIN32
#include <windows.h>

static double now_sec() {
  LARGE_INTEGER freq, counter;
  QueryPerformanceFrequency(&freq);
  QueryPerformanceCounter(&counter);
  return (double)counter.QuadPart / (double)freq.QuadPart;
}

#else
#include <time.h>

static double now_sec() {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return ts.tv_sec + ts.tv_nsec * 1e-9;
}
#endif

static void ds_sync_soft(struct ds_draw *draw, struct ds_gpu *gpu) {
}

static void ds_sync_all(struct ds_draw *draw, struct ds_gpu *gpu) {
}

void ds_sync(struct ds_draw *draw, struct ds_gpu *gpu) {
  if (draw && gpu) {
    double t0 = now_sec();
    double t1;
    GLuint v_total = 0;
    GLuint i_total = 0;
    struct ds_unit *unit = draw->head;
    while (unit) {
      // Sync unit data to GPU
      v_total += unit->V_cnt;
      i_total += unit->I_cnt;
      unit = unit->next;
    }
    if (v_total > gpu->V_data_capacity) {
      struct ds_vertex *new_V_data = realloc(gpu->V_data, v_total * sizeof(struct ds_vertex));
      if (!new_V_data) {
        // Handle allocation failure
        return;
      }
      gpu->V_data = new_V_data;
      gpu->V_data_capacity = v_total;
    }
    if (i_total > gpu->I_data_capacity) {
      GLuint *new_I_data = realloc(gpu->I_data, i_total * sizeof(GLuint));
      if (!new_I_data) {
        // Handle allocation failure
        return;
      }
      gpu->I_data = new_I_data;
      gpu->I_data_capacity = i_total;
    }
    t1 = now_sec();
    unit = draw->head;
    GLuint offset = 0;
    GLuint i_offset = 0;
    int bi = 0;
    if (gpu->batch_cap < draw->unit_cnt) {
      struct ds_gpu_batch *new_batches = realloc(gpu->batches, draw->unit_cnt * sizeof(struct ds_gpu_batch));
      if (!new_batches) {
        // Handle allocation failure
        return;
      }
      gpu->batches = new_batches;
      gpu->batch_cap = draw->unit_cnt;
    }
    t0 = now_sec();
    for (unit = draw->head, bi = 0; unit; unit = unit->next, bi++) {
      memmove(&gpu->V_data[offset], unit->V, unit->V_cnt * sizeof(struct ds_vertex));
      for (GLuint j = 0; j < unit->I_cnt; j++) {
        gpu->I_data[i_offset + j] = unit->I[j] + offset;
      }
      struct ds_gpu_batch *b = &gpu->batches[bi];
      b->flags = unit->flags;
      b->tex_id = 0;
      b->count = unit->I_cnt;
      b->offset = i_offset;
      offset += unit->V_cnt;
      i_offset += unit->I_cnt;
      unit->dirty = 0;
    }
    gpu->V_data_size = offset;
    gpu->I_data_size = i_offset;

    t1 = now_sec();
    if (!gpu->VAO) {
      glGenVertexArrays(1, &gpu->VAO);
      glGenBuffers(1, &gpu->VBO);
      glGenBuffers(1, &gpu->EBO);
      glBindVertexArray(gpu->VAO);
      glBindBuffer(GL_ARRAY_BUFFER, gpu->VBO);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gpu->EBO);
      ds_attrib_ptr();
    } else {
      glBindVertexArray(gpu->VAO);
      glBindBuffer(GL_ARRAY_BUFFER, gpu->VBO);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gpu->EBO);
    }
    if (gpu->VBO_capacity < gpu->V_data_size) {
      glBufferData(GL_ARRAY_BUFFER, gpu->V_data_size * sizeof(struct ds_vertex), gpu->V_data, GL_STREAM_DRAW);
      gpu->VBO_capacity = gpu->V_data_size;
    } else {
      glBufferSubData(GL_ARRAY_BUFFER, 0, gpu->V_data_size * sizeof(struct ds_vertex), gpu->V_data);
    }
    if (gpu->I_data_size > gpu->EBO_capacity) {
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, gpu->I_data_size * sizeof(GLuint), gpu->I_data, GL_STREAM_DRAW);
      gpu->EBO_capacity = gpu->I_data_size;
    } else {
      glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, gpu->I_data_size * sizeof(GLuint), gpu->I_data);
    }
    gpu->batch_cnt = bi;
    draw->dirty = 0;
  }
}

void ds_draw(struct ds_gpu *gpu, GLuint loc_uFlags) {
  if (gpu) {
    // Bind the VAO
    glBindVertexArray(gpu->VAO);
    int i;
    for (i = 0; i < gpu->batch_cnt; i++) {
      struct ds_gpu_batch *batch = &gpu->batches[i];
      glUniform1i(loc_uFlags, batch->flags);
      glDrawElements(GL_TRIANGLES, batch->count, GL_UNSIGNED_INT, (void *)(batch->offset * sizeof(GLuint)));
      GL_CHECK();
    }
    glUniform1i(loc_uFlags, 0);
  }
}

void ds_draw_clear(struct ds_draw *draw) {
  if (draw) {
    struct ds_unit *unit = draw->head;
    while (unit) {
      struct ds_unit *next = unit->next;
      free(unit->V);
      free(unit->I);
      free(unit);
      unit = next;
    }
    draw->head = NULL;
    draw->tail = NULL;
    draw->unit_cnt = 0;
    draw->dirty = 0;
  }
}

void ds_gpu_clear(struct ds_gpu *gpu) {
  if (gpu) {
    free(gpu->V_data);
    free(gpu->I_data);
    free(gpu->batches);
    gpu->batches = NULL;
    gpu->batch_cnt = 0;
    gpu->batch_cap = 0;
    gpu->V_data = NULL;
    gpu->I_data = NULL;
    gpu->V_data_size = 0;
    gpu->I_data_size = 0;
    gpu->V_data_capacity = 0;
    gpu->I_data_capacity = 0;
  }
}
