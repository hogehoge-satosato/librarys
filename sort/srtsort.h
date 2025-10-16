#ifndef STRSORT_H
#define STRSORT_H

#include <string.h>
#include <stdlib.h>
#include "./sortlibs.h"

inline static int strrcmp(const void *s1, const void *s2)
{
    int comp = strcmp((const char *)s1, (const char *)s2);
    return (comp < 0) ? 1 : (comp == 0) ? 0 : -1;
}

inline static int cmp_char(const void *a, const void *b)
{
    return (*(const char *)a) - (*(const char *)b);
}

inline static int cmp_charr(const void *a, const void *b)
{
    return (*(const char *)b) - (*(const char *)a);
}

inline static int ptrcmp(const void *s1, const void *s2)
{
    return strcmp(*(const char **)s1, *(const char **)s2);
}

inline static int ptrrcmp(const void *s1, const void *s2)
{
    int comp = strcmp(*(const char **)s1, *(const char **)s2);
    return (comp < 0) ? 1 : (comp == 0) ? 0 : -1;
}

#define str_ssearch(s, p, n1, n2) ssearch((const void *)s, (void *)p, (size_t)n1, (size_t)n2, (int(*)(const void *, const void *))cmp_char)
#define str_bsearch(s, p, n1, n2) bsearch((const void *)s, (void *)p, (size_t)n1, (size_t)n2, (int(*)(const void *, const void *))cmp_char)
#define str_bsearchx(s, p, n1, n2) bsearchx((const void *)s, (void *)p, (size_t)n1, (size_t)n2, (int(*)(const void *, const void *))cmp_char)
#define str_qsort(p, n1, n2) qsort((void *)p, (size_t)n1, (size_t)n2, (int(*)(const void *, const void *))strcmp)
#define str_msort(p, n1, n2) msort((void *)p, (size_t)n1, (size_t)n2, (int(*)(const void *, const void *))strcmp)

#define str_ssearchr(s, p, n1, n2) ssearch((const void *)s, (const void *)p, (size_t)n1, (size_t)n2, (int(*)(const void *, const void *))cmp_charr)
#define str_bsearchr(s, p, n1, n2) bsearch((const void *)s, (const void *)p, (size_t)n1, (size_t)n2, (int(*)(const void *, const void *))cmp_charr)
#define str_bsearchxr(s, p, n1, n2) bsearchx((const void *)s, (const void *)p, (size_t)n1, (size_t)n2, (int(*)(const void *, const void *))cmp_charr)
#define str_qsortr(p, n1, n2) qsort((void *)p, (size_t)n1, (size_t)n2, (int(*)(const void *, const void *))strrcmp)
#define str_msortr(p, n1, n2) msort((void *)p, (size_t)n1, (size_t)n2, (int(*)(const void *, const void *))strrcmp)

#define ptr_ssearch(s, p, n) ssearch((const void *)s, (void *)p, (size_t)n, sizeof(char *), (int(*)(const void *, const void *))ptrcmp)
#define ptr_bsearch(s, p, n) bsearch((const void *)s, (void *)p, (size_t)n, sizeof(char *), (int(*)(const void *, const void *))ptrcmp)
#define ptr_bsearchx(s, p, n) bsearchx((const void *)s, (void *)p, (size_t)n, sizeof(char *), (int(*)(const void *, const void *))ptrcmp)
#define ptr_qsort(p, n) qsort((void *)p, (size_t)n, sizeof(char *), (int(*)(const void *, const void *))ptrcmp)
#define ptr_msort(p, n) msort((void *)p, (size_t)n, sizeof(char *), (int(*)(const void *, const void *))ptrcmp)

#define ptr_ssearchr(s, p, n) ssearch((const void *)s, (const void *)p, (size_t)n, sizeof(char *), (int(*)(const void *, const void *))ptrrcmp)
#define ptr_bsearchr(s, p, n) bsearch((const void *)s, (const void *)p, (size_t)n, sizeof(char *), (int(*)(const void *, const void *))ptrrcmp)
#define ptr_bsearchxr(s, p, n) bsearchx((const void *)s, (const void *)p, (size_t)n, sizeof(char *), (int(*)(const void *, const void *))ptrrcmp)
#define ptr_qsortr(p, n) qsort((void *)p, (size_t)n, sizeof(char *), (int(*)(const void *, const void *))ptrrcmp)
#define ptr_msortr(p, n) msort((void *)p, (size_t)n, sizeof(char *), (int(*)(const void *, const void *))ptrrcmp)

#endif