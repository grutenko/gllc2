#include "arc.h"
#include "entbuildutil.h"
#include "linalg.h"

#include <stdlib.h>
#include <string.h>

#define SEGCNT 64

#define ARC(o) ((struct gllc_arc *)(o))

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale)
{
        static struct ev pts[SEGCNT];
        if (gllc_entity_geometry_modified(ent))
        {
                ds_unit_reset(ARC(ent)->u);
                int segcnt = SEGCNT * (ARC(ent)->arc_angle / M_PI);
                double n0[2] = {1.0f, 0.0f};
                ROT(n0, ARC(ent)->start_angle);
                ROT(n0, -ARC(ent)->arc_angle / 2);
                double step = ARC(ent)->arc_angle / (segcnt - 1);
                for (int i = 0; i <= segcnt; i++)
                {
                        ADDSCALETO((double[]){ARC(ent)->x, ARC(ent)->y}, n0, ARC(ent)->radius, pts[i].p);
                        ROT(n0, step);
                }
                build_contur(ent, ARC(ent)->u, pts, segcnt);
                ARC(ent)->u->dirty = 1;
                ARC(ent)->u->geometry_dirty = 1;
                ARC(ent)->u->draw->dirty = 1;
                ARC(ent)->u->draw->geometry_dirty = 1;
        }
        else
        {
                soft_update_contur(ent, ARC(ent)->u);
                ARC(ent)->u->dirty = 1;
                ARC(ent)->u->draw->dirty = 1;
        }
        resolv_flags(ent, &ARC(ent)->u->flags);
}

static void destroy(struct gllc_entity *ent)
{
        struct gllc_arc *arc = (struct gllc_arc *)ent;
        if (arc)
        {
                ds_unit_destroy(arc->u);
                free(arc);
        }
}

static int vertices(struct gllc_entity *ent, double scale, struct ev *ver)
{
        return 0;
}

static int bbox(struct gllc_entity *ent, double scale, double *xmin, double *ymin, double *xmax, double *ymax);

static int selected(struct gllc_entity *ent, int mode, double scale, double x0, double y0, double x1, double y1)
{
        double bx0, bx1, by0, by1;
        bbox(ent, scale, &bx0, &by0, &bx1, &by1);
        if (bx0 >= x0 && bx1 <= x1 && by0 >= y0 && by1 <= y1)
                return 1;
        return 0;
}

static int clone(struct gllc_entity *ent, struct gllc_entity **clone)
{
        if (ent->vtable->type != GLLC_ENT_ARC)
                return 0;
        struct gllc_arc *l = (struct gllc_arc *)ent;
        struct gllc_arc *nl = malloc(sizeof(struct gllc_arc));
        if (!nl)
                return 0;
        memcpy(nl, l, sizeof(struct gllc_arc));
        nl->u = ds_unit_clone(l->u);
        *clone = (struct gllc_entity *)nl;
        return 1;
}

static int picked(struct gllc_entity *ent, double scale, double x, double y, double *dis)
{
        double n0[2], n1[2];
        double v0[2];
        double w;
        if (ent->flags & GLLC_ENT_LW_THIN)
        {
                w = 5.0f * scale;
        }
        else if (ent->flags & GLLC_ENT_LW_SCREEN)
        {
                w = (ent->lwidth + 5.0f) * scale;
        }
        else
        {
                w = ent->lwidth + (5.0f * scale);
        }
        VEC(v0, (double[]){ARC(ent)->x, ARC(ent)->y}, (double[]){x, y});
        double len = LEN(v0);
        if (len > ARC(ent)->radius + w || len < ARC(ent)->radius - w)
        {
                return 0;
        }
        NORMTO(v0, n0);
        COPY(n1, (double[]){1.0f, 0.0f});
        ROT(n1, ARC(ent)->start_angle);
        if (DOT(n0, n1) < cos(ARC(ent)->arc_angle / 2.0f))
        {
                return 0;
        }

        return 1;
}

static int bbox(struct gllc_entity *ent, double scale, double *xmin, double *ymin, double *xmax, double *ymax)
{
        double minx = 1e300;
        double miny = 1e300;
        double maxx = -1e300;
        double maxy = -1e300;
        double n0[2] = {1.0f, 0.0f};
        int segcnt = SEGCNT * (ARC(ent)->arc_angle / M_PI);
        if (segcnt == 0)
        {
                segcnt = 2;
        }
        ROT(n0, ARC(ent)->start_angle);
        ROT(n0, -ARC(ent)->arc_angle / 2);
        double step = ARC(ent)->arc_angle / (segcnt - 1);
        for (int i = 0; i <= segcnt; i++)
        {
                double p[2];
                ADDSCALETO((double[]){ARC(ent)->x, ARC(ent)->y}, n0, ARC(ent)->radius, p);
                ROT(n0, step);
                if (p[0] < minx)
                        minx = p[0];
                if (p[1] < miny)
                        miny = p[1];
                if (p[0] > maxx)
                        maxx = p[0];
                if (p[1] > maxy)
                        maxy = p[1];
        }
        if (xmin)
                *xmin = minx;
        if (ymin)
                *ymin = miny;
        if (xmax)
                *xmax = maxx;
        if (ymax)
                *ymax = maxy;
        return 1;
}

static int len(struct gllc_entity *ent, double *len)
{
        return 0;
}

static struct gllc_entity_vtable vtable = {.type = GLLC_ENT_ARC,
                                           .build = build,
                                           .destroy = destroy,
                                           .vertices = vertices,
                                           .selected = selected,
                                           .picked = picked,
                                           .bbox = bbox,
                                           .len = len,
                                           .clone = clone};

static struct gllc_prop pline_props[] = {P_END};

static struct gllc_prop *all_props[] = {G_entity_props, pline_props, NULL};

struct gllc_arc *gllc_arc_create(struct gllc_block *block, struct ds_draw *draw, double x, double y, double radius,
                                 double start_angle, double arc_angle)
{
        struct gllc_arc *pl = malloc(sizeof(struct gllc_arc));
        if (pl)
        {
                GLLC_ENTITY_INIT(&pl->_ent, block, all_props, &vtable);
                pl->u = ds_unit_create(draw);
                pl->x = x;
                pl->y = y;
                pl->radius = radius;
                pl->arc_angle = arc_angle;
                pl->start_angle = start_angle;
        }
        return pl;
}