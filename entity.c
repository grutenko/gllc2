#include "entity.h"
#include "block.h"
#include "layer.h"
#include "litecad.h"
#include "object.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

static struct coloritab {
  int index;
  const char *name;
  int color;
} _coloritab[] = {{-1, NULL, 0}};

static struct coloritab *find_color_by_name(const char *name) {
  int i = 0;
  while (_coloritab[i].index == -1) {
    if (strcmp(_coloritab[i].name, name) == 0)
      return &_coloritab[i];
  }
  return NULL;
}

static struct coloritab *find_color_by_color(int color) {
  int i = 0;
  while (_coloritab[i].index == -1) {
    if (_coloritab[i].color == color)
      return &_coloritab[i];
  }
  return NULL;
}

static struct coloritab *find_color_by_index(int index) {
  int i = 0;
  while (_coloritab[i].index == -1) {
    if (_coloritab[i].index == index)
      return &_coloritab[i];
  }
  return NULL;
}

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
  union gllc_variant v;
  v.handle_ = ((struct gllc_entity *)obj)->block;
  return v;
}

static int _ent_block_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_entity *)obj)->block = value.handle_;
  return 1;
}

static union gllc_variant _ent_drw_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_layer_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = ((struct gllc_entity *)obj)->layer;
  return v;
}

static int _ent_layer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  ((struct gllc_entity *)obj)->layer = value.handle_;
  return 1;
}

static union gllc_variant _ent_linetype_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = gllc_entity_linetype((struct gllc_entity *)obj);
  return v;
}

static int _ent_linetype_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_linetype((struct gllc_entity *)obj, value.handle_);
}

static union gllc_variant _ent_ltscale_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.float_ = gllc_entity_ltscale((struct gllc_entity *)obj);
  return v;
}

static int _ent_ltscale_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_ltscale((struct gllc_entity *)obj, value.float_);
}

static union gllc_variant _ent_lwidth_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  if (type == T_PROP_INT) {
    v.int_ = gllc_entity_lwidth_mode((struct gllc_entity *)obj);
  } else if (type == T_PROP_FLOAT) {
    v.float_ = gllc_entity_lwidth((struct gllc_entity *)obj);
  }
  return v;
}

static int _ent_lwidth_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  if (type == T_PROP_INT) {
    gllc_entity_set_lwidth_mode((struct gllc_entity *)obj, value.int_);
  } else if (type == T_PROP_FLOAT) {
    gllc_entity_set_lwidth((struct gllc_entity *)obj, value.float_);
  }
  return 1;
}

static union gllc_variant _ent_fromcb_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_color_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  if (type == T_PROP_INT) {
    v.int_ = gllc_entity_color((struct gllc_entity *)obj);
  } else if (type == T_PROP_STRING) {
    v.string_ = gllc_entity_color_string((struct gllc_entity *)obj);
  }
  return v;
}

static int _ent_color_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  if (type == T_PROP_INT) {
    return gllc_entity_set_color((struct gllc_entity *)obj, value.int_);
  } else if (type == T_PROP_STRING) {
    return gllc_entity_set_color_by_string((struct gllc_entity *)obj, value.string_);
  }
  return 0;
}

static union gllc_variant _ent_colori_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  if (type == T_PROP_BOOL) {
    v.bool_ = gllc_entity_is_colori((struct gllc_entity *)obj);
  } else if (type == T_PROP_INT) {
    v.int_ = gllc_entity_colori((struct gllc_entity *)obj);
  }
  return v;
}

static int _ent_colori_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_colori((struct gllc_entity *)obj, value.int_);
}

static union gllc_variant _ent_colort_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  if (type == T_PROP_BOOL) {
    v.bool_ = gllc_entity_is_colort((struct gllc_entity *)obj);
  } else if (type == T_PROP_INT) {
    v.int_ = gllc_entity_color((struct gllc_entity *)obj);
  }
  return v;
}

static int _ent_colort_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_color((struct gllc_entity *)obj, value.int_);
}

static union gllc_variant _ent_color_by_layer_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = gllc_entity_color_by_layer((struct gllc_entity *)obj);
  return v;
}

static int _ent_color_by_layer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_color_by_layer((struct gllc_entity *)obj, value.bool_);
}

static union gllc_variant _ent_color_by_block_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = gllc_entity_color_by_block((struct gllc_entity *)obj);
  return v;
}

static int _ent_color_by_block_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_color_by_block((struct gllc_entity *)obj, value.bool_);
}

static union gllc_variant _ent_filled_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = gllc_entity_filled((struct gllc_entity *)obj);
  return v;
}

static int _ent_filled_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_filled((struct gllc_entity *)obj, value.bool_);
}

static union gllc_variant _ent_fcolor_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = gllc_entity_fcolor((struct gllc_entity *)obj);
  return v;
}

