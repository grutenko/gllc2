#ifndef ui_grid_h
#define ui_grid_h

#include "draw.h"
#include "glad.h"

struct ui_grid {
  GLfloat color[4];
  double gap_x;
  double gap_y;
  double offset_x;
  double offset_y;
  struct ds_vertex *v_cache;
  GLuint v_cache_cap;
  GLuint v_cache_size;
  GLuint VAO;
  GLuint VBO;
  GLuint VBO_cnt;
  double last_scale;
  double last_x0;
  double last_y0;
  double last_x1;
  double last_y1;
  double last_vcnt;
};

void ui_grid_init(struct ui_grid *grid);
void ui_grid_draw(struct ui_grid *grid, GLuint loc_uFlags, double scale, double x0, double y0, double x1, double y1);
void ui_grid_cleanup(struct ui_grid *grid);

#endif