#include "entity.h"
#include "block.h"
#include "debug.h"
#include "layer.h"
#include "litecad.h"
#include "named_object.h"
#include "object.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENT(obj) ((struct gllc_entity *)(obj))

static struct
{
        int lc_type;
        int gllc_type;
} type_mapping[] = {{LC_ENT_LINE, GLLC_ENT_LINE},
                    {LC_ENT_CIRCLE, GLLC_ENT_CIRCLE},
                    {LC_ENT_ARC, GLLC_ENT_ARC},
                    {LC_ENT_POLYLINE, GLLC_ENT_POLYLINE},
                    {LC_ENT_TEXT, GLLC_ENT_TEXT}};

static union gllc_variant _ent_type_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        for (size_t i = 0; i < sizeof(type_mapping) / sizeof(type_mapping[0]); i++)
        {
                if (type_mapping[i].gllc_type == ENT(obj)->vtable->type)
                {
                        v.int_ = type_mapping[i].lc_type;
                        return v;
                }
        }
        return (union gllc_variant)0;
}

static union gllc_variant _ent_id_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        if (type == T_PROP_INT)
        {
                v.int_ = gllc_entity_get_id(ENT(obj));
        }
        else if (type == T_PROP_STRING)
        {
                v.string_ = gllc_entity_get_id_string(ENT(obj));
        }
        return v;
}

static union gllc_variant _ent_key_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_entity_get_id(ENT(obj));
        return v;
}

static int _ent_key_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_key(ENT(obj), value.int_);
}

static union gllc_variant _ent_block_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.handle_ = (ENT(obj))->block;
        return v;
}

static int _ent_block_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        ENT(obj)->block = value.handle_;
        return 1;
}

static union gllc_variant _ent_drw_GET(struct gllc_object *obj, int prop, int type)
{
        return (union gllc_variant)0;
}

static union gllc_variant _ent_layer_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.handle_ = gllc_entity_get_layer(ENT(obj));
        return v;
}

static int _ent_layer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_layer(ENT(obj), (struct gllc_layer *)value.handle_);
}

static union gllc_variant _ent_linetype_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.handle_ = gllc_entity_linetype(ENT(obj));
        return v;
}

static int _ent_linetype_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_linetype(ENT(obj), value.handle_);
}

static union gllc_variant _ent_ltscale_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.float_ = gllc_entity_ltscale(ENT(obj));
        return v;
}

static int _ent_ltscale_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_ltscale(ENT(obj), value.float_);
}

static union gllc_variant _ent_lwidth_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        if (type == T_PROP_INT)
        {
                v.int_ = gllc_entity_lwidth_mode(ENT(obj));
        }
        else if (type == T_PROP_FLOAT)
        {
                v.float_ = gllc_entity_lwidth(ENT(obj));
        }
        return v;
}

static int _ent_lwidth_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        if (type == T_PROP_INT)
        {
                gllc_entity_set_lwidth_mode(ENT(obj), value.int_);
        }
        else if (type == T_PROP_FLOAT)
        {
                gllc_entity_set_lwidth(ENT(obj), value.float_);
        }
        return 1;
}

static union gllc_variant _ent_fromcb_GET(struct gllc_object *obj, int prop, int type)
{
        return (union gllc_variant)0;
}

static union gllc_variant _ent_color_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        if (type == T_PROP_INT)
        {
                v.int_ = gllc_entity_color(ENT(obj));
        }
        else if (type == T_PROP_STRING)
        {
                v.string_ = gllc_entity_color_string(ENT(obj));
        }
        return v;
}

static int _ent_color_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        if (type == T_PROP_INT)
        {
                return gllc_entity_set_color(ENT(obj), value.int_);
        }
        else if (type == T_PROP_STRING)
        {
                return gllc_entity_set_color_by_string(ENT(obj), value.string_);
        }
        return 0;
}

static union gllc_variant _ent_colori_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        if (type == T_PROP_BOOL)
        {
                v.bool_ = gllc_entity_is_colori(ENT(obj));
        }
        else if (type == T_PROP_INT)
        {
                v.int_ = gllc_entity_colori(ENT(obj));
        }
        return v;
}

