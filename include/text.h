#ifndef text_h
#define text_h

#include "draw.h"
#include "entity.h"

struct gllc_text
{
        struct gllc_entity _ent;
        int align;
        int dx;
        int dy;
        float height;
        float wscale;
        float angle;
        float oblique;
        float charspace;
        float xfit;
        float yfit;
        char *text;
        struct ds_unit *u;
        struct gllc_text_style *style;
        double x;
        double y;
};

struct gllc_text *gllc_text_create(struct gllc_block *block, struct ds_draw *draw, char *text, double x, double y);
struct gllc_text_style *gllc_text_get_style(struct gllc_text *text);
int gllc_text_set_style(struct gllc_text *text, struct gllc_text_style *style);
char *gllc_text_get_str(struct gllc_text *text);
int gllc_text_set_str(struct gllc_text *text, char *str);
int gllc_text_get_len(struct gllc_text *text);
int gllc_text_get_align(struct gllc_text *text);
int gllc_text_set_align(struct gllc_text *text, int align);
double gllc_text_get_x(struct gllc_text *text);
double gllc_text_get_y(struct gllc_text *text);
int gllc_text_set_x(struct gllc_text *text, double x);
int gllc_text_set_y(struct gllc_text *text, double y);
int gllc_text_get_dx(struct gllc_text *text);
int gllc_text_get_dy(struct gllc_text *text);
int gllc_text_set_dx(struct gllc_text *text, int dx);
int gllc_text_set_dy(struct gllc_text *text, int dy);
float gllc_text_get_height(struct gllc_text *text);
int gllc_text_set_height(struct gllc_text *text, float height);
float gllc_text_get_wscale(struct gllc_text *text);
int gllc_text_set_wscale(struct gllc_text *text, float wscale);
float gllc_text_get_angle(struct gllc_text *text);
int gllc_text_set_angle(struct gllc_text *text, float angle);
float gllc_text_get_oblique(struct gllc_text *text);
int gllc_text_set_oblique(struct gllc_text *text, float oblique);
float gllc_text_get_charspace(struct gllc_text *text);
int gllc_text_set_charspace(struct gllc_text *text, float charspace);
float gllc_text_get_wrect(struct gllc_text *text);
float gllc_text_get_x0(struct gllc_text *text);
float gllc_text_get_y0(struct gllc_text *text);
float gllc_text_get_xfit(struct gllc_text *text);
float gllc_text_get_yfit(struct gllc_text *text);

#endif