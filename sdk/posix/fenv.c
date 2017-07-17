#include "fenv.h"


/******************************************************************************
 *
 * Private Access
 *
 *****************************************************************************/


static int _excepts;


/******************************************************************************
 *
 * Public Access
 *
 *****************************************************************************/


/******************************************************************************
 *
 * The feclearexcept() function attempts to clear the supported floating-point
 * exceptions represented by excepts.
 *
 * If the argument is zero or if all the specified exceptions were successfully
 * cleared, feclearexcept() returns zero. Otherwise, it returns a non-zero
 * value.
 *
 *****************************************************************************/
int feclearexcept(int excepts)
{
    _excepts &= ~excepts;
    return 0;
}


/******************************************************************************
 *
 * The fetestexcept() function determines which of a specified subset of the
 * floating-point exception flags are currently set. The excepts argument
 * specifies the floating-point status flags to be queried.
 *
 * The fetestexcept() function returns the value of the bitwise-inclusive OR
 * of the floating-point exception macros corresponding to the currently set
 * floating-point exceptions included in excepts.
 *
 *****************************************************************************/
int fetestexcept(int excepts)
{
    return _excepts & excepts;
}


/******************************************************************************
 *
 * The feraiseexcept() function raises the supported floating-point exceptions
 * represented by the argument excepts. The order in which these floating-point
 * exceptions are raised is unspecified. Whether the feraiseexcept() function
 * additionally raises the inexact floatingpoint exception whenever it raises
 * the overflow or underflow floating-point exception is architecture-defined.
 *
 * If the argument is zero or if all the specified exceptions were successfully
 * raised, feraiseexcept() returns zero. Otherwise, it returns a non-zero
 * value.
 *
 *****************************************************************************/
int feraiseexcept(int excepts)
{
    _excepts = excepts;

#ifdef __x86_64__
#ifndef FRAMEWORK_TEST
    if (excepts & FE_DIVBYZERO)
    {
        // DIV0 CPU Exception
        __asm__("int $0x00");
    }
    if (excepts & FE_OVERFLOW || excepts & FE_UNDERFLOW)
    {
         // Bounding CPU Exception
        __asm__("int $0x05");
    }

    // x87 FP Co Processor Exceptions
    __asm__("int $0x16");
#endif
#else
#error "TODO: Raise fp exception on this architecture"
#endif

    return 0;
}