#include "block.h"
#include "arc.h"
#include "circle.h"
#include "draw.h"
#include "entity.h"
#include "line.h"
#include "litecad.h"
#include "named_object.h"
#include "object.h"
#include "polyline.h"
#include "rect.h"
#include "sparsegrid.h"
#include "window.h"

#include <math.h>
#include <profileapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winnt.h>

#define BLK(obj) ((struct gllc_block *)(obj))

static inline double wnd_scale(struct gllc_block *block) {
  if (block->wnd) {
    return block->wnd->scale;
  }
  return 1.0f;
}

static inline double wnd_dx(struct gllc_block *block) {
  if (block->wnd) {
    return block->wnd->dx;
  }
  return 0.0f;
}

static inline double wnd_dy(struct gllc_block *block) {
  if (block->wnd) {
    return block->wnd->dy;
  }
  return 0.0f;
}

static union gllc_variant _block_id_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.string_ = BLK(obj)->_nobj.ID_hex;
  return v;
}

static union gllc_variant _block_name_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.string_ = BLK(obj)->_nobj.name;
  return v;
}

static int _block_name_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  strncpy(BLK(obj)->_nobj.name, value.string_, sizeof(BLK(obj)->_nobj.name) - 1);
  BLK(obj)->_nobj.name[sizeof(BLK(obj)->_nobj.name) - 1] = 0;
  return 1;
}

static union gllc_variant _block_descr_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.string_ = BLK(obj)->_nobj.descr;
  return v;
}

static int _block_descr_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  strncpy(BLK(obj)->_nobj.descr, value.string_, sizeof(BLK(obj)->_nobj.descr) - 1);
  BLK(obj)->_nobj.descr[sizeof(BLK(obj)->_nobj.descr) - 1] = 0;
  return 1;
}

static union gllc_variant _block_drw_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = BLK(obj)->_nobj.drawing;
  return v;
}

static union gllc_variant _block_dx_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, x1;
  gllc_block_bbox(BLK(obj), &x0, NULL, &x1, NULL);
  v.float_ = x1 - x0;
  return v;
}

static union gllc_variant _block_dy_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double y0, y1;
  gllc_block_bbox(BLK(obj), NULL, &y0, NULL, &y1);
  v.float_ = y1 - y0;
  return v;
}

static union gllc_variant _block_x_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = BLK(obj)->x;
  return v;
}
static int _block_x_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  BLK(obj)->x = v.float_;
  return 1;
}

static union gllc_variant _block_y_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = BLK(obj)->y;
  return v;
}
static int _block_y_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  BLK(obj)->y = v.float_;
  return 1;
}

static union gllc_variant _block_units_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = BLK(obj)->units;
  return v;
}

static inline double resolve_unitscale(int unit) {
  switch (unit) {
  case LC_INSUNIT_INCHES:
    return 0.0254f;
  case LC_INSUNIT_FEET:
    return 0.3048f;
  case LC_INSUNIT_MILES:
    return 1609.344f;
  case LC_INSUNIT_MILLIMETERS:
    return 0.001f;
  case LC_INSUNIT_CENTIMETERS:
    return 0.01f;
  case LC_INSUNIT_METERS:
    return 1.0f;
  case LC_INSUNIT_KILOMETERS:
    return 1000.0f;
  case LC_INSUNIT_MICROINCHES:
    return 0.0000254f;
  case LC_INSUNIT_MILS:
    return 0.0000254f * 1000.0f; // 1 mil = 0.001 inch
  case LC_INSUNIT_YARDS:
    return 0.914f;
  case LC_INSUNIT_ANGSTROMS:
    return 1.0e-10f;
  case LC_INSUNIT_NANOMETERS:
    return 1.0e-9f;
  case LC_INSUNIT_MICRONS:
    return 1.0e-6f;
  case LC_INSUNIT_DECIMETERS:
    return 0.1f;
  case LC_INSUNIT_DEKAMETERS:
    return 10.0f;
  case LC_INSUNIT_HECTOMETERS:
    return 100.0f;
  case LC_INSUNIT_GIGAMETERS:
    return 1.0e9f;
  case LC_INSUNIT_ASTRONOMICAL:
    return 149.598e9f;
  case LC_INSUNIT_LIGHTYEARS:
    return 9.461e15f;
  case LC_INSUNIT_PARSECS:
    return 30.857e15f;
  case LC_INSUNIT_UNDEFINED:
  default:
    return 1.0f;
  }
}

