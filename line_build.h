#ifndef line_tess_h
#define line_tess_h

#include "glad.h"

struct ds_vertex;

#define LB_CLOSED 0x1
#define LB_SCREENSIZE 0x2

void lb_build(double *v_in, GLuint v_in_cnt, GLfloat width, GLfloat *color, GLfloat fillet, int flags, struct ds_vertex *v_out, GLuint v_out_cnt, GLuint i_out, GLuint i_out_cnt);

#endif