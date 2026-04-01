#include "entity.h"
#include "block.h"
#include "layer.h"
#include "litecad.h"
#include "object.h"
#include <stdlib.h>

static union gllc_variant _ent_type_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = ((struct gllc_entity *)obj)->vtable->type;
  return v;
}

static union gllc_variant _ent_id_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_key_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_key_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_block_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_block_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_drw_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_layer_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_layer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_linetype_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_linetype_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_ltscale_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_ltscale_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_lwidth_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_lwidth_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_fromcb_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_color_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_color_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_colori_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_colori_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_colort_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_colort_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_color_by_layer_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_color_by_layer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_color_by_block_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_color_by_block_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_filled_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_filled_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_fcolor_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_fcolor_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_fcolori_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_fcolori_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_fcolort_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_fcolort_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_fcolor_by_layer_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_fcolor_by_layer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_fcolor_by_block_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_fcolor_by_block_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_falpha_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_falpha_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_linfill_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_linfill_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_linfillnl_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_wipeout_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_wipeout_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_locked_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_visible_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_hidden_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_hidden_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_deleted_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_deleted_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_immortal_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _ent_immortal_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _ent_selected_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_xmin_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_ymin_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_xmax_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_ymax_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_xcen_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_ycen_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_dx_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_dy_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_len_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

struct gllc_prop G_entity_props[] = {
    P_BOOL_RO(LC_PROP_ENT_TYPE, _ent_type_GET),
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
    P_BOOL_RO(LC_PROP_ENT_FROMCB, _ent_fromcb_GET),
    P_INT(LC_PROP_ENT_COLOR, _ent_color_GET, _ent_color_SET),
    P_INT(LC_PROP_ENT_COLORI, _ent_colori_GET, _ent_colori_SET),
    P_INT(LC_PROP_ENT_COLORT, _ent_colort_GET, _ent_colort_SET),
    P_BOOL(LC_PROP_ENT_COLORBYLAYER, _ent_color_by_layer_GET, _ent_color_by_layer_SET),
    P_BOOL(LC_PROP_ENT_COLORBYBLOCK, _ent_color_by_block_GET, _ent_color_by_block_SET),
    P_BOOL(LC_PROP_ENT_SOLIDFILL, _ent_filled_GET, _ent_filled_SET),
    P_BOOL(LC_PROP_ENT_FILLED, _ent_filled_GET, _ent_filled_SET),
    P_INT(LC_PROP_ENT_FCOLOR, _ent_fcolor_GET, _ent_fcolor_SET),
    P_INT(LC_PROP_ENT_FCOLORI, _ent_fcolori_GET, _ent_fcolori_SET),
    P_INT(LC_PROP_ENT_FCOLORT, _ent_fcolort_GET, _ent_fcolort_SET),
    P_BOOL(LC_PROP_ENT_FCOLORBYLAYER, _ent_fcolor_by_layer_GET, _ent_color_by_layer_SET),
    P_BOOL(LC_PROP_ENT_FCOLORBYBLOCK, _ent_fcolor_by_block_GET, _ent_fcolor_by_block_SET),
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

static void obj_entity_destroy(struct gllc_object *obj) {
  struct gllc_entity *ent = (struct gllc_entity *)obj;
  if (ent->vtable && ent->vtable->destroy) {
    ent->vtable->destroy(ent);
  }
}

struct gllc_object_vtable G_entity_obj_vtable = {
    .destroy = obj_entity_destroy};

int gllc_entity_color(struct gllc_entity *ent) {
  if (ent->props.color != -1) {
    return ent->props.color;
  }
  if (ent->layer && ent->layer->props.color != -1) {
    return ent->layer->props.color;
  }
  if (ent->block && ent->block->props.color != -1) {
    return ent->block->props.color;
  }
  return 0;
}

int gllc_entity_fcolor(struct gllc_entity *ent) {
  if (ent->props.fcolor != -1) {
    return ent->props.fcolor;
  }
  if (ent->layer && ent->layer->props.fcolor != -1) {
    return ent->layer->props.fcolor;
  }
  if (ent->block && ent->block->props.fcolor != -1) {
    return ent->block->props.fcolor;
  }
  return 0;
}

void gllc_entity_destroy(struct gllc_entity *ent) {
  if (ent) {
    if (ent->vtable && ent->vtable->destroy) {
      ent->vtable->destroy(ent);
    }
    free(ent);
  }
}

int gllc_entity_set_color(struct gllc_entity *ent, int color) {
  if (ent) {
    ent->props.color = color;
    ent->flags |= GLLC_ENT_MODIFIED;
    return 1;
  }
  return 0;
}

int gllc_entity_set_fcolor(struct gllc_entity *ent, int fcolor) {
  if (ent) {
    ent->props.fcolor = fcolor;
    ent->flags |= GLLC_ENT_MODIFIED;
    return 1;
  }
  return 0;
}