static int _block_units_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  BLK(obj)->units = v.int_;
  return 1;
}

static union gllc_variant _block_ufscaling_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = BLK(obj)->ufscaling;
  return v;
}

static int _block_ufscaling_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  BLK(obj)->ufscaling = value.bool_;
  return 1;
}

static union gllc_variant _block_unitscale_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = resolve_unitscale(BLK(obj)->units);
  return v;
}

static union gllc_variant _block_model_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = (BLK(obj)->_nobj.type == GLLC_OBJ_LAYOUT) ? 0 : 1;
  return v;
}

static union gllc_variant _block_paper_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = (BLK(obj)->_nobj.type == GLLC_OBJ_LAYOUT) ? 1 : 0;
  return v;
}

static union gllc_variant _block_standard_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = 1; // пока заглушка (обычно "non-dynamic block")
  return v;
}

static union gllc_variant _block_layoutname_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.string_ = BLK(obj)->_nobj.name;
  return v;
}

static int _block_layoutname_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  value.string_ = BLK(obj)->_nobj.name;
  return 1;
}

static union gllc_variant _block_layoutorder_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = BLK(obj)->_nobj.priority;
  return v;
}

static int _block_layoutorder_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  BLK(obj)->_nobj.priority = value.int_;
  return 1;
}

static union gllc_variant _block_nents_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = BLK(obj)->cnt;
  return v;
}

static union gllc_variant _block_nselents_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = BLK(obj)->selcnt;
  return v;
}

static union gllc_variant _block_xmin_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0;

  gllc_block_bbox(BLK(obj), &x0, NULL, NULL, NULL);
  v.float_ = x0;

  return v;
}

static union gllc_variant _block_ymin_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_bbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = y0;

  return v;
}

static union gllc_variant _block_xmax_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_bbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = x1;

  return v;
}

static union gllc_variant _block_ymax_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_bbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = y1;

  return v;
}

static union gllc_variant _block_xcen_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_bbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = (x0 + x1) * 0.5;

  return v;
}

static union gllc_variant _block_ycen_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_bbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = (y0 + y1) * 0.5;

  return v;
}

static union gllc_variant _block_selxmin_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_sel_bbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = x0;

  return v;
}

static union gllc_variant _block_selymin_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_sel_bbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = y0;

  return v;
}

static union gllc_variant _block_selxmax_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_sel_bbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = x1;

  return v;
}

static union gllc_variant _block_selymax_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_sel_bbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = y1;

  return v;
}

static union gllc_variant _block_selxcen_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_sel_bbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = (x0 + x1) * 0.5;

  return v;
}

static union gllc_variant _block_selycen_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_sel_bbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = (y0 + y1) * 0.5;

  return v;
}

static union gllc_variant _block_hidden_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = 0;
  return v;
}

static union gllc_variant _block_attribs_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = 0;
  return v;
}

static union gllc_variant _block_vislef_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_visbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = x0;

  return v;
}

static union gllc_variant _block_visbot_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_visbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = y0;

  return v;
}

static union gllc_variant _block_visrig_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_visbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = x1;

  return v;
}

static union gllc_variant _block_vistop_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double x0, y0, x1, y1;

  gllc_block_visbox(BLK(obj), &x0, &y0, &x1, &y1);
  v.float_ = y1;

  return v;
}

static union gllc_variant _block_paper_x0_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = BLK(obj)->paper_x0;
  return v;
}

static int _block_paper_x0_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  BLK(obj)->paper_x0 = value.float_;
  return 1;
}

static union gllc_variant _block_paper_y0_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = BLK(obj)->paper_y0;
  return v;
}

