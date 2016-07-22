#include "string.h"


/******************************************************************************
 *
 * Private Access
 *
 *****************************************************************************/

extern int memcmp_sse2_entry();


static inline void* memccpy_generic(void *__restrict__ s1, const void *__restrict__ s2, int c, size_t n)
{
    register unsigned char* end_address = s1 + n;
    register unsigned char current_value = *(unsigned char*)s2;

    while (s1 != end_address && current_value != c)
    {
        current_value = *(unsigned char*)s2++;
        *(unsigned char*)s1++ = current_value;
    }

    return (s1 != end_address) ? s1 : 0;
}


static inline void* memchr_generic(const void *s, int c, size_t n)
{
    register unsigned char* end_address = (void*)(s + n);
    while (s != end_address && *(unsigned char*)s++ != (unsigned char)c);
    return (s != end_address) ? (void*)--s : 0;
}


#ifdef __x86_64__
static inline int memcmp_x86_64_fast(const void *s1, const void *s2, size_t n)
{
    __asm__ __volatile__("\t movq %0, %%rdi" : : "g" (s1));
    __asm__ __volatile__("\t movq %0, %%rsi" : : "g" (s2));
    __asm__ __volatile__("\t movq %0, %%rdx" : : "g" (n));

    return memcmp_sse2_entry();
}
#else
static inline int memcmp_generic(const void *s1, const void *s2, size_t n)
{
    register unsigned char* end_address = (void*)s1 + n;
    while (s1 != end_address && *(unsigned char*)s1++ == *(unsigned char*)s2++);
    return (--s1 == end_address) ? 0 : *(unsigned char*)s1 - *(unsigned char*)--s2;
}
#endif


static inline void *memcpy_generic(void *__restrict__ s1, const void *__restrict__ s2, size_t n)
{
    register void* start_address = s1;
    register unsigned char* end_address = (void*)s1 + n;

    while (s1 != end_address)
        *(unsigned char*)s1++ = *(unsigned char*)s2++;

    return start_address;
}


static inline void *memset_generic(void *s, int c, size_t n)
{
    register void* start_address = s;
    register unsigned char* end_address = (void*)s + n;

    while (s != end_address)
        *(unsigned char*)s++ = c;

    return start_address;
}


#ifdef __x86_64__
static inline char* stpcpy_x86_64_fast(char *__restrict__ s1, const char *__restrict__ s2)
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
    __asm__ __volatile__("\t movq %%rdi,%0" : "=r"(s1)); // Get DI value
    return --s1;
}
#else
static inline char* stpcpy_generic(char *__restrict__ s1, const char *__restrict__ s2)
{
    while ((*s1++ = *s2++));
    return --s1;
}
#endif


#ifdef __x86_64__
static inline char* strcpy_x86_64_fast(char *__restrict__ s1, const char *__restrict__ s2)
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
static inline char* strcpy_generic(char *__restrict__ s1, const char *__restrict__ s2)
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
 * The memccpy() function copies bytes from memory area s2 into s1,
 * stopping after the first occurrence of byte c (converted to an unsigned
 * char) is copied, or after n bytes are copied, whichever comes first. If
 * copying takes place between objects that overlap, the behavior is undefined.
 *
 * The memccpy() function returns a pointer to the byte after the copy of c in
 * s1, or a null pointer if c was not found in the first n bytes of s2.
 *
 *****************************************************************************/
void *memccpy(void *__restrict__ s1, const void *__restrict__ s2, int c, size_t n)
{
    return memccpy_generic(s1, s2, c, n);
}


/******************************************************************************
 *
 * The memchr() function locates the first occurrence of c (converted to an
 * unsigned char) in the initial n bytes (each interpreted as unsigned char) of
 * the object pointed to by s.
 *
 * The memchr() function returns a pointer to the located byte, or a null
 * pointer if the byte does not occur in the object.
 *
 *****************************************************************************/
void *memchr(const void *s, int c, size_t n)
{
    return memchr_generic(s, c, n);
}


/******************************************************************************
 *
 * The memcmp() function compares the first n bytes (each interpreted as
 * unsigned char) of the object pointed to by s1 to the first n bytes of the
 * object pointed to by s2.
 * The sign of a non-zero return value shall be determined by the sign of the
 * difference between the values of the first pair of bytes (both interpreted
 * as type unsigned char) that differ in the objects being compared.
 *
 * The memcmp() function returns an integer greater than, equal to, or less
 * than 0, if the object pointed to by s1 is greater than, equal to, or less
 * than the object pointed to by s2, respectively.
 *
 ******************************************************************************/
int memcmp(const void *s1, const void *s2, size_t n)
{
#ifdef __x86_64__
    return memcmp_x86_64_fast(s1, s2, n);
#else
    return memcmp_generic(s1, s2, n);
#endif
}


/******************************************************************************
 *
 * The memcpy() function copies n bytes from the object pointed to by s2 into
 * the object pointed to by s1. If copying takes place between objects that
 * overlap, the behavior is undefined.
 *
 * The memcpy() function returns s1; no return value is reserved to indicate
 * an error.
 *
 ******************************************************************************/
void *memcpy(void *__restrict__ s1, const void *__restrict__ s2, size_t n)
{
    return memcpy_generic(s1, s2, n);
}


/******************************************************************************
 *
 * The memset() function copies c (converted to an unsigned char) into each of
 * the first n bytes of the object pointed to by s.
 *
 * The memset() function returns s; no return value is reserved to indicate
 * an error.
 *
 ******************************************************************************/
void *memset(void *s, int c, size_t n)
{
    return memset_generic(s, c, n);
}


/******************************************************************************
 *
 * The stpcpy() function copies the string pointed to by src, including
 * the terminating null byte ('\0'), to the buffer pointed to by dest.
 *
 * If copying takes place between objects that overlap, the behavior is
 * undefined.
 *
 * The stpcpy function returns to the end of the string dest (that is,
 * the address of the terminating null byte) rather than the beginning.
 *
 *****************************************************************************/
char* stpcpy(char *__restrict__ dest, const char *__restrict__ src)
{
#ifdef __x86_64__
    return stpcpy_x86_64_fast(dest, src);
#else
    return stpcpy_generic(dest, src);
#endif
}


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
