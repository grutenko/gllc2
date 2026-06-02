#include "linetype.h"
#include "named_object.h"
#include "object.h"

#include <stdlib.h>
#include <string.h>

static struct gllc_prop linetype_props[] = {P_END};
static struct gllc_prop *all_props[] = {G_nobject_props, linetype_props, NULL};

static void destroy(struct gllc_object *obj)
{
}

static struct gllc_object_vtable vtable = {.type = GLLC_NAMED_OBJECT, .destroy = destroy};

struct gllc_linetype *gllc_linetype_create(struct gllc_drawing *drawing, const char *name)
{
        struct gllc_linetype *lt = malloc(sizeof(struct gllc_linetype));
        if (!lt)
        {
                return NULL;
        }
        memset(lt, 0, sizeof(struct gllc_linetype));
        gllc_nobject_init(&lt->_nobj, drawing, all_props, &vtable, GLLC_OBJ_LINETYPE, name);
        return lt;
}