#include "window.h"
#include "block.h"
#include "debug.h"
#include "draw.h"
#include "event.h"
#include "frag.h"
#include "litecad.h"
#include "object.h"
#include "platform.h"
#include "ui_cursor.h"
#include "ui_grid.h"
#include "ui_selection.h"
#include "vert.h"

#include <string.h>

#define WND(obj) ((struct gllc_window *)obj)

#define COLORI2F(C, CP)                 \
  do {                                  \
    (CP)[0] = (float)((C) >> 16) / 255; \
    (CP)[1] = (float)((C) >> 8) / 255;  \
    (CP)[2] = (float)(C) / 255;         \
    (CP)[3] = 1.0f;                     \
  } while (0)

#define COLORF2I(CP, C)                                                                      \
  do {                                                                                       \
    (C) = ((int)((CP)[0] * 255) << 16) | ((int)((CP)[1] * 255) << 8) | (int)((CP)[2] * 255); \
  } while (0)

static void _destroy(struct gllc_object *obj) {}

static union gllc_variant _wnd_id_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = WND(obj)->id;
  return v;
}

static int _wnd_id_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  WND(obj)->id = value.int_;
  return 1;
}

static union gllc_variant _wnd_width_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = WND(obj)->width;
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_height_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = WND(obj)->height;
  return v;
}

static union gllc_variant _wnd_frame_left_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = 0;
  return v;
}

static union gllc_variant _wnd_frame_top_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = 0;
  return v;
}

static union gllc_variant _wnd_frame_width_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = WND(obj)->width;
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_frame_height_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = WND(obj)->height;
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_HWND_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_block_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = WND(obj)->block;
  return v;
}

static union gllc_variant _wnd_drw_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = WND(obj)->drawing;
  return v;
}

static union gllc_variant _wnd_hasfocus_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_pixelsize_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = WND(obj)->scale;
  return v;
}

static inline void update_camera(struct gllc_window *w);

static int _wnd_pixelsize_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  if (value.float_ < 1000.0f && value.float_ < 0.0001f) {
    WND(obj)->scale = value.float_;
    update_camera(WND(obj));
    nw_dirty(&WND(obj)->nw);
    return 1;
  }
  return 0;
}

static union gllc_variant _wnd_select_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = WND(obj)->selectuse;
  return (union gllc_variant)0;
}

static int _wnd_select_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  WND(obj)->selectuse = !!value.bool_;
  return 1;
}

static union gllc_variant _wnd_dtime_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = WND(obj)->dtime;
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_frozen_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_frozen_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_frozenview_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_frozenview_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_command_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_cmdent1_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_cmdent1_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_osnap_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_osnap_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_osnap_menu_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_osnap_menu_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_ptrack_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_ptrack_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_PTRACK_ANGLE_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_PTRACK_ANGLE_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_PTRACK_ANGREL_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_PTRACK_ANGREL_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_PTRACK_DIST_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_PTRACK_DIST_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_BASEPT_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_BASEX_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_BASEY_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_ORTHO_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_ORTHO_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_BGIMAGE_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_BGIMAGE_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_TIN_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_TIN_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_HASFILETABS_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_NUMFILETABS_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_NUMDRW_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_ENT_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_DROPFILES_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_DROPFILES_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_ZOOMWHEEL_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_ZOOMWHEEL_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_cmd_id_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_cmd_handle_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_cmd_active_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

/* OSNAP */
static union gllc_variant _wnd_osnap_mode_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_osnap_mode_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_osnap_on_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_osnap_on_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_osnapmenu_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_osnapmenu_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_ptrack_angle_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_ptrack_angle_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_ptrack_angrel_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_ptrack_angrel_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_ptrack_dist_enable_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_ptrack_dist_enable_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_ptrack_dist_value_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_ptrack_dist_value_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

/* BASE POINT */
static union gllc_variant _wnd_basept_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_basex_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_basey_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

/* BGIMAGE */
static union gllc_variant _wnd_bgimage_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_bgimage_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_bgimage_visible_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_bgimage_visible_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

/* FILE TABS / DRW */
static union gllc_variant _wnd_hasfiletabs_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_numfiletabs_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_numdrw_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

/* PICKED ENTITY */
static union gllc_variant _wnd_ent_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

/* WINDOW FLAGS */
static union gllc_variant _wnd_dropfiles_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_dropfiles_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_zoomwheel_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_zoomwheel_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

/* UI VISIBILITY */
static union gllc_variant _wnd_rulers_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_rulers_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_magnifier_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_magnifier_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_navigator_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_navigator_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

/* RENDER */
static union gllc_variant _wnd_alphablend_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_alphablend_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

/* CURSOR */
static union gllc_variant _wnd_cursorarrow_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_cursorarrow_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_cursorsys_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_cursorsys_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_cursorhandle_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_cursorhandle_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_cursorcross_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_cursorcross_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_cursorsize_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_cursorsize_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

static union gllc_variant _wnd_cursorpbox_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_cursorpbox_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

