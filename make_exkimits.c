// <lib/exlimit.h> ヘッダ作成プログラム
#include <stdio.h>
#include <limits.h>

int short_bit(void)
{
    int count = 0;
    unsigned short x = USHRT_MAX;
    while (x)
    {
        count++;
        x >>= 1;
    }
    return count;
}


int int_bit(void)
{
    int count = 0;
    unsigned int x = UINT_MAX;
    while (x)
    {
        count++;
        x >>= 1;
    }
    return count;
}


int long_bit(void)
{
    int count = 0;
    unsigned long x = ULONG_MAX;
    while (x)
    {
        count++;
        x >>= 1;
    }
    return count;
}


int llong_bit(void)
{
    int count = 0;
    unsigned long long x = ULLONG_MAX;
    while (x)
    {
        count++;
        x >>= 1;
    }
    return count;
}

int main(void)
{
    FILE *fp = fopen("exlimit.h", "w");
    if(fp == NULL)
    {
        fputs("失敗\n", stderr);
        return 1;
    }
    
    fprintf(fp, "// <lib/exlimit.h> 処理系特性ライブラリ\n\n");
    fprintf(fp, "#ifndef __EXLIMITS__ \n");
    fprintf(fp, "#define __EXLIMITS__ \n");
    fprintf(fp, "#define SIGN_AND_MAGNITUDE 1 // 符号と絶対値\n");
    fprintf(fp, "#define ONE_S_COMPLEMENT 2 // 1の補数\n");
    fprintf(fp, "#define TWO_S_COMPLEMENT 3 // 2の補数\n");
    fprintf(fp, "#define NEGATIVE_INT %d // 負の内部表現\n", (-1) & 3);
    fprintf(fp, "#define SHORT_BIT %d // shortの精度\n", short_bit());
    fprintf(fp, "#define INT_BIT %d // intの精度\n", int_bit());
    fprintf(fp, "#define LONG_BIT %d // longの精度\n", long_bit());
    fprintf(fp, "#define LLONG_BIT %d // long longの精度\n", llong_bit());
    fprintf(fp, "\n");
    fprintf(fp, "#endif\n");

    fclose(fp);
    return 0;
}