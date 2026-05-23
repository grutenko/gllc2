#include "entbuildutil.h"
#include "draw.h"
#include "entity.h"
#include "linebuild.h"
#include "object.h"

#include <stddef.h>

static void resolv_color(struct gllc_entity *ent, unsigned char *color)
{
        int colorint = gllc_entity_color(ent);
        if (ent->flags & GLLC_ENT_SELECTED)
        {
                color[0] = 0;
                color[1] = 0;
                color[2] = 255;
                color[3] = 255;
        }
        else
        {
                color[0] = RED(colorint);
                color[1] = GREEN(colorint);
                color[2] = BLUE(colorint);
                color[3] = 255;
        }
}

void resolv_flags(struct gllc_entity *ent, int *flags)
{
        if (ent->flags & GLLC_ENT_HOVER)
        {
                *flags |= DS_UNIT_CHESS;
        }
        else
        {
                *flags &= ~DS_UNIT_CHESS;
        }
        if (ent->flags & GLLC_ENT_SELECTED)
        {
                *flags |= DS_UNIT_DASH_SCREEN;
        }
        else
        {
                *flags &= ~DS_UNIT_DASH_SCREEN;
        }
}

static double resolv_realwidth(struct gllc_entity *ent)
{
        if (ent->flags & GLLC_ENT_LW_REAL)
                return ent->lwidth;
        return 0.0001f;
}

static double resolv_pixwidth(struct gllc_entity *ent)
{
        int pl = 0;
        if (ent->flags & GLLC_ENT_HOVER)
        {
                pl = 2;
        }
        if (ent->flags & GLLC_ENT_LW_SCREEN)
                return ent->lwidth + pl;
        return 1.0f + pl;
}

void build_contur(struct gllc_entity *ent, struct ds_unit *u, struct ev *v, int cnt)
{
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
}

void build_filltess(struct gllc_entity *ent, struct ds_unit *u, struct ev *v, int cnt)
{
}

void soft_update_contur(struct gllc_entity *ent, struct ds_unit *u)
{
        GLubyte color[4];
        GLfloat th;
        resolv_color(ent, color);
        th = resolv_pixwidth(ent);
        for (int i = ent->offset; i < ds_unit_vcnt(u); i++)
        {
                u->V[i].c[0] = color[0];
                u->V[i].c[1] = color[1];
                u->V[i].c[2] = color[2];
                u->V[i].c[3] = color[3];
                u->V[i].th = th / 2.0f * u->V[i].thmul;
        }
}

void soft_update_filltess(struct gllc_entity *ent, struct ds_unit *u)
{
        for (int i = ent->offset; i < ds_unit_vcnt(u); i++)
        {
        }
}