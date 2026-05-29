#include "draw.h"
#include "debug.h"
#include "hb-gpu.h"
#include "hb.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void push_unit(struct ds_draw *draw, struct ds_unit *unit)
{
        if (draw->tail)
        {
                draw->tail->next = unit;
                unit->prev = draw->tail;
                draw->tail = unit;
        }
        else
        {
                draw->head = unit;
                draw->tail = unit;
        }
        draw->unit_cnt++;
}

struct ds_unit *ds_unit_create(struct ds_draw *draw)
{
        struct ds_unit *unit = malloc(sizeof(struct ds_unit));
        if (unit)
        {
                unit->flags = 0;
                unit->draw = draw;
                unit->V = NULL;
                unit->I = NULL;
                unit->V_cnt = 0;
                unit->I_cnt = 0;
                unit->V_cap = 0;
                unit->I_cap = 0;
                unit->next = NULL;
                unit->prev = NULL;
                push_unit(draw, unit);
                unit->draw->dirty = 1;
        }
        return unit;
}

void ds_unit_reset(struct ds_unit *u)
{
        u->dirty = 1;
        u->I_cnt = 0;
        u->V_cnt = 0;
        u->draw->dirty = 1;
        u->draw->geometry_dirty = 1;
}

int ds_unit_vcnt(struct ds_unit *u)
{
        return u->V_cnt;
}

int ds_unit_icnt(struct ds_unit *u)
{
        return u->I_cnt;
}

struct ds_unit *ds_unit_clone(struct ds_unit *u)
{
        struct ds_unit *nu = ds_unit_create(u->draw);
        if (!nu)
                goto _error;
        struct ds_vertex *v = ds_unit_reserve_vertex(nu, u->V_cnt);
        if (!v)
                goto _error;
        GLuint *i = ds_unit_reserve_index(nu, u->I_cnt);
        if (!i)
                goto _error;
        memcpy(v, u->V, u->V_cnt * sizeof(struct ds_vertex));
        memcpy(i, u->I, u->I_cnt * sizeof(GLuint));
        nu->dirty = u->dirty;
        nu->flags = u->flags;
        return nu;
_error:
        ds_unit_destroy(nu);
        return NULL;
}

struct ds_vertex *ds_unit_reserve_vertex(struct ds_unit *unit, GLuint cnt)
{
        if (unit->V_cap < cnt)
        {
                size_t new_size = cnt;
                struct ds_vertex *new_V = realloc(unit->V, new_size * sizeof(struct ds_vertex));
                if (!new_V)
                {
                        return NULL;
                }
                unit->V = new_V;
                unit->V_cap = new_size;
        }
        unit->V_cnt = cnt;
        unit->draw->dirty = 1;
        return unit->V;
}

GLuint *ds_unit_reserve_index(struct ds_unit *unit, GLuint cnt)
{
        if (unit->I_cap < cnt)
        {
                size_t new_size = cnt;
                GLuint *new_I = realloc(unit->I, new_size * sizeof(GLuint));
                if (!new_I)
                {
                        return NULL;
                }
                unit->I = new_I;
                unit->I_cap = new_size;
        }
        unit->I_cnt = cnt;
        unit->draw->dirty = 1;
        return unit->I;
}

static void remove_unit(struct ds_draw *draw, struct ds_unit *unit)
{
        if (unit->prev)
        {
                unit->prev->next = unit->next;
        }
        else
        {
                draw->head = unit->next;
        }
        if (unit->next)
        {
                unit->next->prev = unit->prev;
        }
        else
        {
                draw->tail = unit->prev;
        }
        draw->unit_cnt--;
        draw->dirty = 1;
        draw->geometry_dirty = 1;
}

void ds_unit_destroy(struct ds_unit *unit)
{
        if (unit)
        {
                remove_unit(unit->draw, unit);
                free(unit->V);
                free(unit->I);
                free(unit);
        }
}

// In draw_proc
int ds_draw_dirty(struct ds_draw *draw)
{
        if (draw)
        {
                return draw->dirty;
        }
        return 0;
}