/* PICKBOX */
static union gllc_variant _wnd_pickboxsize_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

/* CURSOR POSITION */
static union gllc_variant _wnd_curx_px_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_curx_unit_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

/* CURSOR Y */
static union gllc_variant _wnd_cury_px_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_cury_unit_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

/* VIEW BOUNDS */
static union gllc_variant _wnd_xmin_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;
  gllc_window_get_viewport(WND(obj), &x0, &y0, &x1, &y1);
  v.float_ = x0;
  return v;
}

static union gllc_variant _wnd_ymin_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;
  gllc_window_get_viewport(WND(obj), &x0, &y0, &x1, &y1);
  v.float_ = y0;
  return v;
}

static union gllc_variant _wnd_xmax_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;
  gllc_window_get_viewport(WND(obj), &x0, &y0, &x1, &y1);
  v.float_ = x1;
  return v;
}

static union gllc_variant _wnd_ymax_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;
  gllc_window_get_viewport(WND(obj), &x0, &y0, &x1, &y1);
  v.float_ = y1;
  return v;
}

/* VIEW CENTER */
static union gllc_variant _wnd_xcen_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;
  gllc_window_get_viewport(WND(obj), &x0, &y0, &x1, &y1);
  v.float_ = x0 + (x1 - x0) * 0.5f;
  return v;
}

static union gllc_variant _wnd_ycen_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;
  gllc_window_get_viewport(WND(obj), &x0, &y0, &x1, &y1);
  v.float_ = y0 + (y1 - y0) * 0.5f;
  return v;
}

/* VIEW SIZE */
static union gllc_variant _wnd_dx_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;
  gllc_window_get_viewport(WND(obj), &x0, &y0, &x1, &y1);
  v.float_ = x1 - x0;
  return v;
}

static union gllc_variant _wnd_dy_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;
  gllc_window_get_viewport(WND(obj), &x0, &y0, &x1, &y1);
  v.float_ = y1 - y0;
  return v;
}

/* GRID */
static union gllc_variant _wnd_gridsnap_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = WND(obj)->grid.snap;
  return v;
}

static int _wnd_gridsnap_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  WND(obj)->grid.snap = !!v.bool_;
  return 1;
}

static union gllc_variant _wnd_gridshow_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = WND(obj)->griduse;
  return v;
}

static int _wnd_gridshow_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  WND(obj)->griduse = !!v.bool_;
  return 1;
}

static union gllc_variant _wnd_griddx_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = WND(obj)->grid.gap_x;
  return v;
}

static int _wnd_griddx_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  WND(obj)->grid.gap_x = v.float_;
  return 1;
}

static union gllc_variant _wnd_griddy_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = WND(obj)->grid.gap_y;
  return v;
}

static int _wnd_griddy_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  WND(obj)->grid.gap_y = v.float_;
  return 1;
}

/* GRID COLORS */
static union gllc_variant _wnd_gridcolor_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  COLORF2I(WND(obj)->grid.color, v.int_);
  return v;
}

static int _wnd_gridcolor_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  COLORI2F(v.int_, WND(obj)->grid.color);
  return 1;
}

static union gllc_variant _wnd_gridcolor2_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  COLORF2I(WND(obj)->grid.colorbold, v.int_);
  return v;
}

static int _wnd_gridcolor2_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  COLORI2F(v.int_, WND(obj)->grid.colorbold);
  return 1;
}

/* ORTHO */
static union gllc_variant _wnd_ortho_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_ortho_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 1;
}

/* GRIDX0 */
static union gllc_variant _wnd_gridx0_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = WND(obj)->grid.offset_x;
  return v;
}

static int _wnd_gridx0_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  WND(obj)->grid.offset_x = v.float_;
  return 1;
}

/* GRIDY0 */
static union gllc_variant _wnd_gridy0_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = WND(obj)->grid.offset_x;
  return v;
}

static int _wnd_gridy0_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  WND(obj)->grid.offset_y = v.float_;
  return 1;
}

/* GRIDBOLDX */
static union gllc_variant _wnd_gridboldx_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = WND(obj)->grid.boldx;
  return v;
}

static int _wnd_gridboldx_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  WND(obj)->grid.boldx = v.int_;
  return 1;
}

/* GRIDBOLDY */
static union gllc_variant _wnd_gridboldy_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = WND(obj)->grid.boldy;
  return v;
}

static int _wnd_gridboldy_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  WND(obj)->grid.boldy = v.int_;
  return 1;
}

/* GRIDDOTTED */
static union gllc_variant _wnd_griddotted_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = WND(obj)->grid.dotted;
  return v;
}

static int _wnd_griddotted_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  WND(obj)->grid.dotted = !!v.bool_;
  return 1;
}

/* GRIDDOTTED2 */
static union gllc_variant _wnd_griddotted2_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = WND(obj)->grid.dottedbold;
  return v;
}

static int _wnd_griddotted2_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  WND(obj)->grid.dottedbold = !!v.bool_;
  return 1;
}

