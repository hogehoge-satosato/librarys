#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./sortlibs.h"

typedef struct {
    int no;
    char name[13];
    int height;
} Member;

int no_cmp(const Member *x, const Member *y)
{
    return (x->no > y->no) ? 1 : (x->no < y->no) ? -1 : 0;
}

int name_cmp(const Member *x, const Member *y)
{
    return strcmp(x->name, y->name);
}

int height_cmpr(const Member *x, const Member *y)
{
    return (x->height < y->height) ? 1 : (x->height > y->height) ? -1 : 0;
}

void print_all(const Member x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%02d] %2d %-12.12s%4d\n",
            i, x[i].no, x[i].name, x[i].height
        );
    } 
}

void print_result(const Member *base, const Member *ptr)
{
    if (ptr == NULL)
    {
        puts("失敗");
    }
    else
    {
        printf("[%02d] %2d %-12.12s%4d\n",
            (int)(ptr - base), ptr->no, ptr->name, ptr->height
        );
    }
}

int main(void)
{
    Member temp, *p;
    Member x[] = {
        {1, "Sakana", 103},
        {10, "Takana", 190},
        {19, "Gakana", 123},
        {9, "Hakana", 133},
        {4, "Dakana", 183},
        {2, "Takana", 163},
        {6, "Bakana", 203},
        {17, "Aakana", 13},
    };

    int nx = sizeof(x) / sizeof(x[0]);

    print_all(x, nx);

    int issort = is_sorted(x, nx, sizeof(Member), (int (*)(const void *, const void *))no_cmp);

    if(!issort){
        puts("ソート by No");
        msort(x, nx, sizeof(Member), (int (*)(const void *, const void *))no_cmp);
        print_all(x, nx);
    }

    puts("Search by No.9");
    temp.no = 9;
    p = ssearch(&temp, x, nx, sizeof(Member), (int (*)(const void *, const void *))no_cmp);
    print_result(x, p);

    puts("ソート by 身長");
    msort(x, nx, sizeof(Member), (int (*)(const void *, const void *))height_cmpr);
    print_all(x, nx);

    puts("Search by 123cm");
    temp.height = 123;
    p = bsearch(&temp, x, nx, sizeof(Member), (int (*)(const void *, const void *))height_cmpr);
    print_result(x, p);

    puts("ソート by Name");
    msort(x, nx, sizeof(Member), (int (*)(const void *, const void *))name_cmp);
    print_all(x, nx);

    puts("Search by Sakana");
    strcpy(temp.name, "Sakana");
    p = bsearchx(&temp, x, nx, sizeof(Member), (int (*)(const void *, const void *))name_cmp);
    print_result(x, p);

    return 0;
}