static void gl_check_error(const char *file, int line)
{
        GLenum err;
        while ((err = glGetError()) != GL_NO_ERROR)
        {
                const char *err_str = "UNKNOWN";

                switch (err)
                {
                case GL_INVALID_ENUM:
                        err_str = "GL_INVALID_ENUM";
                        break;
                case GL_INVALID_VALUE:
                        err_str = "GL_INVALID_VALUE";
                        break;
                case GL_INVALID_OPERATION:
                        err_str = "GL_INVALID_OPERATION";
                        break;
                case GL_INVALID_FRAMEBUFFER_OPERATION:
                        err_str = "GL_INVALID_FRAMEBUFFER_OPERATION";
                        break;
                case GL_OUT_OF_MEMORY:
                        err_str = "GL_OUT_OF_MEMORY";
                        break;
                }

                fprintf(stderr, "OpenGL error: %s (%s:%d)\n", err_str, file, line);
        }
}

#define GL_CHECK() gl_check_error(__FILE__, __LINE__)

void ds_attrib_ptr()
{
        GLuint stride = sizeof(struct ds_vertex);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, stride, (void *)offsetof(struct ds_vertex, pos));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_BYTE, GL_TRUE, stride, (void *)offsetof(struct ds_vertex, normal));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride,
                              (void *)offsetof(struct ds_vertex, textureCoord));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(3, 4, GL_UNSIGNED_BYTE, GL_TRUE, stride, (void *)offsetof(struct ds_vertex, color));
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(4, 1, GL_FLOAT, GL_FALSE, stride, (void *)offsetof(struct ds_vertex, thickness));
        glEnableVertexAttribArray(4);
        glVertexAttribPointer(5, 1, GL_FLOAT, GL_FALSE, stride, (void *)offsetof(struct ds_vertex, length));
        glEnableVertexAttribArray(5);
        glVertexAttribIPointer(6, 1, GL_UNSIGNED_INT, stride, (void *)offsetof(struct ds_vertex, glyphLoc));
        glEnableVertexAttribArray(6);
}

#ifdef _WIN32
#include <windows.h>

static double now_sec()
{
        LARGE_INTEGER freq, counter;
        QueryPerformanceFrequency(&freq);
        QueryPerformanceCounter(&counter);
        return (double)counter.QuadPart / (double)freq.QuadPart;
}

#else
#include <time.h>

static double now_sec()
{
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        return ts.tv_sec + ts.tv_nsec * 1e-9;
}
#endif

static void ds_sync_soft(struct ds_draw *draw, struct ds_gpu *gpu)
{
}

static void ds_sync_all(struct ds_draw *draw, struct ds_gpu *gpu)
{
}

void ds_unit_set_modified(struct ds_unit *unit, int geometry)
{
        if (geometry)
        {
                unit->draw->geometry_dirty = 1;
        }
        unit->dirty = 1;
        unit->draw->dirty = 1;
}

