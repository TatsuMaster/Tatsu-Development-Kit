#include "math.h"

#include "errno.h"
#include "fenv.h"


/******************************************************************************
 *
 * Private Access
 *
 *****************************************************************************/

typedef union
{
    float value;
    unsigned short value_segments[2];
} float_fracture;


typedef union
{
    double value;
    unsigned short value_segments[4];
} double_fracture;


#ifdef __x86_64__
extern void acos_fpu_sp_entry();
extern void acos_fpu_dp_entry();
extern void acos_fpu_ep_entry();
#else
const double acos_generic_a = -0.939115566365855;
const double acos_generic_b = 0.9217841528914573;
const double acos_generic_c = -1.2845906244690837;
const double acos_generic_d = 0.295624144969963174;
#endif


#ifndef __x86_64__
static inline double sin_generic(double x);
static inline float sinf_generic(float x);
static inline long double sinl_generic(long double x);
#endif



#ifndef __x86_64__
static inline double acos_generic(double x)
{
    const double a = acos_generic_a;
    const double b = acos_generic_b;
    const double c = acos_generic_c;
    const double d = acos_generic_d;

    // acos(x) ~ PI/2 + (ax + bx^3) / (1 + cx^2 + dx^4)
    return M_PI_2 + ((a * x) + (b * (x * x * x))) / (1 + (c * (x * x)) + (d * (x * x * x * x)));
}
#endif


#ifndef __x86_64__
static inline float acosf_generic(float x)
{
    const double a = acos_generic_a;
    const double b = acos_generic_b;
    const double c = acos_generic_c;
    const double d = acos_generic_d;

    // acos(x) ~ PI/2 + (ax + bx^3) / (1 + cx^2 + dx^4)
    return M_PI_2 + ((a * x) + (b * (x * x * x))) / (1 + (c * (x * x)) + (d * (x * x * x * x)));
}
#endif


#ifndef __x86_64__
static inline long double acosl_generic(long double x)
{
    const long double a = acos_generic_a;
    const long double b = acos_generic_b;
    const long double c = acos_generic_c;
    const long double d = acos_generic_d;

    // acos(x) ~ PI/2 + (ax + bx^3) / (1 + cx^2 + dx^4)
    return M_PI_2 + ((a * x) + (b * (x * x * x))) / (1 + (c * (x * x)) + (d * (x * x * x * x)));
}
#endif


#ifndef __x86_64__
static inline double cos_generic(double x)
{
    return sin_generic(x + M_PI_2);
}
#endif


#ifndef __x86_64__
static inline float cosf_generic(float x)
{
    return sinf_generic(x + M_PI_2);
}
#endif


#ifndef __x86_64__
static inline long double cosl_generic(long double x)
{
    return sinl_generic(x + M_PI_2);
}
#endif


#ifndef __x86_64__
// Algorithm inspired by: http://forum.devmaster.net/t/fast-and-accurate-sine-cosine/9648
static inline double sin_generic(double x)
{
    const double B = 4 / M_PI;
    const double C = -4 / (M_PI * M_PI);
    const double P = 0.225;

    // Normalize range to [-PI...PI]
    x = fmod(x + M_PI, 2 * M_PI) - M_PI;

    double y = B * x + C * x * fabs(x);

    return P * (y * fabs(y) - y) + y;
}
#endif


#ifndef __x86_64__
// Algorithm inspired by: http://forum.devmaster.net/t/fast-and-accurate-sine-cosine/9648
static inline float sinf_generic(float x)
{
    const float B = 4 / M_PI;
    const float C = -4 / (M_PI * M_PI);
    const float P = 0.225f;

    // Normalize range to [-PI...PI]
    x = fmodf(x + M_PI, 2 * M_PI) - M_PI;

    float y = B * x + C * x * fabsf(x);

    return P * (y * fabsf(y) - y) + y;
}
#endif


#ifndef __x86_64__
// Algorithm inspired by: http://forum.devmaster.net/t/fast-and-accurate-sine-cosine/9648
static inline long double sinl_generic(long double x)
{
    const long double B = 4 / M_PI;
    const long double C = -4 / (M_PI * M_PI);
    const long double P = 0.225;

    const long double EP_PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348;
    const long double EP_PI_TWO = 6.2831853071795864769252867665590057683943387987502116419498891846156328125724179972560696;

    // Normalize range to [-PI...PI]
    x = fmodl(x + EP_PI, EP_PI_TWO) - EP_PI;

    long double y = B * x + C * x * fabsl(x);

    return P * (y * fabsl(y) - y) + y;
}
#endif


