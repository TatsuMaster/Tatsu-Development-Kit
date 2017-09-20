#ifndef WCHAR_H
#define WCHAR_H

#include "sys/types.h"


#ifndef __WCHAR_T
typedef __WCHAR_TYPE__ wchar_t;
#define __WCHAR_T wchar_t
#endif


wchar_t *wmemchr(const wchar_t *ws, wchar_t wc, size_t n);

int wmemcmp(const wchar_t *ws1, const wchar_t *ws2, size_t n);

wchar_t *wmemcpy(wchar_t *__restrict__ ws1, const wchar_t *__restrict__ ws2, size_t n);
wchar_t *wmemset(wchar_t *ws, wchar_t wc, size_t n);

#endif
