#include "text.h"
#include "cglm/cglm.h"
#include "debug.h"
#include "draw.h"
#include "entbuildutil.h"
#include "entity.h"
#include "font.h"
#include "freetype/freetype.h"
#include "linalg.h"
#include "litecad.h"
#include "named_object.h"
#include "object.h"
#include "textstyle.h"
#include "utf8tools.h"

#include <epoxy/gl_generated.h>
#include <float.h>
#include <hb.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include FT_OUTLINE_H

#define TEXT(obj) ((struct gllc_text *)(obj))

static inline void push_vertex(struct ds_vertex *V, GLfloat x, GLfloat y, GLubyte *color, GLbyte *normal,
                               GLfloat *texCoord, GLuint glyphLoc)
{
        V->pos[0] = x;
        V->pos[1] = y;
        V->color[0] = color[0];
        V->color[1] = color[1];
        V->color[2] = color[2];
        V->color[3] = color[3];
        V->normal[0] = normal[0];
        V->normal[1] = normal[1];
        V->textureCoord[0] = texCoord[0];
        V->textureCoord[1] = texCoord[1];
        V->thickness = 0.0f;
        V->thicknessMiltiplier = 0.0f;
        V->length = 0.0f;
        V->glyphLoc = glyphLoc;
}

static inline void push_bbox_quad(struct ds_unit *u, float x0, float y0, float x1, float y1, unsigned char color[4],
                                  GLuint glyphLoc, float *glyphBbox)
{
        int base = ds_unit_vcnt(u);
        int ibase = ds_unit_icnt(u);

        struct ds_vertex *V = ds_unit_reserve_vertex(u, base + 4);
        GLuint *I = ds_unit_reserve_index(u, ds_unit_icnt(u) + 6);

        GLbyte n0[2] = {127, 127};
        GLbyte n1[2] = {-127, 127};
        GLbyte n2[2] = {-127, -127};
        GLbyte n3[2] = {127, -127};
        GLfloat texCoord[2];
        texCoord[0] = glyphBbox[0];
        texCoord[1] = glyphBbox[1];
        push_vertex(&V[base + 0], x0, y0, color, n0, texCoord, glyphLoc);
        texCoord[0] = glyphBbox[2];
        texCoord[1] = glyphBbox[1];
        push_vertex(&V[base + 1], x1, y0, color, n1, texCoord, glyphLoc);
        texCoord[0] = glyphBbox[2];
        texCoord[1] = glyphBbox[3];
        push_vertex(&V[base + 2], x1, y1, color, n2, texCoord, glyphLoc);
        texCoord[0] = glyphBbox[0];
        texCoord[1] = glyphBbox[3];
        push_vertex(&V[base + 3], x0, y1, color, n3, texCoord, glyphLoc);

        I[ibase + 0] = base + 0;
        I[ibase + 1] = base + 1;
        I[ibase + 2] = base + 2;
        I[ibase + 3] = base + 0;
        I[ibase + 4] = base + 2;
        I[ibase + 5] = base + 3;
}

