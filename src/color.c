#include "color.h"
#include <stdio.h>
#include <string.h>

static struct coloritab
{
        int index;
        const char *name;
        int color;
} _coloritab[] = {{0, "Black", 0x000000},
                  {1, "90% Black", 0x191919},
                  {2, "80% Black", 0x333333},
                  {3, "70% Black", 0x4D4D4D},
                  {4, "60% Black", 0x666666},
                  {5, "50% Black", 0x808080},
                  {6, "40% Black", 0x999999},
                  {7, "30% Black", 0xB3B3B3},
                  {8, "20% Black", 0xCCCCCC},
                  {9, "10% Black", 0xE6E6E6},
                  {10, "White", 0xFFFFFF},
                  {11, "Blue", 0x0000FF},
                  {12, "Cyan", 0x00FFFF},
                  {13, "Green", 0x00FF00},
                  {14, "Yellow", 0xFFFF00},
                  {15, "Red", 0xFF0000},
                  {16, "Magenta", 0xFF00FF},
                  {17, "Purple", 0x9900CC},
                  {18, "Orange", 0xFF6600},
                  {19, "Pink", 0xFF99CC},
                  {20, "Dark Brown", 0x663333},
                  {21, "Powder Blue", 0xCCCCFF},
                  {22, "Pastel Blue", 0x9999FF},
                  {23, "Baby Blue", 0x6699FF},
                  {24, "Electric Blue", 0x6666FF},
                  {25, "Twilight Blue", 0x6666CC},
                  {26, "Navy Blue", 0x003399},
                  {27, "Deep Navy Blue", 0x000066},
                  {28, "Desert Blue", 0x336699},
                  {29, "Dodger Blue", 0x1389FF},
                  {30, "Sky Blue", 0x00CCFF},
                  {31, "Ice Blue", 0x99FFFF},
                  {32, "Smalt Blue", 0x0068D0},
                  {33, "Light BlueGreen", 0x99CCCC},
                  {34, "Ocean Green", 0x669999},
                  {35, "Moss Green", 0x336666},
                  {36, "Dark Green", 0x003333},
                  {37, "Forest Green", 0x006633},
                  {38, "Grass Green", 0x009933},
                  {39, "Wild Willow", 0xB5CC61},
                  {40, "Kentucky Green", 0x339966},
                  {41, "Light Green", 0x33CC66},
                  {42, "Spring Green", 0x33CC33},
                  {43, "Turquoise", 0x66FFCC},
                  {44, "Sea Green", 0x33CC99},
                  {45, "Faded Green", 0x99CC99},
                  {46, "Ghost Green", 0xCCFFCC},
                  {47, "Mint Green", 0x99FF99},
                  {48, "Army Green", 0x669966},
                  {49, "Avocado Green", 0x669933},
                  {50, "Martian Green", 0x99CC33},
                  {51, "Dull Green", 0x99CC66},
                  {52, "Chartreuse", 0x99FF00},
                  {53, "Moon Green", 0xCCFF66},
                  {54, "Murky Green", 0x333300},
                  {55, "Olive Drab", 0x666633},
                  {56, "Khaki", 0x999966},
                  {57, "Olive", 0x999933},
                  {58, "Banana Yellow", 0xCCCC33},
                  {59, "Light Yellow", 0xFFFF66},
                  {60, "Chalk", 0xFFFF99},
                  {61, "Pale Yellow", 0xFFFFCC},
                  {62, "Brown", 0x996633},
                  {63, "Red Brown", 0xCC6633},
                  {64, "Gold", 0xCC9933},
                  {65, "Autumn Orange", 0xFF6633},
                  {66, "Light Orange", 0xFF9933},
                  {67, "Peach", 0xFF9966},
                  {68, "Deep Yellow", 0xFFCC00},
                  {69, "Sand", 0xFFCC99},
                  {70, "Walnut", 0x663300},
                  {71, "Ruby Red", 0x990000},
                  {72, "Brick Red", 0xCC3300},
                  {73, "Tropical Pink", 0xFF6666},
                  {74, "Soft Pink", 0xFF9999},
                  {75, "Faded Pink", 0xFFCCCC},
                  {76, "Dark Red", 0x800000},
                  {77, "Crimson", 0x993366},
                  {78, "Regal Red", 0xCC3366},
                  {79, "Deep Rose", 0xCC3399},
                  {80, "Neon Red", 0xFF0066},
                  {81, "Deep Pink", 0xFF6699},
                  {82, "Hot Pink", 0xFF3399},
                  {83, "Dusty Rose", 0xCC6699},
                  {84, "Plum", 0x660066},
                  {85, "Deep Violet", 0x990099},
                  {86, "Light Violet", 0xFF99FF},
                  {87, "Violet", 0xCC66CC},
                  {88, "Dusty Plum", 0x996699},
                  {89, "Pale Purple", 0xCC99CC},
                  {90, "Majestic Purple", 0x9933CC},
                  {91, "Neon Purple", 0xCC33FF},
                  {92, "Light Purple", 0xCC66FF},
                  {93, "Twilight Violet", 0x9966CC},
                  {94, "Easter Purple", 0xCC99FF},
                  {95, "Deep Purple", 0x330066},
                  {96, "Grape", 0x663399},
                  {97, "Blue Violet", 0x9966FF},
                  {98, "Blue Purple", 0x9900FF},
                  {99, "Deep River", 0x6600CC},
                  {100, "Deep Azure", 0x6633FF},
                  {101, "Storm Blue", 0x330099},
                  {102, "Deep Blue", 0x3300CC},
                  {103, "Dark Blue", 0x000080}};

