#include "entbuildutil.h"
#include "draw.h"
#include "entity.h"
#include "linebuild.h"

void build_contur(struct gllc_entity *ent, struct ds_unit *u, struct ev *v, int cnt) {
  int selected = (ent->flags & GLLC_ENT_SELECTED) != 0;
  int hovered = (ent->flags & GLLC_ENT_HOVER) != 0;
  int closed = (ent->flags & GLLC_ENT_CLOSED) != 0;
  int lwpixel = (ent->flags & GLLC_ENT_LW_SCREEN) != 0;
  int lwreal = (ent->flags & GLLC_ENT_LW_REAL) != 0;
  int lwthin = (ent->flags & GLLC_ENT_LW_THIN) != 0;
  int colorint = gllc_entity_color(ent);
  unsigned char color[4];
  if (selected) {
    color[0] = 0;
    color[1] = 0;
    color[2] = 255;
    color[3] = 255;
  } else {
    color[0] = RED(colorint);
    color[1] = GREEN(colorint);
    color[2] = BLUE(colorint);
    color[3] = 255;
  }
  struct lb_config conf;
  conf.v = v;
  conf.vcnt = cnt;
  conf.c = color;
  conf.closed = 0;
  conf.nroundsegs = 8;
  if (hovered) {
  }
  if (lwpixel) {
    conf.lw = ent->lwidth;
    conf.lrealw = 0.0001f;
  } else if (lwreal) {
    conf.lw = 1.0f;
    conf.lrealw = ent->lwidth;
  } else {
    conf.lw = 1.0f;
    conf.lrealw = 0.0001f;
  }
  if (hovered) {
    conf.lw += 2.0f;
    u->flags |= DS_UNIT_CHESS;
  } else {
    u->flags &= ~DS_UNIT_CHESS;
  }
  if (selected) {
    u->flags |= DS_UNIT_DASH_SCREEN;
  } else {
    u->flags &= ~DS_UNIT_DASH_SCREEN;
  }
  int vcnt, icnt;
  int oldvcnt = ds_unit_vcnt(u);
  int oldicnt = ds_unit_icnt(u);
  conf.off = oldvcnt;
  lb_build(&conf, NULL, NULL, &vcnt, &icnt);
  struct ds_vertex *V = ds_unit_reserve_vertex(u, oldvcnt + vcnt);
  GLuint *I = ds_unit_reserve_index(u, oldicnt + icnt);
  lb_build(&conf, &V[oldvcnt], &I[oldicnt], &vcnt, &icnt);
}

void build_filltess(struct gllc_entity *ent, struct ds_unit *u, struct ev *v, int cnt) {
}
