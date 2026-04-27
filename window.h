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
  GLuint loc_uFlags;
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
  struct nw nw;
  struct gllc_window_cam cam;
  struct gllc_window_UI UI;
  struct gllc_window_GPU GPU;
};

struct gllc_window *gllc_window_create(void *parent);
int gllc_window_resize(struct gllc_window *window, int x, int y, int width, int height);
void gllc_window_wnd_to_drw(struct gllc_window *w, double x, double y, double *xd, double *yd);
int gllc_window_set_block(struct gllc_window *wnd, struct gllc_block *block);
int gllc_window_destroy(struct gllc_window *wnd);
int gllc_window_redraw(struct gllc_window *wnd);
int gllc_window_zoom_rect(struct gllc_window *wnd, double x0, double y0, double x1, double y1);
int gllc_window_zoom_scale(struct gllc_window *wnd, double scale);
int gllc_window_zoom_move(struct gllc_window *wnd, double dx, double dy);
int gllc_window_zoom_pos(struct gllc_window *wnd, double x, double y, double scale);
int gllc_window_get_cursor_coord(struct gllc_window *wnd, int *x, int *y, double *wx, double *wy);
int gllc_window_coord_to_drw(struct gllc_window *wnd, int x, int y, double *wx, double *wy);
int gllc_window_coord_to_wnd(struct gllc_window *wnd, double wx, double wy, int *x, int *y);
struct gllc_entity *gllc_window_get_ent_by_point(struct gllc_window *wnd, int x, int y);
void gllc_window_get_viewport(struct gllc_window *wnd, double *x0, double *y0, double *x1, double *y1);

#endif