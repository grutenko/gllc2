#include "font.h"
#include "mipgost.h"
#include "freetype/freetype.h"
#include "freetype/fttypes.h"

#include <hb.h>
#include <stdlib.h>
#include <string.h>

FT_Library ft;

static struct gllc_font *_fonts = NULL;
int _fontcnt = 0;
int _font_last_id = 0;

static void push_font(struct gllc_font *font)
{
        if (_fonts)
        {
                _fonts->next = font;
        }
        else
        {
                _fonts = font;
        }
        _fontcnt++;
}

void gllc_fonts_scan()
{
        struct gllc_font *simplex = gllc_font_create_binary(1, "Simplex", data, data_len);
        if (simplex)
        {
                push_font(simplex);
                FMTINFO("Load simplex font from binary.");
        }
}

int gllc_fonts_cnt()
{
        return _fontcnt;
}

struct gllc_font *gllc_font_create(int ttf, const char *name, const char *filename)
{
        return NULL;
}

struct gllc_font *gllc_font_create_binary(int ttf, const char *name, void *data, size_t data_size)
{
        struct gllc_font *font = malloc(sizeof(struct gllc_font));
        if (font)
        {
                font->ID = _font_last_id;
                memset(font, 0, sizeof(struct gllc_font));
                if (name)
                {
                        char *nname = malloc(strlen(name) + 1);
                        if (!nname)
                        {
                                free(font);
                                return NULL;
                        }
                        strcpy(nname, name);
                        font->name = nname;
                }
                font->data = hb_blob_create(data, data_size, HB_MEMORY_MODE_DUPLICATE, NULL, NULL);
                if (!font->data)
                {
                        free(font->name);
                        free(font);
                        return NULL;
                }
                font->face = hb_face_create(font->data, 0);
                font->font = hb_font_create(font->face);
                int err = FT_New_Memory_Face(ft, (const FT_Byte *)hb_blob_get_data(font->data, NULL), data_size, 0,
                                             &font->ftface);
                if (err != 0)
                {
                        free(font->name);
                        hb_font_destroy(font->font);
                        hb_face_destroy(font->face);
                        hb_blob_destroy(font->data);
                        FMTERROR("FT_New_Memory_Face failed: %d", err);
                }
                _font_last_id++;
        }
        return font;
}

struct gllc_font *gllc_font_first()
{
        return _fonts;
}

struct gllc_font *gllc_font_next(struct gllc_font *font)
{
        if (font)
        {
                return font->next;
        }
        return NULL;
}

void gllc_fonts_clear()
{
        struct gllc_font *font = _fonts;
        while (font)
        {
                struct gllc_font *t = font->next;
                free(font->name);
                free(font->filename);
                FT_Done_Face(font->ftface);
                hb_font_destroy(font->font);
                hb_face_destroy(font->face);
                hb_blob_destroy(font->data);
                font = t;
        }
        _fonts = NULL;
        _fontcnt = 0;
}