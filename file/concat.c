#include <stdio.h>

void copy(FILE *src, FILE *dest)
{
    int ch;
    while ((ch = fgetc(src)) != EOF)
    {
        fputc(ch, dest);
    }
}

int main(int argc, char **argv)
{
    FILE *fp;
    if (argc < 2)
    {
        copy(stdin, stdout);
    }
    else
    {
        while (--argc > 0)
        {
            if((fp = fopen(*++argv, "r")) == NULL)
            {
                fprintf(stderr, "%sない\n", *argv);
                return 1;
            }
            else
            {
                copy(fp, stdout);
                fclose(fp);
            }
        }
    }
    return 0;
}