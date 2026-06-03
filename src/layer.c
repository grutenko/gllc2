#include "layer.h"
#include "debug.h"
#include "entity.h"
#include "litecad.h"
#include "named_object.h"
#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LAYER(obj) ((struct gllc_layer *)(obj))

static char cstrbuffer[12];

static union gllc_variant _locked_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.bool_ = gllc_layer_locked((struct gllc_layer *)obj);
        return v;
}

static int _locked_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_locked((struct gllc_layer *)obj, !!value.bool_);
}

static union gllc_variant _descr_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.string_ = gllc_layer_get_description((struct gllc_layer *)obj);
        return v;
}

static int _descr_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_description((struct gllc_layer *)obj, value.string_);
}

static union gllc_variant _id_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = LAYER(obj)->_nobj.ID;
        return v;
}

static union gllc_variant _name_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.string_ = gllc_layer_get_name((struct gllc_layer *)obj);
        return v;
}

static int _name_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_name((struct gllc_layer *)obj, value.string_);
}

static union gllc_variant __drw_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.handle_ = LAYER(obj)->_nobj.drawing;
        return v;
}

static union gllc_variant _color_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.string_ = gllc_layer_get_color_string((struct gllc_layer *)obj);
        return v;
}

static int _color_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_color_string((struct gllc_layer *)obj, value.string_);
}

static union gllc_variant _colori_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        if (type == T_PROP_INT)
        {
                v.int_ = gllc_layer_get_colori((struct gllc_layer *)obj);
        }
        else
        {
                v.bool_ = gllc_layer_color_is_index((struct gllc_layer *)obj);
        }
        return v;
}

static int _colori_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_colori((struct gllc_layer *)obj, value.int_);
}

static union gllc_variant _colort_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        if (type == T_PROP_INT)
        {
                v.int_ = gllc_layer_get_colort((struct gllc_layer *)obj);
        }
        else
        {
                v.bool_ = gllc_layer_color_is_true((struct gllc_layer *)obj);
        }
        return v;
}

static int _colort_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_colort((struct gllc_layer *)obj, value.int_);
}

static union gllc_variant _fcolor_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.string_ = gllc_layer_get_fcolor_string((struct gllc_layer *)obj);
        return v;
}

static int _fcolor_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_fcolor_string((struct gllc_layer *)obj, value.string_);
}

static union gllc_variant _fcolori_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        if (type == T_PROP_INT)
        {
                v.int_ = gllc_layer_get_fcolori((struct gllc_layer *)obj);
        }
        else
        {
                v.bool_ = gllc_layer_fcolor_is_index((struct gllc_layer *)obj);
        }
        return v;
}

static int _fcolori_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_fcolori((struct gllc_layer *)obj, value.int_);
}

static union gllc_variant _fcolort_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        if (type == T_PROP_INT)
        {
                v.int_ = gllc_layer_get_fcolort((struct gllc_layer *)obj);
        }
        else
        {
                v.bool_ = gllc_layer_fcolor_is_true((struct gllc_layer *)obj);
        }
        return v;
}

static int _fcolort_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_fcolort((struct gllc_layer *)obj, value.int_);
}

static union gllc_variant _linetype_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.handle_ = gllc_layer_linetype((struct gllc_layer *)obj);
        return v;
}

static int _linetype_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_linetype((struct gllc_layer *)obj, (struct gllc_linetype *)value.handle_);
}

static union gllc_variant _linewidth_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_layer_get_lwidth((struct gllc_layer *)obj);
        return v;
}

static int _linewidth_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_lwidth((struct gllc_layer *)obj, value.int_);
}

static union gllc_variant _noprint_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_layer_noprint((struct gllc_layer *)obj);
        return v;
}

static int _noprint_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_noprint((struct gllc_layer *)obj, value.int_);
}

static union gllc_variant _visible_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_layer_visible((struct gllc_layer *)obj);
        return v;
}

static int _visible_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_visible((struct gllc_layer *)obj, value.int_);
}

static union gllc_variant _is0_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_layer_is0((struct gllc_layer *)obj);
        return v;
}

static union gllc_variant _nodlg_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_layer_nodlg((struct gllc_layer *)obj);
        return v;
}

