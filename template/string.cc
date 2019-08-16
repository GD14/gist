#include <iostream>
#include <stdlib.h>
int memcmp(const void *dest, const void *src, size_t n)
{
}
//return a pointer to dest
void *memcpy(void *dest, const void *src, size_t n)
{
}

//copy no more than n bytes from memory src to dest,
//stopping  when the character c is found
void *memccpy(void *dest, const void *src, int c, size_t n)
{
}

//copy no more than n byte from src to dest,
//the src and dest  may overlap
//return a pointer to dest
void *memmove(void *dest, const void *src, size_t n)
{
}

//wide-character equivalent of memove
wchar_t *wmemmove(wchar_t *dest, const wchar_t *src, size_t n)
{
}

//return length of the s,not including '\0'
size_t strlen(const char *s)
{
    const char *sc;
    for (sc = s; *sc != '\0'; ++sc)
        /*nothing */;
    return sc - s;
}

char *strdup(const char *str)
{
    if (!str)
        return NULL;

    int len = strlen(str) + 1;
    char *buf = (char*)malloc(len);
    if (buf)
        memcmp(buf, str, len);
    return buf;
}

char *strcat(char *dest, const char *src)
{
    char *tmp = dest;
    while (*dest)
        dest++;
    while ((*dest++ = *src++) != '\0')
        ;
    return tmp;
}

char *strncat(char *dest, const char *src, size_t n)
{
    char *tmp = dest;
    if (n)
    {
        while (*dest)
            dest++;
        while ((*dest++ = *src++) != 0)
        {
            if (--n == 0)
            {
                *dest = '\0';
                break;
            }
        }
    }
    return tmp;
}

char *strchr(const char *s, int c)
{
    for (; *s != (char)c; ++s)
        if (*s == '\0')
            return NULL;
    return (char *)s;
}

char *strrchr(const char *s, int c)
{
    const char *last = NULL;
    do
    {
        if (*s == (char)c)
            last = s;
    } while (*s++);
    return (char *)last;
}

//一个神奇的函数,
//不可重入
char *strtok(char *s, const char *delim)
{
    return NULL;
}

char *strtok_r(char *str, const char *delim, char **saveptr)
{
    return NULL;
}

char *strpbrk(const char *s, const char *accept)
{
    const char *sc1, *sc2;
    for (sc1 = s; *sc1 != '0'; ++sc1)
    {
        for (sc2 = accept; *sc2 != '0'; ++sc2)
        {
            if (*sc1 == *sc2)
                return (char *)sc1;
        }
    }
    return NULL;
}
char *strsep(char **s, const char *delim)
{
    char *sbegin = *s;
    char *end;
    if (sbegin == NULL)
        return NULL;

    end = strpbrk(sbegin, delim);
    if (end)
        *end++ = '\0';
    *s = end;
    return sbegin;
}

char *strstr(const char *s1, const char *s2)
{
    size_t l1, l2;
    l2 = strlen(s2);
    if (!l2)
        return (char *)s1;

    l1 = strlen(s1);
    while (l1 >= l2)
    {
        l1--;
        if (!memcmp(s1, s2, l2))
            return (char *)s1;
        s1++;
    }
    return NULL;
}

int strcmp(const char *s1, const char *s2)
{
    unsigned char c1, c2;
    while (1)
    {
        c1 = *s1++;
        c2 = *s2++;
        if (c1 != c2)
            return c1 < c2 ? -1 : 1;
        if (!c1)
            break;
    }
    return 0;
}

//NEVER USE THIS FUNCTION!
// copys the string pointed to by src,include '\0',
// to the buffer pointed to by dest.
// the strings may not overlap,the dest must be large enough
char *strcpy(char *dest, const char *src)
{
    char *tmp = dest;
    while ((*dest++ = *src++) != '\0')
        /*nothing */;
    return tmp;
}

//similar with strcpy,but at most n bytes copied
//WARNING: if there is no '\0' among the first n bytes
// of src, the string placed in dest will not be null terminated.
// if the length src is less than n, strncpy pads the
//remainder of dest with null bytes;

char *strncpy(char *dest, const char *src, size_t n)
{
    char *tmp = dest;
    while (n)
    {
        if ((*tmp = *src) != 0)
            src++;
        tmp++;
        n--;
    }
    return dest;
}

size_t strlcpy(char *dest, const char *src, size_t size)
{
    size_t ret = strlen(src);

    return ret;
}
int main()
{
}