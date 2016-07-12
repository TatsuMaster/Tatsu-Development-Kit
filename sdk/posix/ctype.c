#include "ctype.h"


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
 * The isascii( ) function shall test whether c is a 7-bit US-ASCII character
 * code. The isascii( ) function is defined on all integer values.
 *
 * The isascii( ) function shall return non-zero if c is a 7-bit US-ASCII
 * character code between 0 and octal 0177 inclusive; otherwise, it shall
 * return 0.
 *
 *****************************************************************************/
int isascii(int c)
{
    return (-1 < c && c < 128);
}


/******************************************************************************
 *
 * The islower() function shall test whether c is a character of class lower.
 *   
 * The c argument is an int, the value of which the application shall ensure
 * is a character representable as an unsigned char or equal to the value of
 * the macro EOF. If the argument has any other value, the behavior is
 * undefined.
 *
 * The islower() function shall return non-zero if c is a lowercase letter;
 * otherwise, they shall return 0.
 *
 *****************************************************************************/
int islower(int c)
{
    return (96 < c && c < 123);
}


/******************************************************************************
 *
 * The isupper()  function shall test whether c is a character of class upper.
 *
 * The c argument is an int, the value of which the application shall ensure
 * is a character representable as an unsigned char or equal to the value of
 * the macro EOF. If the argument has any other value, the behavior is
 * undefined.
 *
 * The isupper() function shall return non-zero if c is an uppercase letter;
 * otherwise, they shall return 0.
 *
 *****************************************************************************/
int isupper(int c)
{
    return (64 < c && c < 91);
}