static int _ent_colori_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_colori(ENT(obj), value.int_);
}

static union gllc_variant _ent_colort_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        if (type == T_PROP_BOOL)
        {
                v.bool_ = gllc_entity_is_colort(ENT(obj));
        }
        else if (type == T_PROP_INT)
        {
                v.int_ = gllc_entity_color(ENT(obj));
        }
        return v;
}

static int _ent_colort_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_color(ENT(obj), value.int_);
}

static union gllc_variant _ent_color_by_layer_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.bool_ = gllc_entity_color_by_layer(ENT(obj));
        return v;
}

static int _ent_color_by_layer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_color_by_layer(ENT(obj), value.bool_);
}

static union gllc_variant _ent_color_by_block_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.bool_ = gllc_entity_color_by_block(ENT(obj));
        return v;
}

static int _ent_color_by_block_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_color_by_block(ENT(obj), value.bool_);
}

static union gllc_variant _ent_filled_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.bool_ = gllc_entity_filled(ENT(obj));
        return v;
}

static int _ent_filled_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_filled(ENT(obj), value.bool_);
}

static union gllc_variant _ent_fcolor_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        if (type == T_PROP_INT)
        {
                v.int_ = gllc_entity_fcolor(ENT(obj));
        }
        else if (type == T_PROP_STRING)
        {
                v.string_ = gllc_entity_get_fcolor_string(ENT(obj));
        }
        return v;
}

static int _ent_fcolor_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        if (type == T_PROP_INT)
        {
                return gllc_entity_set_fcolor(ENT(obj), value.int_);
        }
        else if (type == T_PROP_STRING)
        {
                return gllc_entity_set_fcolor_string(ENT(obj), value.string_);
        }
        return 1;
}

static union gllc_variant _ent_fcolori_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_entity_fcolori(ENT(obj));
        return v;
}

static int _ent_fcolori_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_fcolori(ENT(obj), value.int_);
}

static union gllc_variant _ent_fcolort_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_entity_fcolort(ENT(obj));
        return v;
}

static int _ent_fcolort_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_fcolort(ENT(obj), value.int_);
}

static union gllc_variant _ent_fcolor_by_layer_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_entity_fcolor_by_layer(ENT(obj));
        return v;
}

static int _ent_fcolor_by_layer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_fcolor_by_layer(ENT(obj), value.bool_);
}

static union gllc_variant _ent_fcolor_by_block_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_entity_fcolor_by_block(ENT(obj));
        return v;
}

static int _ent_fcolor_by_block_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_fcolor_by_block(ENT(obj), value.bool_);
}

static union gllc_variant _ent_falpha_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = (int)(gllc_entity_falpha(ENT(obj)) * 255.0f);
        return v;
}

static int _ent_falpha_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_falpha(ENT(obj), value.int_ / 255.0f);
}

static union gllc_variant _ent_color_alpha_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = (int)(gllc_entity_alpha(ENT(obj)) * 255.0f);
        return v;
}

static int _ent_color_alpha_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_alpha(ENT(obj), value.int_ / 255.0f);
}

static union gllc_variant _ent_linfill_GET(struct gllc_object *obj, int prop, int type)
{
        return (union gllc_variant)0;
}

static int _ent_linfill_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return 0;
}

static union gllc_variant _ent_linfillnl_GET(struct gllc_object *obj, int prop, int type)
{
        return (union gllc_variant)0;
}

static union gllc_variant _ent_wipeout_GET(struct gllc_object *obj, int prop, int type)
{
        return (union gllc_variant)0;
}

static int _ent_wipeout_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return 0;
}

static union gllc_variant _ent_locked_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.bool_ = gllc_entity_locked(ENT(obj));
        return v;
}

static union gllc_variant _ent_visible_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.bool_ = gllc_entity_visible(ENT(obj));
        return v;
}

static union gllc_variant _ent_hidden_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.bool_ = gllc_entity_hidden(ENT(obj));
        return v;
}

static int _ent_hidden_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_entity_set_hidden(ENT(obj), value.bool_);
}

static union gllc_variant _ent_deleted_GET(struct gllc_object *obj, int prop, int type)
{
        return (union gllc_variant)0;
}

