#ifndef STDLIB_H
#define STDLIB_H


typedef struct {
    long quot;
    long rem;
} ldiv_t;


typedef struct {
    long long quot;
    long long rem;
} lldiv_t;


unsigned int abs(int i);
unsigned long labs(long i);
unsigned long long llabs(long long i);

ldiv_t ldiv(long numer, long denom);
lldiv_t lldiv(long long numer, long long denom);

#endif
