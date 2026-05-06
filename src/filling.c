#include "filling.h"

static struct gllc_filling *filling_tab = NULL;
static int filling_cap = 0;
static int filling_size = 0;

struct gllc_filling_line {
  int iline;
  double dist;
  double angle;
  double w;
};