static int _ent_deleted_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return 0;
}

static union gllc_variant _ent_immortal_GET(struct gllc_object *obj, int prop, int type)
{
        return (union gllc_variant)0;
}

static int _ent_immortal_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return 0;
}

static union gllc_variant _ent_selected_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.bool_ = gllc_entity_selected(ENT(obj));
        return v;
}

static union gllc_variant _ent_xmin_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        ENT(obj)->vtable->bbox(ENT(obj), 1.0f, &v.float_, NULL, NULL, NULL);
        return v;
}

static union gllc_variant _ent_ymin_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        ENT(obj)->vtable->bbox(ENT(obj), 1.0f, NULL, &v.float_, NULL, NULL);
        return v;
}

static union gllc_variant _ent_xmax_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        ENT(obj)->vtable->bbox(ENT(obj), 1.0f, NULL, NULL, &v.float_, NULL);
        return v;
}

static union gllc_variant _ent_ymax_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        ENT(obj)->vtable->bbox(ENT(obj), 1.0f, NULL, NULL, NULL, &v.float_);
        return v;
}

static union gllc_variant _ent_xcen_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        double xmin, xmax;
        ENT(obj)->vtable->bbox(ENT(obj), 1.0f, &xmin, NULL, &xmax, NULL);
        v.float_ = xmin + (xmax - xmin) / 2.0f;
        return v;
}

static union gllc_variant _ent_ycen_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        double ymin, ymax;
        ENT(obj)->vtable->bbox(ENT(obj), 1.0f, NULL, &ymin, NULL, &ymax);
        v.float_ = ymin + (ymax - ymin) / 2.0f;
        return v;
}

static union gllc_variant _ent_dx_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        double xmin, xmax;
        ENT(obj)->vtable->bbox(ENT(obj), 1.0f, &xmin, NULL, &xmax, NULL);
        v.float_ = fabs(xmax - xmin);
        return v;
}

static union gllc_variant _ent_dy_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        double ymin, ymax;
        ENT(obj)->vtable->bbox(ENT(obj), 1.0f, NULL, &ymin, NULL, &ymax);
        v.float_ = fabs(ymax - ymin);
        return v;
}

static union gllc_variant _ent_len_GET(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        ENT(obj)->vtable->len(ENT(obj), &v.float_);
        return v;
}

