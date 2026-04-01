#include "ui_selection.h"
#include "draw.h"
#include <stddef.h>

#define VERTICES 10
#define VBO_SIZE (VERTICES * sizeof(struct ds_vertex))

void ui_selection_init(struct ui_selection *sel) {
  sel->color[0] = 0.0f;
  sel->color[1] = 0.4706f;
  sel->color[2] = 0.8431f;
  sel->color[3] = 1.0f;
}

static inline void _fswap(double *x, double *y) {
  double t = *x;
  *x = *y;
  *y = t;
}

void ui_selection_draw(struct ui_selection *sel, double x0, double y0, double x1, double y1) {
  static struct ds_vertex v[VERTICES];

  int invert = 0;
  if (x0 > x1) {
    _fswap(&x0, &x1);
    invert = 1;
  }
  if (y0 > y1) {
    _fswap(&y0, &y1);
  }

  unsigned char r = 255 * sel->color[0];
  unsigned char g = 255 * sel->color[1];
  unsigned char b = 255 * sel->color[2];
  unsigned char a = 255 * sel->color[3];

  if (invert) {
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
  }

#define SET_VER(I, X, Y, _r, _g, _b, _a) \
  do {                                   \
    v[(I)].p[0] = (GLfloat)(X);          \
    v[(I)].p[1] = (GLfloat)(Y);          \
    v[(I)].c[0] = _r;                    \
    v[(I)].c[1] = _g;                    \
    v[(I)].c[2] = _b;                    \
    v[(I)].c[3] = _a;                    \
    v[(I)].n[0] = 127;                   \
    v[(I)].n[1] = 127;                   \
    v[(I)].uv[0] = 0;                    \
    v[(I)].uv[1] = 0;                    \
  } while (0)

  SET_VER(0, x0, y0, r, g, b, a);
  SET_VER(1, x1, y0, r, g, b, a);
  SET_VER(2, x1, y1, r, g, b, a);
  SET_VER(3, x0, y1, r, g, b, a);
  a = 128;
  SET_VER(4, x0, y0, r, g, b, a);
  SET_VER(5, x1, y0, r, g, b, a);
  SET_VER(6, x1, y1, r, g, b, a);
  SET_VER(7, x0, y0, r, g, b, a);
  SET_VER(8, x1, y1, r, g, b, a);
  SET_VER(9, x0, y1, r, g, b, a);

  if (!sel->VAO) {
    glGenVertexArrays(1, &sel->VAO);
    glGenBuffers(1, &sel->VBO);

    glBindVertexArray(sel->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, sel->VBO);

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

    glBufferData(GL_ARRAY_BUFFER, VBO_SIZE, NULL, GL_DYNAMIC_DRAW);
  } else {
    glBindVertexArray(sel->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, sel->VBO);
  }

  glBufferSubData(GL_ARRAY_BUFFER, 0, VBO_SIZE, v);
  glDrawArrays(GL_LINE_LOOP, 0, 4);
  glDrawArrays(GL_TRIANGLES, 4, 6);
}

void ui_selection_cleanup(struct ui_selection *sel) {
  if (sel->VBO) {
    glDeleteBuffers(1, &sel->VBO);
    sel->VBO = 0;
  }

  if (sel->VAO) {
    glDeleteVertexArrays(1, &sel->VAO);
    sel->VAO = 0;
  }
}