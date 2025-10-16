#include <stdio.h>
#include "./strlibs.h"
#include "../sort/srtsort.h"
#define N 1024

void print_array(char *a[], size_t na)
{
    for (size_t i = 0; i < na; i++)
    {
        printf("%s\n", a[i]);
    }
    
}


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

    // Sort
    char sort1[] = "ZBCABCXABDNKHACABCBGT";
    str_qsort(sort1, sizeof(sort1) / sizeof(sort1[0]) - 1, sizeof(sort1[0]));
    printf("%s\n", sort1);
    
    char sort2[] = "ZBCABCXABDNKHACABCBGT";
    str_msort(sort2, sizeof(sort2) / sizeof(sort2[0]) - 1, sizeof(sort2[0]));
    printf("%s\n", sort2);

    // Search
    char search1[] = "ZBCABCXAAKUAKDNKHACABCBGTW";
    char *ans1 = str_ssearch("W", search1, sizeof(search1) / sizeof(search1[0]) - 1, sizeof(search1[0]));
    if(ans1){
        puts("ある");
    }
    else
    {
        puts("なし");
    }
    
    char search2[] = "WZBCABCXAAKUAUDNKHACABCBGT";
    str_msort(search2, sizeof(search2) / sizeof(search2[0]) - 1, sizeof(search2[0]));
    char *ans2 = str_bsearch("W", search2, sizeof(search2) / sizeof(search2[0]) - 1, sizeof(search2[0]));
    if(ans2){
        puts("ある");
    }
    else
    {
        puts("なし");
    }

    char *ans3 = str_bsearchx("W", search2, sizeof(search2) / sizeof(search2[0]) - 1, sizeof(search2[0]));
    if(ans3){
        puts("ある");
    }
    else
    {
        puts("なし");
    }
    // Sort Pointer
    char *sort3[] = {
        "KABA",
        "SHIMAUMA",
        "LEMON",
        "CAT"
    };
    ptr_qsort(sort3, sizeof(sort3) / sizeof(sort3[0]));
    print_array(sort3, sizeof(sort3) / sizeof(sort3[0]));
    
    char *sort4[] = {
        "KABA",
        "SHIMAUMA",
        "LEMON",
        "CAT"
    };
    ptr_msort(sort4, sizeof(sort4) / sizeof(sort4[0]));
    print_array(sort4, sizeof(sort4) / sizeof(sort4[0]));

    // Search Pointer
    char *search4[] = {
        "KABA",
        "SHIMAUMA",
        "LEMON",
        "CAT"
    };
    char *key = "CAT";
    char *ans4 = ptr_ssearch(&key, search4, sizeof(search4) / sizeof(search4[0]));
    if(ans4){
        puts("ある");
    }
    else
    {
        puts("なし");
    }
    
    char *search5[] = {
        "KABA",
        "SHIMAUMA",
        "LEMON",
        "CAT"
    };
    ptr_msort(search5, sizeof(search5) / sizeof(search5[0]));
    char *ans5 = ptr_bsearch(&key, search5, sizeof(search5) / sizeof(search5[0]));
    if(ans5){
        puts("ある");
    }
    else
    {
        puts("なし");
    }

    char *ans6 = ptr_bsearchx(&key, search5, sizeof(search5) / sizeof(search5[0]));
    if(ans6){
        puts("ある");
    }
    else
    {
        puts("なし");
    }
    return 0;
}