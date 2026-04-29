#include "drawing.h"
#include "block.h"
#include "litecad.h"
#include "named_object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =========================
 * General
 * ========================= */

static union gllc_variant _drw_uid_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _drw_filename_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_filename_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_descr_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_descr_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_comment_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_comment_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_readonly_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_readonly_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_dirty_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_dirty_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_idmax_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_idmax_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_synczoom_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_synczoom_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_hasalphablend_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _drw_blkrefgrips_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_blkrefgrips_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * Jump lines
 * ========================= */

static union gllc_variant _drw_jl_base_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_jl_base_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_jl_basex_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_jl_basex_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_jl_basey_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_jl_basey_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_jl_layer_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_jl_layer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * misc flags
 * ========================= */

static union gllc_variant _drw_extofflayer_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_extofflayer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_locksel_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_locksel_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_maxhatdash_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_maxhatdash_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_proplinfill_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_proplinfill_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_propzth_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_propzth_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_3dview_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

/* =========================
 * SYSTEM VARIABLES
 * ========================= */

static union gllc_variant _drw_lunits_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_lunits_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_luprec_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_luprec_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* (и так далее — все остальные system variables тем же шаблоном) */

/* =========================
 * COLORS (пример)
 * ========================= */

static union gllc_variant _drw_colorbackm_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_colorbackm_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_colorbackp_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_colorbackp_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * ACTIVE OBJECTS
 * ========================= */

static union gllc_variant _drw_layer_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_layer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * LIMITS
 * ========================= */

static union gllc_variant _drw_lim_maxlef_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_lim_maxlef_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * USER DATA
 * ========================= */

static union gllc_variant _drw_int_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_int_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_float_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_float_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_str_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_str_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * XDATA
 * ========================= */

static union gllc_variant _drw_xdatasize_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_xdatasize_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_xdata_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _drw_xdata_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * ANGLE / UNITS
 * ========================= */

static union gllc_variant _drw_aunits_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_aunits_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_auprec_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_auprec_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_angbase_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_angbase_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_angdir_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_angdir_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_insunits_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_insunits_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * POINT / TEXT
 * ========================= */

static union gllc_variant _drw_pdmode_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_pdmode_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_pdsize_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_pdsize_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_cmljust_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_cmljust_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_cmlscale_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_cmlscale_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * BACKGROUND / COLORS
 * ========================= */

static union gllc_variant _drw_colorforem_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_colorforem_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_colorforep_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_colorforep_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_cursorcolorm_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_cursorcolorm_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_cursorcolorp_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_cursorcolorp_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_colorpaper_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_colorpaper_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * ACTIVE COLOR
 * ========================= */

static union gllc_variant _drw_color_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_color_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_colorbylayer_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_colorbylayer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_colorbyblock_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_colorbyblock_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * COLOR INDEX / TRUECOLOR
 * ========================= */

static union gllc_variant _drw_colori_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_colori_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_colort_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_colort_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * FILL COLOR
 * ========================= */

static union gllc_variant _drw_fcolor_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_fcolor_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_fcolorbylayer_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_fcolorbylayer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_fcolorbyblock_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_fcolorbyblock_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_fcolori_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_fcolori_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_fcolort_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_fcolort_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * ACTIVE OBJECTS
 * ========================= */

static union gllc_variant _drw_linetype_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_linetype_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_ltscale_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_ltscale_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_textstyle_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_textstyle_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_pntstyle_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_pntstyle_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_dimstyle_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_dimstyle_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_block_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_block_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * EXPLODE
 * ========================= */

static union gllc_variant _drw_explodearc_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_explodearc_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_expplinela_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_expplinela_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_expsimpleline_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_expsimpleline_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_exptextspline_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_exptextspline_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * RESOLUTION
 * ========================= */

static union gllc_variant _drw_resolarc_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_resolarc_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_resolspline_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_resolspline_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_resoltext_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_resoltext_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

/* =========================
 * LIMITS
 * ========================= */

static union gllc_variant _drw_lim_maxbot_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_lim_maxbot_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_lim_maxrig_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_lim_maxrig_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_lim_maxtop_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_lim_maxtop_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_lim_maxon_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}
static int _drw_lim_maxon_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) {
  return 0;
}

static union gllc_variant _drw_block_model_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = gllc_drw_get_first_object((struct gllc_drawing *)obj, GLLC_OBJ_BLOCK);
  return v;
}

static union gllc_variant _drw_layer_0_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = NULL;
  return v;
}