struct gllc_prop _props[] = {
    P_INT(LC_PROP_WND_ID, _wnd_id_GET, _wnd_id_SET),
    P_INT_RO(LC_PROP_WND_WIDTH, _wnd_width_GET),
    P_INT_RO(LC_PROP_WND_HEIGHT, _wnd_height_GET),
    P_INT_RO(LC_PROP_WND_FRAME_LEFT, _wnd_frame_left_GET),
    P_INT_RO(LC_PROP_WND_FRAME_TOP, _wnd_frame_top_GET),
    P_INT_RO(LC_PROP_WND_FRAME_WIDTH, _wnd_frame_width_GET),
    P_INT_RO(LC_PROP_WND_FRAME_HEIGHT, _wnd_frame_height_GET),
    P_HANDLE_RO(LC_PROP_WND_HWND, _wnd_HWND_GET),
    P_HANDLE_RO(LC_PROP_WND_VIEWBLOCK, _wnd_block_GET),
    P_HANDLE_RO(LC_PROP_WND_DRW, _wnd_drw_GET),
    P_BOOL_RO(LC_PROP_WND_HASFOCUS, _wnd_hasfocus_GET),
    P_FLOAT(LC_PROP_WND_PIXELSIZE, _wnd_pixelsize_GET, _wnd_pixelsize_SET),
    P_BOOL(LC_PROP_WND_SELECT, _wnd_select_GET, _wnd_select_SET),
    P_INT_RO(LC_PROP_WND_DTIME, _wnd_dtime_GET),
    P_BOOL(LC_PROP_WND_FROZEN, _wnd_frozen_GET, _wnd_frozen_SET),
    P_BOOL(LC_PROP_WND_FROZENVIEW, _wnd_frozenview_GET, _wnd_frozenview_SET),
    P_INT_RO(LC_PROP_WND_CMD, _wnd_cmd_id_GET),
    P_HANDLE_RO(LC_PROP_WND_CMD, _wnd_cmd_handle_GET),
    P_BOOL_RO(LC_PROP_WND_CMD, _wnd_cmd_active_GET),
    P_BOOL(LC_PROP_WND_CMDENT1, _wnd_cmdent1_GET, _wnd_cmdent1_SET),
    P_INT(LC_PROP_WND_OSNAP, _wnd_osnap_mode_GET, _wnd_osnap_mode_SET),
    P_BOOL(LC_PROP_WND_OSNAP, _wnd_osnap_on_GET, _wnd_osnap_on_SET),
    P_BOOL(LC_PROP_WND_OSNAPMENU, _wnd_osnapmenu_GET, _wnd_osnapmenu_SET),
    P_BOOL(LC_PROP_WND_PTRACK, _wnd_ptrack_GET, _wnd_ptrack_SET),
    P_FLOAT(LC_PROP_WND_PTRACK_ANGLE, _wnd_ptrack_angle_GET, _wnd_ptrack_angle_SET),
    P_BOOL(LC_PROP_WND_PTRACK_ANGREL, _wnd_ptrack_angrel_GET, _wnd_ptrack_angrel_SET),
    P_BOOL(LC_PROP_WND_PTRACK_DIST, _wnd_ptrack_dist_enable_GET, _wnd_ptrack_dist_enable_SET),
    P_FLOAT(LC_PROP_WND_PTRACK_DIST, _wnd_ptrack_dist_value_GET, _wnd_ptrack_dist_value_SET),
    P_BOOL_RO(LC_PROP_WND_BASEPT, _wnd_basept_GET),
    P_FLOAT_RO(LC_PROP_WND_BASEX, _wnd_basex_GET),
    P_FLOAT_RO(LC_PROP_WND_BASEY, _wnd_basey_GET),
    P_BOOL(LC_PROP_WND_ORTHO, _wnd_ortho_GET, _wnd_ortho_SET),
    P_STRING(LC_PROP_WND_BGIMAGE, _wnd_bgimage_GET, _wnd_bgimage_SET),
    P_BOOL(LC_PROP_WND_BGIMAGE, _wnd_bgimage_visible_GET, _wnd_bgimage_visible_SET),
    P_BOOL_RO(LC_PROP_WND_HASFILETABS, _wnd_hasfiletabs_GET),
    P_INT_RO(LC_PROP_WND_NUMFILETABS, _wnd_numfiletabs_GET),
    P_INT_RO(LC_PROP_WND_NUMDRW, _wnd_numdrw_GET),
    P_HANDLE_RO(LC_PROP_WND_ENT, _wnd_ent_GET),
    P_BOOL(LC_PROP_WND_DROPFILES, _wnd_dropfiles_GET, _wnd_dropfiles_SET),
    P_BOOL(LC_PROP_WND_ZOOMWHEEL, _wnd_zoomwheel_GET, _wnd_zoomwheel_SET),
    P_BOOL(LC_PROP_WND_RULERS, _wnd_rulers_GET, _wnd_rulers_SET),
    P_BOOL(LC_PROP_WND_MAGNIFIER, _wnd_magnifier_GET, _wnd_magnifier_SET),
    P_BOOL(LC_PROP_WND_NAVIGATOR, _wnd_navigator_GET, _wnd_navigator_SET),
    P_BOOL(LC_PROP_WND_ALPHABLEND, _wnd_alphablend_GET, _wnd_alphablend_SET),
    P_BOOL(LC_PROP_WND_CURSORARROW, _wnd_cursorarrow_GET, _wnd_cursorarrow_SET),
    P_INT(LC_PROP_WND_CURSORSYS, _wnd_cursorsys_GET, _wnd_cursorsys_SET),
    P_HANDLE(LC_PROP_WND_CURSORSYS, _wnd_cursorhandle_GET, _wnd_cursorhandle_SET),
    P_BOOL(LC_PROP_WND_CURSORCROSS, _wnd_cursorcross_GET, _wnd_cursorcross_SET),
    P_INT(LC_PROP_WND_CURSORSIZE, _wnd_cursorsize_GET, _wnd_cursorsize_SET),
    P_BOOL(LC_PROP_WND_CURSORPBOX, _wnd_cursorpbox_GET, _wnd_cursorpbox_SET),
    P_FLOAT_RO(LC_PROP_WND_PICKBOXSIZE, _wnd_pickboxsize_GET),
    P_INT_RO(LC_PROP_WND_CURX, _wnd_curx_px_GET),
    P_FLOAT_RO(LC_PROP_WND_CURX, _wnd_curx_unit_GET),
    P_INT_RO(LC_PROP_WND_CURY, _wnd_cury_px_GET),
    P_FLOAT_RO(LC_PROP_WND_CURY, _wnd_cury_unit_GET),
    P_FLOAT_RO(LC_PROP_WND_XMIN, _wnd_xmin_GET),
    P_FLOAT_RO(LC_PROP_WND_YMIN, _wnd_ymin_GET),
    P_FLOAT_RO(LC_PROP_WND_XMAX, _wnd_xmax_GET),
    P_FLOAT_RO(LC_PROP_WND_YMAX, _wnd_ymax_GET),
    P_FLOAT_RO(LC_PROP_WND_XCEN, _wnd_xcen_GET),
    P_FLOAT_RO(LC_PROP_WND_YCEN, _wnd_ycen_GET),
    P_FLOAT_RO(LC_PROP_WND_DX, _wnd_dx_GET),
    P_FLOAT_RO(LC_PROP_WND_DY, _wnd_dy_GET),
    P_BOOL(LC_PROP_WND_GRIDSNAP, _wnd_gridsnap_GET, _wnd_gridsnap_SET),
    P_BOOL(LC_PROP_WND_GRIDSHOW, _wnd_gridshow_GET, _wnd_gridshow_SET),
    P_FLOAT(LC_PROP_WND_GRIDDX, _wnd_griddx_GET, _wnd_griddx_SET),
    P_FLOAT(LC_PROP_WND_GRIDDY, _wnd_griddy_GET, _wnd_griddy_SET),
    P_INT(LC_PROP_WND_GRIDCOLOR, _wnd_gridcolor_GET, _wnd_gridcolor_SET),
    P_INT(LC_PROP_WND_GRIDCOLOR2, _wnd_gridcolor2_GET, _wnd_gridcolor2_SET),
    P_FLOAT(LC_PROP_WND_GRIDX0, _wnd_gridx0_GET, _wnd_gridx0_SET),
    P_FLOAT(LC_PROP_WND_GRIDY0, _wnd_gridy0_GET, _wnd_gridy0_SET),
    P_INT(LC_PROP_WND_GRIDBOLDX, _wnd_gridboldx_GET, _wnd_gridboldx_SET),
    P_INT(LC_PROP_WND_GRIDBOLDY, _wnd_gridboldy_GET, _wnd_gridboldy_SET),
    P_BOOL(LC_PROP_WND_GRIDDOTTED, _wnd_griddotted_GET, _wnd_griddotted_SET),
    P_BOOL(LC_PROP_WND_GRIDDOTTED2, _wnd_griddotted2_GET, _wnd_griddotted2_SET),
    P_END};
