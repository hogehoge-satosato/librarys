#ifndef SORTLIBS_H
#define SORTLIBS_H

#include <stddef.h>

extern void *ssearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
extern void *bsearchx(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
extern void msort(const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
extern int is_sorted(const void *base, size_t nmemb, size_t size, int (* compar)(const void *, const void *));

#endif