/******************************************************************************
 *
 * Public Access
 *
 *****************************************************************************/


/******************************************************************************
 *
 * The functions computes the principal value of the arc cosine of its argument
 * x. The value of x should be in the range [−1,1].
 *
 * An application wishing to check for error situations should set errno to zero
 * and call feclearexcept(FE_ALL_EXCEPT) before calling this function. On
 * return, if errno is non-zero or
 * fetestexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW) is
 * nonzero, an error has occurred.
 *
 * Upon successful completion, this function returns the arc cosine of x, in
 * the range [0,M_PI] radians.
 *
 *****************************************************************************/
double acos(double x)
{
    if (x < -1.0)
    {
        feraiseexcept(FE_INVALID | FE_UNDERFLOW);
        errno = ERANGE;
        return x;
    }
    else if (x > 1.0)
    {
        feraiseexcept(FE_INVALID | FE_OVERFLOW);
        errno = ERANGE;
        return x;
    }

#ifdef __x86_64__
    __asm__ __volatile__("\t movq %0, %%xmm0" : : "g" (x));
    acos_fpu_dp_entry();
    __asm__ __volatile__("\t movq %%xmm0, %0" : "=r"(x));

    return x;
#else
    return acos_generic(x);
#endif
}


/******************************************************************************
 *
 * The functions computes the principal value of the arc cosine of its argument
 * x. The value of x should be in the range [−1,1].
 *
 * An application wishing to check for error situations should set errno to zero
 * and call feclearexcept(FE_ALL_EXCEPT) before calling this function. On
 * return, if errno is non-zero or
 * fetestexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW) is
 * nonzero, an error has occurred.
 *
 * Upon successful completion, this function returns the arc cosine of x, in
 * the range [0,M_PI] radians.
 *
 *****************************************************************************/
float acosf(float x)
{
    if (x < -1.0)
    {
        feraiseexcept(FE_INVALID | FE_UNDERFLOW);
        errno = ERANGE;
        return x;
    }
    else if (x > 1.0)
    {
        feraiseexcept(FE_INVALID | FE_OVERFLOW);
        errno = ERANGE;
        return x;
    }

#ifdef __x86_64__
    __asm__ __volatile__("\t mov %0, %%edx" : : "g" (x));
    acos_fpu_sp_entry();
    __asm__ __volatile__("\t mov %%edx, %0" : "=r"(x));

    return x;
#else
    return acosf_generic(x);
#endif
}


/******************************************************************************
 *
 * The functions computes the principal value of the arc cosine of its argument
 * x. The value of x should be in the range [−1,1].
 *
 * An application wishing to check for error situations should set errno to zero
 * and call feclearexcept(FE_ALL_EXCEPT) before calling this function. On
 * return, if errno is non-zero or
 * fetestexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW) is
 * nonzero, an error has occurred.
 *
 * Upon successful completion, this function returns the arc cosine of x, in
 * the range [0,M_PI] radians.
 *
 *****************************************************************************/
long double acosl(long double x)
{
    if (x < -1.0)
    {
        feraiseexcept(FE_INVALID | FE_UNDERFLOW);
        errno = ERANGE;
        return x;
    }
    else if (x > 1.0)
    {
        feraiseexcept(FE_INVALID | FE_OVERFLOW);
        errno = ERANGE;
        return x;
    }

#ifdef __x86_64__
    __asm__ __volatile__("\t movdqu %0, %%xmm0" : : "g" (x));
    acos_fpu_ep_entry();
    __asm__ __volatile__("\t movdqu %%xmm0, %0" : "=m"(x));

    return x;
#else
    return acosl_generic(x);
#endif
}


/******************************************************************************
 *
 * The ceil() function computes the smallest integral value not less than x.
 * Upon successful completion, this function returns the smallest integral
 * value not less than x, expressed as a double as appropriate for the return
 * type of the function.
 *
 ******************************************************************************/