static struct gllc_prop *_all_props[] = {_props, NULL};
static struct gllc_object_vtable _vtable = {
    .type = GLLC_WINDOW,
    .destroy = _destroy};

static inline void screen_to_world(struct gllc_window *w, double x, double y, double *xd, double *yd) {
  double _w = (double)w->width;
  double _h = (double)w->height;
  *xd = (x - (_w / 2)) * w->scale - w->dx;
  *yd = ((_h - y) - (_h / 2)) * w->scale - w->dy;
}

static inline void world_to_screen(struct gllc_window *w, double x, double y, int *sx, int *sy) {
  double _w = (double)w->width;
  double _h = (double)w->height;

  double xs = ((x + w->dx) / w->scale) + (_w / 2);
  double ys = _h - (((y + w->dy) / w->scale) + (_h / 2));

  *sx = (int)xs;
  *sy = (int)ys;
}

#define GL_CHECK() gl_check_error(__FILE__, __LINE__)

static void draw(struct gllc_window *wnd) {
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  double x0, y0, x1, y1;
  float _w = (float)wnd->width;
  float _h = (float)wnd->height;
  const float *_mvp = (const float *)wnd->mmvp;
  const float *_screenmvp = (const float *)wnd->mscreenmvp;
  screen_to_world(wnd, 0.0f, _h, &x0, &y0);
  screen_to_world(wnd, _w, 0.0f, &x1, &y1);
  nw_make_context_current(&wnd->nw);
  glClear(GL_COLOR_BUFFER_BIT);
  glUseProgram(wnd->program);
  glUniformMatrix4fv(wnd->loc_umvp, 1, GL_FALSE, _mvp);
  glUniform4fv(wnd->loc_uclearcolor, 1, wnd->clearcolor);
  glUniform2f(wnd->loc_uviewportsize, _w, _h);
  glUniform1f(wnd->loc_uscale, wnd->scale);
  if (wnd->griduse) {
    ui_grid_draw(&wnd->grid, wnd->loc_uflags, wnd->scale, x0, y0, x1, y1);
  }
  if (wnd->block) {
    gllc_block_sync_gpu(wnd->block, &wnd->gpucmn);
    ds_draw(&wnd->gpucmn, wnd->loc_uflags);
  }
  if (wnd->mpressed && wnd->mbtn == 1) {
    double sx0, sy0, sx1, sy1;
    sx0 = wnd->mx0;
    sy0 = wnd->my0;
    screen_to_world(wnd, wnd->curx, wnd->cury, &sx1, &sy1);
    ui_selection_draw(&wnd->sel, sx0, sy0, sx1, sy1);
  }
  glUniformMatrix4fv(wnd->loc_umvp, 1, GL_FALSE, _screenmvp);
  ui_cursor_draw(&wnd->cursor, wnd->curx, wnd->cury, wnd->width, wnd->height);
  nw_swap_buffers(&wnd->nw);
}

