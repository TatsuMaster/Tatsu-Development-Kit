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


/******************************************************************************
 *
 * The toascii() function shall convert its argument into a 7-bit ASCII
 * character.
 *
 * The toascii() function shall return the value (c & 0x7f).
 *
 *****************************************************************************/
int toascii(int c)
{
    return (c & 0x7f);
}


/******************************************************************************
 *
 * The tolower() function have as a domain a type int, the value of which is
 * representable as an unsigned char or the value of EOF. If the argument has
 * any other value, the behavior is undefined. If the argument of tolower()
 * represents an uppercase letter, and there exists a corresponding lowercase
 * letter, the result shall be the corresponding lowercase letter. All other
 * arguments in the domain are returned unchanged.
 *
 * Upon successful completion, the tolower() function shall return the
 * lowercase letter corresponding to the argument passed; otherwise, it
 * shall return the argument unchanged.
 *
 *****************************************************************************/
int tolower(int c)
{
    return (64 < c && c < 91) ? c + 32 : c;
}


/******************************************************************************
 *
 * The toupper() functions have as a domain a type int, the value of which is
 * representable as an unsigned char or the value of EOF. If the argument has
 * any other value, the behavior is undefined. If the argument of toupper()
 * represents a lowercase letter, and there exists a corresponding uppercase
 * letter, the result shall be the corresponding uppercase letter. All other
 * arguments in the domain are returned unchanged.
 *
 * Upon successful completion, toupper() shall return the uppercase letter
 * corresponding to the argument passed; otherwise, it shall return the
 * argument unchanged.
 *
 *****************************************************************************/
int toupper(int c)
{
    return (96 < c && c < 123) ? c - 32 : c;
}