static void build(struct gllc_entity *ent, struct ds_draw *draw, double scale)
{
        if (!TEXT(ent)->text)
        {
                ds_unit_reset(TEXT(ent)->u);
        }
        else
        {
                struct gllc_font *font = gllc_font_first();
                if (font)
                {
                        hb_buffer_t *buf = font->hbbuffer;
                        hb_buffer_add_utf8(buf, TEXT(ent)->text, -1, 0, -1);
                        hb_buffer_guess_segment_properties(buf);
                        FT_Set_Pixel_Sizes(font->ftface, 0, 16);
                        hb_font_set_scale(font->font, 16 * 64, 16 * 64);
                        hb_shape(font->font, buf, NULL, 0);
                        unsigned int glyph_count;
                        hb_glyph_info_t *glyph_info = hb_buffer_get_glyph_infos(buf, &glyph_count);
                        hb_glyph_position_t *glyph_pos = hb_buffer_get_glyph_positions(buf, &glyph_count);
                        hb_position_t cursor_x = 0;
                        hb_position_t cursor_y = 0;
                        ds_unit_reset(TEXT(ent)->u);
                        int cacheID = ds_draw_get_font_cache_id(draw, font);
                        int xs, ys;
                        float text_xmin = FLT_MAX;
                        float text_ymin = FLT_MAX;
                        float text_xmax = -FLT_MAX;
                        float text_ymax = -FLT_MAX;
                        float mul;
                        if (TEXT(ent)->height == 0)
                        {
                                mul = 56.0f / 16.0f;
                        }
                        else if (TEXT(ent)->height == -1.0f)
                        {
                                mul = 56.0f / 16.0f;
                        }
                        else
                        {
                                mul = TEXT(ent)->height / 16;
                        }
                        for (unsigned int i = 0; i < glyph_count; i++)
                        {
                                hb_codepoint_t glyphid = glyph_info[i].codepoint;
                                hb_position_t x_offset = glyph_pos[i].x_offset;
                                hb_position_t y_offset = glyph_pos[i].y_offset;
                                hb_position_t x_advance = glyph_pos[i].x_advance;
                                hb_position_t y_advance = glyph_pos[i].y_advance;
                                FT_BBox bbox;
                                FT_Load_Glyph(font->ftface, glyphid, FT_LOAD_DEFAULT);
                                FT_Outline_Get_CBox(&font->ftface->glyph->outline, &bbox);
                                float x = (cursor_x + x_offset) / 64.0f;
                                float y = (cursor_y + y_offset) / 64.0f;
                                float xMin = bbox.xMin / 64.0f + x;
                                float yMin = bbox.yMin / 64.0f + y;
                                float xMax = bbox.xMax / 64.0f + x;
                                float yMax = bbox.yMax / 64.0f + y;
                                int xs, ys;
                                hb_font_get_scale(font->font, &xs, &ys);
                                float glyphBbox[4];
                                glyphBbox[0] = (float)bbox.xMin;
                                glyphBbox[1] = (float)bbox.yMin;
                                glyphBbox[2] = (float)bbox.xMax;
                                glyphBbox[3] = (float)bbox.yMax;
                                if (xMin < text_xmin)
                                        text_xmin = xMin;
                                if (yMin < text_ymin)
                                        text_ymin = yMin;
                                if (xMax > text_xmax)
                                        text_xmax = xMax;
                                if (yMax > text_ymax)
                                        text_ymax = yMax;
                                unsigned char color[4];
                                resolv_color(ent, color);
                                unsigned int glyphLoc = ds_draw_get_font_glyph_loc(draw, font, cacheID, glyphid);
                                push_bbox_quad(TEXT(ent)->u, xMin, yMin, xMax, yMax, color, glyphLoc, glyphBbox);
                                cursor_x += x_advance;
                                cursor_y += y_advance;
                        }
                        TEXT(ent)->u->font_cache_id = cacheID;
                        hb_buffer_reset(font->hbbuffer);
                        double w = fabs(text_xmax - text_xmin);
                        double h = fabs(text_ymax - text_ymin);
                        mat4 T1, S, T2, R;
                        glm_translate_make(T1, (vec3){-(w / 2), -(h / 2), 0});
                        glm_scale_make(S, (vec3){mul, mul, 1.0f});
                        glm_translate_make(T2, (vec3){TEXT(ent)->x, TEXT(ent)->y, 0});
                        glm_rotate_make(R, glm_rad(TEXT(ent)->angle), (vec3){0, 0, 1});
                        for (int i = 0; i < ds_unit_vcnt(TEXT(ent)->u); i++)
                        {
                                vec4 in;
                                vec4 out;
                                in[0] = TEXT(ent)->u->V[i].pos[0];
                                in[1] = TEXT(ent)->u->V[i].pos[1];
                                in[2] = 0.0f;
                                in[3] = 1.0f;
                                glm_mat4_mulv3(T1, in, 1.0f, out);
                                glm_mat4_mulv3(S, out, 1.0f, out);
                                glm_mat4_mulv3(R, out, 1.0f, out);
                                if (ent->flags & GLLC_ENT_LW_SCREEN)
                                {
                                        // Если указано что размеры должны быть привязаны к экрану, используем подход с
                                        // контурами которые расширяются относительно scale в направлении своей нормали
                                        // на расстояние length. прописываем все это в вершину а исходные размеры делаем
                                        // минимально возможными.
                                        TEXT(ent)->u->V[i].thickness = LEN((double[]){out[0], out[1]});
                                        TEXT(ent)->u->V[i].thicknessMiltiplier = 1.0f;
                                        double n0[2];
                                        NORMTO((double[]){out[0], out[1]}, n0);
                                        TEXT(ent)->u->V[i].normal[0] = (GLubyte)(n0[0] * 127);
                                        TEXT(ent)->u->V[i].normal[1] = (GLubyte)(n0[1] * 127);
                                        out[0] = 0.0f;
                                        out[1] = 0.0f;
                                }
                                glm_mat4_mulv3(T2, out, 1.0f, out);
                                TEXT(ent)->u->V[i].pos[0] = out[0];
                                TEXT(ent)->u->V[i].pos[1] = out[1];
                        }
                }
        }
        resolv_flags(ent, &TEXT(ent)->u->flags);
        TEXT(ent)->u->flags |= DS_UNIT_GLYPH;
}

