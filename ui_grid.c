#include "ui_grid.h"
#include "alloc.h"
#include "draw.h"

#include <math.h>
#include <stdlib.h>

void ui_grid_init(struct ui_grid *grid) {
  grid->gap_x = 100.0f;
  grid->gap_y = 100.0f;
  grid->offset_x = 0.0f;
  grid->offset_y = 0.0f;
  grid->v_cache = NULL;
  grid->v_cache_cap = 0;
  grid->color[0] = 0.3f;
  grid->color[1] = 0.3f;
  grid->color[2] = 0.3f;
  grid->color[3] = 1.0f;
}

static void render(struct ui_grid *grid, double scale, double x0, double y0, double x1, double y1) {
  double gap_x = grid->gap_x;
  double gap_y = grid->gap_y;

  while ((gap_x / scale) > (grid->gap_x / 10))
    gap_x /= 10;
  while ((gap_x / scale) < (grid->gap_x / 10))
    gap_x *= 10;
  while ((gap_y / scale) > (grid->gap_y / 10))
    gap_y /= 10;
  while ((gap_y / scale) < (grid->gap_y / 10))
    gap_y *= 10;

  // Определение позиции вхождения первой линии
  double ix = floor(x0 / gap_x);
  double X = ix * gap_x;
  if (X < x0)
    X += gap_x;
  double iy = floor(y0 / gap_y);
  double Y = iy * gap_y;
  if (Y < y0)
    Y += gap_y;

  // определение близости к следующему кратному.
  double coeff = (gap_x / scale) / grid->gap_x;
  if (coeff > 1.0) coeff = 1.0;

  GLuint vcap = 2 * (ceil((x1 - x0) / gap_x) + ceil((y1 - y0) / gap_y) + ceil((x1 - x0) / (gap_x * 10)) + ceil((y1 - y0) / (gap_y * 10))) + 4;

  if (grid->v_cache_cap < vcap) {
    struct ds_vertex *newv = realloc(grid->v_cache, sizeof(struct ds_vertex) * vcap);
    if (newv) {
      grid->v_cache = newv;
      grid->v_cache_cap = vcap;
    } else {
      return;
    }
  }

  grid->v_cache_size = vcap;

  int i;
  unsigned char r = 255 * grid->color[0];
  unsigned char g = 255 * grid->color[1];
  unsigned char b = 255 * grid->color[2];
  unsigned char a = 255 * grid->color[3] * coeff;

#define SET_VER(I, X, Y, _r, _g, _b, _a)        \
  do {                                          \
    struct ds_vertex *v0 = &grid->v_cache[(I)]; \
    v0->p[0] = (X);                             \
    v0->p[1] = (Y);                             \
    v0->c[0] = _r;                              \
    v0->c[1] = _g;                              \
    v0->c[2] = _b;                              \
    v0->c[3] = _a;                              \
    v0->n[0] = 127;                             \
    v0->n[1] = 127;                             \
    v0->uv[0] = 0;                              \
    v0->uv[1] = 0;                              \
    v0->thickness = 0;                          \
  } while (0)

  for (i = 0; X < x1; X += gap_x, i += 2) {
    SET_VER(i, X, y0, r, g, b, a);
    SET_VER(i + 1, X, y1, r, g, b, a);
  }
  for (; Y < y1; Y += gap_y, i += 2) {
    SET_VER(i, x0, Y, r, g, b, a);
    SET_VER(i + 1, x1, Y, r, g, b, a);
  }

  gap_x *= 10;
  gap_y *= 10;
  ix = floor(x0 / gap_x);
  X = ix * gap_x;
  if (X < x0)
    X += gap_x;
  iy = floor(y0 / gap_y);
  Y = iy * gap_y;
  if (Y < y0)
    Y += gap_y;
  a = 255 * grid->color[3];

  for (; X < x1; X += gap_x, i += 2) {
    SET_VER(i, X, y0, r, g, b, a);
    SET_VER(i + 1, X, y1, r, g, b, a);
  }
  for (; Y < y1; Y += gap_y, i += 2) {
    SET_VER(i, x0, Y, r, g, b, a);
    SET_VER(i + 1, x1, Y, r, g, b, a);
  }

  SET_VER(i++, x0, 0.0f, 0, 255, 0, 255);
  SET_VER(i++, x1, 0.0f, 0, 255, 0, 255);
  SET_VER(i++, 0.0f, y0, 0, 0, 255, 255);
  SET_VER(i++, 0.0f, y1, 0, 0, 255, 255);

  if (!grid->VAO) {
    glGenVertexArrays(1, &grid->VAO);
    glGenBuffers(1, &grid->VBO);

    glBindVertexArray(grid->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, grid->VBO);

    GLuint stride = sizeof(struct ds_vertex);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, stride, (void *)offsetof(struct ds_vertex, p));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_BYTE, GL_TRUE, stride, (void *)offsetof(struct ds_vertex, n));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_UNSIGNED_BYTE, GL_TRUE, stride, (void *)offsetof(struct ds_vertex, uv));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(3, 4, GL_UNSIGNED_BYTE, GL_TRUE, stride, (void *)offsetof(struct ds_vertex, c));
    glEnableVertexAttribArray(3);
    glVertexAttribIPointer(4, 1, GL_UNSIGNED_SHORT, stride, (void *)offsetof(struct ds_vertex, thickness));
      glEnableVertexAttribArray(4);
  } else {
    glBindVertexArray(grid->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, grid->VBO);
  }

  if (vcap > grid->VBO_cnt) {
    glBufferData(GL_ARRAY_BUFFER, i * sizeof(struct ds_vertex), grid->v_cache, GL_DYNAMIC_DRAW);
    grid->VBO_cnt = vcap;
  } else {
    glBufferSubData(GL_ARRAY_BUFFER, 0, i * sizeof(struct ds_vertex), grid->v_cache);
  }

  grid->last_vcnt = i;
}

void ui_grid_draw(struct ui_grid *grid, double scale, double x0, double y0, double x1, double y1) {
  if (grid->last_scale != scale || grid->last_x0 != x0 || grid->last_y0 != y0 || grid->last_x1 != x1 || grid->last_y1 != y1) {
    // перестраиваем сетку только при изменении параметров, которые на нее влияют.
    render(grid, scale, x0, y0, x1, y1);
  } else {
    // Иначе просто чисуем готовый VBO
    glBindVertexArray(grid->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, grid->VBO);
  }
  glDrawArrays(GL_LINES, 0, grid->last_vcnt);

  grid->last_scale = scale;
  grid->last_x0 = x0;
  grid->last_y0 = y0;
  grid->last_x1 = x1;
  grid->last_y1 = y1;
}

void ui_grid_cleanup(struct ui_grid *grid) {
  if (grid->VBO) {
    glDeleteBuffers(1, &grid->VBO);
    grid->VBO = 0;
  }

  if (grid->VAO) {
    glDeleteVertexArrays(1, &grid->VAO);
    grid->VAO = 0;
  }

  XFREE(grid->v_cache);
  grid->v_cache_cap = 0;
  grid->v_cache_size = 0;
  grid->VBO_cnt = 0;
}