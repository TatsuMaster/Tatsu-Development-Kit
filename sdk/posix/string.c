#include "string.h"


/******************************************************************************
 *
 * Private Access
 *
 *****************************************************************************/

#ifdef __x86_64__
static inline char* strcpy_x86_64_fast(char *restrict s1, const char *restrict s2)
{
    int rsrc, rdst;
    __asm__ __volatile__(
        "1: \tlodsb\n\t;"                  // loads byte at *SI to register AL, increments SI
        "stosb\n\t;"                       // stores byte at *DI from register AL, increments DI
        "testb %%al,%%al\n\t;"             // sets flags based on value in AL
        "jne 1b;"                          // repeat if AL is non zero
        : "=&S" (rsrc), "=&D" (rdst)
        : "0" (s2), "1" (s1)
        );
    return s1;
}
#else
static inline char* strcpy_generic(char *restrict s1, const char *restrict s2)
{
    register char* start_address = s1;
    while ((*s1++ = *s2++));
    return start_address;
}
#endif


/******************************************************************************
*
* Public Access
*
*****************************************************************************/


/******************************************************************************
 *
 * The strcpy() function copies the string pointed to by src, including
 * the terminating null byte ('\0'), to the buffer pointed to by dest.
 *
 * If copying takes place between objects that overlap, the behavior is
 * undefined.
 *
 * The strcpy function returns a pointer to the destination string dest.
 *
 *****************************************************************************/
char* strcpy(char *__restrict__ dest, const char *__restrict__ src)
{
#ifdef __x86_64__
    return strcpy_x86_64_fast(dest, src);
#else
    return strcpy_generic(dest, src);
#endif
}