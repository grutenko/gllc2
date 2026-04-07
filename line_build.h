#ifndef line_tess_h
#define line_tess_h

#include "glad.h"

struct ds_vertex;

struct lb {
  struct lb_in {
    int flags;
    GLuint closed;
    GLuint screenweight;
    GLfloat weight;
    GLfloat fillet_radius;
    GLfloat color[4];
    double *ver;
    GLuint ver_cnt;
    GLuint ioffset;
  } in;
  struct lb_out {
    struct ds_vertex *ver_ptr;
    GLuint *ind_ptr;
    GLuint ver_cnt;
    GLuint ind_cnt;
  } out;
};

// Рассчитывает lb.out.ver_cnt, lb.out.ind_cnt из переданых данных в lb.in.*
// Позволяет перед lb_build предоставить ver_ptr, ind_ptr необходимого размера
void lb_init(struct lb *lb);
void lb_stats_bevel(struct lb *lb);
void lb_stats_miter(struct lb *lb);
void lb_stats_round(struct lb *lb);
void lb_build_bevel(struct lb *lb);
void lb_build_miter(struct lb *lb);
void lb_build_round(struct lb *lb);

#endif