static int _block_paper_y0_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  BLK(obj)->paper_y0 = value.float_;
  return 1;
}

static union gllc_variant _block_paper_size_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = BLK(obj)->paper_size;
  return v;
}

static union gllc_variant _block_paper_orient_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = BLK(obj)->paper_orient;
  return v;
}

static union gllc_variant _block_paper_w_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = BLK(obj)->paper_width;
  return v;
}

static union gllc_variant _block_paper_h_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = BLK(obj)->paper_height;
  return v;
}

static struct gllc_prop props[] = {
    P_STRING_RO(LC_PROP_BLOCK_ID, _block_id_GET),
    P_STRING(LC_PROP_BLOCK_NAME, _block_name_GET, _block_name_SET),
    P_STRING(LC_PROP_BLOCK_DESCR, _block_descr_GET, _block_descr_SET),
    P_HANDLE_RO(LC_PROP_BLOCK_DRW, _block_drw_GET),
    P_FLOAT(LC_PROP_BLOCK_X, _block_x_GET, _block_x_SET),
    P_FLOAT(LC_PROP_BLOCK_Y, _block_y_GET, _block_y_SET),
    P_BOOL(LC_PROP_BLOCK_UFSCALING, _block_ufscaling_GET, _block_ufscaling_SET),
    P_INT(LC_PROP_BLOCK_UNITS, _block_units_GET, _block_units_SET),
    P_FLOAT_RO(LC_PROP_BLOCK_UNITSCALE, _block_unitscale_GET),
    P_BOOL_RO(LC_PROP_BLOCK_MODEL, _block_model_GET),
    P_BOOL_RO(LC_PROP_BLOCK_PAPER, _block_paper_GET),
    P_BOOL_RO(LC_PROP_BLOCK_STANDARD, _block_standard_GET),
    P_STRING(LC_PROP_BLOCK_LAYOUTNAME, _block_layoutname_GET, _block_layoutname_SET),
    P_INT(LC_PROP_BLOCK_LAYOUTORDER, _block_layoutorder_GET, _block_layoutorder_SET),
    P_BOOL_RO(LC_PROP_BLOCK_HIDDEN, _block_hidden_GET),
    P_INT_RO(LC_PROP_BLOCK_NENTS, _block_nents_GET),
    P_INT_RO(LC_PROP_BLOCK_NSELENTS, _block_nselents_GET),
    P_BOOL_RO(LC_PROP_BLOCK_ATTRIBS, _block_attribs_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_XMIN, _block_xmin_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_YMIN, _block_ymin_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_XMAX, _block_xmax_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_YMAX, _block_ymax_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_XCEN, _block_xcen_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_YCEN, _block_ycen_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_DX, _block_dx_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_DY, _block_dy_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_VISLEF, _block_vislef_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_VISBOT, _block_visbot_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_VISRIG, _block_visrig_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_VISTOP, _block_vistop_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_SELXMIN, _block_selxmin_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_SELYMIN, _block_selymin_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_SELXMAX, _block_selxmax_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_SELYMAX, _block_selymax_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_SELXCEN, _block_selxcen_GET),
    P_FLOAT_RO(LC_PROP_BLOCK_SELYCEN, _block_selycen_GET),
    P_FLOAT(LC_PROP_PAPER_X0, _block_paper_x0_GET, _block_paper_x0_SET),
    P_FLOAT(LC_PROP_PAPER_Y0, _block_paper_y0_GET, _block_paper_y0_SET),
    P_INT_RO(LC_PROP_PAPER_SIZE, _block_paper_size_GET),
    P_INT_RO(LC_PROP_PAPER_ORIENT, _block_paper_orient_GET),
    P_FLOAT_RO(LC_PROP_PAPER_W, _block_paper_w_GET),
    P_FLOAT_RO(LC_PROP_PAPER_H, _block_paper_h_GET),
    P_END};
static struct gllc_prop *all_props[] = {props, G_nobject_props, NULL};