void ds_sync(struct ds_draw *draw, struct ds_gpu *gpu)
{
        if (draw && gpu)
        {
                double t0 = now_sec();
                double t1;
                GLuint v_total = 0;
                GLuint i_total = 0;
                struct ds_unit *unit = draw->head;
                while (unit)
                {
                        // Sync unit data to GPU
                        v_total += unit->V_cnt;
                        i_total += unit->I_cnt;
                        unit = unit->next;
                }
                if (v_total > gpu->V_data_capacity)
                {
                        struct ds_vertex *new_V_data = realloc(gpu->V_data, v_total * sizeof(struct ds_vertex));
                        if (!new_V_data)
                        {
                                // Handle allocation failure
                                return;
                        }
                        gpu->V_data = new_V_data;
                        gpu->V_data_capacity = v_total;
                }
                if (i_total > gpu->I_data_capacity)
                {
                        GLuint *new_I_data = realloc(gpu->I_data, i_total * sizeof(GLuint));
                        if (!new_I_data)
                        {
                                // Handle allocation failure
                                return;
                        }
                        gpu->I_data = new_I_data;
                        gpu->I_data_capacity = i_total;
                }
                t1 = now_sec();
                unit = draw->head;
                GLuint offset = 0;
                GLuint i_offset = 0;
                if (gpu->batch_cap < draw->unit_cnt)
                {
                        struct ds_gpu_batch *new_batches =
                            realloc(gpu->batches, draw->unit_cnt * sizeof(struct ds_gpu_batch));
                        if (!new_batches)
                        {
                                // Handle allocation failure
                                return;
                        }
                        gpu->batches = new_batches;
                        gpu->batch_cap = draw->unit_cnt;
                }
                t0 = now_sec();
                if (!draw->head)
                {
                        gpu->batch_cnt = 0;
                        draw->dirty = 0;
                        return;
                }
                int flags = ~0;
                int font_cache_id = ~0;
                int bi = -1;
                uint64_t vtotal = 0;
                uint64_t itotal = 0;
                if (gpu->font_glyph_cache_cap < draw->font_cache_cnt)
                {
                        struct ds_gpu_font_cache *new_cache =
                            realloc(gpu->font_glyph_cache, draw->font_cache_cnt * sizeof(struct ds_gpu_font_cache));
                        if (new_cache)
                        {
                                memset(&new_cache[gpu->font_glyph_cache_cnt], 0,
                                       sizeof(struct ds_gpu_font_cache) *
                                           (draw->font_cache_cnt - gpu->font_glyph_cache_cnt));
                                gpu->font_glyph_cache = new_cache;
                                gpu->font_glyph_cache_cap = draw->font_cache_cnt;
                        }
                }
                for (int i = 0; i < draw->font_cache_cnt; i++)
                {
                        GL_CHECK();
                        struct ds_gpu_font_cache *cache = &gpu->font_glyph_cache[i];
                        if (!gpu->font_glyph_cache[i].ready)
                        {
                                glGenBuffers(1, &cache->bufferID);
                                glBindBuffer(GL_TEXTURE_BUFFER, cache->bufferID);
                                glBufferData(GL_TEXTURE_BUFFER, draw->font_cache[i].buffer_size,
                                             draw->font_cache[i].buffer, GL_STATIC_DRAW);
                                glGenTextures(1, &cache->texID);
                                glBindTexture(GL_TEXTURE_BUFFER, cache->texID);
                                glTexBuffer(GL_TEXTURE_BUFFER, GL_RGBA16I, cache->bufferID);
                                printf("%d\n", draw->font_cache[i].buffer_size);
                                gpu->font_glyph_cache[i].ready = 1;
                        }
                        if (draw->font_cache[i].modified)
                        {
                                glBindBuffer(GL_TEXTURE_BUFFER, cache->bufferID);
                                glBufferData(GL_TEXTURE_BUFFER, draw->font_cache[i].buffer_size,
                                             draw->font_cache[i].buffer, GL_STATIC_DRAW);
                                glBindTexture(GL_TEXTURE_BUFFER, cache->texID);
                                draw->font_cache[i].modified = 0;
                        }
                        GL_CHECK();
                }
                gpu->font_glyph_cache_cnt = draw->font_cache_cnt;
                size_t total = 0;
                for (unit = draw->head; unit; unit = unit->next)
                {
                        vtotal += unit->V_cnt;
                        itotal += unit->I_cnt;
                        memmove(&gpu->V_data[offset], unit->V, unit->V_cnt * sizeof(struct ds_vertex));
                        for (GLuint j = 0; j < unit->I_cnt; j++)
                        {
                                gpu->I_data[i_offset + j] = unit->I[j] + offset;
                        }
                        if (unit->flags != flags || unit->font_cache_id != font_cache_id)
                        {
                                bi++;
                                gpu->batches[bi].flags = unit->flags;
                                gpu->batches[bi].count = unit->I_cnt;
                                gpu->batches[bi].offset = i_offset;
                                gpu->batches[bi].tex_id = -1;
                                if (unit->flags & DS_UNIT_GLYPH)
                                {
                                        if (unit->font_cache_id >= 0 && unit->font_cache_id < gpu->font_glyph_cache_cnt)
                                                gpu->batches[bi].tex_id =
                                                    gpu->font_glyph_cache[unit->font_cache_id].texID;
                                }
                                flags = unit->flags;
                                font_cache_id = unit->font_cache_id;
                        }
                        else
                        {
                                gpu->batches[bi].count += unit->I_cnt;
                        }
                        offset += unit->V_cnt;
                        i_offset += unit->I_cnt;
                        unit->dirty = 0;
                        total += unit->V_cnt * sizeof(struct ds_vertex);
                        total += unit->I_cnt * 4;
                }
                bi++;
                gpu->V_data_size = offset;
                gpu->I_data_size = i_offset;
                t1 = now_sec();
                if (!gpu->VAO)
                {
                        glGenVertexArrays(1, &gpu->VAO);
                        glGenBuffers(1, &gpu->VBO);
                        glGenBuffers(1, &gpu->EBO);
                        glBindVertexArray(gpu->VAO);
                        glBindBuffer(GL_ARRAY_BUFFER, gpu->VBO);
                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gpu->EBO);
                        ds_attrib_ptr();
                }
                else
                {
                        glBindVertexArray(gpu->VAO);
                        glBindBuffer(GL_ARRAY_BUFFER, gpu->VBO);
                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gpu->EBO);
                }
                if (gpu->VBO_capacity < gpu->V_data_size)
                {
                        glBufferData(GL_ARRAY_BUFFER, gpu->V_data_size * sizeof(struct ds_vertex), NULL,
                                     GL_DYNAMIC_DRAW);
                        gpu->VBO_capacity = gpu->V_data_size;
                }
                void *ptr = glMapBufferRange(GL_ARRAY_BUFFER, 0, gpu->V_data_size * sizeof(struct ds_vertex),
                                             GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
                memcpy(ptr, gpu->V_data, gpu->V_data_size * sizeof(struct ds_vertex));
                glUnmapBuffer(GL_ARRAY_BUFFER);
                if (gpu->I_data_size > gpu->EBO_capacity)
                {
                        glBufferData(GL_ELEMENT_ARRAY_BUFFER, gpu->I_data_size * sizeof(GLuint), NULL, GL_DYNAMIC_DRAW);
                        gpu->EBO_capacity = gpu->I_data_size;
                }
                ptr = glMapBufferRange(GL_ELEMENT_ARRAY_BUFFER, 0, gpu->I_data_size * sizeof(GLuint),
                                       GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
                memcpy(ptr, gpu->I_data, gpu->I_data_size * sizeof(GLuint));
                glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
                gpu->batch_cnt = bi;
                draw->dirty = 0;
        }
}