static union gllc_variant _drw_linetype_cont_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = NULL;
  return v;
}

static union gllc_variant _drw_linetype_bylay_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = NULL;
  return v;
}

static union gllc_variant _drw_linetype_byblk_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = NULL;
  return v;
}

static union gllc_variant _drw_textstyle_std_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = NULL;
  return v;
}

static union gllc_variant _drw_pntstyle_std_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = NULL;
  return v;
}

static union gllc_variant _drw_dimstyle_std_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = NULL;
  return v;
}

static struct gllc_prop props[] = {
    P_STRING_RO(LC_PROP_DRW_UID, _drw_uid_GET),
    P_STRING(LC_PROP_DRW_FILENAME, _drw_filename_GET, _drw_filename_SET),
    P_STRING(LC_PROP_DRW_DESCR, _drw_descr_GET, _drw_descr_SET),
    P_STRING(LC_PROP_DRW_COMMENT, _drw_comment_GET, _drw_comment_SET),
    P_BOOL(LC_PROP_DRW_READONLY, _drw_readonly_GET, _drw_readonly_SET),
    P_BOOL(LC_PROP_DRW_DIRTY, _drw_dirty_GET, _drw_dirty_SET),
    P_STRING(LC_PROP_DRW_IDMAX, _drw_idmax_GET, _drw_idmax_SET),
    P_BOOL(LC_PROP_DRW_SYNCZOOM, _drw_synczoom_GET, _drw_synczoom_SET),
    P_BOOL_RO(LC_PROP_DRW_HASALPHABLEND, _drw_hasalphablend_GET),
    P_INT(LC_PROP_DRW_BLKREFGRIPS, _drw_blkrefgrips_GET, _drw_blkrefgrips_SET),
    P_BOOL(LC_PROP_DRW_JL_BASE, _drw_jl_base_GET, _drw_jl_base_SET),
    P_FLOAT(LC_PROP_DRW_JL_BASEX, _drw_jl_basex_GET, _drw_jl_basex_SET),
    P_FLOAT(LC_PROP_DRW_JL_BASEY, _drw_jl_basey_GET, _drw_jl_basey_SET),
    P_BOOL(LC_PROP_DRW_JL_LAYER, _drw_jl_layer_GET, _drw_jl_layer_SET),
    P_BOOL(LC_PROP_DRW_EXTOFFLAYER, _drw_extofflayer_GET, _drw_extofflayer_SET),
    P_BOOL(LC_PROP_DRW_LOCKSEL, _drw_locksel_GET, _drw_locksel_SET),
    P_INT(LC_PROP_DRW_MAXHATDASH, _drw_maxhatdash_GET, _drw_maxhatdash_SET),
    P_BOOL(LC_PROP_DRW_PROPLINFILL, _drw_proplinfill_GET, _drw_proplinfill_SET),
    P_BOOL(LC_PROP_DRW_PROPZTH, _drw_propzth_GET, _drw_propzth_SET),
    P_BOOL_RO(LC_PROP_DRW_3DVIEW, _drw_3dview_GET),
    P_INT(LC_PROP_DRW_LUNITS, _drw_lunits_GET, _drw_lunits_SET),
    P_INT(LC_PROP_DRW_LUPREC, _drw_luprec_GET, _drw_luprec_SET),
    P_INT(LC_PROP_DRW_AUNITS, _drw_aunits_GET, _drw_aunits_SET),
    P_INT(LC_PROP_DRW_AUPREC, _drw_auprec_GET, _drw_auprec_SET),
    P_INT(LC_PROP_DRW_ANGBASE, _drw_angbase_GET, _drw_angbase_SET),
    P_INT(LC_PROP_DRW_ANGDIR, _drw_angdir_GET, _drw_angdir_SET),
    P_INT(LC_PROP_DRW_INSUNITS, _drw_insunits_GET, _drw_insunits_SET),
    P_INT(LC_PROP_DRW_PDMODE, _drw_pdmode_GET, _drw_pdmode_SET),
    P_FLOAT(LC_PROP_DRW_PDSIZE, _drw_pdsize_GET, _drw_pdsize_SET),
    P_INT(LC_PROP_DRW_CMLJUST, _drw_cmljust_GET, _drw_cmljust_SET),
    P_FLOAT(LC_PROP_DRW_CMLSCALE, _drw_cmlscale_GET, _drw_cmlscale_SET),
    P_INT(LC_PROP_DRW_COLORBACKM, _drw_colorbackm_GET, _drw_colorbackm_SET),
    P_INT(LC_PROP_DRW_COLORBACKP, _drw_colorbackp_GET, _drw_colorbackp_SET),
    P_INT(LC_PROP_DRW_COLORFOREM, _drw_colorforem_GET, _drw_colorforem_SET),
    P_INT(LC_PROP_DRW_COLORFOREP, _drw_colorforep_GET, _drw_colorforep_SET),
    P_INT(LC_PROP_DRW_COLORCURSORM, _drw_cursorcolorm_GET, _drw_cursorcolorm_SET),
    P_INT(LC_PROP_DRW_COLORCURSORP, _drw_cursorcolorp_GET, _drw_cursorcolorp_SET),
    P_INT(LC_PROP_DRW_COLORPAPER, _drw_colorpaper_GET, _drw_colorpaper_SET),
    P_STRING(LC_PROP_DRW_COLOR, _drw_color_GET, _drw_color_SET),
    P_BOOL(LC_PROP_DRW_COLORBYLAYER, _drw_colorbylayer_GET, _drw_colorbylayer_SET),
    P_BOOL(LC_PROP_DRW_COLORBYBLOCK, _drw_colorbyblock_GET, _drw_colorbyblock_SET),
    P_INT(LC_PROP_DRW_COLORI, _drw_colori_GET, _drw_colori_SET),
    P_BOOL_RO(LC_PROP_DRW_COLORI, _drw_colori_GET),
    P_INT(LC_PROP_DRW_COLORT, _drw_colort_GET, _drw_colort_SET),
    P_BOOL_RO(LC_PROP_DRW_COLORT, _drw_colort_GET),
    P_STRING(LC_PROP_DRW_FCOLOR, _drw_fcolor_GET, _drw_fcolor_SET),
    P_BOOL(LC_PROP_DRW_FCOLORBYLAYER, _drw_fcolorbylayer_GET, _drw_fcolorbylayer_SET),
    P_BOOL(LC_PROP_DRW_FCOLORBYBLOCK, _drw_fcolorbyblock_GET, _drw_fcolorbyblock_SET),
    P_INT(LC_PROP_DRW_FCOLORI, _drw_fcolori_GET, _drw_fcolori_SET),
    P_INT(LC_PROP_DRW_FCOLORT, _drw_fcolort_GET, _drw_fcolort_SET),
    P_HANDLE(LC_PROP_DRW_LAYER, _drw_layer_GET, _drw_layer_SET),
    P_HANDLE(LC_PROP_DRW_LINETYPE, _drw_linetype_GET, _drw_linetype_SET),
    P_FLOAT(LC_PROP_DRW_LTSCALE, _drw_ltscale_GET, _drw_ltscale_SET),
    P_HANDLE(LC_PROP_DRW_TEXTSTYLE, _drw_textstyle_GET, _drw_textstyle_SET),
    P_HANDLE(LC_PROP_DRW_PNTSTYLE, _drw_pntstyle_GET, _drw_pntstyle_SET),
    P_HANDLE(LC_PROP_DRW_DIMSTYLE, _drw_dimstyle_GET, _drw_dimstyle_SET),
    P_HANDLE(LC_PROP_DRW_BLOCK, _drw_block_GET, _drw_block_SET),
    P_BOOL(LC_PROP_DRW_EXPLODEARC, _drw_explodearc_GET, _drw_explodearc_SET),
    P_BOOL(LC_PROP_DRW_EXPPLINELA, _drw_expplinela_GET, _drw_expplinela_SET),
    P_BOOL(LC_PROP_DRW_EXPSIMPLINE, _drw_expsimpleline_GET, _drw_expsimpleline_SET),
    P_BOOL(LC_PROP_DRW_EXPTEXTSPLINE, _drw_exptextspline_GET, _drw_exptextspline_SET),
    P_HANDLE_RO(LC_PROP_DRW_BLOCK_MODEL, _drw_block_model_GET),
    P_HANDLE_RO(LC_PROP_DRW_LAYER_0, _drw_layer_0_GET),
    P_HANDLE_RO(LC_PROP_DRW_LINETYPE_CONT, _drw_linetype_cont_GET),
    P_HANDLE_RO(LC_PROP_DRW_LINETYPE_BYLAY, _drw_linetype_bylay_GET),
    P_HANDLE_RO(LC_PROP_DRW_LINETYPE_BYBLK, _drw_linetype_byblk_GET),
    P_HANDLE_RO(LC_PROP_DRW_TEXTSTYLE_STD, _drw_textstyle_std_GET),
    P_HANDLE_RO(LC_PROP_DRW_PNTSTYLE_STD, _drw_pntstyle_std_GET),
    P_HANDLE_RO(LC_PROP_DRW_DIMSTYLE_STD, _drw_dimstyle_std_GET),
    P_INT(LC_PROP_DRW_RESOLARC, _drw_resolarc_GET, _drw_resolarc_SET),
    P_INT(LC_PROP_DRW_RESOLSPLINE, _drw_resolspline_GET, _drw_resolspline_SET),
    P_INT(LC_PROP_DRW_RESOLTEXT, _drw_resoltext_GET, _drw_resoltext_SET),
    P_FLOAT(LC_PROP_DRW_LIM_MAXLEF, _drw_lim_maxlef_GET, _drw_lim_maxlef_SET),
    P_FLOAT(LC_PROP_DRW_LIM_MAXBOT, _drw_lim_maxbot_GET, _drw_lim_maxbot_SET),
    P_FLOAT(LC_PROP_DRW_LIM_MAXRIG, _drw_lim_maxrig_GET, _drw_lim_maxrig_SET),
    P_FLOAT(LC_PROP_DRW_LIM_MAXTOP, _drw_lim_maxtop_GET, _drw_lim_maxtop_SET),
    P_BOOL(LC_PROP_DRW_LIM_MAXON, _drw_lim_maxon_GET, _drw_lim_maxon_SET),
    P_INT(LC_PROP_DRW_INT0, _drw_int_GET, _drw_int_SET),
    P_FLOAT(LC_PROP_DRW_FLOAT0, _drw_float_GET, _drw_float_SET),
    P_STRING(LC_PROP_DRW_STR0, _drw_str_GET, _drw_str_SET),
    P_INT(LC_PROP_DRW_XDATASIZE, _drw_xdatasize_GET, _drw_xdatasize_SET),
    P_HANDLE(LC_PROP_DRW_XDATA, _drw_xdata_GET, _drw_xdata_SET),
    P_END};