static void destroy(struct gllc_entity *ent)
{
        struct gllc_text *pl = (struct gllc_text *)ent;
        if (pl)
        {
                ds_unit_destroy(pl->u);
                free(pl->text);
                free(pl);
        }
}

static int vertices(struct gllc_entity *ent, double scale, struct ev *ver)
{
        return 0;
}

static int selected(struct gllc_entity *ent, int mode, double scale, double x0, double y0, double x1, double y1)
{
        return 0;
}

static int clone(struct gllc_entity *ent, struct gllc_entity **clone)
{
        if (ent->vtable->type != GLLC_ENT_TEXT)
                return 0;
        struct gllc_text *t = (struct gllc_text *)ent;
        struct gllc_text *nt = malloc(sizeof(struct gllc_text));
        if (!nt)
                return 0;
        memcpy(nt, t, sizeof(struct gllc_text));
        nt->u = ds_unit_clone(t->u);
        nt->text = malloc(strlen(t->text));
        if (!nt->text)
        {
                free(nt);
                return 0;
        }
        memcpy(nt->text, t->text, strlen(t->text) + 1);
        *clone = (struct gllc_entity *)nt;
        return 1;
}

static int picked(struct gllc_entity *ent, double scale, double x, double y, double *dis)
{
        return 0;
}

static int bbox(struct gllc_entity *ent, double scale, double *xmin, double *ymin, double *xmax, double *ymax)
{
        return 1;
}

static int len(struct gllc_entity *ent, double *len)
{
        return 1;
}

static struct gllc_entity_vtable vtable = {.type = GLLC_ENT_TEXT,
                                           .build = build,
                                           .destroy = destroy,
                                           .vertices = vertices,
                                           .selected = selected,
                                           .picked = picked,
                                           .bbox = bbox,
                                           .len = len,
                                           .clone = clone};

static union gllc_variant GET_style(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.handle_ = gllc_text_get_style(TEXT(obj));
        return v;
}

static int SET_style(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_style(TEXT(obj), (struct gllc_text_style *)value.handle_);
}

static union gllc_variant GET_str(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.string_ = gllc_text_get_str(TEXT(obj));
        return v;
}

static int SET_str(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_str(TEXT(obj), value.string_);
}

static union gllc_variant GET_len(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_text_get_len(TEXT(obj));
        return v;
}

static union gllc_variant GET_align(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_text_get_align(TEXT(obj));
        return v;
}

static int SET_align(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_align(TEXT(obj), value.int_);
}

static union gllc_variant GET_x(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_text_get_x(TEXT(obj));
        return v;
}

static int SET_x(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_x(TEXT(obj), value.float_);
}

static union gllc_variant GET_y(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.int_ = gllc_text_get_y(TEXT(obj));
        return v;
}

static int SET_y(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_y(TEXT(obj), value.float_);
}

static union gllc_variant GET_dx(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.float_ = gllc_text_get_dx(TEXT(obj));
        return v;
}

static int SET_dx(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_dx(TEXT(obj), value.float_);
}

static union gllc_variant GET_dy(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.float_ = gllc_text_get_dy(TEXT(obj));
        return v;
}

static int SET_dy(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_dy(TEXT(obj), value.float_);
}