static struct coloritab *find_color_by_name(const char *name)
{
        for (int i = 0; i < 104; i++)
        {
                if (strcmp(_coloritab[i].name, name) == 0)
                        return &_coloritab[i];
        }
        return NULL;
}

static struct coloritab *find_color_by_color(color_t color)
{
        for (int i = 0; i < 104; i++)
        {
                if (_coloritab[i].color == color)
                        return &_coloritab[i];
        }
        return NULL;
}

static struct coloritab *find_color_by_index(int index)
{
        for (int i = 0; i < 104; i++)
        {
                if (_coloritab[i].index == index)
                        return &_coloritab[i];
        }
        return NULL;
}

color_t color_from_rgb(uint8_t r, uint8_t g, uint8_t b)
{
        return (r << 16) | (g << 8) | b;
}

color_t color_from_index(int index)
{
        struct coloritab *color = find_color_by_index(index);
        if (color)
                return color->color;
        return COLOR_INVALID;
}

color_t color_from_rgbv(const uint8_t *rgb)
{
        return color_from_rgb(rgb[0], rgb[1], rgb[2]);
}

color_t color_from_float(float r, float g, float b)
{
        return color_from_rgb((uint8_t)(r * 255), (uint8_t)(g * 255), (uint8_t)(b * 255));
}

color_t color_from_floatv(const float *rgb)
{
        return color_from_float(rgb[0], rgb[1], rgb[2]);
}

static inline color_t parse_color_rgb(const char *str)
{
        int r, g, b;
        if (sscanf(str, "%d,%d,%d", &r, &g, &b) == 3)
        {
                if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
                {
                        return color_from_rgb((uint8_t)r, (uint8_t)g, (uint8_t)b);
                }
        }
        return COLOR_INVALID;
}

color_t color_from_string(const char *str)
{
        struct coloritab *colorstruct = find_color_by_name(str);
        if (colorstruct)
                return colorstruct->color;
        color_t color = parse_color_rgb(str);
        if (color != COLOR_INVALID)
                return color;
        return COLOR_INVALID;
}

void color_to_rgb(color_t color, uint8_t *r, uint8_t *g, uint8_t *b)
{
        *r = (color >> 16) & 0xFF;
        *g = (color >> 8) & 0xFF;
        *b = color & 0xFF;
}

void color_to_rgbv(color_t color, uint8_t *rgb)
{
        color_to_rgb(color, &rgb[0], &rgb[1], &rgb[2]);
}

void color_to_float(color_t color, float *r, float *g, float *b)
{
        uint8_t r_val, g_val, b_val;
        color_to_rgb(color, &r_val, &g_val, &b_val);
        *r = r_val / 255.0f;
        *g = g_val / 255.0f;
        *b = b_val / 255.0f;
}

void color_to_floatv(color_t color, float *rgb)
{
        color_to_float(color, &rgb[0], &rgb[1], &rgb[2]);
}

const char *color_get_name(color_t color)
{
        struct coloritab *colorstruct = find_color_by_color(color);
        if (colorstruct)
                return colorstruct->name;
        return NULL;
}

void color_to_string(color_t color, char *buffer, size_t buflen)
{
        struct coloritab *colorstruct = find_color_by_color(color);
        if (colorstruct)
        {
                strncpy(buffer, colorstruct->name, buflen);
                buffer[buflen - 1] = '\0';
        }
        else
        {
                uint8_t r, g, b;
                color_to_rgb(color, &r, &g, &b);
                snprintf(buffer, buflen, "%d,%d,%d", r, g, b);
        }
}

int color_to_index(color_t color)
{
        struct coloritab *colorstruct = find_color_by_color(color);
        if (colorstruct)
                return colorstruct->index;
        return -1;
}

int color_is_index(color_t color)
{
        return color_to_index(color) != -1;
}