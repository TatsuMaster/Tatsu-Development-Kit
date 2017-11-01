#ifndef STRINGS_H
#define STRINGS_H


#include "sys/types.h"


int ffs(int i);

int strcasecmp(const char *s1, const char *s2);
int strncasecmp(const char *s1, const char *s2, size_t n);

#endif