static union gllc_variant GET_h(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.float_ = gllc_text_get_height(TEXT(obj));
        return v;
}

static int SET_h(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_height(TEXT(obj), value.float_);
}

static union gllc_variant GET_wscale(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.float_ = gllc_text_get_wscale(TEXT(obj));
        return v;
}

static int SET_wscale(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_wscale(TEXT(obj), value.float_);
}

static union gllc_variant GET_angle(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.float_ = gllc_text_get_angle(TEXT(obj));
        return v;
}

static int SET_angle(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_angle(TEXT(obj), value.float_);
}

static union gllc_variant GET_oblique(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.float_ = gllc_text_get_oblique(TEXT(obj));
        return v;
}

static int SET_oblique(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_oblique(TEXT(obj), value.float_);
}

static union gllc_variant GET_charspace(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.float_ = gllc_text_get_charspace(TEXT(obj));
        return v;
}

static int SET_charspace(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_charspace(TEXT(obj), value.float_);
}

static union gllc_variant GET_wrect(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.float_ = gllc_text_get_wrect(TEXT(obj));
        return v;
}

static union gllc_variant GET_x0(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.float_ = gllc_text_get_x0(TEXT(obj));
        return v;
}

static union gllc_variant GET_y0(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.float_ = gllc_text_get_y0(TEXT(obj));
        return v;
}

static union gllc_variant GET_xfit(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.float_ = gllc_text_get_xfit(TEXT(obj));
        return v;
}

static int SET_xfit(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_xfit(TEXT(obj), value.float_);
}

static union gllc_variant GET_yfit(struct gllc_object *obj, int prop, int type)
{
        union gllc_variant v;
        v.float_ = gllc_text_get_yfit(TEXT(obj));
        return v;
}

static int SET_yfit(struct gllc_object *obj, int prop, int type, union gllc_variant value)
{
        return gllc_text_set_yfit(TEXT(obj), value.float_);
}

static struct gllc_prop text_props[] = {P_HANDLE(LC_PROP_TEXT_STYLE, GET_style, SET_style),
                                        P_STRING(LC_PROP_TEXT_STYLE, GET_style, SET_style),
                                        P_STRING(LC_PROP_TEXT_STR, GET_str, SET_str),
                                        P_INT_RO(LC_PROP_TEXT_LEN, GET_len),
                                        P_INT(LC_PROP_TEXT_ALIGN, GET_align, SET_align),
                                        P_FLOAT(LC_PROP_TEXT_X, GET_x, SET_x),
                                        P_FLOAT(LC_PROP_TEXT_Y, GET_y, SET_y),
                                        P_INT(LC_PROP_TEXT_DX, GET_dx, SET_dx),
                                        P_INT(LC_PROP_TEXT_DY, GET_dy, SET_dy),
                                        P_FLOAT(LC_PROP_TEXT_H, GET_h, SET_h),
                                        P_FLOAT(LC_PROP_TEXT_WSCALE, GET_wscale, SET_wscale),
                                        P_FLOAT(LC_PROP_TEXT_ANGLE, GET_angle, SET_angle),
                                        P_FLOAT(LC_PROP_TEXT_OBLIQUE, GET_oblique, SET_oblique),
                                        P_FLOAT(LC_PROP_TEXT_CHARSPACE, GET_charspace, SET_charspace),
                                        P_FLOAT_RO(LC_PROP_TEXT_WRECT, GET_wrect),
                                        P_FLOAT_RO(LC_PROP_TEXT_X0, GET_x0),
                                        P_FLOAT_RO(LC_PROP_TEXT_Y0, GET_y0),
                                        P_FLOAT(LC_PROP_TEXT_XFIT, GET_xfit, SET_xfit),
                                        P_FLOAT(LC_PROP_TEXT_YFIT, GET_yfit, SET_yfit),
                                        P_END};

static struct gllc_prop *all_props[] = {G_entity_props, text_props, NULL};