struct gllc_prop G_entity_props[] = {
    P_INT_RO(LC_PROP_ENT_TYPE, _ent_type_GET),
    P_INT_RO(LC_PROP_ENT_ID, _ent_id_GET),
    P_STRING_RO(LC_PROP_ENT_ID, _ent_id_GET),
    P_INT(LC_PROP_ENT_KEY, _ent_key_GET, _ent_key_SET),
    P_HANDLE(LC_PROP_ENT_BLOCK, _ent_block_GET, _ent_block_SET),
    P_STRING(LC_PROP_ENT_BLOCK, _ent_block_GET, _ent_block_SET),
    P_HANDLE_RO(LC_PROP_ENT_DRW, _ent_drw_GET),
    P_HANDLE(LC_PROP_ENT_LAYER, _ent_layer_GET, _ent_layer_SET),
    P_HANDLE(LC_PROP_ENT_LINETYPE, _ent_linetype_GET, _ent_linetype_SET),
    P_STRING(LC_PROP_ENT_LINETYPE, _ent_linetype_GET, _ent_linetype_SET),
    P_FLOAT(LC_PROP_ENT_LTSCALE, _ent_ltscale_GET, _ent_ltscale_SET),
    P_INT(LC_PROP_ENT_LWIDTH, _ent_lwidth_GET, _ent_lwidth_SET),
    P_FLOAT(LC_PROP_ENT_LWIDTH, _ent_lwidth_GET, _ent_lwidth_SET),
    P_BOOL_RO(LC_PROP_ENT_FROMCB, _ent_fromcb_GET),
    P_STRING(LC_PROP_ENT_COLOR, _ent_color_GET, _ent_color_SET),
    P_INT(LC_PROP_ENT_COLOR, _ent_color_GET, _ent_color_SET),
    P_INT(LC_PROP_ENT_COLORI, _ent_colori_GET, _ent_colori_SET),
    P_BOOL_RO(LC_PROP_ENT_COLORI, _ent_colori_GET),
    P_INT(LC_PROP_ENT_COLORT, _ent_colort_GET, _ent_colort_SET),
    P_BOOL_RO(LC_PROP_ENT_COLORT, _ent_colort_GET),
    P_BOOL(LC_PROP_ENT_COLORBYLAYER, _ent_color_by_layer_GET, _ent_color_by_layer_SET),
    P_BOOL(LC_PROP_ENT_COLORBYBLOCK, _ent_color_by_block_GET, _ent_color_by_block_SET),
    P_BOOL(LC_PROP_ENT_SOLIDFILL, _ent_filled_GET, _ent_filled_SET),
    P_BOOL(LC_PROP_ENT_FILLED, _ent_filled_GET, _ent_filled_SET),
    P_INT(LC_PROP_ENT_FCOLOR, _ent_fcolor_GET, _ent_fcolor_SET),
    P_STRING(LC_PROP_ENT_FCOLOR, _ent_fcolor_GET, _ent_fcolor_SET),
    P_INT(LC_PROP_ENT_FCOLORI, _ent_fcolori_GET, _ent_fcolori_SET),
    P_INT(LC_PROP_ENT_FCOLORT, _ent_fcolort_GET, _ent_fcolort_SET),
    P_BOOL(LC_PROP_ENT_FCOLORBYLAYER, _ent_fcolor_by_layer_GET, _ent_fcolor_by_layer_SET),
    P_BOOL(LC_PROP_ENT_FCOLORBYBLOCK, _ent_fcolor_by_block_GET, _ent_fcolor_by_block_SET),
    P_INT(XLC_PROP_ENT_ALPHA, _ent_color_alpha_GET, _ent_color_alpha_SET),
    P_INT(LC_PROP_ENT_FALPHA, _ent_falpha_GET, _ent_falpha_SET),
    P_HANDLE(LC_PROP_ENT_LINFILL, _ent_linfill_GET, _ent_linfill_SET),
    P_STRING(LC_PROP_ENT_LINFILL, _ent_linfill_GET, _ent_linfill_SET),
    P_INT_RO(LC_PROP_ENT_LINFILLNL, _ent_linfillnl_GET),
    P_BOOL(LC_PROP_ENT_WIPEOUT, _ent_wipeout_GET, _ent_wipeout_SET),
    P_BOOL_RO(LC_PROP_ENT_LOCKED, _ent_locked_GET),
    P_BOOL_RO(LC_PROP_ENT_VISIBLE, _ent_visible_GET),
    P_BOOL(LC_PROP_ENT_HIDDEN, _ent_hidden_GET, _ent_hidden_SET),
    P_BOOL(LC_PROP_ENT_DELETED, _ent_deleted_GET, _ent_deleted_SET),
    P_BOOL(LC_PROP_ENT_IMMORTAL, _ent_immortal_GET, _ent_immortal_SET),
    P_FLOAT_RO(LC_PROP_ENT_XMIN, _ent_xmin_GET),
    P_FLOAT_RO(LC_PROP_ENT_YMIN, _ent_ymin_GET),
    P_FLOAT_RO(LC_PROP_ENT_XMAX, _ent_xmax_GET),
    P_FLOAT_RO(LC_PROP_ENT_YMAX, _ent_ymax_GET),
    P_FLOAT_RO(LC_PROP_ENT_XCEN, _ent_xcen_GET),
    P_FLOAT_RO(LC_PROP_ENT_YCEN, _ent_ycen_GET),
    P_FLOAT_RO(LC_PROP_ENT_DX, _ent_dx_GET),
    P_FLOAT_RO(LC_PROP_ENT_DY, _ent_dy_GET),
    P_FLOAT_RO(LC_PROP_ENT_LEN, _ent_len_GET),
    P_END};

static void obj_entity_destroy(struct gllc_object *obj)
{
        struct gllc_entity *ent = ENT(obj);
        if (ent->layer)
        {
                gllc_layer_unset_entity(ent->layer, ent);
                gllc_nobject_decref((struct gllc_nobject *)(ent->layer));
        }
        if (ent->vtable && ent->vtable->destroy)
        {
                ent->vtable->destroy(ent);
        }
}

