#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <sys/types.h>
#include <stdlib.h>

char *strcut(char *s, size_t n)
{
    if (s == NULL) return NULL;

    size_t len = strlen(s);
    if (n > len) n = len;
    
    s[n] = '\0';

    return s;
}

char *strrep(char *s1, size_t idx, size_t n, const char *s2)
{
    size_t i, j;
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    
    if (idx < len1)
    {
        if (idx + n > len1)
        {
            n = len1 - idx;
        }

        if (len2 > n)
        {
            for (i = len1; i >= idx + n; i--)
            {
                s1[i + len2 - n] = s1[i];
            }
        }
        for (i = idx, j = 0; j < len2; i++, j++)
        {
            s1[i] = s2[j];
        }
        
        if (len2 < n)
        {
            for (; i < len1; i++)
            {
                s1[i] = s1[i + n - len2];
            }
        }
    }
    return s1;
}

char *strxcat(char *s, size_t max_size, ...)
{
    char *p = s;                                  // 最初のポインター位置を保持
    char *str;
    va_list ap;
    va_start(ap, max_size);                       // 最後の固定引数

    size_t len = strlen(s);
    s += len;                                     // ポインターを最終位置に移動

    while ((str = va_arg(ap, char *)) != NULL)
    {
        while (*str && len + 1 < max_size)
        {
            *s++ = *str++;                        // 1文字ずつコピー
            len++;
        }
    }

    *s = '\0';

    va_end(ap);
    return p;
}

char *strrstr(char *s1, const char *s2)
{
    ssize_t pt;
    size_t pp;
    size_t s1len = strlen(s1);
    size_t s2len = strlen(s2);
    size_t skip[UCHAR_MAX + 1]; 

    if (s2len == 0)
    {
        return s1;
    }

    for ( pt = 0; pt < UCHAR_MAX; pt++)
    {
        skip[pt] = s2len;                     // s2に含まれない文字はs2の長さだけ飛ばす
    }
    for (pt = s2len -1; pt > 0 ; pt--)
    {
        skip[(unsigned char)s2[pt]] = pt;     // s2に含まれる文字はその文字のindex分飛ばす
    }
    
    pt = s1len - s2len;                       // 開始位置をs1の最後からs2の長さを引いた位置に移動

    while (pt >= 0)
    {
        pp = 0;
        while (s1[pt] == s2[pp])              // 1文字一致
        {
            if (pp == s2len -1)               // s2に完全一致
            {
                return s1 + pt - s2len + 1;   // ポインターの位置を移動して戻す
            }
            pp++;
            pt++;
        }
        pt -= skip[(unsigned char)s1[pt]];    // 不一致  文字に応じて位置を前方に進める
    }
    return NULL;
}

char *strinsch(char *s, size_t idx, int ch)
{
    size_t len = strlen(s);

    if (idx <= len++)
    {
        for (size_t i = len; i > idx; --i)
        {
            s[i] = s[i -1];
        }
        s[idx] = ch;
    }
    return s;
}

char *strinsstr(char *s1, size_t idx, const char *s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    if (idx <= len1 && len2 > 0)
    {
        for (size_t i = len1; i >= idx; --i)
        {
            s1[i + len2] = s1[i];
        }
        
        for (size_t i = 0; i < len2; i++)
        {
            s1[idx + i] = s2[i];
        }
    }
    return s1;
}

char *strdelch(char *s, size_t idx)
{
    size_t len = strlen(s);
    if (idx < len)
    {
        for (size_t i = idx; i < len; i++)
        {
            s[i] = s[i + 1];
        }
    }
    return s;
}

char *strdelchs(char *s, size_t idx, size_t n)
{
    size_t len = strlen(s);

    if (idx < len)
    {
        size_t m = (n > len - idx) ? len - idx : n;
        for (size_t i = idx; i < len; i++)
        {
            s[i] = s[i + m];
        }
    }
    return s;
}

char *strrvs(char *s)
{
    char *p = s;
    char *save = s;

    while (*p)
    {
        p++;
    }

    if (p != s)
    {
        p--;
        while (p > s)
        {
            char temp = *p;
            *p-- = *s;
            *s++ = temp;
        }
    }
    return save;
}

void strxchng(char *s1, char *s2)
{
    while (*s1 || *s2)
    {
        char t = *s1;
        *s1++ = *s2;
        *s2++ = t;
    }
    *s1 = *s2 = '\0';
}

char *substring(char *s, size_t start, size_t size)
{
    size_t len = strlen(s);
    if (start > len)
    {
        return NULL;
    }

    size_t actual_size = (len > start + size) ? size : len - start;

    s += start;
    return strcut(s, actual_size);
}