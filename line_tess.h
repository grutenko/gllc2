#ifndef line_tess_h
#define line_tess_h

#include "glad.h"

struct gllc_DB_vertex;

int line_tess(double *V_in, int V_in_cnt, struct gllc_DB_vertex *V_out,
              GLuint *I_out, GLuint *V_out_cnt, GLuint *I_out_cnt);

#endif