struct gllc_object_vtable G_entity_obj_vtable = {.type = GLLC_ENTITY, .destroy = obj_entity_destroy};

uint32_t gllc_entity_get_id(struct gllc_entity *ent)
{
        return ent->ID;
}

char *gllc_entity_get_id_string(struct gllc_entity *ent)
{
        return ent->ID_hex;
}

uint32_t gllc_entity_get_key(struct gllc_entity *ent)
{
        return ent->key;
}

int gllc_entity_set_key(struct gllc_entity *ent, uint32_t key)
{
        ent->key = key;
        return 1;
}

color_t gllc_entity_color(struct gllc_entity *ent)
{
        return ent->props.color;
}

color_t gllc_entity_fcolor(struct gllc_entity *ent)
{
        return ent->props.fcolor;
}

void gllc_entity_destroy(struct gllc_entity *ent)
{
        if (ent)
        {
                if (ent->vtable && ent->vtable->destroy)
                {
                        ent->vtable->destroy(ent);
                }
                free(ent);
        }
}

int gllc_entity_set_color(struct gllc_entity *ent, color_t color)
{
        if (ent)
        {
                ent->props.color = color;
                gllc_entity_set_modified(ent, 0);
                return 1;
        }
        return 0;
}

int gllc_entity_set_fcolor(struct gllc_entity *ent, color_t fcolor)
{

        if (ent)
        {
                ent->props.fcolor = fcolor;
                gllc_entity_set_modified(ent, 0);
                return 1;
        }
        return 0;
}

static uint32_t last_ID = 0;

static char ID_hex_tab[] = "0123456789ABCDEF";

static inline void ID_hexify(uint32_t ID, char *ID_hex)
{
        for (int i = 0, j = 28; i <= 8; i++, j -= 4)
        {
                ID_hex[i] = ID_hex_tab[(ID >> j) & 0xF];
        }
        ID_hex[8] = '\0';
}

void _gllc_entity_init(struct gllc_entity *ent, struct gllc_block *block, struct gllc_prop **props,
                       struct gllc_entity_vtable *vtable)
{
        memset(ent, 0, sizeof(struct gllc_entity));
        ent->block = block;
        GLLC_OBJECT_INIT(&ent->_obj, props, &G_entity_obj_vtable);
        ent->vtable = vtable;
        ent->flags |= (GLLC_ENT_MODIFIED | GLLC_ENT_GEOMETRY_MODIFIED | GLLC_ENT_LW_THIN | GLLC_ENT_INITIAL |
                       GLLC_ENT_COLOR_BY_LAYER | GLLC_ENT_FCOLOR_BY_LAYER);
        ent->ID = last_ID++;
        ID_hexify(ent->ID, ent->ID_hex);
        gllc_entity_set_ltscale(ent, 1.0f);
        gllc_entity_set_color(ent, 0x000000);
        gllc_entity_set_fcolor(ent, 0x000000);
        gllc_entity_set_falpha(ent, 1.0f);
        gllc_entity_set_alpha(ent, 1.0f);
}

int gllc_entity_set_falpha(struct gllc_entity *ent, float falpha)
{
        ent->props.falpha = falpha;
        gllc_entity_set_modified(ent, 0);
        return 1;
}

float gllc_entity_falpha(struct gllc_entity *ent)
{
        return ent->props.falpha;
}

int gllc_entity_set_ltscale(struct gllc_entity *ent, float ltscale)
{
        ent->props.ltscale = ltscale;
        gllc_entity_set_modified(ent, 0);
        return 1;
}

int gllc_entity_set_lwidth_mode(struct gllc_entity *ent, int mode)
{
        ent->flags &= ~(GLLC_ENT_LW_REAL | GLLC_ENT_LW_SCREEN | GLLC_ENT_LW_THIN);
        if (mode == LC_LW_REAL)
        {
                ent->flags |= GLLC_ENT_LW_REAL;
        }
        else if (mode == LC_LW_PIXEL)
        {
                ent->flags |= GLLC_ENT_LW_SCREEN;
        }
        else if (mode == LC_LW_THIN)
        {
                ent->flags |= GLLC_ENT_LW_THIN;
        }
        else
        {
                return 0;
        }
        gllc_entity_set_modified(ent, 1);
        return 1;
}