static void on_paint(struct nw *w, void *data) {
  nw_make_context_current(w);
  draw(WND(data));
}

static inline void update_camera(struct gllc_window *w) {
  float half_w = (float)w->width / 2.0f * w->scale;
  float half_h = (float)w->height / 2.0f * w->scale;
  glm_ortho(-half_w, half_w, -half_h, half_h, -1.0f, 1.0f, w->mproj);
  glm_mat4_identity(w->mview);
  vec4 t = {w->dx, w->dy, 0.0f, 1.0f};
  glm_translate(w->mview, t);
  glm_mat4_mul(w->mproj, w->mview, w->mmvp);
  glm_mat4_mul(w->mmvp, w->mmodel, w->mmvp);
  half_w = (float)w->width;
  half_h = (float)w->height;
  mat4 screenProj;
  mat4 screenView;
  glm_ortho(0, half_w, half_h, 0, -1.0f, 1.0f, screenProj);
  glm_mat4_identity(screenView);
  glm_mat4_mul(screenProj, screenView, w->mscreenmvp);
}

static void on_size(struct nw *w, int width, int height, void *data) {
  WND(data)->width = width;
  WND(data)->height = height;
  update_camera(WND(data));
  nw_make_context_current(&WND(data)->nw);
  glViewport(0, 0, width, height);
  nw_dirty(w);
}

static inline void _fswap(double *x, double *y) {
  double t = *x;
  *x = *y;
  *y = t;
}

static void send_mouse_event(struct gllc_window *w, int x, int y, double wx, double wy, int shift, int ctrl) {
  struct gllc_event e;
  gllc_event_init(&e);
  e.window = w;
  e.block = w->block;
  if (w->block) {
    e.drawing = w->block->_nobj.drawing;
  } else {
    e.drawing = NULL;
  }
  e._float1 = wx;
  e._float2 = wy;
  e._int1 = x;
  e._int2 = y;
  e._int3 = shift;
  e._int4 = ctrl;
  gllc_event_send(LC_EVENT_MOUSEMOVE, &e);
}

