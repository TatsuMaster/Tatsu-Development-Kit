#include "strings.h"
#include "ctype.h"


/******************************************************************************
 *
 * Private Access
 *
 *****************************************************************************/


/******************************************************************************
 *
 * Public Access
 *
 *****************************************************************************/


/******************************************************************************
 *
 * The ffs() function finds the first bit set (beginning with the least
 * significant bit) in i, and returns the index of that bit. Bits are numbered
 * starting at one (the least significant bit).
 *
 * The ffs() function returns the index of the first bit set. If i is 0, then
 * ffs() returns 0.
 *
 *****************************************************************************/
int ffs(int i)
{
    int ret = 0;

    if (i == 0)
        return ret;

#ifdef __x86_64__
    __asm__ __volatile__("bsf %0, %1" : "=r" (ret) : "r" (i));
    return ++ret;
#else
    for (; ret < sizeof(int) * 8; ++ret)
    {
        if(i & (1 << ret))
            return ++ret;
    }

    ret = 0;
#endif

    return ret;
}


/******************************************************************************
 *
 * TBD
 *
 *****************************************************************************/
int strcasecmp(const char *s1, const char *s2)
{
    int ret_val = 0;

    if(s1 == s2)
        return ret_val;

    while(*s1 != 0)
    {
        ret_val = tolower(*s1++) - tolower(*s2++);

        if(ret_val != 0)
            break;
    }

    return (*s2 == 0) ? ret_val : -(int)*s2;
}


/******************************************************************************
 *
 * TBD
 *
 *****************************************************************************/
int strncasecmp(const char *s1, const char *s2, size_t n)
{
    (void)s1;
    (void)s2;
    (void)n;

    return n;
}
