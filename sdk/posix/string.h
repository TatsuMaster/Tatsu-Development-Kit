#ifndef STRING_H
#define STRING_H

#include "sys/types.h"


#ifndef NULL
#define NULL 0
#endif


void *memccpy(void *__restrict__ s1, const void *__restrict__ s2, int c, size_t n);
void *memchr(const void *s, int c, size_t n);

int memcmp(const void *s1, const void *s2, size_t n);

void *memcpy(void *__restrict__ s1, const void *__restrict__ s2, size_t n);
void *memset(void *s, int c, size_t n);

char *strchr(const char *s, int c);

int strcmp(const char *s1, const char *s2);

size_t strcspn(const char *s1, const char *s2);

char *strerror(int errnum);

size_t strlen(const char *s);

int strncmp(const char *s1, const char *s2, size_t n);

char *stpcpy(char *__restrict__ dest, const char *__restrict__ src);
char *stpncpy(char *__restrict__ s1, const char *__restrict__ s2, size_t n);

char *strcpy(char *__restrict__ dest, const char *__restrict__ src);
char *strncpy(char *__restrict__ s1, const char *__restrict__ s2, size_t n);

size_t strnlen(const char *s, size_t maxlen);

char *strsignal(int signum);

#endif
