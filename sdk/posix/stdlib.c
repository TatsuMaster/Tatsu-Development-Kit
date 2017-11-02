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


/******************************************************************************
 *
 * The ldiv() function computes the quotient and remainder of the division of
 * the numerator numer by the denominator denom. If the division is inexact,
 * the resulting quotient is the long integer of lesser magnitude that is the
 * nearest to the algebraic quotient. If the result cannot be represented, the
 * behavior is undefined; otherwise, quot * denom + rem equals numer.
 *
 * The ldiv() function returns a structure of type ldiv_t, comprising both
 * the quotient and the remainder. The structure includes the following members,
 * in any order:
 *
 * long quot;  <== Quotient
 * long rem;   <== Remainder
 *
 ******************************************************************************/
ldiv_t ldiv(long numer, long denom)
{
    ldiv_t result;
    result.quot = numer / denom;
    result.rem = numer % denom;

    return result;
}


/******************************************************************************
 *
 * The lldiv() function computes the quotient and remainder of the division of
 * the numerator numer by the denominator denom. If the division is inexact,
 * the resulting quotient is the long integer of lesser magnitude that is the
 * nearest to the algebraic quotient. If the result cannot be represented, the
 * behavior is undefined; otherwise, quot * denom + rem equals numer.
 *
 * The lldiv() function returns a structure of type lldiv_t, comprising both
 * the quotient and the remainder. The structure includes the following members,
 * in any order:
 *
 * long long quot;  <== Quotient
 * long long rem;   <== Remainder
 *
 ******************************************************************************/
lldiv_t lldiv(long long numer, long long denom)
{
    lldiv_t result;
    result.quot = numer / denom;
    result.rem = numer % denom;

    return result;
}