double ceil(double x)
{
    return -floor(-x);
}


/******************************************************************************
 *
 * The ceilf() function computes the smallest integral value not less than x.
 * Upon successful completion, this function returns the smallest integral
 * value not less than x, expressed as a float as appropriate for the return
 * type of the function.
 *
 ******************************************************************************/
float ceilf(float x)
{
    return -floorf(-x);
}


/******************************************************************************
 *
 * The ceill() function computes the smallest integral value not less than x.
 * Upon successful completion, this function returns the smallest integral
 * value not less than x, expressed as a long double as appropriate for the
 * return type of the function.
 *
 ******************************************************************************/
long double ceill(long double x)
{
    return -floorl(-x);
}


/******************************************************************************
 *
 * The copysign function produces a value with the magnitude of x and the sign
 * of y. On implementations that represent a signed zero but do not treat
 * negative zero consistently in arithmetic operations, this function regard
 * the sign of zero as positive.
 *
 * Upon successful completion, copysign returns a value with the magnitude of
 * x and the sign of y.
 *
 ******************************************************************************/
double copysign(double x, double y)
{
    double_fracture xt, yt;
    xt.value = x;
    yt.value = y;
    xt.value_segments[3] = (
        (yt.value_segments[3] & 0x8000) | (xt.value_segments[3] & 0x7fff)
    );

    return xt.value;
}


/******************************************************************************
 *
 * The copysignf function produces a value with the magnitude of x and the sign
 * of y. On implementations that represent a signed zero but do not treat
 * negative zero consistently in arithmetic operations, this function regard
 * the sign of zero as positive.
 *
 * Upon successful completion, copysignf returns a value with the magnitude of
 * x and the sign of y.
 *
 ******************************************************************************/
float copysignf(float x, float y)
{
    float_fracture xt, yt;
    xt.value = x;
    yt.value = y;
    xt.value_segments[1] = (
        (yt.value_segments[1] & 0x8000) | (xt.value_segments[1] & 0x7fff)
    );

    return xt.value;
}


/******************************************************************************
 *
 * The copysignl function produces a value with the magnitude of x and the sign
 * of y. On implementations that represent a signed zero but do not treat
 * negative zero consistently in arithmetic operations, this function regard
 * the sign of zero as positive.
 *
 * Upon successful completion, copysignl returns a value with the magnitude of
 * x and the sign of y.
 *
 ******************************************************************************/
long double copysignl(long double x, long double y)
{
    return copysign(x, y);
}


/******************************************************************************
 *
 * The cos() function computes the cosine of its argument x, measured in
 * radians.
 *
 * Upon successful completion, this function shall return the cosine of x.
 *
 ******************************************************************************/
double cos(double x)
{
#ifdef __x86_64__
    double sin;
    __asm__ __volatile__("fldl %2;"
                         "fsincos;"
                         "fstpl %1;"
                         "fstpl %0" : "=m"(sin), "=m"(x) : "m"(x));
    return x;
#else
    return cos_generic(x);
#endif
}


/******************************************************************************
 *
 * The cosf() function computes the cosine of its argument x, measured in
 * radians.
 *
 * Upon successful completion, this function shall return the cosine of x.
 *
 ******************************************************************************/
float cosf(float x)
{
#ifdef __x86_64__
    float sin;
    __asm__ __volatile__("flds %2;"
                         "fsincos;"
                         "fstps %1;"
                         "fstps %0" : "=m"(sin), "=m"(x) : "m"(x));
    return x;
#else
    return cosf_generic(x);
#endif
}


/******************************************************************************
 *
 * The cosl() function computes the cosine of its argument x, measured in
 * radians.
 *
 * Upon successful completion, this function shall return the cosine of x.
 *
 ******************************************************************************/
long double cosl(long double x)
{
#ifdef __x86_64__
    long double sin;
    __asm__ __volatile__("fldt %2;"
                         "fsincos;"
                         "fstpt %1;"
                         "fstpt %0" : "=m"(sin), "=m"(x) : "m"(x));
    return x;
#else
    return cosl_generic(x);
#endif
}


/******************************************************************************
 *
 * The fabs() function computes the absolute value of their argument x, |x|.
 * It returns the absolute value of its double operand.
 *
 ******************************************************************************/
