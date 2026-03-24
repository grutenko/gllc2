#ifndef alloc_h
#define alloc_h

#include <stddef.h>

void *_xalloc_impl(size_t size);
void *_xalloc_observed_impl(size_t size);
void _xfree_impl(void *p);

void _xalloc_free_observed();

#define XALLOC(SIZE) (_xalloc_impl(SIZE))
#define XALLOC_OBSERVED(SIZE) (_xalloc_observed_impl(SIZE))
#define XFREE(P) (_xfree_impl(P))

#endif