struct gllc_text *gllc_text_create(struct gllc_block *block, struct ds_draw *draw, char *text, double x, double y)
{
        if (!utf8check(text, strlen(text)))
        {
                FMTERROR("Invalid utf8 string.");
                return NULL;
        }
        struct gllc_text *pl = malloc(sizeof(struct gllc_text));
        if (pl)
        {
                GLLC_ENTITY_INIT(&pl->_ent, block, all_props, &vtable);
                pl->_ent.flags |= GLLC_ENT_FILLED;
                pl->u = ds_unit_create(draw);
                if (text)
                {
                        pl->text = malloc(strlen(text) + 1);
                        if (pl->text)
                        {
                                strcpy(pl->text, text);
                        }
                }
                else
                {
                        pl->text = NULL;
                }
                pl->x = x;
                pl->y = y;
        }
        return pl;
}

struct gllc_text_style *gllc_text_get_style(struct gllc_text *text)
{
        return text->style;
}

int gllc_text_set_style(struct gllc_text *text, struct gllc_text_style *style)
{
        if (text->style)
        {
                gllc_nobject_decref((struct gllc_nobject *)text->style);
        }
        if (style)
        {
                gllc_nobject_incref((struct gllc_nobject *)style);
        }
        text->style = style;
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}

char *gllc_text_get_str(struct gllc_text *text)
{
        return text->text;
}

int gllc_text_set_str(struct gllc_text *text, char *str)
{
        if (str && !utf8check(str, strlen(str)))
        {
                FMTERROR("Invalid utf8 string.");
                return 0;
        }
        free(text->text);
        if (text)
        {
                text->text = malloc(strlen(str) + 1);
                if (text->text)
                {
                        strcpy(text->text, str);
                }
        }
        else
        {
                text->text = NULL;
        }
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}

int gllc_text_get_len(struct gllc_text *text)
{
        if (text->text)
        {
                return strlen(text->text);
        }
        return 0;
}

int gllc_text_get_align(struct gllc_text *text)
{
        return text->align;
}

int gllc_text_set_align(struct gllc_text *text, int align)
{
        text->align = align;
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}

double gllc_text_get_x(struct gllc_text *text)
{
        return text->x;
}

double gllc_text_get_y(struct gllc_text *text)
{
        return text->y;
}

int gllc_text_set_x(struct gllc_text *text, double x)
{
        text->x = x;
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}

int gllc_text_set_y(struct gllc_text *text, double y)
{
        text->y = y;
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}

int gllc_text_get_dx(struct gllc_text *text)
{
        return text->dx;
}

int gllc_text_get_dy(struct gllc_text *text)
{
        return text->dy;
}

int gllc_text_set_dx(struct gllc_text *text, int dx)
{
        text->dx = dx;
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}

int gllc_text_set_dy(struct gllc_text *text, int dy)
{
        text->dy = dy;
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}

float gllc_text_get_height(struct gllc_text *text)
{
        return text->height;
}

int gllc_text_set_height(struct gllc_text *text, float height)
{
        text->height = height;
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}

float gllc_text_get_wscale(struct gllc_text *text)
{
        return text->wscale;
}

int gllc_text_set_wscale(struct gllc_text *text, float wscale)
{
        text->wscale = wscale;
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}

float gllc_text_get_angle(struct gllc_text *text)
{
        return text->angle;
}

int gllc_text_set_angle(struct gllc_text *text, float angle)
{
        text->angle = angle;
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}

float gllc_text_get_oblique(struct gllc_text *text)
{
        return text->oblique;
}

int gllc_text_set_oblique(struct gllc_text *text, float oblique)
{
        text->oblique = oblique;
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}

float gllc_text_get_charspace(struct gllc_text *text)
{
        return text->charspace;
}

int gllc_text_set_charspace(struct gllc_text *text, float charspace)
{
        text->charspace = charspace;
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}

float gllc_text_get_wrect(struct gllc_text *text)
{
}

float gllc_text_get_x0(struct gllc_text *text)
{
}

float gllc_text_get_y0(struct gllc_text *text)
{
}

float gllc_text_get_xfit(struct gllc_text *text)
{
}

float gllc_text_get_yfit(struct gllc_text *text)
{
}

int gllc_text_set_xfit(struct gllc_text *text, double xfit)
{
        text->xfit = xfit;
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}

int gllc_text_set_yfit(struct gllc_text *text, double yfit)
{
        text->yfit = yfit;
        gllc_entity_set_modified((struct gllc_entity *)text, 1);
        return 1;
}
