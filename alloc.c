#include "alloc.h"
#include <stdlib.h>

void *_xalloc_impl(size_t size) { return malloc(size); }

void *_xalloc_observed_impl(size_t size) { return _xalloc_impl(size); }

void _xfree_impl(void *p) { free(p); }

void _xalloc_free_observed() {}