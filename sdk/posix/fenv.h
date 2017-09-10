#ifndef FENV_H
#define FENV_H


#define FE_DIVBYZERO  4
#define FE_INEXACT    32
#define FE_INVALID    1
#define FE_OVERFLOW   8
#define FE_UNDERFLOW  16
#define FE_DOWNWARD   1024
#define FE_TONEAREST  0
#define FE_TOWARDZERO 3072
#define FE_UPWARD     2048

#define FE_ALL_EXCEPT (FE_DIVBYZERO | FE_INEXACT | FE_INVALID | FE_OVERFLOW | FE_UNDERFLOW | FE_DOWNWARD | FE_TONEAREST | FE_TOWARDZERO | FE_UPWARD)


int feclearexcept(int excepts);
int fetestexcept(int excepts);
int feraiseexcept(int excepts);

int fegetround();
int fesetround(int round);

#endif