int gllc_entity_set_lwidth(struct gllc_entity *ent, float lwidth)
{
        ent->props.lwidth = lwidth;
        gllc_entity_set_modified(ent, 1);
        return 1;
}

float gllc_entity_ltscale(struct gllc_entity *ent)
{
        if (ent->props.ltscale > -1)
        {
                return ent->props.ltscale;
        }
        else if (ent->layer && ent->layer->props.ltscale > -1)
        {
                return ent->layer->props.ltscale;
        }
        return 1.0f;
}

int gllc_entity_lwidth_mode(struct gllc_entity *ent)
{
        if (ent->flags & GLLC_ENT_LW_REAL)
        {
                return LC_LW_REAL;
        }
        else if (ent->flags & GLLC_ENT_LW_SCREEN)
        {
                return LC_LW_PIXEL;
        }
        else if (ent->flags & GLLC_ENT_LW_THIN)
        {
                return LC_LW_THIN;
        }
        return 0;
}

float gllc_entity_lwidth(struct gllc_entity *ent)
{
        return ent->props.lwidth;
}

int gllc_entity_set_linetype(struct gllc_entity *ent, struct gllc_linetype *linetype)
{
        ent->props.linetype = linetype;
        gllc_entity_set_modified(ent, 1);
        return 1;
}

struct gllc_linetype *gllc_entity_linetype(struct gllc_entity *ent)
{
        if (ent->props.linetype)
        {
                return ent->props.linetype;
        }
        else if (ent->layer->props.linetype)
        {
                return ent->layer->props.linetype;
        }
        return NULL;
}

int gllc_entity_color_by_layer(struct gllc_entity *ent)
{
        return (ent->flags & GLLC_ENT_COLOR_BY_LAYER) > 0;
}

int gllc_entity_color_by_block(struct gllc_entity *ent)
{
        return (ent->flags & GLLC_ENT_COLOR_BY_BLOCK) > 0;
}

int gllc_entity_fcolor_by_layer(struct gllc_entity *ent)
{
        return (ent->flags & GLLC_ENT_FCOLOR_BY_LAYER) > 0;
}

int gllc_entity_fcolor_by_block(struct gllc_entity *ent)
{
        return (ent->flags & GLLC_ENT_FCOLOR_BY_BLOCK) > 0;
}

int gllc_entity_set_color_by_layer(struct gllc_entity *ent, int enable)
{
        ent->flags &= ~(GLLC_ENT_COLOR_BY_LAYER | GLLC_ENT_COLOR_BY_BLOCK);
        if (enable)
        {
                ent->flags |= GLLC_ENT_COLOR_BY_LAYER;
        }
        gllc_entity_set_modified(ent, 0);
        return 1;
}

int gllc_entity_set_color_by_block(struct gllc_entity *ent, int enable)
{
        ent->flags &= ~(GLLC_ENT_COLOR_BY_LAYER | GLLC_ENT_COLOR_BY_BLOCK);
        if (enable)
        {
                ent->flags |= GLLC_ENT_COLOR_BY_BLOCK;
        }
        gllc_entity_set_modified(ent, 0);
        return 1;
}

int gllc_entity_set_fcolor_by_layer(struct gllc_entity *ent, int enable)
{
        ent->flags &= ~(GLLC_ENT_FCOLOR_BY_LAYER | GLLC_ENT_FCOLOR_BY_BLOCK);
        if (enable)
        {
                ent->flags |= GLLC_ENT_FCOLOR_BY_LAYER;
        }
        gllc_entity_set_modified(ent, 0);
        return 1;
}

int gllc_entity_set_fcolor_by_block(struct gllc_entity *ent, int enable)
{
        ent->flags &= ~(GLLC_ENT_FCOLOR_BY_LAYER | GLLC_ENT_FCOLOR_BY_BLOCK);
        if (enable)
        {
                ent->flags |= GLLC_ENT_FCOLOR_BY_BLOCK;
        }
        gllc_entity_set_modified(ent, 0);
        return 1;
}