static int _nodlg_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_layer_set_nodlg((struct gllc_layer *)obj, value.int_);
}

static union gllc_variant _jumplines_GET(struct gllc_object *obj, int prop, int type)
{
        return (union gllc_variant)0;
}

static int _jumplines_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return 1;
}

static union gllc_variant _osnap_GET(struct gllc_object *obj, int prop, int type)
{
        return (union gllc_variant)0;
}

static int _osnap_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return 1;
}

static union gllc_variant _noexport_GET(struct gllc_object *obj, int prop, int type)
{
        return (union gllc_variant)0;
}

static int _noexport_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return 1;
}

static struct gllc_prop props[] = {P_INT_RO(LC_PROP_LAYER_ID, _id_GET),
                                   P_STRING(LC_PROP_LAYER_NAME, _name_GET, _name_SET),
                                   P_STRING(LC_PROP_LAYER_DESCR, _descr_GET, _descr_SET),
                                   P_HANDLE_RO(LC_PROP_LAYER_DRW, __drw_GET),
                                   P_STRING(LC_PROP_LAYER_COLOR, _color_GET, _color_SET),
                                   P_INT(LC_PROP_LAYER_COLORI, _colori_GET, _colori_SET),
                                   P_BOOL(LC_PROP_LAYER_COLORI, _colori_GET, _colori_SET),
                                   P_INT(LC_PROP_LAYER_COLORT, _colort_GET, _colort_SET),
                                   P_BOOL_RO(LC_PROP_LAYER_COLORT, _colort_GET),
                                   P_STRING(LC_PROP_LAYER_FCOLOR, _fcolor_GET, _fcolor_SET),
                                   P_INT(LC_PROP_LAYER_FCOLORI, _fcolori_GET, _fcolori_SET),
                                   P_BOOL_RO(LC_PROP_LAYER_FCOLORI, _fcolori_GET),
                                   P_INT(LC_PROP_LAYER_FCOLORT, _fcolort_GET, _fcolort_SET),
                                   P_BOOL_RO(LC_PROP_LAYER_FCOLORT, _fcolort_GET),
                                   P_HANDLE(LC_PROP_LAYER_LINETYPE, _linetype_GET, _linetype_SET),
                                   P_STRING(LC_PROP_LAYER_LINETYPE, _linetype_GET, _linetype_SET),
                                   P_INT(LC_PROP_LAYER_LWIDTH, _linewidth_GET, _linewidth_SET),
                                   P_BOOL(LC_PROP_LAYER_LOCKED, _locked_GET, _locked_SET),
                                   P_BOOL(LC_PROP_LAYER_NOPRINT, _noprint_GET, _noprint_SET),
                                   P_BOOL(LC_PROP_LAYER_VISIBLE, _visible_GET, _visible_SET),
                                   P_BOOL_RO(LC_PROP_LAYER_0, _is0_GET),
                                   P_BOOL(LC_PROP_LAYER_NODLG, _nodlg_GET, _nodlg_SET),
                                   P_BOOL(LC_PROP_LAYER_JUMPLINES, _jumplines_GET, _jumplines_SET),
                                   P_BOOL(LC_PROP_LAYER_OSNAP, _osnap_GET, _osnap_SET),
                                   P_BOOL(LC_PROP_LAYER_NOEXPORT, _noexport_GET, _noexport_SET),
                                   P_END};
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
                if (color)
                {
                        gllc_layer_set_color_string(layer, (char *)color);
                }
                else
                {
                        gllc_layer_set_color_string(layer, "Black");
                }
                if (linetype)
                {
                        gllc_layer_set_linetype(layer, linetype);
                }
                gllc_layer_set_lwidth(layer, linewidth);
                gllc_layer_set_visible(layer, 1);
                gllc_layer_set_is0(layer, 0);
                gllc_layer_set_nodlg(layer, 0);
                gllc_layer_set_locked(layer, 0);
                gllc_layer_set_noprint(layer, 0);
                gllc_layer_set_fcolor_string(layer, "Black");
        }
        return layer;
}

