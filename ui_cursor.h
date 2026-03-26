#ifndef ui_cursor_h
#define ui_cursor_h

#include "draw.h"
#include "glad.h"

struct ui_cursor {
  GLfloat color[4];
  GLuint VAO;
  GLuint VBO;
};

void ui_cursor_init(struct ui_cursor *cur);
void ui_cursor_draw(struct ui_cursor *cur, int mx, int my, int width, int height);
void ui_cursor_cleanup(struct ui_cursor *cur);

#endif