double fabs(double x)
{
#ifdef __x86_64__
    __asm__ __volatile__("fldl %0;"
                         "fabs;"
                         "fstpl %0" : "+m"(x));
    return x;
#else
    return (x >= 0) ? x : -x;
#endif
}


/******************************************************************************
 *
 * The fabsf() function computes the absolute value of their argument x, |x|.
 * It returns the absolute value of its double operand.
 *
 ******************************************************************************/
float fabsf(float x)
{
#ifdef __x86_64__
    __asm__ __volatile__("flds %0;"
                         "fabs;"
                         "fstps %0" : "+m"(x));
    return x;
#else
    return (x >= 0) ? x : -x;
#endif
}


/******************************************************************************
 *
 * The fabsl() function computes the absolute value of their argument x, |x|.
 * It returns the absolute value of its double operand.
 *
 ******************************************************************************/
long double fabsl(long double x)
{
#ifdef __x86_64__
    __asm__ __volatile__("fldt %0;"
                         "fabs;"
                         "fstpt %0" : "+m"(x));
    return x;
#else
    return (x >= 0) ? x : -x;
#endif
}


/******************************************************************************
 *
 * The floor() function computes the largest integral value not greater than x.
 * Upon successful completion, this function returns the largest integral value
 * not greater than x, expressed as a double as appropriate for the return type
 * of the function.
 *
 ******************************************************************************/
double floor(double x)
{
    int xi = (int)x;
    return x < xi ? xi - 1 : xi;
}


/******************************************************************************
 *
 * The floorf() function computes the largest integral value not greater than x.
 * Upon successful completion, this function returns the largest integral value
 * not greater than x, expressed as a float as appropriate for the return type
 * of the function.
 *
 ******************************************************************************/
float floorf(float x)
{
    int xi = (int)x;
    return x < xi ? xi - 1 : xi;
}


/******************************************************************************
 *
 * The floorl() function computes the largest integral value not greater than x.
 * Upon successful completion, this function returns the largest integral value
 * not greater than x, expressed as a long double as appropriate for the return
 * type of the function.
 *
 ******************************************************************************/
long double floorl(long double x)
{
    int xi = (int)x;
    return x < xi ? xi - 1 : xi;
}


/******************************************************************************
 *
 * The fmod() function returns the floating-point remainder of the division
 * of x by y.
 *
 * Upon successful completion, this functions returns the value x−i*y, for
 * some value i such that, if y is non-zero, the result has the same sign as
 * x and magnitude less than the magnitude of y.
 *
 ******************************************************************************/
double fmod(double x, double y)
{
    if (y == 0.0)
        return x;

    double m = x - y * floor(x/y);

    if (y > 0.0)
    {
        if (m >= y)
            return 0.0;

        if (m < 0.0)
        {
            if ((y + m) == y)
                return 0.0;
            else
                return y + m;
        }
    }
    else
    {
        if (m <= y)
            return 0.0;

        if (m > 0.0)
        {
            if ((y + m) == y)
                return 0.0;
            else
                return y + m;
        }
    }

    return m;
}


/******************************************************************************
 *
 * The fmodf() function returns the floating-point remainder of the division
 * of x by y.
 *
 * Upon successful completion, this functions returns the value x−i*y, for
 * some value i such that, if y is non-zero, the result has the same sign as
 * x and magnitude less than the magnitude of y.
 *
 ******************************************************************************/
float fmodf(float x, float y)
{
    if (y == 0.0f)
        return x;

    double m = x - y * floor(x/y);

    if (y > 0.0f)
    {
        if (m >= y)
            return 0.0f;

        if (m < 0.0f)
        {
            if ((y + m) == y)
                return 0.0f;
            else
                return y + m;
        }
    }
    else
    {
        if (m <= y)
            return 0.0f;

        if (m > 0.0f)
        {
            if ((y + m) == y)
                return 0.0f;
            else
                return y + m;
        }
    }

    return m;
}


/******************************************************************************
 *
 * The fmodl() function returns the floating-point remainder of the division
 * of x by y.
 *
 * Upon successful completion, this functions returns the value x−i*y, for
 * some value i such that, if y is non-zero, the result has the same sign as
 * x and magnitude less than the magnitude of y.
 *
 ******************************************************************************/
