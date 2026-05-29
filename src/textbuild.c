#include "textbuild.h"
#include "freetype/ftmm.h"
#include "freetype/ftoutln.h"
#include "hb-ft.h"
#include <math.h>

static void configure_font(struct gllc_font *font, struct tb_font_config *config)
{
        if (!font || !config)
                return;
        FT_Set_Pixel_Sizes(font->ftface, 0, (FT_UInt)config->size);
        int scale = (int)(config->size * 64.0f);
        hb_font_set_scale(font->font, scale, scale);
        hb_ft_font_changed(font->font);

        /* synthetic oblique */
        if (config->oblique != 0.0f)
        {
                FT_Matrix matrix;
                float shear = tanf(config->oblique);
                matrix.xx = 1 << 16;
                matrix.xy = (FT_Fixed)(shear * 65536.0f);
                matrix.yx = 0;
                matrix.yy = 1 << 16;
                FT_Set_Transform(font->ftface, &matrix, NULL);
        }
        else
        {
                FT_Set_Transform(font->ftface, NULL, NULL);
        }
#ifdef FT_FACE_FLAG_MULTIPLE_MASTERS
        if (FT_HAS_MULTIPLE_MASTERS(font->ftface))
        {
                FT_MM_Var *mmvar = NULL;
                if (FT_Get_MM_Var(font->ftface, &mmvar) == 0)
                {
                        FT_Fixed *coords = calloc(mmvar->num_axis, sizeof(FT_Fixed));
                        if (coords)
                        {
                                for (FT_UInt i = 0; i < mmvar->num_axis; i++)
                                {
                                        FT_Var_Axis *axis = &mmvar->axis[i];
                                        /*
                                         * OpenType 'wght'
                                         */
                                        if (axis->tag == FT_MAKE_TAG('w', 'g', 'h', 't'))
                                        {
                                                coords[i] = config->weight << 16;
                                        }
                                        else
                                        {
                                                coords[i] = axis->def;
                                        }
                                }
                                FT_Set_Var_Design_Coordinates(font->ftface, mmvar->num_axis, coords);
                                free(coords);
                        }

                        FT_Done_MM_Var(font->ftface->glyph->library, mmvar);
                }
        }
#endif
}

int tb_get_extents(struct gllc_font *font, struct tb_font_config *config, const char *text, int *width, int *height)
{
        configure_font(font, config);
        FT_Set_Pixel_Sizes(font->ftface, 0, 16);
        hb_font_set_scale(font->font, 16 * 64, 16 * 64);
        hb_buffer_t *buf;
        buf = hb_buffer_create();
        hb_buffer_add_utf8(buf, text, -1, 0, -1);
        hb_buffer_guess_segment_properties(buf);
        hb_shape(font->font, buf, NULL, 0);
        unsigned int count;
        hb_glyph_position_t *pos = hb_buffer_get_glyph_positions(buf, &count);
        float w = 0.0f;
        for (unsigned int i = 0; i < count; i++)
        {
                w += pos[i].x_advance / 64.0f;
        }
        *width = (int)ceilf(w);
        *height = (int)config->lineheight;
        hb_buffer_destroy(buf);
        return 1;
}

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

int tb_build(struct gllc_font *font, struct tb_font_config *config, const char *text, double x, double y,
             unsigned char *color, struct ds_draw *draw, struct ds_unit *u)
{
        configure_font(font, config);
        hb_buffer_t *buf;
        buf = hb_buffer_create();
        hb_buffer_add_utf8(buf, text, -1, 0, -1);
        hb_buffer_guess_segment_properties(buf);
        hb_shape(font->font, buf, NULL, 0);
        unsigned int glyph_count;
        hb_glyph_info_t *glyph_info = hb_buffer_get_glyph_infos(buf, &glyph_count);
        hb_glyph_position_t *glyph_pos = hb_buffer_get_glyph_positions(buf, &glyph_count);
        hb_position_t cursor_x = 0;
        hb_position_t cursor_y = 0;
        int cacheID = ds_draw_get_font_cache_id(draw, font);
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
                float cx = (cursor_x + x_offset) / 64.0f;
                float cy = (cursor_y + y_offset) / 64.0f;
                float xMin = bbox.xMin / 64.0f + cx + x;
                float yMin = bbox.yMin / 64.0f + cy + y;
                float xMax = bbox.xMax / 64.0f + cx + x;
                float yMax = bbox.yMax / 64.0f + cy + y;
                float glyphBbox[4];
                glyphBbox[0] = (float)bbox.xMin;
                glyphBbox[1] = (float)bbox.yMin;
                glyphBbox[2] = (float)bbox.xMax;
                glyphBbox[3] = (float)bbox.yMax;
                unsigned int glyphLoc = ds_draw_get_font_glyph_loc(draw, font, cacheID, glyphid);
                push_bbox_quad(u, xMin, yMin, xMax, yMax, color, glyphLoc, glyphBbox);
                cursor_x += x_advance;
                cursor_y += y_advance;
        }
        u->font_cache_id = cacheID;
        u->flags |= DS_UNIT_GLYPH;
        hb_buffer_destroy(buf);
        return 1;
}