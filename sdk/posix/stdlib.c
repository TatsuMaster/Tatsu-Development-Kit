#include "stdlib.h"

extern unsigned int abs_entry(int i);
extern unsigned long long abs64_entry(long long i);


/******************************************************************************
 *
 * Private Access
 *
 *****************************************************************************/

#ifndef __x86_64__
static inline unsigned int abs_generic(int i)
{
    return (i >= 0) ? i : -i;
}
#endif


#ifndef __x86_64__
static inline unsigned long labs_generic(long i)
{
    return (i >= 0) ? i : -i;
}
#endif


#ifndef __x86_64__
static inline unsigned long long llabs_generic(long long i)
{
    return (i >= 0) ? i : -i;
}
#endif


/******************************************************************************
 *
 * Public Access
 *
 *****************************************************************************/

/******************************************************************************
 *
 * The abs() function computes the absolute value of the integer
 * operand i. If the result cannot be represented, the behavior is undefined.
 *
 * The abs() function returns the absolute value of the integer operand.
 *
 ******************************************************************************/
unsigned int abs(int i)
{
#ifdef __x86_64__
    return abs_entry(i);
#else
    return abs_generic(i);
#endif
}


/******************************************************************************
 *
 * The labs() function computes the absolute value of the long integer
 * operand i. If the result cannot be represented, the behavior is undefined.
 *
 * The labs() function returns the absolute value of the long integer operand.
 *
 ******************************************************************************/
unsigned long labs(long i)
{
#ifdef __x86_64__
    return abs64_entry(i);
#else
    return labs_generic(i);
#endif
}


/******************************************************************************
 *
 * The llabs() function computes the absolute value of the long integer
 * operand i. If the result cannot be represented, the behavior is undefined.
 *
 * The llabs() function returns the absolute value of the long integer operand.
 *
 ******************************************************************************/
unsigned long long llabs(long long i)
{
#ifdef __x86_64__
    return abs64_entry(i);
#else
    return llabs_generic(i);
#endif
}
