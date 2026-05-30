#include "entbuildutil.h"
#include "draw.h"
#include "entity.h"
#include "linebuild.h"
#include "tess2/tess2.h"

#include <stddef.h>
#include <stdlib.h>

void resolv_color(struct gllc_entity *ent, unsigned char *color)
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
                color[3] = (unsigned char)(ent->alpha * 255);
        }
}

void resolv_fcolor(struct gllc_entity *ent, unsigned char *color)
{
        int colorint = gllc_entity_fcolor(ent);
        color[0] = RED(colorint);
        color[1] = GREEN(colorint);
        color[2] = BLUE(colorint);
        color[3] = (unsigned char)(ent->falpha * 255);
}

void resolv_flags(struct gllc_entity *ent, uint16_t *flags)
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
        conf.off = ds_unit_vcnt(u);
        int vcnt, icnt;
        int oldvcnt = ds_unit_vcnt(u);
        int oldicnt = ds_unit_icnt(u);
        lb_build(&conf, NULL, NULL, &vcnt, &icnt);
        struct ds_vertex *V = ds_unit_reserve_vertex(u, oldvcnt + vcnt);
        GLuint *I = ds_unit_reserve_index(u, oldicnt + icnt);
        lb_build(&conf, &V[oldvcnt], &I[oldicnt], &vcnt, &icnt);
        u->flags |= DS_UNIT_DIRTY;
}

void build_filltess(struct gllc_entity *ent, struct ds_unit *u, struct ev *v, int cnt)
{
        TESStesselator *tess = tessNewTess(NULL);
        if (tess)
        {
                float stackbuf[32];
                float *heapbuf = NULL;
                float *bufp = NULL;
                if (cnt < 16)
                {
                        bufp = stackbuf;
                }
                else
                {
                        heapbuf = malloc(sizeof(float) * 2 * cnt);
                        if (!heapbuf)
                                return;
                        bufp = heapbuf;
                }
                for (int i = 0; i < cnt; i++)
                {
                        bufp[i * 2] = (float)v[i].p[0];
                        bufp[i * 2 + 1] = (float)v[i].p[1];
                }
                unsigned char color[4];
                resolv_fcolor(ent, color);
                tessAddContour(tess, 2, bufp, sizeof(GLfloat) * 2, cnt);
                if (tessTesselate(tess, TESS_WINDING_POSITIVE, TESS_POLYGONS, 3, 2, NULL))
                {
                        const float *verts = tessGetVertices(tess);
                        int vert_count = tessGetVertexCount(tess);
                        int indices_count = tessGetElementCount(tess);
                        const int *indices = tessGetElements(tess);
                        int oldvcnt = ds_unit_vcnt(u);
                        int oldicnt = ds_unit_icnt(u);
                        struct ds_vertex *V = ds_unit_reserve_vertex(u, oldvcnt + vert_count);
                        GLuint *I = ds_unit_reserve_index(u, oldicnt + indices_count * 3);
                        for (int i = 0; i < vert_count; i++)
                        {
                                V[oldvcnt + i].pos[0] = verts[i * 2];
                                V[oldvcnt + i].pos[1] = verts[i * 2 + 1];
                                V[oldvcnt + i].color[0] = color[0];
                                V[oldvcnt + i].color[1] = color[1];
                                V[oldvcnt + i].color[2] = color[2];
                                V[oldvcnt + i].color[3] = color[3];
                                V[oldvcnt + i].normal[0] = 0;
                                V[oldvcnt + i].normal[1] = 0;
                                V[oldvcnt + i].length = 0.0f;
                                V[oldvcnt + i].thickness = 0.0f;
                                V[oldvcnt + i].thicknessMiltiplier = 0.0f;
                                V[oldvcnt + i].textureCoord[0] = 0;
                                V[oldvcnt + i].textureCoord[1] = 0;
                        }
                        for (int i = 0; i < indices_count * 3; i++)
                        {
                                I[i] = indices[i];
                        }
                }
                if (heapbuf)
                {
                        free(heapbuf);
                }
                tessDeleteTess(tess);
        }
}

void soft_update_contur(struct gllc_entity *ent, struct ds_unit *u)
{
        GLubyte color[4];
        GLfloat th;
        resolv_color(ent, color);
        th = resolv_pixwidth(ent);
        for (int i = ent->offset; i < ds_unit_vcnt(u); i++)
        {
                u->V[i].color[0] = color[0];
                u->V[i].color[1] = color[1];
                u->V[i].color[2] = color[2];
                u->V[i].color[3] = color[3];
                u->V[i].thickness = th / 2.0f * u->V[i].thicknessMiltiplier;
        }
}

void soft_update_filltess(struct gllc_entity *ent, struct ds_unit *u)
{
        GLubyte color[4];
        resolv_fcolor(ent, color);
        for (int i = 0; i < ent->offset && i < ds_unit_vcnt(u); i++)
        {
                u->V[i].color[0] = color[0];
                u->V[i].color[1] = color[1];
                u->V[i].color[2] = color[2];
                u->V[i].color[3] = color[3];
        }
}