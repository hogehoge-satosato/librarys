#include <stdio.h>
#include "./strlibs.h"

#define N 1024


// Test for string library
int main(void)
{
    // Cut
    char s1[] = "ABCABCXABDNKHACABCBGT";
    char *cut = strcut(s1, 5);
    printf("%s\n", cut);

    // Replace
    char s2[] = "ABCABCXABDNKHACABCBGT";
    char *replaced = strrep(s2, 5, 4, "ABC");
    printf("%s\n", replaced);

    // Concat
    char concated[N] = "TEST"; 
    strxcat(concated, N, cut, replaced, NULL);
    printf("%s\n", concated);

    // Search from back
    char target[] = "ABCABCXABDNKHACABCBGT";
    char *search = "ABC";
    char *searched = strrstr(target, search);
    printf("%s\n", searched);

    // Insert a character
    char before1[6] = "SASA";
    char *after1 = strinsch(before1, 2, 'U');
    printf("%s\n", after1);

    // Insert string
    char before2[9] = "SASA";
    char *after2 = strinsstr(before2, 2, "MISI");
    printf("%s\n", after2);

    // Delete a character
    char before3[5] = "SASA";
    char *after3 = strdelch(before3, 2);
    printf("%s\n", after3);

    // Delete characters
    char before4[9] = "SASA";
    char *after4 = strdelchs(before4, 1, 2);
    printf("%s\n", after4);
    
    // Reverse
    char original[] = "ABCDEFG";
    char *reversed = strrvs(original);
    printf("%s\n", reversed);

    // Swap
    char swap1[] = "ABCDEFG";
    char swap2[] = "HIJKLMN";
    strxchng(swap1, swap2);
    printf("%s\n%s\n", swap1, swap2);

    // Substring
    char substrings[] = "ABCABCXABDNKHACABCBGT";
    char *substringed = substring(substrings, 5, 5);
    printf("%s\n", substringed);
    return 0;
}