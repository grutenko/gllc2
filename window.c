#include "window.h"
#include "alloc.h"
#include "cglm/include/cglm/common.h"
#include "draw.h"
#include "frag.h"
#include "object.h"
#include "platform.h"
#include "ui_cursor.h"
#include "ui_grid.h"
#include "vert.h"

#include <string.h>

static void _destroy(struct gllc_object *obj) {}

static union gllc_variant _wnd_id_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = ((struct gllc_window *)obj)->id;
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_width_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = ((struct gllc_window *)obj)->UI.width;
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_height_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = ((struct gllc_window *)obj)->UI.height;
  return v;
}

static union gllc_variant _wnd_frame_left_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = 0;
  return v;
}

static union gllc_variant _wnd_frame_top_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = 0;
  return v;
}

static union gllc_variant _wnd_frame_width_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = ((struct gllc_window *)obj)->UI.width;
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_frame_height_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.int_ = ((struct gllc_window *)obj)->UI.height;
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_HWND_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_block_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = ((struct gllc_window *)obj)->block;
  return v;
}

static union gllc_variant _wnd_drw_GET(struct gllc_object *obj, int prop, int type) {
  union gllc_variant v;
  v.handle_ = ((struct gllc_window *)obj)->drawing;
  return v;
}

static union gllc_variant _wnd_hasfocus_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_pixelsize_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_pixelsize_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_select_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_select_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_dtime_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_frozen_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_frozen_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_frozenview_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_frozenview_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_command_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_cmdent1_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_cmdent1_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_osnap_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_osnap_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_osnap_menu_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_osnap_menu_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_ptrack_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_ptrack_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_PTRACK_ANGLE_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_PTRACK_ANGLE_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_PTRACK_ANGREL_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_PTRACK_ANGREL_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_PTRACK_DIST_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_PTRACK_DIST_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_BASEPT_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_BASEX_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_BASEY_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_ORTHO_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_ORTHO_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_BGIMAGE_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_BGIMAGE_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_TIN_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_TIN_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_HASFILETABS_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_NUMFILETABS_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_NUMDRW_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_ENT_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static union gllc_variant _wnd_DROPFILES_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_DROPFILES_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static union gllc_variant _wnd_ZOOMWHEEL_GET(struct gllc_object *obj, int prop, int type) {
  return (union gllc_variant)0;
}

static int _wnd_ZOOMWHEEL_SET(struct gllc_object *obj, int prop, int type, union gllc_variant value) {
  return 0;
}

static struct gllc_prop _props[] = {P_END};
static struct gllc_prop *_all_props[] = {_props, NULL};
static struct gllc_object_vtable _vtable = {
    .destroy = _destroy};

static void draw(struct gllc_window *wnd) {
  double x0, y0, x1, y1;
  gllc_window_wnd_to_drw(wnd, 0.0f, 0.0f, &x0, &y0);
  gllc_window_wnd_to_drw(wnd, wnd->UI.width, wnd->UI.height, &x1, &y1);

  _gllc_NW_make_context_current(&wnd->nw);

  glClear(GL_COLOR_BUFFER_BIT);
  glUseProgram(wnd->GPU.program);
  glUniformMatrix4fv(wnd->GPU.loc_uMVP, 1, GL_FALSE, (const float *)wnd->cam.mMVP);

  ui_grid_draw(&(wnd->UI.grid), wnd->cam.scale, x0, y0, x1, y1);

  // Screen view
  glUniformMatrix4fv(wnd->GPU.loc_uMVP, 1, GL_FALSE, (const float *)wnd->cam.mScreenMVP);

  if(wnd->UI.menter) {
    ui_cursor_draw(&wnd->UI.cursor, wnd->UI.mx, wnd->UI.my, wnd->UI.width, wnd->UI.height);
  }

  _gllc_NW_swap_buffers(&wnd->nw);
}

static void on_paint(struct _gllc_NW *w, void *data) {
  draw((struct gllc_window *)data);
}

