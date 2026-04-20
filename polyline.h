#ifndef polyline_h
#define polyline_h

#include "draw.h"
#include "entity.h"
#include "entity_vertex.h"
#include "object.h"

struct gllc_pline_ver {
  struct gllc_object _obj;
  int i;
  double x;
  double y;
};

struct gllc_polyline {
  struct gllc_entity _ent;
  int fit;
  int cnt;
  int cap;
  struct ds_unit *unit;
  struct ev *pts;
};

struct gllc_polyline *gllc_polyline_create(struct gllc_block *block, struct ds_draw *draw, int closed, int filled);
void gllc_pline_add_ver(struct gllc_polyline *pline, double x, double y);
void gllc_pline_end(struct gllc_polyline *pline);
int gllc_pline_fit_type(struct gllc_polyline *pline);
int gllc_pline_nvers(struct gllc_polyline *pline);
float gllc_pline_width(struct gllc_polyline *pline);
int gllc_pline_width_bool(struct gllc_polyline *pline);
float gllc_pline_radius(struct gllc_polyline *pline);
int gllc_pline_radius_bool(struct gllc_polyline *pline);
int gllc_pline_set_width(struct gllc_polyline *pline, float width);
int gllc_pline_set_width_bool(struct gllc_polyline *pline, int width);
int gllc_pline_set_radius(struct gllc_polyline *pline, float radius);
int gllc_pline_set_radius_bool(struct gllc_polyline *pline, int radius);
int gllc_pline_chamfer(struct gllc_polyline *pline);
int gllc_pline_set_chamfer(struct gllc_polyline *pline, int chamfer);
double gllc_pline_area(struct gllc_polyline *pline);
int gllc_pline_cw(struct gllc_polyline *pline);
int gllc_pline_ccw(struct gllc_polyline *pline);
int gllc_pline_hasang0(struct gllc_polyline *pline);
int gllc_pline_set_hasang0(struct gllc_polyline *pline, int hasang2);
int gllc_pline_hasang2(struct gllc_polyline *pline);
int gllc_pline_set_hasang2(struct gllc_polyline *pline, int hasang2);
double gllc_pline_ang0(struct gllc_polyline *pline);
int gllc_pline_set_ang0(struct gllc_polyline *pline, double ang2);
double gllc_pline_ang2(struct gllc_polyline *pline);
int gllc_pline_set_ang2(struct gllc_polyline *pline, double ang2);
#endif