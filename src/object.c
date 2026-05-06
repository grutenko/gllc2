#include "object.h"
#include "block.h"
#include "litecad.h"

#define G(obj) ((struct g_props_object *)(obj))

static void destroy(struct gllc_object *obj) {}

static union gllc_variant _g_regcode_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }

static union gllc_variant _g_version_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.string_ = G(obj)->version;
  return v;
}

static union gllc_variant _g_msgtitle_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_msgtitle_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_helpfile_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_helpfile_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_dirdll_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.string_ = G(obj)->dirdll;
  return v;
}

static union gllc_variant _g_dirfonts_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_dirfonts_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_dirlng_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_dirlng_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_dirtpl_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_dirtpl_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_dircfg_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_dircfg_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_savecfg_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_savecfg_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_icon16_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_icon16_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_icon32_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_icon32_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_rulerbmp_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_rulerbmp_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_prnusebmp_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_prnusebmp_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_prnbmpfile_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_prnbmpfile_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_prnbtnras_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_prnbtnras_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_prnbtnsrif_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_prnbtnsrif_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_pntpixsize_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_pntpixsize_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_getdelent_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_getdelent_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_fileprogress_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_fileprogress_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_str_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_str_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_int_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_int_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_float_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_float_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _g_handle_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _g_handle_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _sel_pickboxsize_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _sel_pickboxsize_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _sel_pickbyrect_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _sel_pickbyrect_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _sel_pickdrag_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _sel_pickdrag_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _sel_pickadd_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _sel_pickadd_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _sel_pickbylayer_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _sel_pickbylayer_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _sel_pickinpgon_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _sel_pickinpgon_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _sel_pickinpgonf_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _sel_pickinpgonf_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _sel_pickinimg_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _sel_pickinimg_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _sel_colorl1_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _sel_colorl1_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _sel_colorl2_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _sel_colorl2_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _sel_colorf_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _sel_colorf_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _osnap_mark_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _osnap_mark_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _osnap_aper_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _osnap_aper_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _osnap_marksize_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _osnap_marksize_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _osnap_apersize_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _osnap_apersize_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _osnap_markcolor_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _osnap_markcolor_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _cam_count_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _cam_count_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _cam_i_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _cam_i_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _cam_name_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }

static union gllc_variant _cam_on_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }

static union gllc_variant _cam_time_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _cam_time_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _cam_width_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static union gllc_variant _cam_height_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }

static union gllc_variant _cam_bits_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }

static union gllc_variant _cam_bprow_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }

static union gllc_variant _ras_fill_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _ras_fill_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _ras_color_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _ras_color_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static union gllc_variant _ras_noprint_GET(struct gllc_object *obj, int prop, int type) { return (union gllc_variant)0; }
static int _ras_noprint_SET(struct gllc_object *obj, int prop, int type, union gllc_variant v) { return 0; }

