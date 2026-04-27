#include "font.h"
#include <stdlib.h>

static struct gllc_font *_fonts = NULL;
int _fontcnt = 0;

void gllc_fonts_scan() {
}

int gllc_fonts_cnt() {
  return _fontcnt;
}

struct gllc_font *gllc_font_create(int ttf, const char *name, const char *filename) {
  return NULL;
}

struct gllc_font *gllc_font_create_binary(int ttf, const char *name, void *data) {
  return NULL;
}

struct gllc_font *gllc_font_first() {
  return _fonts;
}

struct gllc_font *gllc_font_next(struct gllc_font *font) {
  if (font) {
    return font->next;
  }
  return NULL;
}

void gllc_fonts_clear() {
  struct gllc_font *font = _fonts;
  while (font) {
    struct gllc_font *t = font->next;
    free(font->name);
    free(font->filename);
    free(font->data);
    free(font);
    font = t;
  }
  _fonts = NULL;
  _fontcnt = 0;
}