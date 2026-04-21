#include "line.h"
#include "block.h"
#include "draw.h"
#include "entity.h"
#include "entity_vertex.h"
#include "lb.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale) {
  struct gllc_line *line = (struct gllc_line *)ent;
  if (!line || !draw)
    return;

  unsigned char color[4] = {GLLC_COLOR_RED(ent->props.color), GLLC_COLOR_GREEN(ent->props.color), GLLC_COLOR_BLUE(ent->props.color), 255};
  struct ev pts[2] = {
      {.p = {line->p0[0], line->p0[1]}},
      {.p = {line->p1[0], line->p1[1]}},
  };
  struct lb_config lb_conf = {
      .v = pts,
      .vcnt = 2,
      .nroundsegs = 8,
      .closed = 0,
      .c = color,
      .off = 0,
  };
  if (ent->flags & GLLC_ENT_LW_SCREEN) {
    lb_conf.lw = ent->lwidth;
    lb_conf.lrealw = 0.001f;
    lb_conf.mode = LB_MODE_ROUND;
  } else if (ent->flags & GLLC_ENT_LW_REAL) {
    lb_conf.lrealw = ent->lwidth;
    lb_conf.lw = 1.0f;
    lb_conf.mode = LB_MODE_ROUND;
  } else {
    lb_conf.lw = 1.0f;
    lb_conf.lrealw = 0.001f;
    lb_conf.mode = LB_MODE_MITER;
  }
  int vcnt, icnt;
  // первый вызов для получения количества вершин и индексов
  lb_build(&lb_conf, NULL, NULL, &vcnt, &icnt);
  struct ds_vertex *V = ds_unit_reserve_vertex(line->unit, vcnt);
  GLuint *I = ds_unit_reserve_index(line->unit, icnt);
  if (line->_ent.flags & GLLC_ENT_SELECTED) {
    line->unit->flags = DS_UNIT_CHESS;
  } else {
    line->unit->flags = 0;
  }
  if (V && I) {
    lb_build(&lb_conf, V, I, &vcnt, &icnt);
  }
}

static void destroy(struct gllc_entity *ent) {
  struct gllc_line *line = (struct gllc_line *)ent;
  if (line) {
    ds_unit_destroy(line->unit);
    free(line);
  }
}

static int vertices(struct gllc_entity *ent, double scale, struct ev *ver) {
  struct gllc_line *line = (struct gllc_line *)ent;
  if (ver) {
    ver[0].p[0] = line->p0[0];
    ver[0].p[1] = line->p0[1];
    ver[1].p[0] = line->p1[0];
    ver[1].p[1] = line->p1[1];
  }
  return 2;
}

static int selected(struct gllc_entity *ent, int mode, double scale, double x0, double y0, double x1, double y1) {
  struct gllc_line *line = (struct gllc_line *)ent;
  double min_x = line->p0[0] < line->p1[0] ? line->p0[0] : line->p1[0];
  double max_x = line->p0[0] > line->p1[0] ? line->p0[0] : line->p1[0];
  double min_y = line->p0[1] < line->p1[1] ? line->p0[1] : line->p1[1];
  double max_y = line->p0[1] > line->p1[1] ? line->p0[1] : line->p1[1];
  if (mode == 0) {
    // пересечение рамки и линии
    return !(x1 < min_x || x0 > max_x || y1 < min_y || y0 > max_y);
  } else {
    // линия внутри рамки
    return min_x >= x0 && max_x <= x1 && min_y >= y0 && max_y <= y1;
  }
}

static int clone(struct gllc_entity *ent, struct gllc_entity **clone) {
  if (!ent || !clone)
    return 0;
  struct gllc_line *line = (struct gllc_line *)ent;
  struct gllc_line *new_line = malloc(sizeof(struct gllc_line));
  if (!new_line)
    return 0;
  memcpy(new_line, line, sizeof(struct gllc_line));
  new_line->unit = ds_unit_clone(line->unit);
  *clone = (struct gllc_entity *)new_line;
  return 1;
}

static int picked(struct gllc_entity *ent, double scale, double x, double y) {
}

static int bbox(struct gllc_entity *ent, double scale, double *xmin, double *ymin, double *xmax, double *ymax) {
  struct gllc_line *line = (struct gllc_line *)ent;
  if (xmin)
    *xmin = line->p0[0] < line->p1[0] ? line->p0[0] : line->p1[0];
  if (ymin)
    *ymin = line->p0[1] < line->p1[1] ? line->p0[1] : line->p1[1];
  if (xmax)
    *xmax = line->p0[0] > line->p1[0] ? line->p0[0] : line->p1[0];
  if (ymax)
    *ymax = line->p0[1] > line->p1[1] ? line->p0[1] : line->p1[1];
  return 1;
}

static int len(struct gllc_entity *ent, double *len) {
  struct gllc_line *line = (struct gllc_line *)ent;
  if (len) {
    *len = sqrt(pow(line->p1[0] - line->p0[0], 2) + pow(line->p1[1] - line->p0[1], 2));
  }
  return 1;
}

static struct gllc_entity_vtable vtable = {
    .type = GLLC_ENT_LINE,
    .build = build,
    .destroy = destroy,
    .vertices = vertices,
    .selected = selected,
    .picked = picked,
    .bbox = bbox,
    .len = len,
    .clone = clone};

static struct gllc_prop line_props[] = {
    P_END};

static struct gllc_prop *all_props[] = {G_entity_props, line_props, NULL};

struct gllc_line *gllc_line_create(struct gllc_block *block, struct ds_draw *draw, double p0[2], double p1[2]) {
  struct gllc_line *line = malloc(sizeof(struct gllc_line));
  if (line) {
    GLLC_ENTITY_INIT(&line->_ent, block, all_props, &vtable);
    line->p0[0] = p0[0];
    line->p0[1] = p0[1];
    line->p1[0] = p1[0];
    line->p1[1] = p1[1];
    line->unit = ds_unit_create(draw);
  }
  return line;
}