static void destroy(struct gllc_object *obj) {
  gllc_block_destroy((struct gllc_block *)obj);
}

static struct gllc_object_vtable vtable = {
    .destroy = destroy};

struct gllc_block *gllc_block_create(struct gllc_drawing *drawing, const char *name, double x, double y) {
  struct gllc_block *block = malloc(sizeof(struct gllc_block));
  if (block) {
    memset(block, 0, sizeof(struct gllc_block));
    gllc_nobject_init((struct gllc_nobject *)block, drawing, all_props, &vtable, GLLC_OBJ_BLOCK, name);
    block->x = x;
    block->y = y;
    block->props.color = -1;
    block->props.fcolor = -1;
    block->sg = sg_create(6);
    if (!block->sg) {
      free(block);
      return NULL;
    }
  }
  return block;
}

void gllc_block_set_window(struct gllc_block *block, struct gllc_window *window) {
  block->wnd = window;
}

void gllc_block_update(struct gllc_block *block) {
  if (!block)
    return;
  int i;
  double x0, y0, x1, y1;
  struct gllc_entity *ent;
  for (i = 0; i < block->bqcnt; i++) {
    ent = block->bq[i];
    gllc_entity_build(ent, &block->draw, wnd_scale(block));
    ent->flags &= ~GLLC_ENT_MODIFIED;
    if (gllc_entity_geometry_modified(ent)) {
      ent->flags &= ~GLLC_ENT_GEOMETRY_MODIFIED;
      gllc_entity_bbox(ent, wnd_scale(block), &x0, &y0, &x1, &y1);
      x0 -= 1.0f;
      y0 -= 1.0f;
      x1 += 1.0f;
      y1 += 1.0f;
      if (!(ent->flags & GLLC_ENT_INITIAL)) {
        sg_remove(block->sg, ent);
      }
      sg_push(block->sg, ent, x0, y0, x1, y1);
      ent->flags &= ~GLLC_ENT_INITIAL;
    }
  }
  block->bqcnt = 0;
}

void gllc_block_destroy(struct gllc_block *block) {
  if (!block)
    return;
  struct gllc_entity *ent = block->h;
  while (ent) {
    struct gllc_entity *next = ent->next;
    gllc_entity_destroy(ent);
    ent = next;
  }
  sg_destroy(block->sg);
  ds_draw_clear(&block->draw);
  free(block->bq);
  free(block->hov);
  free(block->sel);
  free(block->fil);
  free(block);
}

static void push_ent(struct gllc_block *block, struct gllc_entity *ent) {
  if (block->h) {
    block->h->next = ent;
    ent->prev = block->t;
    block->t = ent;
  } else {
    block->h = ent;
    block->t = ent;
  }
  block->cnt++;
}

static void remove_ent(struct gllc_block *block, struct gllc_entity *ent) {
  if (ent->prev)
    ent->prev->next = ent->next;
  else
    block->h = ent->next;
  if (ent->next)
    ent->next->prev = ent->prev;
  else
    block->t = ent->prev;
  block->cnt--;
  ent->prev = NULL;
  ent->next = NULL;
  ent->block = NULL;
}

struct gllc_polyline *gllc_block_add_polyline(struct gllc_block *block, int closed, int filled) {
  struct gllc_polyline *pline = gllc_polyline_create(block, &block->draw, closed, filled);
  if (pline) {
    push_ent(block, (struct gllc_entity *)pline);
    gllc_block_put_bq(block, (struct gllc_entity *)pline);
  }
  return pline;
}

struct gllc_circle *gllc_block_add_circle(struct gllc_block *block, double x, double y, double r, int filled) {
  struct gllc_circle *circle = gllc_circle_create(block, &block->draw, x, y, r, filled);
  if (circle) {
    push_ent(block, (struct gllc_entity *)circle);
    gllc_block_put_bq(block, (struct gllc_entity *)circle);
  }
  return circle;
}