long double fmodl(long double x, long double y)
{
    if (y == 0.0)
        return x;

    double m = x - y * floor(x/y);

    if (y > 0.0)
    {
        if (m >= y)
            return 0.0;

        if (m < 0.0)
        {
            if ((y + m) == y)
                return 0.0;
            else
                return y + m;
        }
    }
    else
    {
        if (m <= y)
            return 0.0;

        if (m > 0.0)
        {
            if ((y + m) == y)
                return 0.0;
            else
                return y + m;
        }
    }

    return m;
}


/******************************************************************************
 *
 * This function rounds their argument to the nearest integer value, rounding
 * according to the current rounding direction.
 *
 * Upon successful completion, this function returns the rounded integer value.
 *
 ******************************************************************************/
long lrint(double x)
{
    return (long)rint(x);
}


/******************************************************************************
 *
 * This function rounds their argument to the nearest integer value, rounding
 * according to the current rounding direction.
 *
 * Upon successful completion, this function returns the rounded integer value.
 *
 ******************************************************************************/
long lrintf(float x)
{
    return (long)rintf(x);
}


/******************************************************************************
 *
 * This function rounds their argument to the nearest integer value, rounding
 * according to the current rounding direction.
 *
 * Upon successful completion, this function returns the rounded integer value.
 *
 ******************************************************************************/
long lrintl(long double x)
{
    return (long)rintl(x);
}


/******************************************************************************
 *
 * This function rounds their argument to the nearest integer value, rounding
 * according to the current rounding direction.
 *
 * Upon successful completion, this function returns the rounded integer value.
 *
 ******************************************************************************/
long long llrint(double x)
{
    return (long long)rint(x);
}


/******************************************************************************
 *
 * This function rounds their argument to the nearest integer value, rounding
 * according to the current rounding direction.
 *
 * Upon successful completion, this function returns the rounded integer value.
 *
 ******************************************************************************/
long long llrintf(float x)
{
    return (long long)rintf(x);
}


/******************************************************************************
 *
 * This function rounds their argument to the nearest integer value, rounding
 * according to the current rounding direction.
 *
 * Upon successful completion, this function returns the rounded integer value.
 *
 ******************************************************************************/
long long llrintl(long double x)
{
    return (long long)rintl(x);
}


/******************************************************************************
 *
 * This function returns the integral value (represented as a double) nearest
 * x in the direction of the current rounding mode.
 *
 * If the current rounding mode rounds toward negative infinity, then rint()
 * is equivalent to floor(). If the current rounding mode rounds toward positive
 * infinity, then rint() is equivalent to ceil().
 *
 * Upon successful completion, this function returns the integer
 * (represented as a double precision number) nearest x in the direction of
 * the current rounding mode.
 *
 ******************************************************************************/
double rint(double x)
{
    const int rounding = fegetround();

    if(rounding == FE_TONEAREST)
    {
        return fmod(x, 1) < 0.5 ? floor(x) : ceil(x);
    }

    if(rounding == FE_DOWNWARD)
    {
        return floor(x);
    }

    if(rounding == FE_UPWARD)
    {
        return ceil(x);
    }

    // rounding == FE_TOWARDZERO
    return fmod(x, 1) == 0.0 ? x : (x < 0.0 ? ceil(x) : floor(x));
}


/******************************************************************************
 *
 * This function returns the integral value (represented as a float) nearest
 * x in the direction of the current rounding mode.
 *
 * If the current rounding mode rounds toward negative infinity, then rintf()
 * is equivalent to floorf(). If the current rounding mode rounds toward positive
 * infinity, then rintf() is equivalent to ceilf().
 *
 * Upon successful completion, this function returns the integer
 * (represented as a single precision number) nearest x in the direction of
 * the current rounding mode.
 *
 ******************************************************************************/
float rintf(float x)
{
    const int rounding = fegetround();

    if(rounding == FE_TONEAREST)
    {
        return fmodf(x, 1) < 0.5f ? floorf(x) : ceilf(x);
    }

    if(rounding == FE_DOWNWARD)
    {
        return floorf(x);
    }

    if(rounding == FE_UPWARD)
    {
        return ceilf(x);
    }

    // rounding == FE_TOWARDZERO
    return fmodf(x, 1) == 0.0f ? x : (x < 0.0f ? ceilf(x) : floorf(x));
}


