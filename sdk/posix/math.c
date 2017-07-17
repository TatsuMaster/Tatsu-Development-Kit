#include "math.h"


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



//#ifndef __x86_64__
static inline double acos_generic(double x)
{
    const double a = acos_generic_a;
    const double b = acos_generic_b;
    const double c = acos_generic_c;
    const double d = acos_generic_d;

    // acos(x) ~ PI/2 + (ax + bx^3) / (1 + cx^2 + dx^4)
    return M_PI_2 + ((a * x) + (b * (x * x * x))) / (1 + (c * (x * x)) + (d * (x * x * x * x)));
}
//#endif


//#ifndef __x86_64__
static inline float acosf_generic(float x)
{
    const double a = acos_generic_a;
    const double b = acos_generic_b;
    const double c = acos_generic_c;
    const double d = acos_generic_d;

    // acos(x) ~ PI/2 + (ax + bx^3) / (1 + cx^2 + dx^4)
    return M_PI_2 + ((a * x) + (b * (x * x * x))) / (1 + (c * (x * x)) + (d * (x * x * x * x)));
}
//#endif


//#ifndef __x86_64__
static inline long double acosl_generic(long double x)
{
    const long double a = acos_generic_a;
    const long double b = acos_generic_b;
    const long double c = acos_generic_c;
    const long double d = acos_generic_d;

    // acos(x) ~ PI/2 + (ax + bx^3) / (1 + cx^2 + dx^4)
    return M_PI_2 + ((a * x) + (b * (x * x * x))) / (1 + (c * (x * x)) + (d * (x * x * x * x)));
}
//#endif


/******************************************************************************
 *
 * Public Access
 *
 *****************************************************************************/


/*
* TODO: - Range check
* TODO: - Exception setzen, Error values etc.
*/
double acos(double x)
{
/*#ifdef __x86_64__
    __asm__ __volatile__("\t movq %0, %%xmm0" : : "g" (x));
    acos_fpu_dp_entry();
    __asm__ __volatile__("\t movq %%xmm0, %0" : "=r"(x));

    return x;
#else*/
    return acos_generic(x);
//#endif
}


/*
*/
float acosf(float x)
{
/*#ifdef __x86_64__
    __asm__ __volatile__("\t mov %0, %%edx" : : "g" (x));
    acos_fpu_sp_entry();
    __asm__ __volatile__("\t mov %%edx, %0" : "=r"(x));

    return x;
#else*/
    return acosf_generic(x);
//#endif
}


/*
*/
long double acosl(long double x)
{
/*#ifdef __x86_64__
    acos_fpu_ep_entry();
    return x;
#else*/
    return acosl_generic(x);
//#endif
}