static int _ent_fcolor_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_fcolor((struct gllc_entity *)obj, value.int_);
}

static union gllc_variant _ent_fcolori_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = gllc_entity_fcolori((struct gllc_entity *)obj);
  return v;
}

static int _ent_fcolori_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_fcolori((struct gllc_entity *)obj, value.int_);
}

static union gllc_variant _ent_fcolort_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = gllc_entity_fcolort((struct gllc_entity *)obj);
  return v;
}

static int _ent_fcolort_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_fcolort((struct gllc_entity *)obj, value.int_);
}

static union gllc_variant _ent_fcolor_by_layer_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = gllc_entity_fcolor_by_layer((struct gllc_entity *)obj);
  return v;
}

static int _ent_fcolor_by_layer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_fcolor_by_layer((struct gllc_entity *)obj, value.bool_);
}

static union gllc_variant _ent_fcolor_by_block_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = gllc_entity_fcolor_by_block((struct gllc_entity *)obj);
  return v;
}

static int _ent_fcolor_by_block_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_fcolor_by_block((struct gllc_entity *)obj, value.bool_);
}

static union gllc_variant _ent_falpha_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = (int)(gllc_entity_falpha((struct gllc_entity *)obj) * 255.0f);
  return v;
}

static int _ent_falpha_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_falpha((struct gllc_entity *)obj, value.int_ / 255.0f);
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
  union gllc_variant v;
  v.bool_ = gllc_entity_locked((struct gllc_entity *)obj);
  return v;
}

static union gllc_variant _ent_visible_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = gllc_entity_visible((struct gllc_entity *)obj);
  return v;
}

static union gllc_variant _ent_hidden_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.bool_ = gllc_entity_hidden((struct gllc_entity *)obj);
  return v;
}

static int _ent_hidden_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return gllc_entity_set_hidden((struct gllc_entity *)obj, value.bool_);
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
  union gllc_variant v;
  v.bool_ = gllc_entity_selected((struct gllc_entity *)obj);
  return v;
}

static union gllc_variant _ent_xmin_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  ((struct gllc_entity *)obj)->vtable->bbox((struct gllc_entity *)obj, 1.0f, &v.float_, NULL, NULL, NULL);
  return v;
}

static union gllc_variant _ent_ymin_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  ((struct gllc_entity *)obj)->vtable->bbox((struct gllc_entity *)obj, 1.0f, NULL, &v.float_, NULL, NULL);
  return v;
}

static union gllc_variant _ent_xmax_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  ((struct gllc_entity *)obj)->vtable->bbox((struct gllc_entity *)obj, 1.0f, NULL, NULL, &v.float_, NULL);
  return v;
}

static union gllc_variant _ent_ymax_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  ((struct gllc_entity *)obj)->vtable->bbox((struct gllc_entity *)obj, 1.0f, NULL, NULL, NULL, &v.float_);
  return v;
}

static union gllc_variant _ent_xcen_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double xmin, xmax;
  ((struct gllc_entity *)obj)->vtable->bbox((struct gllc_entity *)obj, 1.0f, &xmin, NULL, &xmax, NULL);
  v.float_ = xmin + (xmax - xmin) / 2.0f;
  return v;
}

static union gllc_variant _ent_ycen_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  double ymin, ymax;
  ((struct gllc_entity *)obj)->vtable->bbox((struct gllc_entity *)obj, 1.0f, NULL, &ymin, NULL, &ymax);
  v.float_ = ymin + (ymax - ymin) / 2.0f;
  return v;
}

static union gllc_variant _ent_dx_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_dy_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _ent_len_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  ((struct gllc_entity *)obj)->vtable->len((struct gllc_entity *)obj, &v.float_);
  return v;
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
  if (ent->layer && ent->flags & GLLC_ENT_COLOR_BY_LAYER) {
    return ent->layer->props.color;
  } else if (ent->block && ent->flags & GLLC_ENT_COLOR_BY_BLOCK) {
    return ent->block->props.color;
  }
  return ent->props.color;
}

