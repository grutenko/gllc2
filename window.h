#ifndef window_h
#define window_h

#include "draw.h"
#include "entity.h"
#include "glad.h"
#include "litecad.h"
#include "object.h"

#include "cglm/call.h"
#include "platform.h"
#include "ui_cursor.h"
#include "ui_grid.h"
#include "ui_selection.h"

struct gllc_window {
  struct gllc_object _obj;
  int id;
  struct gllc_block *block;
  struct gllc_drawing *drawing;
  struct nw nw;
  GLuint program;
  GLuint loc_umvp;
  GLuint loc_uscale;
  GLuint loc_uviewportsize;
  GLuint loc_uflags;
  GLuint loc_uclearcolor;
  struct ds_gpu gpucmn;
  struct ds_gpu gpuinter;
  struct ds_draw inder;
  double dx;
  double dy;
  double scale;
  double mx0;
  double my0;
  mat4 mview;
  mat4 mproj;
  mat4 mmodel;
  mat4 mmvp;
  mat4 mscreenmvp;
  int curx;
  int cury;
  int mpressed;
  int mbtn;
  int mpressx;
  int mpressy;
  int width;
  int height;
  int menter;
  int griduse;
  int drag;
  int selectuse;
  int dtime;
  float clearcolor[4];
  struct gllc_entity *ent;
  struct ui_grid grid;
  struct ui_cursor cursor;
  struct ui_selection sel;
};

struct gllc_window *gllc_window_create(void *parent);
int gllc_window_destroy(struct gllc_window *wnd);
int gllc_window_resize(struct gllc_window *window, int x, int y, int width, int height);
int gllc_window_redraw(struct gllc_window *wnd);
int gllc_window_set_focus(struct gllc_window *wnd);
int gllc_window_set_extents(struct gllc_window *wnd, double Xmin, double Ymin, double Xmax, double Ymax);
int gllc_window_set_block(struct gllc_window *wnd, struct gllc_block *block);
int gllc_window_set_props(struct gllc_window *wnd, void *props);
int gllc_window_set_cmdwin(struct gllc_window *wnd, void *cmdwin);
int gllc_window_set_base_point(struct gllc_window *wnd, int bState, double x, double y);
int gllc_window_emulator(struct gllc_window *wnd, int mode);
int gllc_window_hover_text(struct gllc_window *wnd, const char *text, int x, int y, int align);
int gllc_window_message(struct gllc_window *wnd, const char *text, int type);
int gllc_window_magnifier(struct gllc_window *wnd, int bOn, int Width, int Height, int Zoom, int Flags);
int gllc_window_pick_ent(struct gllc_window *wnd, const char *text, const char *cursor_text);
int gllc_window_wait_point(struct gllc_window *wnd, const char *text, double *x, double *y);
int gllc_window_wait_point_2(struct gllc_window *wnd, const char *text, double *x, double *y, F_WAITPOINT pFunc, int FuncPrm);
int gllc_window_update(struct gllc_window *wnd, int mode);
int gllc_window_input_str(struct gllc_window *wnd);
int gllc_window_zoom_rect(struct gllc_window *wnd, double x0, double y0, double x1, double y1);
int gllc_window_zoom_scale(struct gllc_window *wnd, double scale);
int gllc_window_zoom_move(struct gllc_window *wnd, double dx, double dy);
int gllc_window_zoom_pos(struct gllc_window *wnd, double x, double y, double scale);
int gllc_window_zoom_ent(struct gllc_window *wnd, struct gllc_entity *ent);
void gllc_window_wnd_to_drw(struct gllc_window *w, double x, double y, double *xd, double *yd);
int gllc_window_get_cursor_coord(struct gllc_window *wnd, int *x, int *y, double *wx, double *wy);
int gllc_window_coord_to_drw(struct gllc_window *wnd, int x, int y, double *wx, double *wy);
int gllc_window_coord_to_wnd(struct gllc_window *wnd, double wx, double wy, int *x, int *y);
int gllc_window_get_ents_by_rect(struct gllc_window *wnd, double x0, double y0, double x1, double y1, int cross, int max_ents);
struct gllc_entity *gllc_window_get_ent_by_point(struct gllc_window *wnd, int x, int y);
int gllc_window_get_ents_by_point(struct gllc_window *wnd, int x, int y, int max_ents);
struct gllc_entity *gllc_window_get_ent_by_id(struct gllc_window *wnd, int id);
struct gllc_entity *gllc_window_get_ent_by_idh(struct gllc_window *wnd, const char *idh);
struct gllc_entity *gllc_window_get_ent_by_key(struct gllc_window *wnd, const char *key);
void gllc_window_get_viewport(struct gllc_window *wnd, double *x0, double *y0, double *x1, double *y1);

#endif