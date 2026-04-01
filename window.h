#ifndef window_h
#define window_h

#include "draw.h"
#include "glad.h"
#include "object.h"

#include "cglm/include/cglm/call.h"
#include "platform.h"
#include "ui_cursor.h"
#include "ui_grid.h"
#include "ui_selection.h"

struct gllc_window_GPU {
  GLuint program;
  GLuint loc_uMVP;
  GLuint loc_uScale;
  GLuint loc_uViewportSize;
  struct ds_gpu cmn;
  struct ds_gpu inter;
};

struct gllc_window_cam {
  double dx;
  double dy;
  double scale;
  mat4 mView;
  mat4 mProj;
  mat4 mModel;
  mat4 mMVP;
  mat4 mScreenMVP;
};

struct gllc_window_UI {
  int mx;
  int my;
  int menter;
  int mpressed;
  int mbtn;
  int mdownx;
  int mdowny;
  int width;
  int height;
  double sel_x0;
  double sel_y0;
  GLfloat back_color[4];
  int grid_enable;
  struct ui_grid grid;
  struct ui_cursor cursor;
  struct ui_selection sel;
};

struct gllc_window {
  struct gllc_object _obj;
  int id;
  struct gllc_block *block;
  struct gllc_drawing *drawing;
  struct _gllc_NW nw;
  struct gllc_window_cam cam;
  struct gllc_window_UI UI;
  struct gllc_window_GPU GPU;
};

struct gllc_window *gllc_window_create(void *parent);
void gllc_window_resize(struct gllc_window *window, int x, int y, int width, int height);
void gllc_window_wnd_to_drw(struct gllc_window *w, double x, double y, double *xd, double *yd);
void gllc_window_set_block(struct gllc_window *wnd, struct gllc_block *block);
void gllc_window_destroy(struct gllc_window *wnd);
#endif