#include "string.h"


/******************************************************************************
 *
 * Private Access
 *
 *****************************************************************************/

extern int memcmp_sse2_entry();


static inline void* memccpy_generic(unsigned char *__restrict__ s1, const unsigned char *__restrict__ s2, unsigned char c, size_t n)
{
    register unsigned char* end_address = s1 + n;
    register unsigned char current_value = *s2;

    while (s1 != end_address && current_value != c)
    {
        current_value = *s2++;
        *s1++ = current_value;
    }

    return (s1 != end_address) ? s1 : 0;
}


static inline void* memchr_generic(const unsigned char* s, char c, size_t n)
{
    register unsigned char* end_address = (void*)(s + n);
    while (s != end_address && *s++ != c);
    return (s != end_address) ? (void*)--s : 0;
}


#ifdef __x86_64__
static inline int memcmp_x86_64_fast(const void* s1, const void* s2, size_t n)
{
    __asm__ __volatile__("\t movq %0, %%rdi" : : "g" (s1));
    __asm__ __volatile__("\t movq %0, %%rsi" : : "g" (s2));
    __asm__ __volatile__("\t movq %0, %%rdx" : : "g" (n));

    return memcmp_sse2_entry();
}
#else
static inline int memcmp_generic(const unsigned char* s1, const unsigned char* s2, size_t n)
{
    register unsigned char* end_address = (void*)s1 + n;
    while (s1 != end_address && *s1++ == *s2++);
    return (--s1 == end_address) ? 0 : *s1 - *--s2;
}
#endif


static inline void* memcpy_generic(unsigned char *__restrict__ s1, const unsigned char *__restrict__ s2, size_t n)
{
    register void* start_address = s1;
    register unsigned char* end_address = (void*)s1 + n;

    while (s1 != end_address)
        *s1++ = *s2++;

    return start_address;
}


static inline void* memset_generic(unsigned char* s, char c, size_t n)
{
    register void* start_address = s;
    register unsigned char* end_address = (void*)s + n;

    while (s != end_address)
        *s++ = c;

    return start_address;
}


static inline int strcmp_generic(const char* s1, const char* s2)
{
    register size_t offset = s2 - s1;

    while (*s1 && s1[offset] && *s1 == s1[offset])
        ++s1;

    return *s1 - s1[offset];
}


static inline size_t strcspn_generic(const char* s1, const char* s2)
{
    register const char* iter = s1;
    register const char* character_set = s2;

    while (*iter)
    {
        while (*character_set)
        {
            if (*character_set == *iter)
                goto calculate_length;

            ++character_set;
        }

        ++iter;
        character_set = s2;
    }


calculate_length:

    return iter - s1;
}


static inline char* stpncpy_generic(char* __restrict__ s1, const char* __restrict__ s2, size_t n)
{
    register char* iter = s1;
    register char* result;

    while ((size_t)(iter - s1) < n && *s2)
        *iter++ = *s2++;

    result = iter;

    while ((size_t)(iter - s1) < n)
        *iter++ = 0;

    return result;
}


static inline size_t strlen_generic(const char* s)
{
    register size_t length = -1;
    while (s[++length]);
    return length;
}


static inline int strncmp_generic(const char* s1, const char* s2, size_t n)
{
    register size_t offset = 0;
    --n; // Match length to offset

    while (offset != n && s1[offset] && s2[offset] && s1[offset] == s2[offset])
        ++offset;

    return s1[offset] - s2[offset];
}


static inline char* strncpy_generic(char* __restrict__ s1, const char* __restrict__ s2, size_t n)
{
    register char* iter = s1;

    while ((size_t)(iter - s1) < n && *s2)
        *iter++ = *s2++;

    while ((size_t)(iter - s1) < n)
        *iter++ = 0;
    
    return s1;
}


static inline size_t strnlen_generic(const char* s, size_t maxlen)
{
    register size_t length = -1;
    register size_t limit = maxlen;
    while (limit != length && s[++length]);
    return length;
}


static inline char* strchr_generic(const char* s, char c)
{
    register char* pos = (char*)s;

    while (*pos && *pos != c)
        ++pos;

    if (!c)
        return pos;

    return *pos ? pos : 0;
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
    return memccpy_generic((unsigned char*)s1, (const unsigned char*)s2, (unsigned char)c, n);
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
    return memchr_generic((const unsigned char*)s, (unsigned char)c, n);
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
    return memcmp_generic((const unsigned char*)s1, (const unsigned char*)s2, n);
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
    return memcpy_generic((unsigned char*)s1, (const unsigned char*)s2, n);
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
    return memset_generic((unsigned char*)s, (unsigned char)c, n);
}


