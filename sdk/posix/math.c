#include "math.h"

#include "errno.h"
#include "fenv.h"


/******************************************************************************
 *
 * Private Access
 *
 *****************************************************************************/


#ifdef __x86_64__
extern void acos_fpu_sp_entry();
extern void acos_fpu_dp_entry();
extern void acos_fpu_ep_entry();
//#else
const double acos_generic_a = -0.939115566365855;
const double acos_generic_b = 0.9217841528914573;
const double acos_generic_c = -1.2845906244690837;
const double acos_generic_d = 0.295624144969963174;
#endif


static inline double sin_generic(double x);
static inline float sinf_generic(float x);
static inline long double sinl_generic(long double x);



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


static inline double cos_generic(double x)
{
    return sin_generic(x + M_PI_2);
}


static inline float cosf_generic(float x)
{
    return sinf_generic(x + M_PI_2);
}


static inline long double cosl_generic(long double x)
{
    return sinl_generic(x + M_PI_2);
}


// Algorithm inspired by: http://forum.devmaster.net/t/fast-and-accurate-sine-cosine/9648
static inline double sin_generic(double x)
{
    const double B = 4 / M_PI;
    const double C = -4 / (M_PI * M_PI);
    const double P = 0.225;
    const double Q = 0.775;



    double y = B * x + C * x * fabs(x);

    return Q * y + P * y * fabs(y);
    //return P * (y * fabs(y) - y) + y;
}


// Algorithm inspired by: http://forum.devmaster.net/t/fast-and-accurate-sine-cosine/9648
static inline float sinf_generic(float x)
{
    const float B = 4 / M_PI;
    const float C = -4 / (M_PI * M_PI);
    const float P = 0.225f;

    //x = -M_PI / 

    float y = B * x + C * x * fabsf(x);

    // P * y + P * y * abs(y)
    return P * (y * fabsf(y) - y) + y;
}


// Algorithm inspired by: http://forum.devmaster.net/t/fast-and-accurate-sine-cosine/9648
static inline long double sinl_generic(long double x)
{
    const long double B = 4 / M_PI;
    const long double C = -4 / (M_PI * M_PI);
    const long double P = 0.225;

    long double y = B * x + C * x * fabsl(x);

    // P * y + P * y * abs(y)
    return P * (y * fabsl(y) - y) + y;
}


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


/*
* TBD
*/
double cos(double x)
{
    return cos_generic(x);
}


/*
* TBD
*/
float cosf(float x)
{
    return cosf_generic(x);
}


/*
* TBD
*/
long double cosl(long double x)
{
    return cosl_generic(x);
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


/*
* TBD
*/
double sin(double x)
{
    return sin_generic(x);
}


/*
* TBD
*/
float sinf(float x)
{
    return sinf_generic(x);
}


/*
* TBD
*/
long double sinl(long double x)
{
    return sinl_generic(x);
}
