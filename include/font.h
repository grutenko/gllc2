#ifndef font_h
#define font_h

#include "object.h"

struct gllc_font {
  struct gllc_object _obj;
  int ttf;
  char *filename;
  char *name;
  void *data;
  int data_size;
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