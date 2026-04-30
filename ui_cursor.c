#include "ui_cursor.h"
#include "draw.h"

#define CURSOR_VCOUNT 12
#define CURSOR_VBO_SIZE (CURSOR_VCOUNT * sizeof(struct ds_vertex))

void ui_cursor_init(struct ui_cursor *cur) {
  cur->color[0] = 1.0f;
  cur->color[1] = 0.0f;
  cur->color[2] = 0.0f;
  cur->color[3] = 1.0f;
}

void ui_cursor_draw(struct ui_cursor *c, int mx, int my, int width, int height) {
  if (!c->VAO) {
    glGenVertexArrays(1, &c->VAO);
    glBindVertexArray(c->VAO);
    glGenBuffers(1, &c->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, c->VBO);
    glBufferData(GL_ARRAY_BUFFER, CURSOR_VBO_SIZE, NULL, GL_STREAM_DRAW);

    ds_attrib_ptr();
  } else {
    glBindVertexArray(c->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, c->VBO);
  }

  unsigned char r = 255 * c->color[0];
  unsigned char g = 255 * c->color[1];
  unsigned char b = 255 * c->color[2];
  unsigned char a = 255 * c->color[3];
  static struct ds_vertex V[CURSOR_VCOUNT];

#define SET_VER(I, X, Y)        \
  do {                          \
    V[(I)].p[0] = (GLfloat)(X); \
    V[(I)].p[1] = (GLfloat)(Y); \
    V[(I)].n[0] = 1.0f;         \
    V[(I)].n[1] = 1.0f;         \
    V[(I)].uv[0] = 0.0f;        \
    V[(I)].uv[1] = 0.0f;        \
    V[(I)].c[0] = r;            \
    V[(I)].c[1] = g;            \
    V[(I)].c[2] = b;            \
    V[(I)].c[3] = a;            \
    V[(I)].th = 0.0f;           \
  } while (0)

  SET_VER(0, mx, (double)my - 99.5f);
  SET_VER(1, mx, (double)my + 99.5f);
  SET_VER(2, (double)mx - 99.5f, my);
  SET_VER(3, (double)mx + 99.5f, my);
  SET_VER(4, (double)mx - 4.0f, (double)my - 4.0f);
  SET_VER(5, (double)mx + 4.0f, (double)my - 4.0f);
  SET_VER(6, (double)mx + 4.0f, (double)my - 4.0f);
  SET_VER(7, (double)mx + 4.0f, (double)my + 4.0f);
  SET_VER(8, (double)mx + 4.0f, (double)my + 4.0f);
  SET_VER(9, (double)mx - 4.0f, (double)my + 4.0f);
  SET_VER(10, (double)mx - 4.5f, (double)my + 4.5f);
  SET_VER(11, (double)mx - 4.0f, (double)my - 4.0f);

  glBufferSubData(GL_ARRAY_BUFFER, 0, CURSOR_VBO_SIZE, V);
  glDrawArrays(GL_LINES, 0, CURSOR_VCOUNT);
}

void ui_cursor_cleanup(struct ui_cursor *cur) {
  if (cur->VBO) {
    glDeleteBuffers(1, &cur->VBO);
    cur->VBO = 0;
  }
  if (cur->VAO) {
    glDeleteVertexArrays(1, &cur->VAO);
    cur->VAO = 0;
  }
}