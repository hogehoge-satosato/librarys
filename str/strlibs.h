#ifndef STRLIBS_H
#define STRLIBS_H

extern char *strcut(char *s, size_t n);
extern char *strrep(char *s1, size_t idx, size_t n, const char *s2);
extern char *strxcat(char *s, ...);
extern char *strrstr(char *s1, const char *s2);
extern char *strinsch(char *s, size_t idx, int ch);
extern char *strinsstr(char *s1, size_t idx, const char *s2);
extern char *strdelch(char *s, size_t idx);
extern char *strdelchs(char *s, size_t idx, size_t n);
extern char *strrvs(char *s);
extern void strxchng(char *s1, char *s2);
extern char *substring(char *s, size_t start, size_t size);

#endif // STRLIBS_H