static void on_mouse_move(struct nw *w, int x, int y, void *data) {
  double wx, wy;
  screen_to_world(WND(data), (double)x, (double)y, &wx, &wy);

  send_mouse_event(WND(data), x, y, wx, wy, 0, 0);
  if (WND(data)->mpressed) {
    if (WND(data)->drag) {
      WND(data)->dx += ((double)x - WND(data)->curx) * WND(data)->scale;
      WND(data)->dy -= ((double)y - WND(data)->cury) * WND(data)->scale;
      update_camera(WND(data));
      struct gllc_event e;
      gllc_event_init(&e);
      e.window = WND(data);
      gllc_event_send(LC_EVENT_WNDVIEW, &e);
    }
    if (WND(data)->mbtn == 1) {
      double x0, y0, x1, y1;
      x0 = WND(data)->mx0;
      y0 = WND(data)->my0;
      x1 = wx;
      y1 = wy;
      int invert = 0;
      if (x0 > x1) {
        invert = 1;
      }
      if (WND(data)->block) {
        gllc_block_ent_filter_rect(WND(data)->block, invert, x0, y0, x1, y1, 1, 1);
        gllc_block_ent_hover(WND(data)->block, NULL, 1);
        int filcnt = gllc_block_ent_get_filter_cnt(WND(data)->block);
        for (int i = 0; i < filcnt; i++) {
          gllc_block_ent_hover(WND(data)->block, gllc_block_ent_get_filter_at(WND(data)->block, i), 0);
        }
        gllc_block_update(WND(data)->block);
      }
    }
  } else {
    if (WND(data)->block) {
      gllc_block_ent_hover(WND(data)->block, gllc_block_pick_ent(WND(data)->block, wx, wy, 1, 1), 1);
      gllc_block_update(WND(data)->block);
    }
  }
  if (!WND(data)->drag) {
    double x0, y0, x1, y1;
    gllc_window_get_viewport(WND(data), &x0, &y0, &x1, &y1);
    double sx, sy;
    if (ui_grid_snap(&WND(data)->grid, WND(data)->scale, x0, y0, x1, y1, &sx, &sy)) {
      world_to_screen(WND(data), sx, sy, &x, &y);
      nw_cursor_set_pos(x, y);
    }
  }
  WND(data)->curx = x;
  WND(data)->cury = y;
  nw_dirty(w);
}

static void on_mouse_click(struct nw *wn, int x, int y, int mode, int action, void *data) {
  struct gllc_window *wnd = (struct gllc_window *)data;
  wnd->mbtn = mode;
  wnd->mpressed = action;
  double wx, wy;
  screen_to_world(wnd, (double)x, (double)y, &wx, &wy);
  if (action) {
    if (mode == 3) {
      wnd->drag = 1;
    } else if (mode == 1) {
      wnd->mpressx = x;
      wnd->mpressy = y;
      wnd->mx0 = wx;
      wnd->my0 = wy;
    }
  } else {
    if (mode == 3) {
      wnd->drag = 0;
    }
    if (wnd->block) {
      if (mode == 1) {
        double x0, y0, x1, y1;
        int invert = 0;
        x0 = WND(data)->mx0;
        y0 = WND(data)->my0;
        screen_to_world(WND(data), (double)x, (double)y, &x1, &y1);
        if (x0 > x1) {
          invert = 1;
        }
        gllc_block_ent_hover(wnd->block, NULL, 1);
        gllc_block_ent_filter_rect(WND(data)->block, invert, x0, y0, x1, y1, 1, 1);
        int fcnt = gllc_block_ent_get_filter_cnt(wnd->block);
        if (fcnt == 0) {
          struct gllc_entity *ent = gllc_block_pick_ent(wnd->block, wx, wy, 1, 1);
          if (ent) {
            gllc_block_select(wnd->block, ent, 1);
          }
        } else {
          gllc_block_select(wnd->block, NULL, 1);
          for (int i = 0; i < fcnt; i++) {
            gllc_block_select(wnd->block, gllc_block_ent_get_filter_at(wnd->block, i), 0);
          }
        }
        gllc_block_update(wnd->block);
      }
    }
  }
  nw_dirty(wn);
}

static void on_mouse_scroll(struct nw *wn, int dx, int dy, void *data) {
  if (dy >= 10)
    dy = 10;
  if (dy <= -10)
    dy = -10;
  double _scale = WND(data)->scale;
  if ((_scale > 1000.0f && dy < 0) || (_scale < 0.0001f && dy > 0)) {
    return;
  }
  double _w = WND(data)->width;
  double _h = WND(data)->height;
  double _curx = WND(data)->curx;
  double _cury = WND(data)->cury;
  double old_scale = WND(data)->scale;
  double _dy = WND(data)->dy;
  double _ddy = (double)dy;
  WND(data)->scale *= 1.0f - (_ddy * 0.2f);
  _scale = WND(data)->scale;
  WND(data)->dx += (_curx - (int)(_w / 2)) * (_scale - old_scale);
  WND(data)->dy += ((_h - _cury) - (int)(_h / 2)) * (_scale - old_scale);
  update_camera(WND(data));
  struct gllc_event e;
  gllc_event_init(&e);
  e.window = WND(data);
  gllc_event_send(LC_EVENT_WNDVIEW, &e);
  nw_dirty(wn);
}

static void on_mouse_leave(struct nw *wn, void *data) {
  WND(data)->menter = 0;
  nw_dirty(wn);
  nw_show_cursor(1);
}

static struct nw_vtable _nw_vtable = {
    .paint = on_paint,
    .size = on_size,
    .mouse_move = on_mouse_move,
    .mouse_click = on_mouse_click,
    .mouse_scroll = on_mouse_scroll,
    .mouse_leave = on_mouse_leave};

