#include "entbuildutil.h"
#include "draw.h"
#include "entity.h"
#include "linebuild.h"

static void resolv_color(struct gllc_entity *ent, unsigned char *color) {
  int colorint = gllc_entity_color(ent);
  if (ent->flags & GLLC_ENT_SELECTED) {
    color[0] = 0;
    color[1] = 255;
    color[2] = 0;
    color[3] = 255;
  } else {
    color[0] = RED(colorint);
    color[1] = GREEN(colorint);
    color[2] = BLUE(colorint);
    color[3] = 255;
  }
}

static void resolv_flags(struct gllc_entity *ent, int *flags) {
  if (ent->flags & GLLC_ENT_HOVER) {
    *flags |= DS_UNIT_CHESS;
  } else {
    *flags &= ~DS_UNIT_CHESS;
  }
  if (ent->flags & GLLC_ENT_SELECTED) {
    *flags |= DS_UNIT_DASH_SCREEN;
  } else {
    *flags &= ~DS_UNIT_DASH_SCREEN;
  }
}

static double resolv_realwidth(struct gllc_entity *ent) {
  if (ent->flags & GLLC_ENT_LW_REAL)
    return ent->lwidth;
  return 0.0001f;
}

static double resolv_pixwidth(struct gllc_entity *ent) {
  int pl = 0;
  if (ent->flags & GLLC_ENT_HOVER) {
    pl = 2;
  }
  if (ent->flags & GLLC_ENT_LW_SCREEN)
    return ent->lwidth + pl;
  return 1.0f + pl;
}

void build_contur(struct gllc_entity *ent, struct ds_unit *u, struct ev *v, int cnt, int skip) {
  if (gllc_entity_geometry_modified(ent)) {
    struct lb_config conf;
    conf.v = v;
    conf.vcnt = cnt;
    resolv_color(ent, conf.c);
    conf.closed = 0;
    conf.nroundsegs = 8;
    conf.lw = resolv_pixwidth(ent);
    conf.lrealw = resolv_realwidth(ent);
    resolv_flags(ent, &u->flags);
    conf.off = ds_unit_vcnt(u);
    int vcnt, icnt;
    int oldvcnt = ds_unit_vcnt(u);
    int oldicnt = ds_unit_icnt(u);
    lb_build(&conf, NULL, NULL, &vcnt, &icnt);
    struct ds_vertex *V = ds_unit_reserve_vertex(u, oldvcnt + vcnt);
    GLuint *I = ds_unit_reserve_index(u, oldicnt + icnt);
    lb_build(&conf, &V[oldvcnt], &I[oldicnt], &vcnt, &icnt);
    u->dirty = 1;
    u->geometry_dirty = 1;
  } else {
    int vcnt = ds_unit_vcnt(u);
    unsigned char color[4];
    double th = resolv_pixwidth(ent);
    resolv_flags(ent, &u->flags);
    resolv_color(ent, color);
    for (int i = skip; i < vcnt; i++) {
      u->V[i].th = th / 2 * u->V[i].thmul;
      u->V[i].c[0] = color[0];
      u->V[i].c[1] = color[1];
      u->V[i].c[2] = color[2];
      u->V[i].c[3] = color[3];
    }
    u->dirty = 1;
  }
  u->draw->dirty = 1;
  u->draw->geometry_dirty = 1;
}

void build_filltess(struct gllc_entity *ent, struct ds_unit *u, struct ev *v, int cnt) {
}
