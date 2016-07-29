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
 * The isascii() function tests whether c is a 7-bit US-ASCII character
 * code. The isascii() function is defined on all integer values.
 *
 * The isascii() function returns non-zero if c is a 7-bit US-ASCII
 * character code between 0 and octal 0177 inclusive; otherwise, it
 * returns 0.
 *
 *****************************************************************************/
int isascii(int c)
{
    return (-1 < c && c < 128);
}


/******************************************************************************
 *
 * The isalnum() function tests whether c is a character of class alpha or
 * digit. 
 * 
 * The c argument is an int, the value of which the application ensures
 * is representable as an unsigned char or equal to the value of the macro EOF.
 * If the argument has any other value, the behavior is undefined.
 *
 * The isalnum() function returns non-zero if c is an alphanumeric character;
 * otherwise, it returns 0.
 *
 *****************************************************************************/
int isalnum(int c)
{
    return (47 < c && c < 58) || (64 < c && c < 91) || (96 < c && c < 123);
}


/******************************************************************************
 *
 * The isalpha() function tests whether c is a character of class alpha in the.
 *
 * The c argument is an int, the value of which the application ensures is
 * representable as an unsigned char or equal to the value of the macro EOF.
 * If the argument has any other value, the behavior is undefined.
 *
 * The isalpha() function returns non-zero if c is an alphabetic character;
 * otherwise, it returns 0.
 *
 *****************************************************************************/
int isalpha(int c)
{
    return (64 < c && c < 91) || (96 < c && c < 123);
}


/******************************************************************************
 *
 * The isblank() function tests whether c is a character of class blank.
 *
 * The c argument is a type int, the value of which the application ensures is
 * a character representable as an unsigned char or equal to the value of the
 * macro EOF. If the argument has any other value, the behavior is undefined.
 *
 * The isblank() function returns non-zero if c is a <blank>; otherwise, it
 * returns 0.
 *
 *****************************************************************************/
int isblank(int c)
{
    return (c == 9 || c == 32);
}


/******************************************************************************
 *
 * The iscntrl() function tests whether c is a character of class cntrl.
 *
 * The c argument is a type int, the value of which the application ensures is
 * a character representable as an unsigned char or equal to the value of the
 * macro EOF. If the argument has any other value, the behavior is undefined.
 *
 * The iscntrl() function returns non-zero if c is a control character; otherwise,
 * it returns 0.
 *
 *****************************************************************************/
int iscntrl(int c)
{
    return (-1 < c && c < 32) || (c == 127);
}


/******************************************************************************
 *
 * The isdigit() function tests whether c is a character of class digit.
 *
 * The c argument is an int, the value of which the application ensures is
 * a character representable as an unsigned char or equal to the value of the
 * macro EOF. If the argument has any other value, the behavior is undefined.
 *
 * The isdigit() function returns non-zero if c is a decimal digit; otherwise,
 * it returns 0.
 *
 *****************************************************************************/
int isdigit(int c)
{
    return (47 < c && c < 58);
}


/******************************************************************************
 *
 * The islower() function tests whether c is a character of class lower.
 *   
 * The c argument is an int, the value of which the application ensures
 * is a character representable as an unsigned char or equal to the value of
 * the macro EOF. If the argument has any other value, the behavior is
 * undefined.
 *
 * The islower() function returns non-zero if c is a lowercase letter;
 * otherwise, it returns 0.
 *
 *****************************************************************************/
int islower(int c)
{
    return (96 < c && c < 123);
}


/******************************************************************************
 *
 * The isprint() function tests whether c is a character of class print.
 *
 * The c argument is an int, the value of which the application ensures
 * is a character representable as an unsigned char or equal to the value of
 * the macro EOF. If the argument has any other value, the behavior is
 * undefined.
 *
 * The isprint() function returns non-zero if c is a printable character;
 * otherwise, it returns 0.
 *
 *****************************************************************************/
int isprint(int c)
{
    return (31 < c && c < 127);
}


/******************************************************************************
 *
 * The ispunct() function tests whether c is a character of class punct.
 *
 * The c argument is an int, the value of which the application ensures
 * is a character representable as an unsigned char or equal to the value of
 * the macro EOF. If the argument has any other value, the behavior is
 * undefined.
 *
 * The ispunct() function returns non-zero if c is a punctuation character;
 * otherwise, it returns 0.
 *
 *****************************************************************************/
int ispunct(int c)
{
    return (32 < c && c < 48) || (57 < c && c < 65) || (90 < c && c < 97) || (122 < c && c < 127);
}


/******************************************************************************
 *
 * The isspace() function tests whether c is a character of class space.
 *
 * The c argument is an int, the value of which the application ensures
 * is a character representable as an unsigned char or equal to the value of
 * the macro EOF. If the argument has any other value, the behavior is
 * undefined.
 *
 * The isspace() function returns non-zero if c is a white-space character;
 * otherwise, it returns 0.
 *
 *****************************************************************************/
int isspace(int c)
{
    return (8 < c && c < 14) || (c == 32);
}


/******************************************************************************
 *
 * The isupper()  function tests whether c is a character of class upper.
 *
 * The c argument is an int, the value of which the application ensures
 * is a character representable as an unsigned char or equal to the value of
 * the macro EOF. If the argument has any other value, the behavior is
 * undefined.
 *
 * The isupper() function returns non-zero if c is an uppercase letter;
 * otherwise, it returns 0.
 *
 *****************************************************************************/
int isupper(int c)
{
    return (64 < c && c < 91);
}


/******************************************************************************
 *
 * The toascii() function converts its argument into a 7-bit ASCII
 * character.
 *
 * The toascii() function returns the value (c & 0x7f).
 *
 *****************************************************************************/
int toascii(int c)
{
    return (c & 0x7f);
}


/******************************************************************************
 *
 * The tolower() function has as a domain a type int, the value of which is
 * representable as an unsigned char or the value of EOF. If the argument has
 * any other value, the behavior is undefined. If the argument of tolower()
 * represents an uppercase letter, and there exists a corresponding lowercase
 * letter, the result is the corresponding lowercase letter. All other
 * arguments in the domain are returned unchanged.
 *
 * Upon successful completion, the tolower() function returns the
 * lowercase letter corresponding to the argument passed; otherwise, it
 * returns the argument unchanged.
 *
 *****************************************************************************/
int tolower(int c)
{
    return (64 < c && c < 91) ? c + 32 : c;
}


/******************************************************************************
 *
 * The toupper() functions has as a domain a type int, the value of which is
 * representable as an unsigned char or the value of EOF. If the argument has
 * any other value, the behavior is undefined. If the argument of toupper()
 * represents a lowercase letter, and there exists a corresponding uppercase
 * letter, the result is the corresponding uppercase letter. All other
 * arguments in the domain are returned unchanged.
 *
 * Upon successful completion, toupper() returns the uppercase letter
 * corresponding to the argument passed; otherwise, it returns the
 * argument unchanged.
 *
 *****************************************************************************/
int toupper(int c)
{
    return (96 < c && c < 123) ? c - 32 : c;
}