static GLuint load_shader(GLuint type, const char *source) {
  GLuint shader = glCreateShader(type);
  if (shader == 0) {
    fprintf(stderr, "Failed to create shader\n");
    return 0;
  }
  glShaderSource(shader, 1, &source, NULL);
  glCompileShader(shader);
  GLint compiled = GL_FALSE;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
  if (compiled != GL_TRUE) {
    GLint logLength = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
    char *log = (char *)malloc(logLength);
    if (log) {
      glGetShaderInfoLog(shader, logLength, NULL, log);
      fprintf(stderr, "Shader compilation failed:\n%s\n", log);
      free(log);
    }
    glDeleteShader(shader);
    return 0;
  }
  return shader;
}

static GLuint load_program(GLuint vert_shader, GLuint frag_shader) {
  GLuint program = glCreateProgram();
  if (program == 0) {
    fprintf(stderr, "Failed to create program\n");
    return 0;
  }
  glAttachShader(program, vert_shader);
  glAttachShader(program, frag_shader);
  glLinkProgram(program);
  GLint linked = GL_FALSE;
  glGetProgramiv(program, GL_LINK_STATUS, &linked);
  if (linked != GL_TRUE) {
    GLint logLength = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    char *log = (char *)malloc(logLength);
    if (log) {
      glGetProgramInfoLog(program, logLength, NULL, log);
      fprintf(stderr, "Program link failed:\n%s\n", log);
      free(log);
    }
    glDeleteProgram(program);
    return 0;
  }
  glDetachShader(program, vert_shader);
  glDetachShader(program, frag_shader);

  return program;
}

static void load_GL_program(struct gllc_window *w) {
  GLuint V_shader = load_shader(GL_VERTEX_SHADER, vert_glsl);
  if (!V_shader) {
    return;
  }
  GLuint F_shader = load_shader(GL_FRAGMENT_SHADER, frag_glsl);
  if (!F_shader) {
    glDeleteShader(V_shader);
    return;
  }
  w->program = load_program(V_shader, F_shader);
  glDeleteShader(V_shader);
  glDeleteShader(F_shader);
}

static void load_GL_uniform_loc(struct gllc_window *w) {
#define LOADLOC(out, var)                            \
  out = glGetUniformLocation(w->program, var);       \
  if (out == -1) {                                   \
    fprintf(stderr, "Uniform %s not found!\n", var); \
  }
  LOADLOC(w->loc_umvp, "uMVP");
  LOADLOC(w->loc_uscale, "uScale");
  LOADLOC(w->loc_uviewportsize, "uViewportSize");
  LOADLOC(w->loc_uflags, "uFlags");
  LOADLOC(w->loc_uclearcolor, "uClearColor");
}

