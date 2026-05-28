#ifndef draw_h
#define draw_h

#include "font.h"
#include <setjmp.h>
#if defined(_WIN32)
#include "glad.h"
#elif defined(__linux__)
#include <epoxy/gl.h>
#endif

struct ds_vertex
{
        GLfloat thickness;
        GLfloat thicknessMiltiplier;
        GLbyte normal[2];
        GLfloat textureCoord[2];
        GLubyte color[4];
        GLfloat pos[2];
        GLfloat length;
        GLuint glyphLoc;
};

#define DS_UNIT_CHESS 0x1
#define DS_UNIT_DASH_SCREEN 0x2
#define DS_UNIT_DASH_REAL 0x4
#define DS_UNIT_GLYPH 0x8

struct ds_unit
{
        int flags;
        int id;
        int font_cache_id;
        struct ds_draw *draw;
        struct ds_vertex *V;
        GLuint *I;
        GLuint V_cnt;
        GLuint I_cnt;
        GLuint I_cap;
        GLuint V_cap;
        struct ds_unit *next;
        struct ds_unit *prev;
        int order;
        int dirty;
        int geometry_dirty;
        uint64_t order0;
        uint64_t order1;
        uint64_t order2;
};

struct ds_gpu_batch
{
        int flags;
        GLuint tex_id;
        GLuint offset;
        GLuint count;
};

struct ds_gpu_font_cache
{
        int ready;
        GLuint texID;
        GLuint bufferID;
};

struct ds_gpu
{
        struct ds_gpu_batch *batches;
        GLuint batch_cnt;
        GLuint batch_cap;
        GLuint VAO;
        GLuint VBO;
        GLuint EBO;
        GLuint VBO_size;
        GLuint EBO_size;
        GLuint VBO_capacity;
        GLuint EBO_capacity;
        struct ds_vertex *V_data;
        GLuint *I_data;
        GLuint V_data_size;
        GLuint I_data_size;
        GLuint V_data_capacity;
        GLuint I_data_capacity;
        struct ds_gpu_font_cache *font_glyph_cache;
        int font_glyph_cache_cnt;
        int font_glyph_cache_cap;
};

struct ds_draw_font_cache_glyph
{
        int glyph;
        int offset;
        int size;
};

struct ds_draw_font_cache
{
        int font_ID;
        void *buffer;
        int buffer_size;
        int buffer_cap;
        struct ds_draw_font_cache_glyph *glyphs;
        int glyph_cnt;
        int modified;
};

struct ds_draw
{
        int dirty;
        int geometry_dirty;
        struct ds_unit *head;
        struct ds_unit *tail;
        int unit_cnt;
        struct ds_draw_font_cache *font_cache;
        int font_cache_cnt;
        int font_cache_cap;
};

void ds_attrib_ptr();
struct ds_unit *ds_unit_clone(struct ds_unit *u);
struct ds_unit *ds_unit_create(struct ds_draw *draw);
void ds_unit_reset(struct ds_unit *u);
int ds_unit_vcnt(struct ds_unit *u);
int ds_unit_icnt(struct ds_unit *u);
struct ds_vertex *ds_unit_reserve_vertex(struct ds_unit *unit, GLuint cnt);
GLuint *ds_unit_reserve_index(struct ds_unit *unit, GLuint cnt);
void ds_unit_destroy(struct ds_unit *unit);
void ds_unit_set_modified(struct ds_unit *unit, int geometry);
// In draw_proc
int ds_draw_dirty(struct ds_draw *draw);
void ds_sync(struct ds_draw *draw, struct ds_gpu *gpu);
void ds_draw(struct ds_gpu *gpu, GLuint loc_uFlags, GLuint loc_hb_texture_atlas);
void ds_draw_clear(struct ds_draw *draw);
void ds_gpu_clear(struct ds_gpu *gpu);
int ds_draw_get_font_cache_id(struct ds_draw *draw, struct gllc_font *font);
unsigned int ds_draw_get_font_glyph_loc(struct ds_draw *draw, struct gllc_font *font, int font_cache_id, int glyph_id);
struct ds_unit *ds_unit_clone(struct ds_unit *unit);

#endif