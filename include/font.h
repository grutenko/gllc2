#ifndef font_h
#define font_h

#include "draw.h"
#include "object.h"

struct gllc_glyph_geom {
        struct ds_vertex *V;
        GLuint *I;
        GLuint Vcnt;
        GLuint Icnt;
};

struct gllc_font_glyph
{
        int flags;
        struct gllc_glyph_geom normal;
        struct gllc_glyph_geom italic;
        struct gllc_glyph_geom bold;
        struct gllc_glyph_geom bold_italic;
};

struct gllc_font_glyph_cache
{
        struct gllc_font_glyph *glyphs;
        int glyphcnt;
        int glyphcap;
};

struct gllc_font
{
        struct gllc_object _obj;
        char *filename;
        char *name;
        void *data;
        int data_size;
        struct gllc_font_glyph_cache cache;
        int nrefs;
        struct gllc_font *prev;
        struct gllc_font *next;
};

void gllc_fonts_scan();
int gllc_fonts_cnt();
struct gllc_font *gllc_font_create(int ttf, const char *name, const char *filename);
struct gllc_font *gllc_font_create_binary(int ttf, const char *name, void *data);
struct gllc_font *gllc_font_first();
struct gllc_font *gllc_font_next(struct gllc_font *font);
void gllc_fonts_clear();

#endif