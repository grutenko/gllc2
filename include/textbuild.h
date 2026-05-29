#ifndef textbuild_h
#define textbuild_h

#include "draw.h"
#include "font.h"

enum tb_halign {
    TB_HALIGN_LEFT,
    TB_HALIGN_CENTER,
    TB_HALIGN_RIGHT
};

enum tb_valign {
    TB_VALIGN_BASELINE,
    TB_VALIGN_BOTTOM,
    TB_VALIGN_MIDDLE,
    TB_VALIGN_TOP
};

struct tb_font_config
{
        float size;
        float oblique;
        int weight;
        int underline;
        int multiline;
        float linemaxwidth;
        float lineheight;
        float letterspacing;
        int valign;
        int halign;
};

int tb_get_extents(struct gllc_font *font, struct tb_font_config *config, const char *text, int *width, int *height);
int tb_build(struct gllc_font *font, struct tb_font_config *config, const char *text, double x, double y,
             unsigned char *color, struct ds_draw *draw, struct ds_unit *u);

#endif