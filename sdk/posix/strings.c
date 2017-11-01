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
 * The strcasecmp() function compares, while ignoring differences in case,
 * the string pointed to by s1 to the string pointed to by s2.
 *
 * Upon completion, strcasecmp() returns an integer greater than, equal to,
 * or less than 0, if the string pointed to by s1 is, ignoring case, greater
 * than, equal to, or less than the string pointed to by s2, respectively.
 *
 *****************************************************************************/
int strcasecmp(const char *s1, const char *s2)
{
    register size_t offset = s2 - s1;

    while (*s1 && s1[offset] && tolower(*s1) == tolower(s1[offset]))
        ++s1;

    return tolower(*s1) - tolower(s1[offset]);
}


/******************************************************************************
 *
 * The strncasecmp() function compares, while ignoring differences in case,
 * not more than n bytes from the string pointed to by s1 to the string
 * pointed to by s2.
 *
 * Upon successful completion, strncasecmp() returns an integer greater
 * than, equal to, or less than 0, if the possibly null-terminated array
 * pointed to by s1 is, ignoring case, greater than, equal to, or less than
 * the possibly null-terminated array pointed to by s2, respectively.
 *
 *****************************************************************************/
int strncasecmp(const char *s1, const char *s2, size_t n)
{
    register size_t offset = 0;
    --n; // Match length to offset

    while (offset != n && s1[offset] && s2[offset] && tolower(s1[offset]) == tolower(s2[offset]))
        ++offset;

    return tolower(s1[offset]) - tolower(s2[offset]);
}