int gllc_entity_fcolor(struct gllc_entity *ent) {
  if (ent->layer && ent->flags & GLLC_ENT_FCOLOR_BY_LAYER) {
    return ent->layer->props.fcolor;
  } else if (ent->block && ent->flags & GLLC_ENT_FCOLOR_BY_BLOCK) {
    return ent->block->props.fcolor;
  }
  return ent->props.fcolor;
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

void _gllc_entity_init(struct gllc_entity *ent, struct gllc_block *block, struct gllc_prop **props, struct gllc_entity_vtable *vtable) {
  memset(ent, 0, sizeof(struct gllc_entity));
  ent->block = block;
  GLLC_OBJECT_INIT(&ent->_obj, props, &G_entity_obj_vtable);
  ent->vtable = vtable;
  ent->flags |= GLLC_ENT_MODIFIED | GLLC_ENT_GEOMETRY_MODIFIED | GLLC_ENT_LW_THIN | GLLC_ENT_INITIAL;
  ent->props.ltscale = 1.0f;
  ent->props.color = 0;
  ent->props.fcolor = 0;
  ent->falpha = 1.0f;
}

int gllc_entity_set_falpha(struct gllc_entity *ent, float falpha) {
  ent->falpha = falpha;
  ent->flags |= GLLC_ENT_MODIFIED;
  return 1;
}

float gllc_entity_falpha(struct gllc_entity *ent) {
  return ent->falpha;
}

int gllc_entity_set_ltscale(struct gllc_entity *ent, float ltscale) {
  ent->props.ltscale = ltscale;
  ent->flags |= GLLC_ENT_MODIFIED;
  return 1;
}

int gllc_entity_set_lwidth_mode(struct gllc_entity *ent, int mode) {
  ent->flags &= ~(GLLC_ENT_LW_REAL | GLLC_ENT_LW_SCREEN | GLLC_ENT_LW_THIN);
  if (mode == LC_LW_REAL) {
    ent->flags |= GLLC_ENT_LW_REAL;
  } else if (mode == LC_LW_PIXEL) {
    ent->flags |= GLLC_ENT_LW_SCREEN;
  } else if (mode == LC_LW_THIN) {
    ent->flags |= GLLC_ENT_LW_THIN;
  } else {
    return 0;
  }
  ent->flags |= GLLC_ENT_MODIFIED | GLLC_ENT_GEOMETRY_MODIFIED;
  return 1;
}

int gllc_entity_set_lwidth(struct gllc_entity *ent, float lwidth) {
  ent->lwidth = lwidth;
  ent->flags |= GLLC_ENT_MODIFIED | GLLC_ENT_GEOMETRY_MODIFIED;
  return 1;
}

float gllc_entity_ltscale(struct gllc_entity *ent) {
  if (ent->props.ltscale > -1) {
    return ent->props.ltscale;
  } else if (ent->layer && ent->layer->props.ltscale > -1) {
    return ent->layer->props.ltscale;
  } else if (ent->block && ent->block->props.ltscale > -1) {
    return ent->block->props.ltscale;
  }
  return 1.0f;
}

int gllc_entity_lwidth_mode(struct gllc_entity *ent) {
  if (ent->flags & GLLC_ENT_LW_REAL) {
    return LC_LW_REAL;
  } else if (ent->flags & GLLC_ENT_LW_SCREEN) {
    return LC_LW_PIXEL;
  } else if (ent->flags & GLLC_ENT_LW_THIN) {
    return LC_LW_THIN;
  }
  return 0;
}

float gllc_entity_lwidth(struct gllc_entity *ent) {
  return ent->lwidth;
}

int gllc_entity_set_linetype(struct gllc_entity *ent, struct gllc_linetype *linetype) {
  ent->props.linetype = linetype;
  ent->flags |= GLLC_ENT_MODIFIED | GLLC_ENT_GEOMETRY_MODIFIED;
  return 1;
}

struct gllc_linetype *gllc_entity_linetype(struct gllc_entity *ent) {
  if (ent->props.linetype) {
    return ent->props.linetype;
  } else if (ent->layer->props.linetype) {
    return ent->layer->props.linetype;
  } else if (ent->block->props.linetype) {
    return ent->block->props.linetype;
  }
  return NULL;
}

int gllc_entity_color_by_layer(struct gllc_entity *ent) {
  return (ent->flags & GLLC_ENT_COLOR_BY_LAYER) > 0;
}

int gllc_entity_color_by_block(struct gllc_entity *ent) {
  return (ent->flags & GLLC_ENT_COLOR_BY_BLOCK) > 0;
}

int gllc_entity_fcolor_by_layer(struct gllc_entity *ent) {
  return (ent->flags & GLLC_ENT_FCOLOR_BY_LAYER) > 0;
}

int gllc_entity_fcolor_by_block(struct gllc_entity *ent) {
  return (ent->flags & GLLC_ENT_FCOLOR_BY_BLOCK) > 0;
}

int gllc_entity_set_color_by_layer(struct gllc_entity *ent, int enable) {
  ent->flags &= ~(GLLC_ENT_COLOR_BY_LAYER | GLLC_ENT_COLOR_BY_BLOCK);
  if (enable) {
    ent->flags |= GLLC_ENT_COLOR_BY_LAYER;
  }
  ent->flags |= GLLC_ENT_MODIFIED;
  return 1;
}

int gllc_entity_set_color_by_block(struct gllc_entity *ent, int enable) {
  ent->flags &= ~(GLLC_ENT_COLOR_BY_LAYER | GLLC_ENT_COLOR_BY_BLOCK);
  if (enable) {
    ent->flags |= GLLC_ENT_COLOR_BY_BLOCK;
  }
  ent->flags |= GLLC_ENT_MODIFIED;
  return 1;
}

int gllc_entity_set_fcolor_by_layer(struct gllc_entity *ent, int enable) {
  ent->flags &= ~(GLLC_ENT_FCOLOR_BY_LAYER | GLLC_ENT_FCOLOR_BY_BLOCK);
  if (enable) {
    ent->flags |= GLLC_ENT_FCOLOR_BY_LAYER;
  }
  ent->flags |= GLLC_ENT_MODIFIED;
  return 1;
}

int gllc_entity_set_fcolor_by_block(struct gllc_entity *ent, int enable) {
  ent->flags &= ~(GLLC_ENT_FCOLOR_BY_LAYER | GLLC_ENT_FCOLOR_BY_BLOCK);
  if (enable) {
    ent->flags |= GLLC_ENT_FCOLOR_BY_BLOCK;
  }
  ent->flags |= GLLC_ENT_MODIFIED;
  return 1;
}

int gllc_entity_filled(struct gllc_entity *ent) {
  return (ent->flags & GLLC_ENT_FILLED) > 0;
}

int gllc_entity_set_filled(struct gllc_entity *ent, int filled) {
  if (filled) {
    ent->flags |= GLLC_ENT_FILLED;
  } else {
    ent->flags &= ~GLLC_ENT_FILLED;
  }
  ent->flags |= GLLC_ENT_MODIFIED | GLLC_ENT_GEOMETRY_MODIFIED;
  return 1;
}

int gllc_entity_is_colori(struct gllc_entity *ent) {
  return find_color_by_color(gllc_entity_color(ent)) != NULL;
}

int gllc_entity_is_colort(struct gllc_entity *ent) {
  return find_color_by_color(gllc_entity_color(ent)) == NULL;
}

int gllc_entity_set_colori(struct gllc_entity *ent, int color) {
  struct coloritab *c = find_color_by_index(color);
  if (c) {
    gllc_entity_set_color(ent, c->color);
    return 1;
  }
  return 0;
}

int gllc_entity_set_colort(struct gllc_entity *ent, int color) {
  gllc_entity_set_color(ent, color);
  return 1;
}

int gllc_entity_set_color_by_string(struct gllc_entity *ent, const char *color) {
  struct coloritab *c = find_color_by_name(color);
  if (c) {
    gllc_entity_set_color(ent, c->color);
    return 1;
  }
  return 0;
}

int gllc_entity_colori(struct gllc_entity *ent) {
  struct coloritab *c = find_color_by_color(gllc_entity_color(ent));
  if (c) {
    return c->color;
  }
  return 0;
}

char *gllc_entity_color_string(struct gllc_entity *ent) {
  struct coloritab *c = find_color_by_color(gllc_entity_color(ent));
  if (c) {
    return (char *)c->name;
  }
  return NULL;
}

int gllc_entity_fcolori(struct gllc_entity *ent) {
  struct coloritab *c = find_color_by_color(gllc_entity_fcolor(ent));
  if (c) {
    return c->color;
  }
  return 0;
}

int gllc_entity_fcolort(struct gllc_entity *ent) {
  return gllc_entity_fcolor(ent);
}

int gllc_entity_set_fcolori(struct gllc_entity *ent, int ind) {
  struct coloritab *c = find_color_by_index(ind);
  if (c) {
    gllc_entity_set_fcolor(ent, c->color);
    return 1;
  }
  return 0;
}

int gllc_entity_set_fcolort(struct gllc_entity *ent, int color) {
  return gllc_entity_set_fcolor(ent, color);
}

int gllc_entity_locked(struct gllc_entity *ent) {
  return (ent->flags & GLLC_ENT_LOCKED) > 0;
}

int gllc_entity_visible(struct gllc_entity *ent) {
  return (ent->flags & GLLC_ENT_HIDDEN) == 0;
}

int gllc_entity_hidden(struct gllc_entity *ent) {
  return (ent->flags & GLLC_ENT_HIDDEN) > 0;
}

int gllc_entity_set_hidden(struct gllc_entity *ent, int enable) {
  if (enable) {
    ent->flags |= GLLC_ENT_HIDDEN;
  } else {
    ent->flags &= ~GLLC_ENT_HIDDEN;
  }
  ent->flags |= GLLC_ENT_MODIFIED;
  return 1;
}

int gllc_entity_selected(struct gllc_entity *ent) {
  return (ent->flags & GLLC_ENT_SELECTED) > 0;
}