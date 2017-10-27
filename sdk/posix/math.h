#ifndef MATH_H
#define MATH_H


#define M_E        2.7182818284590452354
#define M_LOG2E    1.4426950408889634074    /*  log_2 e     */
#define M_LOG10E   0.43429448190325182765   /*  log_10 e    */
#define M_LN2      0.69314718055994530942   /*  log_e 2     */
#define M_LN10     2.30258509299404568402   /*  log_e 10    */
#define M_PI       3.14159265358979323846   /*  pi          */
#define M_PI_2     1.57079632679489661923   /*  pi/2        */
#define M_PI_4     0.78539816339744830962   /*  pi/4        */
#define M_1_PI     0.31830988618379067154   /*  1/pi        */
#define M_2_PI     0.63661977236758134308   /*  2/pi        */
#define M_2_SQRTPI 1.12837916709551257390   /*  2/sqrt(pi)  */
#define M_SQRT2    1.41421356237309504880   /*  sqrt(2)     */
#define M_SQRT1_2  0.70710678118654752440   /*  1/sqrt(2)   */

#define fmax(x, y) (x < y ? y : x)
#define fmaxf(x, y) fmax(x, y)
#define fmaxl(x, y) fmax(x, y)

#define fmin(x, y) (x < y ? x : y)
#define fminf(x, y) fmin(x, y)
#define fminl(x, y) fmin(x, y)


/******************************************************************************
 *
 * The isnan() macro determines whether its argument value is a NaN. First, an
 * argument represented in a format wider than its semantic type is converted
 * to its semantic type. Then determination is based on the type of the
 * argument.
 *
 * The isnan() macro returns a non-zero value if and only if its argument has
 * a NaN value.
 *
 * A bit-wise example of a IEEE floating-point standard single precision
 * (32-bit) NaN: s111 1111 1axx xxxx xxxx xxxx xxxx xxxx where s is the sign,
 * x is the payload, and a determines the type of NaN. If a = 1, it is a quiet
 * NaN; if a is zero and the payload is nonzero, then it is a signaling NaN
 *
 * x = 0x7FBFFFFF (sign bit 0, a = 0, rest of bits 1)
 *
 *****************************************************************************/
#define isnan(x) (x != x)


/******************************************************************************
 *
 * The isless() macro determines whether its first argument is less than its
 * second argument. The value of isless(x, y) is equal to (x) < (y); however,
 * unlike (x) < (y), isless(x, y) will not raise the invalid floating-point
 * exception when x and y are unordered.
 *
 * Upon successful completion, the isless() macro returns the value of
 * (x) < (y). If x or y is NaN, 0 will be returned.
 *
 *****************************************************************************/
#define isless(x ,y) (isnan(x) ? 0 : isnan(y) ? 0 : x < y)


/******************************************************************************
 *
 * The islessequal() macro determines whether its first argument is less than
 * or equal to its second argument. The value of islessequal(x, y) is equal to
 * (x) <= (y); however, unlike (x) <= (y), islessequal(x, y) will not raise the
 * invalid floating-point exception when x and y are unordered.
 *
 * Upon successful completion, the islessequal() macro returns the value of
 * (x) <= (y). If x or y is NaN, 0 will be returned.
 *
 *****************************************************************************/
#define islessequal(x, y) (isnan(x) ? 0 : isnan(y) ? 0 : x <= y)


/******************************************************************************
 *
 * The islessgreater() macro determines whether its first argument is less than
 * or greater than its second argument. The islessgreater(x, y) macro is
 * similar to (x) < (y) || (x) > (y); however, islessgreater(x, y) will not
 * raise the invalid floating-point exception when x and y are unordered
 * (nor shall it evaluate x and y twice).
 *
 * Upon successful completion, the islessgreater() macro returns the value of
 * (x) < (y) || (x) > (y). If x or y is NaN, 0 will be returned.
 *
 *****************************************************************************/
#define islessgreater(x, y) (isnan(x) ? 0 : isnan(y) ? 0 : (x < y) || (x > y))


/******************************************************************************
 *
 * The isgreater() macro determines whether its first argument is greater than
 * its second argument. The value of isgreater(x, y) is equal to (x) > (y);
 * however, unlike (x) > (y), isgreater(x, y) will not raise the invalid
 * floating-point exception when x and y are unordered.
 *
 * Upon successful completion, the isgreater() macro returns the value of
 * (x) > (y). If x or y is NaN, 0 will be returned.
 *
 *****************************************************************************/
#define isgreater(x, y) (isnan(x) ? 0 : isnan(y) ? 0 : x > y)


/******************************************************************************
 *
 * The isgreaterequal() macro determines whether its first argument is greater
 * than or equal to its second argument. The value of isgreaterequal(x, y) is
 * equal to (x) >= (y); however, unlike (x) >= (y), isgreaterequal(x, y) will
 * not raise the invalid floating-point exception when x and y are unordered.
 *
 * Upon successful completion, the isgreaterequal() macro returns the value of
 * (x) >= (y). If x or y is NaN, 0 will be returned.
 *
 *****************************************************************************/
#define isgreaterequal(x, y) (isnan(x) ? 0 : isnan(y) ? 0 : x >= y)


double acos(double x);
float acosf(float x);
long double acosl(long double x);

double ceil(double x);
float ceilf(float x);
long double ceill(long double x);

double copysign(double x, double y);
float copysignf(float x, float y);
long double copysignl(long double x, long double y);

double cos(double x);
float cosf(float x);
long double cosl(long double x);

double fabs(double x);
float fabsf(float x);
long double fabsl(long double x);

double floor(double x);
float floorf(float x);
long double floorl(long double x);

double fmod(double x, double y);
float fmodf(float x, float y);
long double fmodl(long double x, long double y);

long lrint(double x);
long lrintf(float x);
long lrintl(long double x);

long lround(double x);
long lroundf(float x);
long lroundl(long double x);

long long llrint(double x);
long long llrintf(float x);
long long llrintl(long double x);

long long llround(double x);
long long llroundf(float x);
long long llroundl(long double x);

double rint(double x);
float rintf(float x);
long double rintl(long double x);

double round(double x);
float roundf(float x);
long double roundl(long double x);

double sin(double x);
float sinf(float x);
long double sinl(long double x);

double tan(double x);
float tanf(float x);
long double tanl(long double x);

double trunc(double x);
float truncf(float x);
long double truncl(long double x);

#endif