struct gllc_entity *gllc_block_pick_ent(struct gllc_block *block, double x, double y, int skiplocked, int skiphidden) {
  struct gllc_entity *ent = NULL;
  struct sg_cell *cell = sg_pick_cell(block->sg, x, y);
  if (!cell)
    return NULL;
  int i;
  struct gllc_entity **ents = sg_cell_ents(cell);
  int cnt = sg_cell_ents_cnt(cell);
  for (i = 0; i < cnt; i++) {
    if ((skiplocked && ents[i]->flags & GLLC_ENT_LOCKED) || (skiphidden && ents[i]->flags & GLLC_ENT_HIDDEN))
      continue;
    //double x0, y0, x1, y1;
    //gllc_entity_bbox(ents[i], wnd_scale(block), &x0, &y0, &x1, &y1);
    //double tol = 10.0f * wnd_scale(block);
    //if (x + tol < x0 || x - tol > x1 || y + tol < y0 || y - tol > y1)
    //  continue;
    if (ents[i]->vtable->picked(ents[i], wnd_scale(block), x, y, NULL)) {
      return ents[i];
    }
  }
  return NULL;
}

void gllc_block_sync_gpu(struct gllc_block *block, struct ds_gpu *gpu) {
  if (ds_draw_dirty(&block->draw)) {
    ds_sync(&block->draw, gpu);
  }
}

void gllc_block_put_bq(struct gllc_block *block, struct gllc_entity *ent) {
  if (block->bqcap <= block->bqcnt) {
    size_t sz = block->bqcap ? block->bqcap * 2 : 64;
    struct gllc_entity **bq = realloc(block->bq, sz * sizeof(struct gllc_entity *));
    if (!bq) {
      return;
    }
    block->bq = bq;
    block->bqcap = sz;
  }
  block->bq[block->bqcnt] = ent;
  block->bqcnt++;
}

struct gllc_line *gllc_block_add_line(struct gllc_block *block, double p0[2], double p1[2]) {
  struct gllc_line *line = gllc_line_create(block, &block->draw, p0, p1);
  if (line) {
    push_ent(block, (struct gllc_entity *)line);
    gllc_block_put_bq(block, (struct gllc_entity *)line);
  }
  return line;
}

static inline void arr_ent_push(struct gllc_entity ***arr, int *cnt, int *cap, struct gllc_entity *ent) {
  if (*cap <= *cnt) {
    size_t sz = *cap ? (*cap) * 2 : 64;
    struct gllc_entity **narr = realloc(*arr, sz * sizeof(struct gllc_entity *));
    if (!narr) {
      return;
    }
    *arr = narr;
    *cap = sz;
  }
  (*arr)[*cnt] = ent;
  (*cnt)++;
}

static void clear_hover(struct gllc_block *block) {
  int i;
  struct gllc_entity *ent;
  for (i = 0; i < block->hovcnt; i++) {
    ent = block->hov[i];
    ent->flags &= ~GLLC_ENT_HOVER;
    ent->flags |= GLLC_ENT_MODIFIED;
    gllc_block_put_bq(block, ent);
  }
  block->hovcnt = 0;
}

static void push_hover(struct gllc_block *block, struct gllc_entity *ent) {
  arr_ent_push(&block->hov, &block->hovcnt, &block->hovcap, ent);
}

void gllc_block_ent_hover(struct gllc_block *block, struct gllc_entity *ent, int exclusive) {
  if (exclusive) {
    if (block->hovcnt == 1 && block->hov[0] == ent) {
      return;
    }
    clear_hover(block);
  }
  if (!ent)
    return;
  if (ent->flags & GLLC_ENT_HOVER)
    return;
  ent->flags |= GLLC_ENT_HOVER;
  ent->flags |= GLLC_ENT_MODIFIED;
  gllc_block_put_bq(block, ent);
  push_hover(block, ent);
}

struct gllc_entity *gllc_block_ent_get_filter_at(struct gllc_block *block, int index) {
  if (index < 0 || index >= block->filcnt)
    return NULL;
  return block->fil[index];
}

int gllc_block_ent_get_filter_cnt(struct gllc_block *block) {
  return block->filcnt;
}

