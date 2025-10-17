#include <stdlib.h>
#include <limits.h>

int strtoi(const char *str, int *err)
{
    int no = 0;
    int sign = 1;
    div_t int_min = div(INT_MIN, 10);
    int_min.rem *= -1;
    *err = 2;

    while(isspace(*str))
        str++;

    switch (*str)
    {
        case '+': str++;            break;
        case '-': str++; sign = -1; break;
    }

    for (; isdigit(*str); str++)
    {
        if((no < int_min.quot) ||
           no == int_min.quot && *str - '0' > int_min.rem)
        {
            no = INT_MIN;
            goto Overflow;
        }
        no = no * 10 - (*str - '0');
    }

    if (sign == 1)
    {
        if(no < -INT_MAX)
        {
            no = INT_MAX;
            goto Overflow;
        }
        no = -no;
    }
    *err = *str ? 1 : 0;

Overflow:
    return no;
}