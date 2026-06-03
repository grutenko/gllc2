#ifndef color_h
#define color_h

#include <stddef.h>
#include <stdint.h>

typedef uint32_t color_t;

#define COLOR_INVALID (color_t)0xFFFFFFFF

color_t color_from_rgb(uint8_t r, uint8_t g, uint8_t b);
color_t color_from_index(int index);
color_t color_from_rgbv(const uint8_t *rgb);
color_t color_from_float(float r, float g, float b);
color_t color_from_floatv(const float *rgb);
color_t color_from_string(const char *str);
void color_to_rgb(color_t color, uint8_t *r, uint8_t *g, uint8_t *b);
void color_to_rgbv(color_t color, uint8_t *rgb);
void color_to_float(color_t color, float *r, float *g, float *b);
void color_to_floatv(color_t color, float *rgb);
void color_to_string(color_t color, char *buffer, size_t buflen);
int color_to_index(color_t color);
int color_is_index(color_t color);
const char *color_get_name(color_t color);
color_t color_sanitize(color_t color);

#endif // color_h