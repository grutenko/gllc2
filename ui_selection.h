#ifndef ui_selection_h
#define ui_selection_h

#include "glad.h"

struct ui_selection {
  GLfloat color[4];
  GLuint VAO;
  GLuint VBO;
};

void ui_selection_init(struct ui_selection *sel);
void ui_selection_draw(struct ui_selection *sel, double x0, double y0, double x1, double y1);
void ui_selection_cleanup(struct ui_selection *sel);

#endif