static inline void push_filter_ent(struct gllc_block *block, struct gllc_entity *ent) {
  arr_ent_push(&block->fil, &block->filcnt, &block->filcap, ent);
}

static inline void _swapf(double *a, double *b) {
  double t = *a;
  *a = *b;
  *b = t;
}

int gllc_block_ent_filter_rect(struct gllc_block *block, int mode, double x0, double y0, double x1, double y1, int skiplocked, int skiphidden) {
  for (int i = 0; i < block->filcnt; i++)
    block->fil[i]->flags &= ~GLLC_ENT_FILTER;
  block->filcnt = 0;
  int shift = sg_shift(block->sg);

  if (x0 > x1)
    _swapf(&x0, &x1);
  if (y0 > y1)
    _swapf(&y0, &y1);

  int cx0 = ((int)floor(x0)) >> shift;
  int cy0 = ((int)floor(y0)) >> shift;
  int cx1 = ((int)floor(x1)) >> shift;
  int cy1 = ((int)floor(y1)) >> shift;

  for (int x = cx0; x <= cx1; x++) {
    for (int y = cy0; y <= cy1; y++) {
      struct sg_cell *cell = sg_cell_at(block->sg, x, y);
      if (!cell)
        continue;
      struct gllc_entity **ents = sg_cell_ents(cell);
      int entcnt = sg_cell_ents_cnt(cell);
      for (int i = 0; i < entcnt; i++) {
        if (ents[i]->flags & GLLC_ENT_FILTER)
          continue;
        if (ents[i]->vtable->selected(ents[i], mode, wnd_scale(block), x0, y0, x1, y1)) {
          ents[i]->flags |= GLLC_ENT_FILTER;
          push_filter_ent(block, ents[i]);
        }
      }
    }
  }
  return 1;
}

struct gllc_rect *gllc_block_add_rect(struct gllc_block *block, double *p, double w, double h, double angle) {
  struct gllc_rect *r = gllc_rect_create(block, &block->draw, p, w, h, angle);
  if (r) {
    push_ent(block, (struct gllc_entity *)r);
    gllc_block_put_bq(block, (struct gllc_entity *)r);
  }
  return r;
}

static void push_select(struct gllc_block *block, struct gllc_entity *ent) {
  arr_ent_push(&block->sel, &block->selcnt, &block->selcap, ent);
}

static void clear_select(struct gllc_block *block) {
  int i;
  struct gllc_entity *ent;
  for (i = 0; i < block->selcnt; i++) {
    ent = block->sel[i];
    ent->flags &= ~GLLC_ENT_SELECTED;
    ent->flags |= GLLC_ENT_MODIFIED;
    gllc_block_put_bq(block, ent);
  }
  block->selcnt = 0;
}

void gllc_block_select(struct gllc_block *block, struct gllc_entity *ent, int exclusive) {
  if (exclusive)
    clear_select(block);
  if (!ent)
    return;
  if (ent->flags & GLLC_ENT_SELECTED)
    return;
  ent->flags |= GLLC_ENT_SELECTED;
  ent->flags |= GLLC_ENT_MODIFIED;
  gllc_block_put_bq(block, ent);
  push_select(block, ent);
}

int gllc_block_get_select_cnt(struct gllc_block *block) {
  return block->selcnt;
}

struct gllc_entity *gllc_block_get_select_at(struct gllc_block *block, int index) {
  if (index < 0 || block->selcnt <= index)
    return NULL;
  return block->sel[index];
}

struct gllc_arc *gllc_block_add_arc(struct gllc_block *block, double x, double y, double radius, double start_angle, double arc_angle) {
  struct gllc_arc *r = gllc_arc_create(block, &block->draw, x, y, radius, start_angle, arc_angle);
  if (r) {
    push_ent(block, (struct gllc_entity *)r);
    gllc_block_put_bq(block, (struct gllc_entity *)r);
  }
  return r;
}