void gllc_layer_set_entity(struct gllc_layer *layer, struct gllc_entity *ent)
{
        if (layer->entcap <= layer->entcnt)
        {
                size_t newcap = layer->entcap ? layer->entcap + 8 : 8;
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

static void set_entities_modified(struct gllc_layer *layer, int geometry)
{
        for (int i = 0; i < layer->entcnt; i++)
        {
                gllc_entity_set_modified(layer->ents[i], geometry);
        }
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

char *gllc_layer_get_color_string(struct gllc_layer *layer)
{
        color_t color = gllc_layer_color(layer);
        const char *name = color_get_name(color);
        if (name)
        {
                return (char *)name;
        }
        if (color != COLOR_INVALID)
        {
                uint8_t r, g, b;
                color_to_rgb(color, &r, &g, &b);
                sprintf(cstrbuffer, "%hhu,%hhu,%hhu", r, g, b);
                return cstrbuffer;
        }
        return 0;
}

int gllc_layer_set_color_string(struct gllc_layer *layer, char *color)
{
        color_t colorint = color_from_string(color);
        if (colorint != COLOR_INVALID)
        {
                return gllc_layer_set_color(layer, colorint);
        }
        return 0;
}

int gllc_layer_set_color(struct gllc_layer *layer, color_t color)
{
        layer->props.color = color_sanitize(color);
        set_entities_modified(layer, 0);
        return 1;
}

int gllc_layer_get_colori(struct gllc_layer *layer)
{
        color_t color = gllc_layer_color(layer);
        if (color_is_index(color))
        {
                return color_to_index(color);
        }
        return -1;
}

int gllc_layer_set_colori(struct gllc_layer *layer, int index)
{
        color_t color = color_from_index(index);
        if (color != COLOR_INVALID)
        {
                return gllc_layer_set_color(layer, color);
        }
        return 0;
}

int gllc_layer_color_is_index(struct gllc_layer *layer)
{
        return color_is_index(gllc_layer_color(layer));
}

color_t gllc_layer_get_colort(struct gllc_layer *layer)
{
        return gllc_layer_color(layer);
}

int gllc_layer_color_is_true(struct gllc_layer *layer)
{
        return !color_is_index(gllc_layer_color(layer));
}

color_t gllc_layer_color(struct gllc_layer *layer)
{
        return layer->props.color;
}

int gllc_layer_locked(struct gllc_layer *layer)
{
        return layer->flags & GLLC_LAYER_LOCKED;
}

int gllc_layer_set_locked(struct gllc_layer *layer, int locked)
{
        if (locked)
        {
                layer->flags |= GLLC_LAYER_LOCKED;
        }
        else
        {
                layer->flags &= ~GLLC_LAYER_LOCKED;
        }
        set_entities_modified(layer, 0);
        return 1;
}

int gllc_layer_set_colort(struct gllc_layer *layer, color_t color)
{
        return gllc_layer_set_color(layer, color);
}

int gllc_layer_set_fcolor(struct gllc_layer *layer, color_t color)
{
        layer->props.fcolor = color_sanitize(color);
        set_entities_modified(layer, 1);
        return 1;
}

int gllc_layer_get_fcolori(struct gllc_layer *layer)
{
        color_t color = gllc_layer_get_fcolor(layer);
        if (color_is_index(color))
        {
                return color_to_index(color);
        }
        return -1;
}

int gllc_layer_set_fcolori(struct gllc_layer *layer, int index)
{
        color_t color = color_from_index(index);
        if (color != COLOR_INVALID)
        {
                return gllc_layer_set_fcolor(layer, color);
        }
        return 0;
}

int gllc_layer_get_fcolort(struct gllc_layer *layer)
{
        return gllc_layer_get_fcolor(layer);
}

int gllc_layer_set_fcolort(struct gllc_layer *layer, color_t color)
{
        return gllc_layer_set_fcolor(layer, color);
}

int gllc_layer_set_fcolor_string(struct gllc_layer *layer, char *color)
{
        color_t colorint = color_from_string(color);
        if (colorint != COLOR_INVALID)
        {
                return gllc_layer_set_fcolor(layer, colorint);
        }
        return 0;
}

char *gllc_layer_get_fcolor_string(struct gllc_layer *layer)
{
        color_t color = gllc_layer_get_fcolor(layer);
        const char *name = color_get_name(color);
        if (name)
        {
                return (char *)name;
        }
        if (color != COLOR_INVALID)
        {
                uint8_t r, g, b;
                color_to_rgb(color, &r, &g, &b);
                sprintf(cstrbuffer, "%hhu,%hhu,%hhu", r, g, b);
                return cstrbuffer;
        }
        return 0;
}

int gllc_layer_fcolor_is_index(struct gllc_layer *layer)
{
        return color_is_index(gllc_layer_get_fcolor(layer));
}

int gllc_layer_fcolor_is_true(struct gllc_layer *layer)
{
        return !color_is_index(gllc_layer_get_fcolor(layer));
}

int gllc_layer_get_lwidth(struct gllc_layer *layer)
{
        return layer->props.lwidth;
}

int gllc_layer_set_lwidth(struct gllc_layer *layer, int lwidth)
{
        layer->props.lwidth = lwidth;
        set_entities_modified(layer, 1);
        return 1;
}

struct gllc_linetype *gllc_layer_linetype(struct gllc_layer *layer)
{
        return layer->props.linetype;
}

int gllc_layer_set_linetype(struct gllc_layer *layer, struct gllc_linetype *linetype)
{
        layer->props.linetype = linetype;
        set_entities_modified(layer, 1);
        return 1;
}

int gllc_layer_noprint(struct gllc_layer *layer)
{
        return layer->flags & GLLC_LAYER_NOPRINT;
}

int gllc_layer_set_noprint(struct gllc_layer *layer, int noprint)
{
        if (noprint)
        {
                layer->flags |= GLLC_LAYER_NOPRINT;
        }
        else
        {
                layer->flags &= ~GLLC_LAYER_NOPRINT;
        }
        set_entities_modified(layer, 0);
        return 1;
}

int gllc_layer_visible(struct gllc_layer *layer)
{
        return layer->flags & GLLC_LAYER_VISIBLE;
}

int gllc_layer_set_visible(struct gllc_layer *layer, int visible)
{
        if (visible)
        {
                layer->flags |= GLLC_LAYER_VISIBLE;
        }
        else
        {
                layer->flags &= ~GLLC_LAYER_VISIBLE;
        }
        set_entities_modified(layer, 0);
        return 1;
}

int gllc_layer_nodlg(struct gllc_layer *layer)
{
        return layer->flags & GLLC_LAYER_NODLG;
}

int gllc_layer_set_nodlg(struct gllc_layer *layer, int nodlg)
{
        if (nodlg)
        {
                layer->flags |= GLLC_LAYER_NODLG;
        }
        else
        {
                layer->flags &= ~GLLC_LAYER_NODLG;
        }
        set_entities_modified(layer, 0);
        return 1;
}

int gllc_layer_is0(struct gllc_layer *layer)
{
        return layer->flags & GLLC_LAYER_0;
}

int gllc_layer_set_is0(struct gllc_layer *layer, int is0)
{
        if (is0)
        {
                layer->flags |= GLLC_LAYER_0;
        }
        else
        {
                layer->flags &= ~GLLC_LAYER_0;
        }
        set_entities_modified(layer, 0);
        return 1;
}

color_t gllc_layer_get_color(struct gllc_layer *layer)
{
        return layer->props.color;
}

color_t gllc_layer_get_fcolor(struct gllc_layer *layer)
{
        return layer->props.fcolor;
}

char *gllc_layer_get_name(struct gllc_layer *layer)
{
        return gllc_nobject_get_name((struct gllc_nobject *)layer);
}

char *gllc_layer_get_description(struct gllc_layer *layer)
{
        return gllc_nobject_get_description((struct gllc_nobject *)layer);
}

int gllc_layer_set_name(struct gllc_layer *layer, const char *name)
{
        return gllc_nobject_set_name((struct gllc_nobject *)layer, name);
}

int gllc_layer_set_description(struct gllc_layer *layer, const char *description)
{
        return gllc_nobject_set_description((struct gllc_nobject *)layer, description);
}