#ifndef UNISTD_H
#define UNISTD_H

#include "sys/types.h"


void swab(const void *__restrict__ src, void *__restrict__ dest, ssize_t nbytes);

#endif
