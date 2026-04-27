#ifndef entbuildutil_h
#define entbuildutil_h

#include "draw.h"
#include "entity.h"

void build_contur(struct gllc_entity *ent, struct ds_unit *u, struct ev *v, int cnt);
void build_filltess(struct gllc_entity *ent, struct ds_unit *u, struct ev *v, int cnt);
void build_fillcircle(struct gllc_entity *ent, struct ds_unit *u, double *p0, double R, int segcnt);
void build_fillrect(struct gllc_entity *ent, struct ds_unit *u, double *p0, double *sz, double *n);

#endif