void ds_draw(struct ds_gpu *gpu, GLuint loc_uFlags, GLuint loc_hb_texture_atlas)
{
        if (gpu)
        {
                // Bind the VAO
                glActiveTexture(GL_TEXTURE0);
                glBindVertexArray(gpu->VAO);
                glUniform1i(loc_hb_texture_atlas, 0);
                int i;
                for (i = 0; i < gpu->batch_cnt; i++)
                {
                        struct ds_gpu_batch *batch = &gpu->batches[i];
                        if (batch->count == 0)
                                continue;
                        if (batch->flags & DS_UNIT_GLYPH)
                        {
                                glBindTexture(GL_TEXTURE_BUFFER, batch->tex_id);
                        }
                        glUniform1i(loc_uFlags, batch->flags);
                        glDrawElements(GL_TRIANGLES, batch->count, GL_UNSIGNED_INT,
                                       (void *)(batch->offset * sizeof(GLuint)));
                }
                glUniform1i(loc_uFlags, 0);
        }
}

void ds_draw_clear(struct ds_draw *draw)
{
        if (draw)
        {
                struct ds_unit *unit = draw->head;
                while (unit)
                {
                        struct ds_unit *next = unit->next;
                        free(unit->V);
                        free(unit->I);
                        free(unit);
                        unit = next;
                }
                draw->head = NULL;
                draw->tail = NULL;
                draw->unit_cnt = 0;
                draw->dirty = 0;
                for (int i = 0; i < draw->font_cache_cnt; i++)
                {
                        free(draw->font_cache[i].buffer);
                        free(draw->font_cache[i].glyphs);
                }
                free(draw->font_cache);
                draw->font_cache_cnt = 0;
                draw->font_cache_cap = 0;
        }
}