static struct gllc_prop props[] = {
    P_STRING_RO(LC_PROP_G_REGCODE, _g_regcode_GET),
    P_STRING_RO(LC_PROP_G_VERSION, _g_version_GET),
    P_STRING(LC_PROP_G_MSGTITLE, _g_msgtitle_GET, _g_msgtitle_SET),
    P_STRING(LC_PROP_G_HELPFILE, _g_helpfile_GET, _g_helpfile_SET),
    P_STRING_RO(LC_PROP_G_DIRDLL, _g_dirdll_GET),
    P_STRING(LC_PROP_G_DIRFONTS, _g_dirfonts_GET, _g_dirfonts_SET),
    P_STRING(LC_PROP_G_DIRLNG, _g_dirlng_GET, _g_dirlng_SET),
    P_STRING(LC_PROP_G_DIRTPL, _g_dirtpl_GET, _g_dirtpl_SET),
    P_STRING(LC_PROP_G_DIRCFG, _g_dircfg_GET, _g_dircfg_SET),
    P_HANDLE(LC_PROP_G_ICON16, _g_icon16_GET, _g_icon16_SET),
    P_STRING(LC_PROP_G_ICON16, _g_icon16_GET, _g_icon16_SET),
    P_HANDLE(LC_PROP_G_ICON32, _g_icon32_GET, _g_icon32_SET),
    P_STRING(LC_PROP_G_ICON32, _g_icon32_GET, _g_icon32_SET),
    P_HANDLE(LC_PROP_G_RULERBMP, _g_rulerbmp_GET, _g_rulerbmp_SET),
    P_STRING(LC_PROP_G_RULERBMP, _g_rulerbmp_GET, _g_rulerbmp_SET),
    P_BOOL(LC_PROP_G_PRNUSEBMP, _g_prnusebmp_GET, _g_prnusebmp_SET),
    P_STRING(LC_PROP_G_PRNBMPFILE, _g_prnbmpfile_GET, _g_prnbmpfile_SET),
    P_BOOL(LC_PROP_G_PRNBTNRAS, _g_prnbtnras_GET, _g_prnbtnras_SET),
    P_BOOL(LC_PROP_G_PRNBTNSRIF, _g_prnbtnsrif_GET, _g_prnbtnsrif_SET),
    P_BOOL(LC_PROP_G_PNTPIXSIZE, _g_pntpixsize_GET, _g_pntpixsize_SET),
    P_BOOL(LC_PROP_G_GETDELENT, _g_getdelent_GET, _g_getdelent_SET),
    P_BOOL(LC_PROP_G_FILEPROGRESS, _g_fileprogress_GET, _g_fileprogress_SET),
    P_STRING(LC_PROP_G_STR, _g_str_GET, _g_str_SET),
    P_INT(LC_PROP_G_INT, _g_int_GET, _g_int_SET),
    P_FLOAT(LC_PROP_G_FLOAT, _g_float_GET, _g_float_SET),
    P_HANDLE(LC_PROP_G_HANDLE, _g_handle_GET, _g_handle_SET),
    P_INT(LC_PROP_SEL_PICKBOXSIZE, _sel_pickboxsize_GET, _sel_pickboxsize_SET),
    P_BOOL(LC_PROP_SEL_PICKBYRECT, _sel_pickbyrect_GET, _sel_pickbyrect_SET),
    P_BOOL(LC_PROP_SEL_PICKDRAG, _sel_pickdrag_GET, _sel_pickdrag_SET),
    P_BOOL(LC_PROP_SEL_PICKADD, _sel_pickadd_GET, _sel_pickadd_SET),
    P_BOOL(LC_PROP_SEL_PICKBYLAYER, _sel_pickbylayer_GET, _sel_pickbylayer_SET),
    P_BOOL(LC_PROP_SEL_PICKINPGON, _sel_pickinpgon_GET, _sel_pickinpgon_SET),
    P_BOOL(LC_PROP_SEL_PICKINPGONF, _sel_pickinpgonf_GET, _sel_pickinpgonf_SET),
    P_BOOL(LC_PROP_SEL_PICKINIMG, _sel_pickinimg_GET, _sel_pickinimg_SET),
    P_INT(LC_PROP_SEL_COLORL1, _sel_colorl1_GET, _sel_colorl1_SET),
    P_INT(LC_PROP_SEL_COLORL2, _sel_colorl2_GET, _sel_colorl2_SET),
    P_INT(LC_PROP_SEL_COLORF, _sel_colorf_GET, _sel_colorf_SET),
    P_BOOL(LC_PROP_G_OSNAP_MARK, _osnap_mark_GET, _osnap_mark_SET),
    P_BOOL(LC_PROP_G_OSNAP_APER, _osnap_aper_GET, _osnap_aper_SET),
    P_INT(LC_PROP_G_OSNAP_MARKSIZE, _osnap_marksize_GET, _osnap_marksize_SET),
    P_INT(LC_PROP_G_OSNAP_APERSIZE, _osnap_apersize_GET, _osnap_apersize_SET),
    P_INT(LC_PROP_G_OSNAP_MARKCOLOR, _osnap_markcolor_GET, _osnap_markcolor_SET),
    P_INT(LC_PROP_G_CAMERA_COUNT, _cam_count_GET, _cam_count_SET),
    P_INT(LC_PROP_G_CAMERA_I, _cam_i_GET, _cam_i_SET),
    P_STRING_RO(LC_PROP_G_CAMERA_NAME, _cam_name_GET),
    P_INT(LC_PROP_G_CAMERA_TIME, _cam_time_GET, _cam_time_SET),
    P_INT_RO(LC_PROP_G_CAMERA_WIDTH, _cam_width_GET),
    P_INT_RO(LC_PROP_G_CAMERA_HEIGHT, _cam_height_GET),
    P_HANDLE_RO(LC_PROP_G_CAMERA_BITS, _cam_bits_GET),
    P_INT_RO(LC_PROP_G_CAMERA_BPROW, _cam_bprow_GET),
    P_BOOL(LC_PROP_G_RAS_FILL, _ras_fill_GET, _ras_fill_SET),
    P_BOOL(LC_PROP_G_RAS_COLOR, _ras_color_GET, _ras_color_SET),
    P_BOOL(LC_PROP_G_RAS_NOPRINT, _ras_noprint_GET, _ras_noprint_SET),
    P_END};
