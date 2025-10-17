#include <stdio.h>

typedef struct {
    char a[9];
    char b[7];
    char c[9];
    char d[10];
    char e[8];
} Rec;

int fgetword(FILE *fp, char *str)
{
    int ch;
    while ((ch = fgetc(fp)) != EOF && ch != '\t' && ch != '\n')
    {
        if(ch != ' ')
            *str++ = ch;
    }
    *str = '\0';
    return ch;
}

int getrec(FILE *fp, Rec *dat)
{
    if(fgetword(fp, dat->a) == EOF) return EOF;
    if(fgetword(fp, dat->b) == EOF) return EOF;
    if(fgetword(fp, dat->c) == EOF) return EOF;
    if(fgetword(fp, dat->d) == EOF) return EOF;
    if(fgetword(fp, dat->e) == EOF) return EOF;
    return 0;
}

int main(void)
{
    FILE *fp = fopen("data_file.dat", "r");
    if (fp)
    {
        Rec dat;
        while (getrec(fp, &dat) != EOF)
        {
            printf("%s\t%s\t%s\t%s\t%s\n", dat.a, dat.b, dat.c, dat.d, dat.e);
        }
        fclose(fp);
    }
    return 0;
}