void ds_gpu_clear(struct ds_gpu *gpu)
{
        if (gpu)
        {
                free(gpu->V_data);
                free(gpu->I_data);
                free(gpu->batches);
                gpu->batches = NULL;
                gpu->batch_cnt = 0;
                gpu->batch_cap = 0;
                gpu->V_data = NULL;
                gpu->I_data = NULL;
                gpu->V_data_size = 0;
                gpu->I_data_size = 0;
                gpu->V_data_capacity = 0;
                gpu->I_data_capacity = 0;
        }
}

int ds_draw_get_font_cache_id(struct ds_draw *draw, struct gllc_font *font)
{
        int cacheID = 0;
        for (; cacheID < draw->font_cache_cnt; cacheID++)
        {
                if (draw->font_cache[cacheID].font_ID == font->ID)
                {
                        return cacheID;
                }
        }
        if (draw->font_cache_cap <= draw->font_cache_cnt)
        {
                size_t newsize = draw->font_cache_cap ? draw->font_cache_cap * 2 : 8;
                struct ds_draw_font_cache *newfontcache =
                    realloc(draw->font_cache, newsize * sizeof(struct ds_draw_font_cache));
                if (!newfontcache)
                {
                        FMTERROR("Cannot allocate memory");
                        return -1;
                }
                draw->font_cache = newfontcache;
                draw->font_cache_cap = newsize;
        }

        struct ds_draw_font_cache *cache = &draw->font_cache[draw->font_cache_cnt];

        cache->font_ID = font->ID;
        cache->buffer = NULL;
        cache->buffer_size = 0;
        cache->buffer_cap = 0;
        cache->glyphs = NULL;
        cache->glyph_cnt = 0;
        cache->modified = 1;

        draw->font_cache_cnt++;
        return draw->font_cache_cnt - 1;
}

unsigned int ds_draw_get_font_glyph_loc(struct ds_draw *draw, struct gllc_font *font, int font_cache_id, int glyph_id)
{
        if (font_cache_id < 0 || font_cache_id >= draw->font_cache_cnt)
        {
                FMTERROR("Invalid font cache id");
                return 0;
        }
        struct ds_draw_font_cache *cache = &draw->font_cache[font_cache_id];
        for (int i = 0; i < cache->glyph_cnt; i++)
        {
                if (cache->glyphs[i].glyph == glyph_id)
                {
                        return cache->glyphs[i].offset / 8;
                }
        }

        hb_gpu_draw_t *hbdraw = hb_gpu_draw_create_or_fail();
        hb_gpu_draw_glyph(hbdraw, font->font, glyph_id);
        hb_blob_t *blob = hb_gpu_draw_encode(hbdraw, NULL);
        unsigned int length = hb_blob_get_length(blob);
        if (cache->buffer_size + length > cache->buffer_cap)
        {
                size_t new_size = cache->buffer_cap ? cache->buffer_cap + length : length * 2;
                void *new_buffer = realloc(cache->buffer, new_size);
                if (!new_buffer)
                {
                        FMTERROR("Cannot allocate buffer");
                        hb_gpu_draw_recycle_blob(hbdraw, blob);
                        hb_gpu_draw_destroy(hbdraw);
                        return 0;
                }
                cache->buffer = new_buffer;
                cache->buffer_cap = new_size;
        }
        unsigned int offset = cache->buffer_size;
        size_t new_size = cache->glyph_cnt + 1;
        struct ds_draw_font_cache_glyph *new_glyph_arr =
            realloc(cache->glyphs, new_size * sizeof(struct ds_draw_font_cache_glyph));
        if (!new_glyph_arr)
        {
                FMTERROR("Cannot allocate buffer");
                hb_gpu_draw_recycle_blob(hbdraw, blob);
                hb_gpu_draw_destroy(hbdraw);
                return 0;
        }
        cache->glyphs = new_glyph_arr;
        cache->glyphs[cache->glyph_cnt].glyph = glyph_id;
        cache->glyphs[cache->glyph_cnt].offset = cache->buffer_size;
        cache->glyphs[cache->glyph_cnt].size = length;
        cache->glyph_cnt++;
        memmove(cache->buffer + cache->buffer_size, hb_blob_get_data(blob, NULL), length);
        cache->buffer_size += length;
        hb_gpu_draw_recycle_blob(hbdraw, blob);
        hb_gpu_draw_destroy(hbdraw);
        cache->modified = 1;

        return offset / 8;
}