#include "wchar.h"


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
 * The wmemchr() function locates the first occurrence of wc in the initial n
 * wide characters of the object pointed to by ws. This function is not
 * affected by locale and all wchar_t values are treated identically. The null
 * wide character and wchar_t values not corresponding to valid characters are
 * not treated specially.
 *
 * If n is zero, the function behaves as if no valid occurrence of wc is
 * found.
 *
 * The wmemchr() function returns a pointer to the located wide character,
 * or a null pointer if the wide character does not occur in the object.
 *
 *****************************************************************************/
wchar_t *wmemchr(const wchar_t *ws, wchar_t wc, size_t n)
{
    register const wchar_t* end_address = &ws[n];
    while (ws != end_address && *ws++ != wc);
    return (ws != end_address) ? (wchar_t*)--ws : 0;
}


/******************************************************************************
 *
 * The wmemcmp() function compares the first n wide characters of the object
 * pointed to by ws1 to the first n wide characters of the object pointed to
 * by ws2. This function is not affected by locale and all wchar_t values are
 * treated identically. The null wide character and wchar_t values not
 * corresponding to valid characters are not treated specially.
 *
 * If n is zero, the the function behaves as if the two objects compare equal.
 *
 * The wmemcmp() function returns an integer greater than, equal to, or less
 * than zero, respectively, as the object pointed to by ws1 is greater than,
 * equal to, or less than the object pointed to by ws2.
 *
 *****************************************************************************/
int wmemcmp(const wchar_t *ws1, const wchar_t *ws2, size_t n)
{
    register const wchar_t* end_address = &ws1[n];
    while (ws1 != end_address && *ws1++ == *ws2++);
    return (--ws1 == end_address) ? 0 : *ws1 - *--ws2;
}


/******************************************************************************
 *
 * The wmemcpy() function copies n wide characters from the object pointed to
 * by ws2 to the object pointed to by ws1. This function is not affected by
 * locale and all wchar_t values are treated identically. The null wide
 * character and wchar_t values not corresponding to valid characters are not
 * treated specially.
 *
 * If n is zero, the function copies zero wide characters.
 *
 * The wmemcpy() function returns the value of ws1.
 *
 *****************************************************************************/
wchar_t *wmemcpy(wchar_t *__restrict__ ws1, const wchar_t *__restrict__ ws2, size_t n)
{
    if (n == 0 || ws1 == ws2)
        return ws1;

    register wchar_t* start_address = ws1;
    register wchar_t* end_address = &ws1[n];

    while (ws1 != end_address)
        *ws1++ = *ws2++;

    return start_address;
}


/******************************************************************************
 *
 * The wmemset() function copyies the value of wc into each of the first n wide
 * characters of the object pointed to by ws. This function is not affected by
 * locale and all wchar_t values are treated identically. The null wide
 * character and wchar_t values not corresponding to valid characters are not
 * treated specially.
 *
 * If n is zero, the function copies zero wide characters.
 *
 * The wmemset() function returns the value of ws.
 *
 *****************************************************************************/
wchar_t *wmemset(wchar_t *ws, wchar_t wc, size_t n)
{
    if (n == 0)
        return ws;

    register wchar_t* start_address = ws;
    register wchar_t* end_address = &ws[n];

    while (ws != end_address)
        *ws++ = wc;

    return start_address;
}
