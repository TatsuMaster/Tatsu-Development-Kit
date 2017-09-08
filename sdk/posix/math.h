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


double acos(double x);
float acosf(float x);
long double acosl(long double x);

double ceil(double x);
float ceilf(float x);
long double ceill(long double x);

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

double sin(double x);
float sinf(float x);
long double sinl(long double x);

#endif
