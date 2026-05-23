#ifndef entbuildutil_h
#define entbuildutil_h

#include "draw.h"
#include "entity.h"

void build_contur(struct gllc_entity *ent, struct ds_unit *u, struct ev *v, int cnt);
void build_filltess(struct gllc_entity *ent, struct ds_unit *u, struct ev *v, int cnt);
void soft_update_contur(struct gllc_entity *ent, struct ds_unit *u);
void soft_update_filltess(struct gllc_entity *ent, struct ds_unit *u);

#endif