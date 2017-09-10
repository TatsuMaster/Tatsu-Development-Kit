#include "fenv.h"


/******************************************************************************
 *
 * Private Access
 *
 *****************************************************************************/


static int _excepts;
static int _rounding_mode = FE_TONEAREST;


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


/******************************************************************************
 *
 * The fegetround() function returns the value of the rounding direction macro
 * representing the current rounding direction or a negative value if there is
 * no such rounding direction macro or the current rounding direction is not
 * determinable.
 *
 *****************************************************************************/
int fegetround()
{
    return _rounding_mode;
}


/******************************************************************************
 *
 * The fesetround() function returns establish the rounding direction
 * represented by its argument round. If the argument is not equal to the value
 * of a rounding direction macro, the rounding direction is not changed.
 *
 * The fesetround() function returns a zero value if and only if the
 * requested rounding direction was established.
 *
 *****************************************************************************/
int fesetround(int round)
{
    if (round == FE_TONEAREST || round == FE_DOWNWARD || round == FE_UPWARD || round == FE_TOWARDZERO)
    {
        _rounding_mode = round;
        return 0;
    }

    return -1;
}