int gllc_entity_filled(struct gllc_entity *ent)
{
        return (ent->flags & GLLC_ENT_FILLED) > 0;
}

int gllc_entity_set_filled(struct gllc_entity *ent, int filled)
{
        if (filled)
        {
                ent->flags |= GLLC_ENT_FILLED;
        }
        else
        {
                ent->flags &= ~GLLC_ENT_FILLED;
        }
        gllc_entity_set_modified(ent, 1);
        return 1;
}

int gllc_entity_is_colori(struct gllc_entity *ent)
{
        return color_is_index(ent->props.color);
}

int gllc_entity_is_colort(struct gllc_entity *ent)
{
        return !color_is_index(ent->props.color);
}

int gllc_entity_set_colori(struct gllc_entity *ent, int index)
{
        color_t color = color_from_index(index);
        if (color != COLOR_INVALID)
        {
                gllc_entity_set_color(ent, color);
                return 1;
        }
        return 0;
}

int gllc_entity_set_colort(struct gllc_entity *ent, color_t color)
{
        gllc_entity_set_color(ent, color);
        return 1;
}

int gllc_entity_set_color_by_string(struct gllc_entity *ent, const char *color)
{
        color_t colorint = color_from_string(color);
        if (colorint != COLOR_INVALID)
        {
                gllc_entity_set_color(ent, colorint);
                return 1;
        }
        return 0;
}

int gllc_entity_colori(struct gllc_entity *ent)
{
        return color_to_index(gllc_entity_color(ent));
}

char *gllc_entity_color_string(struct gllc_entity *ent)
{
        color_t color = gllc_entity_color(ent);
        const char *name = color_get_name(color);
        if (name)
        {
                return (char *)name;
        }
        if (color != COLOR_INVALID)
        {
                uint8_t r, g, b;
                color_to_rgb(color, &r, &g, &b);
                sprintf(ent->props.cstrbuffer, "%hhu,%hhu,%hhu", r, g, b);
                return ent->props.cstrbuffer;
        }
        return NULL;
}

int gllc_entity_fcolori(struct gllc_entity *ent)
{
        return color_to_index(gllc_entity_fcolor(ent));
}

color_t gllc_entity_fcolort(struct gllc_entity *ent)
{
        return gllc_entity_fcolor(ent);
}

int gllc_entity_set_fcolori(struct gllc_entity *ent, int ind)
{
        color_t color = color_from_index(ind);
        if (color != COLOR_INVALID)
        {
                gllc_entity_set_fcolor(ent, color);
                return 1;
        }
        return 0;
}

int gllc_entity_set_fcolort(struct gllc_entity *ent, color_t color)
{
        return gllc_entity_set_fcolor(ent, color);
}

char *gllc_entity_get_fcolor_string(struct gllc_entity *ent)
{
        color_t color = gllc_entity_fcolor(ent);
        const char *name = color_get_name(color);
        if (name)
        {
                return (char *)name;
        }
        int r, g, b;
        color_to_rgb(color, (uint8_t *)&r, (uint8_t *)&g, (uint8_t *)&b);
        sprintf(ent->props.cstrbuffer, "%hhu,%hhu,%hhu", r, g, b);
        return ent->props.cstrbuffer;
}

int gllc_entity_set_fcolor_string(struct gllc_entity *ent, char *color)
{
        color_t colorint = color_from_string(color);
        if (colorint != COLOR_INVALID)
        {
                gllc_entity_set_fcolor(ent, colorint);
                return 1;
        }
        return 0;
}

int gllc_entity_locked(struct gllc_entity *ent)
{
        return ent->layer && (ent->layer->flags & GLLC_LAYER_LOCKED);
}

int gllc_entity_visible(struct gllc_entity *ent)
{
        return (ent->flags & GLLC_ENT_HIDDEN) == 0;
}

int gllc_entity_hidden(struct gllc_entity *ent)
{
        return (ent->flags & GLLC_ENT_HIDDEN) > 0;
}

int gllc_entity_set_hidden(struct gllc_entity *ent, int enable)
{
        if (enable)
        {
                ent->flags |= GLLC_ENT_HIDDEN;
        }
        else
        {
                ent->flags &= ~GLLC_ENT_HIDDEN;
        }
        gllc_entity_set_modified(ent, 1);
        return 1;
}