static inline void update_camera(struct gllc_window *w) {
  float half_w = (float)w->UI.width / 2.0f * w->cam.scale;
  float half_h = (float)w->UI.height / 2.0f * w->cam.scale;
  glm_ortho(-half_w, half_w, -half_h, half_h, -1.0f, 1.0f, w->cam.mProj);
  glm_mat4_identity(w->cam.mView);
  vec4 t = {w->cam.dx, w->cam.dy, 0.0f, 1.0f};
  glm_translate(w->cam.mView, t);
  glm_mat4_mul(w->cam.mProj, w->cam.mView, w->cam.mMVP);
  glm_mat4_mul(w->cam.mMVP, w->cam.mModel, w->cam.mMVP);
  half_w = (float)w->UI.width;
  half_h = (float)w->UI.height;
  mat4 screenProj;
  mat4 screenView;
  glm_ortho(0, half_w, half_h, 0, -1.0f, 1.0f, screenProj);
  glm_mat4_identity(screenView);
  glm_mat4_mul(screenProj, screenView, w->cam.mScreenMVP);
}

static void on_size(struct _gllc_NW *w, int width, int height, void *data) {
  struct gllc_window *wnd = (struct gllc_window *)data;

  wnd->UI.width = width;
  wnd->UI.height = height;
  update_camera((struct gllc_window *)data);
  _gllc_NW_make_context_current(w);
  glViewport(0, 0, width, height);
  _gllc_NW_dirty(w);
}

static void on_mouse_move(struct _gllc_NW *w, int x, int y, void *data) {
  struct gllc_window *wnd = (struct gllc_window *)data;

  _gllc_NW_get_cursor(w, &x, &y);

  if (wnd->UI.mpressed && wnd->UI.mbtn == 3) {
    wnd->cam.dx += (x - wnd->UI.mx) * wnd->cam.scale;
    wnd->cam.dy -= (y - wnd->UI.my) * wnd->cam.scale;

    update_camera(wnd);
  }

  if (wnd->UI.mpressed && wnd->UI.mbtn == 1) {

  }

  wnd->UI.mx = x;
  wnd->UI.my = y;
  wnd->UI.menter = 1;

  _gllc_NW_dirty(w);
}

static void on_mouse_click(struct _gllc_NW *wn, int x, int y, int mode, int action, void *data) {
  struct gllc_window *wnd = (struct gllc_window *)data;
  wnd->UI.mbtn = mode;
  wnd->UI.mpressed = action;
  if (action) {
    wnd->UI.mdownx = x;
    wnd->UI.mdowny = y;
  }
  _gllc_NW_dirty(wn);
}

static void on_mouse_scroll(struct _gllc_NW *wn, int dx, int dy, void *data) {
  struct gllc_window *w = (struct gllc_window *)data;

  if (dy >= 10)
    dy = 2;
  if (dy <= -10)
    dy = -2;

  if ((w->cam.scale > 300.0f && dy > 0) || (w->cam.scale < 0.005f && dy < 0))
    return;

  double old_scale = w->cam.scale;
  w->cam.scale *= 1.0f + ((double)dy * 0.05);

  w->cam.dx += (w->UI.mx - (int)(w->UI.width / 2)) * (w->cam.scale - old_scale);
  w->cam.dy += ((w->UI.height - w->UI.my) - (int)(w->UI.height / 2)) * (w->cam.scale - old_scale);

  update_camera(w);
  
  _gllc_NW_dirty(wn);
}

static void on_mouse_leave(struct _gllc_NW *wn, void *data) {
  struct gllc_window *wnd = (struct gllc_window *)data;

  wnd->UI.menter = 0;

  _gllc_NW_dirty(wn);
}

static struct _gllc_NW_vtable _nw_vtable = {
    .paint = on_paint,
    .size = on_size,
    .mouse_move = on_mouse_move,
    .mouse_click = on_mouse_click,
    .mouse_scroll = on_mouse_scroll,
    .mouse_leave = on_mouse_leave};

static GLuint load_shader(GLuint type, const char *source) {
  GLuint shader = glCreateShader(type);
  if (shader == 0) {
    fprintf(stderr, "Failed to create shader\n");
    return 0;
  }
  glShaderSource(shader, 1, &source, NULL);
  glCompileShader(shader);
  GLint compiled = GL_FALSE;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
  if (compiled != GL_TRUE) {
    GLint logLength = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
    char *log = (char *)malloc(logLength);
    if (log) {
      glGetShaderInfoLog(shader, logLength, NULL, log);
      fprintf(stderr, "Shader compilation failed:\n%s\n", log);
      free(log);
    }
    glDeleteShader(shader);
    return 0;
  }
  return shader;
}

