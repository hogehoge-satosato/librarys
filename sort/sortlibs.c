#include <stddef.h>
#include <stdlib.h>
#include <string.h>

// 線形検索
void *ssearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
    char *x = (char *)base;
    for (size_t i = 0; i < nmemb; i++)
        if (!compar(key, (const void *)&x[i * size]))
        {
            return &x[i * size];
        }
    return NULL;
}

// 二分探索拡張版
void *bsearchx(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
    if (nmemb > 0)
    {
        char *x = (char *)base;
        size_t pl = 0;
        size_t pr = nmemb - 1;
        
        while (1)
        {
            size_t pc = (pl + pr) / 2;
            int comp = compar(key, (const void *)&x[pc * size]);
            if(comp == 0)
            {
                for ( ; pc > pl ; pc--)
                {
                    if (compar((const void *)&x[(pc - 1) * size], key))
                    {
                        break;
                    }
                }
                return &x[pc * size];
            }
            else if (pl == pr)
            {
                break;
            }
            else if (comp > 0)
            {
                pl = pc + 1;
            }
            else
            {
                pr = pc - 1;
            }
        }
    }
    return NULL;
}

// マージソート
// Swap
#define swap(type, x, y) do { type (t) = (x); (x) = (y); (y) = (t); } while (0)

#define INSERTINSORT_THRESHOLD 7

static void memswap(void *x, void *y, size_t n)
{
    unsigned char *a = (unsigned char *)x;
    unsigned char *b = (unsigned char *)y;

    for ( ; n--; a++, b++)
    {
        swap(unsigned char, *a, *b);
    }
}

static size_t __sz;
static int (*__comp)(const void *, const void *);

#define E(a, idx)                ((void *)&a[(idx) * __sz])
#define comp(a, idx1, idx2)      __comp(E(a, idx1), E(a, idx2))
#define swap_elem(a, idx1, idx2) memswap(E(a, idx1), E(a, idx2), __sz)

static void merge_sort(char *src, char *dest, int low, int high, int off)
{
    int length = high - low;
    if (length < INSERTINSORT_THRESHOLD)
    {
        for (int i = low; i < high; i++)
        {
            for (int j = i; j > low && comp(dest, j -1, j) > 0 ; j--)
            {
                swap_elem(dest, j, j -1);
            }
        }
        return;
    }
    else
    {
        int dest_low = low;
        int dest_high = high;
        low += off;
        high += off;
        int mid = (low + high) / 2;

        merge_sort(dest, src, low, mid, -off);
        merge_sort(dest, src, mid, high, -off);

        if (comp(src, mid -1, mid) <= 0)
        {
            memcpy(dest + dest_low * __sz, src + low * __sz, length * __sz);
            return;
        }

        for (int i = dest_low, p = low, q = mid; i < dest_high; i++)
        {
            if (q >= high || (p < mid && comp(src, p, q) <= 0))
            {
                memcpy(E(dest, i), E(src, p++), __sz);
            }
            else
            {
                memcpy(E(dest, i), E(src, q++), __sz);
            }
        }
    }
}

void msort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
    char *p = calloc(nmemb, size);
    __sz = size;
    __comp = compar;

    if (p == NULL)
    {
        char *x = (char *)base;
        for (size_t i = 1; i < nmemb; i++)
        {
            for (size_t j = i; j > 0 && comp(x, j -1, j) > 0 ; j--)
            {
                swap_elem(x, j, j -1);
            }
        }
    }
    else
    {
        memcpy(p, base, nmemb * size);
        merge_sort(p, base, 0, nmemb, 0);
        free(p);
    }
}

// ソート判定
int is_sorted(const void *base, size_t nmemb, size_t size, int (* compar)(const void *, const void *))
{
    char * x =(char *)base;
    for (size_t i = 0; i < nmemb - 1; i++)
    {
        if (compar((const void *)&x[i * size], (const void *)&x[(i + 1) * size]) > 0)
        {
            return 0;
        }
        
    }
    return 1;
}