int gllc_entity_selected(struct gllc_entity *ent)
{
        return (ent->flags & GLLC_ENT_SELECTED) > 0;
}

int gllc_entity_hover(struct gllc_entity *ent)
{
        return (ent->flags & GLLC_ENT_HOVER) > 0;
}

int gllc_entity_set_hover(struct gllc_entity *ent, int enable)
{
        if (enable)
        {
                ent->flags |= GLLC_ENT_HOVER;
        }
        else
        {
                ent->flags &= ~GLLC_ENT_HOVER;
        }
        gllc_entity_set_modified(ent, 0);
        return 1;
}

int gllc_entity_modified(struct gllc_entity *ent)
{
        return (ent->flags & GLLC_ENT_MODIFIED) > 0;
}

int gllc_entity_geometry_modified(struct gllc_entity *ent)
{
        return (ent->flags & GLLC_ENT_GEOMETRY_MODIFIED) > 0;
}

int gllc_entity_set_modified(struct gllc_entity *ent, int geometry)
{
        int flags = ent->flags;
        flags |= GLLC_ENT_MODIFIED;
        if (geometry)
        {
                flags |= GLLC_ENT_GEOMETRY_MODIFIED;
        }
        if (flags != ent->flags)
        {
                gllc_block_put_bq(ent->block, ent);
        }
        return 1;
}

void gllc_entity_bbox(struct gllc_entity *ent, double scale, double *x0, double *y0, double *x1, double *y1)
{
        if (gllc_entity_geometry_modified(ent))
        {
                ent->vtable->bbox(ent, scale, &ent->bbox[0], &ent->bbox[1], &ent->bbox[2], &ent->bbox[3]);
        }
        *x0 = ent->bbox[0];
        *y0 = ent->bbox[1];
        *x1 = ent->bbox[2];
        *y1 = ent->bbox[3];
}

void gllc_entity_build(struct gllc_entity *ent, struct ds_draw *draw, double scale)
{
        if (gllc_entity_geometry_modified(ent))
        {
                ent->vtable->bbox(ent, scale, &ent->bbox[0], &ent->bbox[1], &ent->bbox[2], &ent->bbox[3]);
        }
        ent->vtable->build(ent, draw, scale);
}

int gllc_entity_set_layer(struct gllc_entity *ent, struct gllc_layer *layer)
{
        NONULL(ent, 0);
        if (layer)
        {
                OBJGUARD(layer, GLLC_NAMED_OBJECT, 0);
                if (layer->_nobj.type != GLLC_OBJ_LAYER)
                {
                        FMTERROR("Argument layer is not valid layer object.");
                        return 0;
                }
        }
        if (ent->layer)
        {
                gllc_layer_unset_entity(ent->layer, ent);
                gllc_nobject_decref((struct gllc_nobject *)(ent->layer));
        }
        if (layer)
        {
                gllc_layer_set_entity(layer, ent);
                gllc_nobject_incref((struct gllc_nobject *)layer);
        }
        ent->layer = layer;
        gllc_entity_set_modified(ent, 0);
        return 1;
}

struct gllc_layer *gllc_entity_get_layer(struct gllc_entity *ent)
{
        return ent->layer;
}

int gllc_entity_set_alpha(struct gllc_entity *ent, float alpha)
{
        ent->props.alpha = alpha;
        gllc_entity_set_modified(ent, 0);
        return 1;
}

float gllc_entity_alpha(struct gllc_entity *ent)
{
        return ent->props.alpha;
}

color_t gllc_entity_resolv_color(struct gllc_entity *ent)
{
        if (ent->layer && gllc_entity_color_by_layer(ent))
        {
                return gllc_layer_get_color(ent->layer);
        }
        return gllc_entity_color(ent);
}

color_t gllc_entity_resolv_fcolor(struct gllc_entity *ent)
{
        if (ent->layer && gllc_entity_fcolor_by_layer(ent))
        {
                return gllc_layer_get_fcolor(ent->layer);
        }
        return gllc_entity_fcolor(ent);
}