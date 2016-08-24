#include "math.h"


/******************************************************************************
 *
 * Private Access
 *
 *****************************************************************************/


#ifdef __x86_64__
/*extern float       sp_st0;
extern double      dp_st0;
extern long double ep_st0;*/

extern float       acos_fpu_sp_entry();
extern double      acos_fpu_dp_entry();
extern long double acos_fpu_ep_entry();
#endif


#ifndef __x86_64__
static inline double acos_generic(double x)
{
    return 0.0;
}
#endif


#ifdef __x86_64__
static inline float acosf_fast(float x)
{
    return 0.0f;
}
#else
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
*/
double acos(double x)
{
#ifdef __x86_64__
    //dp_st0 = x;
    //__asm__ __volatile__("\t movq %0, %%rdi" : : "g" (&x));
    acos_fpu_dp_entry(x);
    return x;// 42.789;
    //return dp_st0;
#else
    return acos_generic(x);
#endif
}


/*
*/
float acosf(float x)
{
#ifdef __x86_64__
    return acosf_fast(x);
#else
    return acosf_generic(x);
#endif
}


/*
*/
long double acosl(long double x)
{
#ifdef __x86_64__
    return acosl_fast(x);
#else
    return acosl_generic(x);
#endif
}