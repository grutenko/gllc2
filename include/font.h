#ifndef font_h
#define font_h

#include "hb-gpu.h"
#include "hb.h"
#include "object.h"

#include <ft2build.h>
#include FT_FREETYPE_H

struct gllc_font
{
        struct gllc_object _obj;
        int ID;
        char *filename;
        char *name;
        hb_blob_t *data;
        hb_face_t *face;
        hb_font_t *font;
        hb_gpu_draw_t *hbdraw;
        hb_buffer_t *hbbuffer;
        FT_Face ftface;
        int nrefs;
        struct gllc_font *prev;
        struct gllc_font *next;
};

void gllc_fonts_scan();
int gllc_fonts_cnt();
struct gllc_font *gllc_font_create(int ttf, const char *name, const char *filename);
struct gllc_font *gllc_font_create_binary(int ttf, const char *name, void *data, size_t data_size);
struct gllc_font *gllc_font_first();
struct gllc_font *gllc_font_next(struct gllc_font *font);
void gllc_fonts_clear();

extern FT_Library ft;

#endif