static GLuint load_program(GLuint vert_shader, GLuint frag_shader) {
  GLuint program = glCreateProgram();
  if (program == 0) {
    fprintf(stderr, "Failed to create program\n");
    return 0;
  }
  glAttachShader(program, vert_shader);
  glAttachShader(program, frag_shader);
  glLinkProgram(program);
  GLint linked = GL_FALSE;
  glGetProgramiv(program, GL_LINK_STATUS, &linked);
  if (linked != GL_TRUE) {
    GLint logLength = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    char *log = (char *)malloc(logLength);
    if (log) {
      glGetProgramInfoLog(program, logLength, NULL, log);
      fprintf(stderr, "Program link failed:\n%s\n", log);
      free(log);
    }
    glDeleteProgram(program);
    return 0;
  }
  glDetachShader(program, vert_shader);
  glDetachShader(program, frag_shader);

  return program;
}

static void load_GL_program(struct gllc_window *w) {
  GLuint V_shader = load_shader(GL_VERTEX_SHADER, vert_glsl);
  if (!V_shader) {
    return;
  }

  GLuint F_shader = load_shader(GL_FRAGMENT_SHADER, frag_glsl);
  if (!F_shader) {
    glDeleteShader(V_shader);
    return;
  }

  w->GPU.program = load_program(V_shader, F_shader);

  glDeleteShader(V_shader);
  glDeleteShader(F_shader);
}

static void load_GL_uniform_loc(struct gllc_window *w) {
#define LOADLOC(out, var)                            \
  out = glGetUniformLocation(w->GPU.program, var);   \
  if (out == -1) {                                   \
    fprintf(stderr, "Uniform %s not found!\n", var); \
  }

  LOADLOC(w->GPU.loc_uMVP, "uMVP");
  LOADLOC(w->GPU.loc_uScale, "uScale");
}

struct gllc_window *gllc_window_create(void *p) {
  int success = 0;
  struct gllc_window *wnd = XALLOC(sizeof(struct gllc_window));
  if (wnd) {
    memset(wnd, 0, sizeof(struct gllc_window));
    GLLC_OBJECT_INIT(wnd, _all_props, &_vtable);

    float white_03[4] = {1.0f, 1.0f, 1.0f, 0.3f};
    float black[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    float white[4] = {1.0f, 1.0f, 1.0f, 1.0f};

    memcpy(wnd->UI.back_color, black, sizeof(black));
    memcpy(wnd->UI.sel_color, white, sizeof(white));

    ui_grid_init(&wnd->UI.grid);
    ui_cursor_init(&wnd->UI.cursor);

    if (_gllc_NW_create(&wnd->nw, p, &_nw_vtable, wnd)) {
      _gllc_NW_make_context_current(&wnd->nw);
      if (gladLoadGL()) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBlendEquation(GL_FUNC_ADD);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDisable(GL_CULL_FACE);

        load_GL_program(wnd);
        glUseProgram(wnd->GPU.program);
        load_GL_uniform_loc(wnd);
        _gllc_NW_get_size(&wnd->nw, &wnd->UI.width, &wnd->UI.height);
        wnd->cam.scale = 1.0f;
        glm_mat4_identity(wnd->cam.mModel);
        glm_mat4_identity(wnd->cam.mView);
        glm_mat4_identity(wnd->cam.mProj);
        glViewport(0, 0, wnd->UI.width, wnd->UI.height);
        update_camera(wnd);

        return wnd;
      }
      _gllc_NW_make_context_current(0);
    }
  }
  if (wnd) {
    _gllc_NW_destroy(&wnd->nw);
    XFREE(wnd);
  }
  return NULL;
}

void gllc_window_resize(struct gllc_window *window, int x, int y, int width, int height) {
  _gllc_NW_set_size(&window->nw, x, y, width, height);
  _gllc_NW_dirty(&window->nw);
}

void gllc_window_wnd_to_drw(struct gllc_window *w, double x, double y, double *xd, double *yd) {
  *xd = (x - ((double)w->UI.width / 2)) * w->cam.scale - w->cam.dx;
  *yd = (y - ((double)w->UI.height / 2)) * w->cam.scale - w->cam.dy;
}