static struct gllc_prop *all_props[] = {props, G_nobject_props, NULL};

static void destroy(struct gllc_object *obj) {
  gllc_block_destroy((struct gllc_block *)obj);
}

static struct gllc_object_vtable vtable = {
    .destroy = destroy};

struct gllc_drawing *gllc_drw_create() {
  struct gllc_drawing *d = malloc(sizeof(struct gllc_drawing));
  if (d) {
    memset(d, 0, sizeof(struct gllc_drawing));
    GLLC_OBJECT_INIT(&d->_obj, all_props, &vtable);
    gllc_drw_add_block(d, "main", 0.0f, 0.0f);
  }
  return d;
}

static void push_obj(struct gllc_drawing *drawing, struct gllc_nobject *obj) {
  obj->prev = drawing->ot;
  obj->next = NULL;
  if (drawing->ot)
    drawing->ot->next = obj;
  else
    drawing->oh = obj;
  drawing->ot = obj;
  drawing->ocnt++;
}

struct gllc_block *gllc_drw_add_block(struct gllc_drawing *drawing,
                                      const char *name, double dx, double dy) {
  struct gllc_block *block = gllc_block_create(drawing, name, dx, dy);
  if (block) {
    push_obj(drawing, (struct gllc_nobject *)block);
  }
  return block;
}

struct gllc_layer *gllc_drw_add_layer(struct gllc_drawing *drw, const char *name, const char *color, struct gllc_linetype *linetype, int linewidth) {
  struct gllc_layer *layer = gllc_layer_create(drw, name, color, linetype, linewidth);
  if (layer) {
    push_obj(drw, (struct gllc_nobject *)layer);
  }
  return layer;
}

void gllc_drawing_destroy(struct gllc_drawing *drawing) {
  struct gllc_nobject *nobj = drawing->oh;
  while (nobj) {
    struct gllc_nobject *next = nobj->next;
    gllc_nobject_destroy(nobj);
    nobj = next;
  }
  free(drawing);
}

struct gllc_nobject *gllc_drw_get_first_object(struct gllc_drawing *drawing, int objtype) {
  for (struct gllc_nobject *item = drawing->ot; item; item = item->next) {
    if (item->type == objtype) {
      return item;
    }
  }
  return NULL;
}