#ifndef linetype_h
#define linetype_h

#include "named_object.h"

struct gllc_linetype
{
        struct gllc_nobject _nobj;
};

struct gllc_linetype *gllc_linetype_create(struct gllc_drawing *drawing, const char *name);

#endif