struct gllc_window *gllc_window_create(void *p) {
  int success = 0;
  struct gllc_window *wnd = malloc(sizeof(struct gllc_window));
  if (wnd) {
    memset(wnd, 0, sizeof(struct gllc_window));
    GLLC_OBJECT_INIT(wnd, _all_props, &_vtable);
    float white_03[4] = {1.0f, 1.0f, 1.0f, 0.3f};
    float black[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    float white[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    memcpy(wnd->clearcolor, black, sizeof(black));
    wnd->griduse = 1;
    ui_grid_init(&wnd->grid);
    ui_cursor_init(&wnd->cursor);
    ui_selection_init(&wnd->sel);
    if (nw_create(&wnd->nw, p, &_nw_vtable, wnd)) {
      nw_make_context_current(&wnd->nw);
      if (gladLoadGL()) {
        glDisable(GL_MULTISAMPLE);
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_POINT_SMOOTH);
        glDisable(GL_POLYGON_SMOOTH);
        glDisable(GL_DITHER);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDisable(GL_CULL_FACE);
        glClearColor(wnd->clearcolor[0], wnd->clearcolor[1], wnd->clearcolor[2], wnd->clearcolor[3]);
        load_GL_program(wnd);
        glUseProgram(wnd->program);
        load_GL_uniform_loc(wnd);
        nw_get_size(&wnd->nw, &wnd->width, &wnd->height);
        wnd->scale = 1.0f;
        glm_mat4_identity(wnd->mmodel);
        glm_mat4_identity(wnd->mview);
        glm_mat4_identity(wnd->mproj);
        glViewport(0, 0, wnd->width, wnd->height);
        update_camera(wnd);
        return wnd;
      }
      nw_make_context_current(0);
    }
  }
  if (wnd) {
    nw_destroy(&wnd->nw);
    free(wnd);
  }
  return NULL;
}

int gllc_window_resize(struct gllc_window *window, int x, int y, int width, int height) {
  NONULL(window, 0);
  nw_set_size(&window->nw, x, y, width, height);
  nw_dirty(&window->nw);
  return 1;
}

void gllc_window_wnd_to_drw(struct gllc_window *w, double x, double y, double *xd, double *yd) {
  NONULL(w, );
  double _w = (double)w->width;
  double _h = (double)w->height;
  *xd = (x - (_w / 2)) * w->scale - w->dx;
  *yd = (y - (_h / 2)) * w->scale - w->dy;
}

int gllc_window_set_block(struct gllc_window *wnd, struct gllc_block *block) {
  NONULL(wnd, 0);
  if (wnd->block) {
    gllc_block_set_window(wnd->block, NULL);
    wnd->block = NULL;
  }
  if (block) {
    wnd->block = block;
    gllc_block_set_window(wnd->block, wnd);
  }
  nw_dirty(&wnd->nw);
  return 1;
}

int gllc_window_destroy(struct gllc_window *w) {
  NONULL(w, 0);
  nw_make_context_current(&w->nw);
  gllc_block_set_window(w->block, NULL);
  ds_gpu_clear(&w->gpucmn);
  ds_gpu_clear(&w->gpuinter);
  ui_grid_cleanup(&w->grid);
  ui_cursor_cleanup(&w->cursor);
  ui_selection_cleanup(&w->sel);
  nw_destroy(&w->nw);
  free(w);
  return 1;
}

int gllc_window_redraw(struct gllc_window *wnd) {
  NONULL(wnd, 0);
  nw_dirty(&wnd->nw);
  return 1;
}

void gllc_window_get_viewport(struct gllc_window *wnd, double *x0, double *y0, double *x1, double *y1) {
  NONULL(wnd, );
  gllc_window_wnd_to_drw(wnd, 0.0f, 0.0f, x0, y0);
  gllc_window_wnd_to_drw(wnd, wnd->width, wnd->height, x1, y1);
  if (*x0 > *x1)
    _fswap(x0, x1);
  if (*y0 > *y1)
    _fswap(x0, x1);
}

int gllc_window_set_focus(struct gllc_window *wnd) {
  NONULL(wnd, 0);
  nw_focus(&wnd->nw);
  return 1;
}

int gllc_window_set_extents(struct gllc_window *wnd, double Xmin, double Ymin, double Xmax, double Ymax) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_set_props(struct gllc_window *wnd, void *props) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_set_cmdwin(struct gllc_window *wnd, void *cmdwin) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_set_base_point(struct gllc_window *wnd, int bState, double x, double y) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_emulator(struct gllc_window *wnd, int mode) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_hover_text(struct gllc_window *wnd, const char *text, int x, int y, int align) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_message(struct gllc_window *wnd, const char *text, int type) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_magnifier(struct gllc_window *wnd, int bOn, int Width, int Height, int Zoom, int Flags) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_pick_ent(struct gllc_window *wnd, const char *text, const char *cursor_text) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_wait_point(struct gllc_window *wnd, const char *text, double *x, double *y) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_wait_point_2(struct gllc_window *wnd, const char *text, double *x, double *y, F_WAITPOINT pFunc, int FuncPrm) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_update(struct gllc_window *wnd, int mode) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_input_str(struct gllc_window *wnd) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_zoom_rect(struct gllc_window *wnd, double x0, double y0, double x1, double y1) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_zoom_scale(struct gllc_window *wnd, double scale) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_zoom_move(struct gllc_window *wnd, double dx, double dy) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_zoom_pos(struct gllc_window *wnd, double x, double y, double scale) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_zoom_ent(struct gllc_window *wnd, struct gllc_entity *ent) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_get_cursor_coord(struct gllc_window *wnd, int *x, int *y, double *wx, double *wy) {
  NONULL(wnd, 0);
  return 1;
}

int gllc_window_coord_to_drw(struct gllc_window *wnd, int x, int y, double *wx, double *wy) {
  NONULL(wnd, 0);
  screen_to_world(wnd, x, y, wx, wy);
  return 1;
}

int gllc_window_coord_to_wnd(struct gllc_window *wnd, double wx, double wy, int *x, int *y) {
  NONULL(wnd, 0);
  world_to_screen(wnd, wx, wy, x, y);
  return 1;
}

int gllc_window_get_ents_by_rect(struct gllc_window *wnd, double x0, double y0, double x1, double y1, int cross, int max_ents) {
  NONULL(wnd, 0);
  return 1;
}

struct gllc_entity *gllc_window_get_ent_by_point(struct gllc_window *wnd, int x, int y) {
  NONULL(wnd, 0);
  double xd, yd;
  screen_to_world(wnd, x, y, &xd, &yd);
  return gllc_block_pick_ent(wnd->block, xd, yd, 1, 1);
}

int gllc_window_get_ents_by_point(struct gllc_window *wnd, int x, int y, int max_ents) {
  NONULL(wnd, 0);
  return 1;
}

struct gllc_entity *gllc_window_get_ent_by_id(struct gllc_window *wnd, int id) {
  NONULL(wnd, 0);
  return NULL;
}

struct gllc_entity *gllc_window_get_ent_by_idh(struct gllc_window *wnd, const char *idh) {
  NONULL(wnd, 0);
  return NULL;
}

struct gllc_entity *gllc_window_get_ent_by_key(struct gllc_window *wnd, const char *key) {
  NONULL(wnd, 0);
  return NULL;
}