/******************************************************************************
 *
 * This function returns the integral value (represented as a long double)
 * nearest x in the direction of the current rounding mode.
 *
 * If the current rounding mode rounds toward negative infinity, then rint()
 * is equivalent to floor(). If the current rounding mode rounds toward positive
 * infinity, then rint() is equivalent to ceil().
 *
 * Upon successful completion, this function returns the integer
 * (represented as a extended precision number) nearest x in the direction of
 * the current rounding mode.
 *
 ******************************************************************************/
long double rintl(long double x)
{
    const int rounding = fegetround();

    if(rounding == FE_TONEAREST)
    {
        return fmodl(x, 1) < 0.5 ? floorl(x) : ceill(x);
    }

    if(rounding == FE_DOWNWARD)
    {
        return floorl(x);
    }

    if(rounding == FE_UPWARD)
    {
        return ceill(x);
    }

    // rounding == FE_TOWARDZERO
    return fmodl(x, 1) == 0.0 ? x : (x < 0.0 ? ceill(x) : floorl(x));
}


/******************************************************************************
 *
 * The sin() function computes the sine of its argument x, measured in
 * radians.
 *
 * Upon successful completion, this function shall return the sine of x.
 *
 ******************************************************************************/
double sin(double x)
{
#ifdef __x86_64__
    __asm__ __volatile__("fldl %0;"
                         "fsin;"
                         "fstpl %0" : "+m"(x));
    return x;
#else
    return sin_generic(x);
#endif
}


/******************************************************************************
 *
 * The sinf() function computes the sine of its argument x, measured in
 * radians.
 *
 * Upon successful completion, this function shall return the sine of x.
 *
 ******************************************************************************/
float sinf(float x)
{
#ifdef __x86_64__
    __asm__ __volatile__("flds %0;"
                         "fsin;"
                         "fstps %0" : "+m"(x));
    return x;
#else
    return sinf_generic(x);
#endif
}


/******************************************************************************
 *
 * The sinl() function computes the sine of its argument x, measured in
 * radians.
 *
 * Upon successful completion, this function shall return the sine of x.
 *
 ******************************************************************************/
long double sinl(long double x)
{
#ifdef __x86_64__
    __asm__ __volatile__("fldt %0;"
                         "fsin;"
                         "fstpt %0" : "+m"(x));
    return x;
#else
    return sinl_generic(x);
#endif
}


/******************************************************************************
 *
 * The tan() function computes the tangent of its argument x, measured in
 * radians.
 *
 * Upon successful completion, this function shall return the tangent of x.
 *
 ******************************************************************************/
double tan(double x)
{
#ifdef __x86_64__
    double tmp;
    __asm__ __volatile__("fldl %0;"
                         "fptan;"
                         "fdivrp;"
                         "fstpl %0;"
                         "fstpl %1" : "=m"(x), "=m"(tmp) : "m"(x));
    return x;
#else
    return sin(x) / cos(x);
#endif
}


/******************************************************************************
 *
 * The tanf() function computes the tangent of its argument x, measured in
 * radians.
 *
 * Upon successful completion, this function shall return the tangent of x.
 *
 ******************************************************************************/
float tanf(float x)
{
#ifdef __x86_64__
    float tmp;
    __asm__ __volatile__("flds %0;"
                         "fptan;"
                         "fdivrp;"
                         "fstps %0;"
                         "fstps %1" : "=m"(x), "=m"(tmp) : "m"(x));
    return x;
#else
    return sinf(x) / cosf(x);
#endif
}


/******************************************************************************
 *
 * The tanl() function computes the tangent of its argument x, measured in
 * radians.
 *
 * Upon successful completion, this function shall return the tangent of x.
 *
 ******************************************************************************/
long double tanl(long double x)
{
#ifdef __x86_64__
    long double tmp;
    __asm__ __volatile__("fldt %0;"
                         "fptan;"
                         "fdivrp;"
                         "fstpt %0;"
                         "fstpt %1" : "=m"(x), "=m"(tmp) : "m"(x));
    return x;
#else
    return sinl(x) / cosl(x);
#endif
}
