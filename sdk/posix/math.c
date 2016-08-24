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
#endif


#ifndef __x86_64__
static inline double acos_generic(double x)
{
    return 0.0;
}
#endif


#ifndef __x86_64__
static inline float acosf_generic(float x)
{
    return 0.0f;
}
#endif


#ifdef __x86_64__
static inline long double acosl_fast(long double x)
{
    return 0.0;
}
#else
static inline long double acosl_generic(long double x)
{
    return 0.0;
}
#endif


/******************************************************************************
 *
 * Public Access
 *
 *****************************************************************************/


/*
* TODO: - Rang check
* TODO: - Exception setzen, Error values etc.
* TODO: - TTF erweitern
*/
double acos(double x)
{
#ifdef __x86_64__
    __asm__ __volatile__("\t movq %0, %%xmm0" : : "g" (x));
    acos_fpu_dp_entry();
    __asm__ __volatile__("\t movq %%xmm0, %0" : "=r"(x));

    return x;
#else
    return acos_generic(x);
#endif
}


/*
*/
float acosf(float x)
{
#ifdef __x86_64__
    __asm__ __volatile__("\t mov %0, %%edx" : : "g" (x));
    acos_fpu_sp_entry();
    __asm__ __volatile__("\t mov %%edx, %0" : "=r"(x));

    return x;
#else
    return acosf_generic(x);
#endif
}


/*
*/
long double acosl(long double x)
{
#ifdef __x86_64__
    /*__asm__ __volatile__("\t movdqa %0, %%xmm0" : : "g" (x));
    acos_fpu_ep_entry();
    __asm__ __volatile__("\t movdqa %%xmm0, %0" : "=r"(x));*/

    return x;
#else
    return acosl_generic(x);
#endif
}