static struct gllc_prop *all_props[] = {props, NULL};
static struct gllc_object_vtable vtable = {
    .destroy = destroy};
struct g_props_object G_props_object = {
    ._obj = {
        .magic = GLLC_OBJMAGIC,
        .props = all_props,
        .vtable = &vtable},
    .version = "1.0.0",
    .dirdll = "."};

static inline struct gllc_prop *find_prop(struct gllc_prop **props, int prop, int typ) {
  int i, j;
  for (i = 0; props[i]; i++) {
    for (j = 0; props[i][j].prop != -1; j++) {
      if (props[i][j].prop == prop && props[i][j].type == typ) {
        return &props[i][j];
      }
    }
  }
  return NULL;
}

#define GET(T0, T1, T2)                                      \
  T2 gllc_prop_get_##T1(struct gllc_object *obj, int prop) { \
    if (!obj) {                                              \
      obj = (struct gllc_object *)&G_props_object;           \
    }                                                        \
    OBJGUARD(obj, 0, 0);                                     \
    struct gllc_prop **props = obj->props;                   \
    struct gllc_prop *p = find_prop(props, prop, T0);        \
    if (p) {                                                 \
      return p->getter(obj, prop, T0).T1##_;                 \
    }                                                        \
    return 0;                                                \
  }

GET(T_PROP_BOOL, bool, int)
GET(T_PROP_INT, int, int64_t)
GET(T_PROP_FLOAT, float, double)
GET(T_PROP_STRING, string, char *)
GET(T_PROP_HANDLE, handle, void *)

#define PUT(T0, T1, T2)                                                 \
  int gllc_prop_put_##T1(struct gllc_object *obj, int prop, T2 value) { \
    if (!obj) {                                                         \
      obj = (struct gllc_object *)&G_props_object;                      \
    }                                                                   \
    OBJGUARD(obj, 0, 0);                                                \
    struct gllc_prop **props = obj->props;                              \
    struct gllc_prop *p = find_prop(props, prop, T0);                   \
    if (p && !p->readonly) {                                            \
      union gllc_variant v;                                             \
      v.T1##_ = value;                                                  \
      return p->setter(obj, prop, T0, v);                               \
    }                                                                   \
    return 0;                                                           \
  }

PUT(T_PROP_BOOL, bool, int)
PUT(T_PROP_INT, int, int64_t)
PUT(T_PROP_FLOAT, float, double)
PUT(T_PROP_STRING, string, char *)
PUT(T_PROP_HANDLE, handle, void *)

void gllc_object_destroy(struct gllc_object *obj) {
  if (obj->vtable->destroy)
    obj->vtable->destroy(obj);
}