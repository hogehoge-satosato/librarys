#include <stdio.h>
#include "./strlibs.h"
#include <stdlib.h>

#define N 1024

int main(void)
{
    char s1[] = "ABCABCXABDNKHACABCBGT";
    char *cut = strcut(s1, 5);
    printf("%s\n", cut);

    char s2[] = "ABCABCXABDNKHACABCBGT";
    char *replaced = strrep(s2, 5, 4, "ABC");
    printf("%s\n", replaced);

    char concated[N] = "TEST"; 
    strxcat(concated, N, cut, replaced, NULL);
    printf("%s\n", concated);

    char target[] = "ABCABCXABDNKHACABCBGT";
    char *search = "ABC";
    char *searched = strrstr(target, search);
    printf("%s\n", searched);
    return 0;
}