static void arr_remove_ent(struct gllc_entity **arr, int *size, struct gllc_entity *ent) {
  int n = *size;
  for (int i = 0; i < n; i++) {
    if (arr[i] == ent) {
      memmove(&arr[i], &arr[i + 1], (n - i - 1) * sizeof(*arr));
      (*size)--;
      return;
    }
  }
}

void gllc_block_ent_remove(struct gllc_block *block, struct gllc_entity *ent) {
  if (!ent)
    return;
  if (!block)
    return;
  if (ent->block != block)
    return;
  arr_remove_ent(block->bq, &block->bqcnt, ent);
  arr_remove_ent(block->fil, &block->filcnt, ent);
  arr_remove_ent(block->hov, &block->hovcnt, ent);
  arr_remove_ent(block->sel, &block->selcnt, ent);
  remove_ent(block, ent);
  ent->vtable->destroy(ent);
  free(ent);
}

void gllc_block_bbox(struct gllc_block *block, double *x0, double *y0, double *x1, double *y1) {
  if (!block) return;
  if (block->cnt == 0) {
    if (x0)
      *x0 = 0.0f;
    if (y0)
      *y0 = 0.0f;
    if (x1)
      *x1 = 0.0f;
    if (y1)
      *y1 = 0.0f;
    return;
  }
  double minx = 1e300;
  double miny = 1e300;
  double maxx = -1e300;
  double maxy = -1e300;
  struct gllc_entity *e = block->h;
  for (; e; e = e->next) {
    double ex0, ey0, ex1, ey1;
    gllc_entity_bbox(e, wnd_scale(block), &ex0, &ey0, &ex1, &ey1);
    if (ex0 < minx) minx = ex0;
    if (ey0 < miny) miny = ey0;
    if (ex1 > maxx) maxx = ex1;
    if (ey1 > maxy) maxy = ey1;
  }
  if (x0)
    *x0 = minx;
  if (y0)
    *y0 = miny;
  if (x1)
    *x1 = maxx;
  if (y1)
    *y1 = maxy;
}

void gllc_block_sel_bbox(struct gllc_block *block, double *x0, double *y0, double *x1, double *y1) {
  if (!block) return;
  if (block->selcnt == 0) {
    if (x0)
      *x0 = 0.0f;
    if (y0)
      *y0 = 0.0f;
    if (x1)
      *x1 = 0.0f;
    if (y1)
      *y1 = 0.0f;
    return;
  }
  double minx = 1e300;
  double miny = 1e300;
  double maxx = -1e300;
  double maxy = -1e300;
  for (int i = 0; i < block->selcnt; i++) {
    struct gllc_entity *e = block->sel[i];
    double ex0, ey0, ex1, ey1;
    gllc_entity_bbox(e, wnd_scale(block), &ex0, &ey0, &ex1, &ey1);
    if (ex0 < minx) minx = ex0;
    if (ey0 < miny) miny = ey0;
    if (ex1 > maxx) maxx = ex1;
    if (ey1 > maxy) maxy = ey1;
  }
  if (x0)
    *x0 = minx;
  if (y0)
    *y0 = miny;
  if (x1)
    *x1 = maxx;
  if (y1)
    *y1 = maxy;
}

void gllc_block_visbox(struct gllc_block *block, double *x0, double *y0, double *x1, double *y1) {
  if (block->wnd) {
    double xb0, yb0, xb1, yb1, xw0, yw0, xw1, yw1;
    gllc_window_get_viewport(block->wnd, &xw0, &yw0, &xw1, &yw1);
    gllc_block_bbox(block, &xb0, &yb0, &xb1, &yb1);
    *x0 = xb0 > xw0 ? xb0 : xw0;
    *y0 = yb0 > yw0 ? yb0 : yw0;
    *x1 = xb1 < xw1 ? xb1 : xw1;
    *y1 = yb1 < yw1 ? yb1 : yw1;
  } else {
    gllc_block_bbox(block, x0, y0, x1, y1);
  }
  if (*x0 > *x1 || *y0 > *y1) {
    *x0 = *y0 = *x1 = *y1 = 0.0;
  }
}