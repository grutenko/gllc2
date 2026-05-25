#include "layer.h"
#include "entity.h"
#include "litecad.h"
#include "named_object.h"
#include "object.h"
#include <stdlib.h>
#include <string.h>

#define LAYER(obj) ((struct gllc_layer *)(obj))

static union gllc_variant _locked_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.bool_ = !!(((struct gllc_layer *)obj)->flags & GLLC_LAYER_LOCKED);
        return v;
}

static int _locked_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        if (value.bool_)
        {
                LAYER(obj)->flags |= GLLC_LAYER_LOCKED;
        }
        else
        {
                LAYER(obj)->flags &= ~GLLC_LAYER_LOCKED;
        }
        for (int i = 0; i < LAYER(obj)->entcnt; i++)
        {
                gllc_entity_set_modified(LAYER(obj)->ents[i], 0);
        }
}

static struct gllc_prop props[] = {P_BOOL(LC_PROP_LAYER_LOCKED, _locked_GET, _locked_SET)};
static struct gllc_prop *all_props[] = {props, G_nobject_props, NULL};

#define LAYER(obj) ((struct gllc_layer *)(obj))

static void destroy(struct gllc_object *obj)
{
        if (LAYER(obj)->props.linetype)
        {
                gllc_nobject_decref((struct gllc_nobject *)LAYER(obj)->props.linetype);
        }
        free(LAYER(obj)->ents);
        free(obj);
}

static struct gllc_object_vtable vtable = {.type = GLLC_NAMED_OBJECT, .destroy = destroy};

struct gllc_layer *gllc_layer_create(struct gllc_drawing *drw, const char *name, const char *color,
                                     struct gllc_linetype *linetype, int linewidth)
{
        NONULL(drw, NULL);
        OBJGUARD(drw, GLLC_DRAWING, NULL);
        struct gllc_layer *layer = malloc(sizeof(struct gllc_layer));
        if (layer)
        {
                memset(layer, 0, sizeof(struct gllc_layer));
                gllc_nobject_init((struct gllc_nobject *)layer, drw, all_props, &vtable, GLLC_OBJ_LAYER, name);
        }
        return layer;
}

void gllc_layer_set_entity(struct gllc_layer *layer, struct gllc_entity *ent)
{
        if (layer->entcap <= layer->entcnt)
        {
                size_t newcap = layer->entcap ? layer->entcap * 2 : 8;
                struct gllc_entity **ents = realloc(layer->ents, newcap * sizeof(struct gllc_entity *));
                if (!ents)
                {
                        return;
                }
                layer->ents = ents;
                layer->entcap = newcap;
        }
        layer->ents[layer->entcnt] = ent;
        layer->entcnt++;
}

void gllc_layer_unset_entity(struct gllc_layer *layer, struct gllc_entity *ent)
{
        for (int i = 0; i < layer->entcnt; i++)
        {
                if (layer->ents[i] == ent)
                {
                        layer->ents[i] = layer->ents[layer->entcnt - 1];
                        layer->entcnt--;
                        return;
                }
        }
}