/******************************************************************************
 *
 * The strchr() function locates the first occurrence of c (converted to a
 * char) in the string pointed to by s. The terminating NUL character is
 * considered to be part of the string.
 *
 * Upon completion, strchr() returns a pointer to the byte, or a null pointer
 * if the byte was not found.
 *
 *****************************************************************************/
char *strchr(const char *s, int c)
{
    return strchr_generic(s, (char)c);
}


/******************************************************************************
 *
 * The strcmp() function compares the string pointed to by s1 to the
 * string pointed to by s2. The sign of a non-zero return value is determined
 * by the sign of the difference between the values of the first pair of bytes
 * (both interpreted as type unsigned char) that differ in the strings
 * being compared.
 *
 * Upon completion, strcmp() returns an integer greater than, equal to, or
 * less than 0, if the string pointed to by s1 is greater than, equal to, or
 * less than the string pointed to by s2, respectively.
 *
 *****************************************************************************/
int strcmp(const char *s1, const char *s2)
{
    return strcmp_generic(s1, s2);
}


/******************************************************************************
 *
 * The strcspn() function computes the length (in bytes) of the maximum
 * initial segment of the string pointed to by s1 which consists entirely of
 * bytes not from the string pointed to by s2.
 *
 * The strcspn() function returns the length of the computed segment of the
 * string pointed to by s1; no return value is reserved to indicate an error.
 *
 *****************************************************************************/
size_t strcspn(const char *s1, const char *s2)
{
    return strcspn_generic(s1, s2);
}


/******************************************************************************
 *
 * The strlen() function computes the number of bytes in the string to which
 * s points, not including the terminating NUL character.
 *
 * The strlen() function returns the length of s; no return value is reserved
 * to indicate an error.
 *
 *****************************************************************************/
size_t strlen(const char *s)
{
    return strlen_generic(s);
}


/******************************************************************************
 *
 * The strncmp() function compares not more than n bytes (bytes that follow a
 * NUL character are not compared) from the array pointed to by s1 to the array
 * pointed to by s2. The sign of a non-zero return value is determined by the
 * sign of the difference between the values of the first pair of bytes
 * (both interpreted as type unsigned char) that differ in the strings
 * being compared.
 *
 * Upon successful completion, strncmp() returns an integer greater than, equal
 * to, or less than 0, if the possibly null-terminated array pointed to by s1
 * is greater than, equal to, or less than the possibly null-terminated array
 * pointed to by s2 respectively.
 *
 *****************************************************************************/
int strncmp(const char *s1, const char *s2, size_t n)
{
    return strncmp_generic(s1, s2, n);
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
 * The stpncpy() function copies not more than n bytes (bytes that follow a NUL
 * character are not copied) from the array pointed to by s2 to the array
 * pointed to by s1. If the array pointed to by s2 is a string that is shorter
 * than n bytes, NUL characters are appended to the copy in the array pointed
 * to by s1, until n bytes in all are written. If copying takes place between
 * objects that overlap, the behavior is undefined.
 *
 * If a NUL character is written to the destination, the stpncpy() function
 * returns the address of the first such NUL character. Otherwise, it returns
 * &s1[n].
 *
 * No return values are reserved to indicate an error.
 *
 *****************************************************************************/
char *stpncpy(char *__restrict__ s1, const char *__restrict__ s2, size_t n)
{
    return stpncpy_generic(s1, s2, n);
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


/******************************************************************************
 *
 * The strncpy() function copies not more than n bytes (bytes that follow a NUL
 * character are not copied) from the array pointed to by s2 to the array
 * pointed to by s1. If the array pointed to by s2 is a string that is shorter
 * than n bytes, NUL characters are appended to the copy in the array pointed
 * to by s1, until n bytes in all are written. If copying takes place between
 * objects that overlap, the behavior is undefined.
 *
 * The strncpy() function returns s1. No return values are reserved to
 * indicate an error.
 *
 *****************************************************************************/
char *strncpy(char *__restrict__ s1, const char *__restrict__ s2, size_t n)
{
    return strncpy_generic(s1, s2, n);
}


/******************************************************************************
 *
 * The strnlen() function computes the smaller of the number of bytes in the
 * array to which s points, not including the terminating NUL character, or
 * the value of the maxlen argument. The strnlen() function never examines
 * more than maxlen bytes of the array pointed to by s.
 *
 * The strnlen() function returns an integer containing the smaller of either
 * the length of the string pointed to by s or maxlen.
 *
 *****************************************************************************/
size_t strnlen(const char *s, size_t maxlen)
{
    return strnlen_generic(s, maxlen);
}
