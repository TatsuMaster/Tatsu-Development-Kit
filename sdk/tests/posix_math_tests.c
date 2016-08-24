#include "posix_math_tests.h"

#include "../posix/errno.h"
#include "../posix/math.h"
#include "../../ttf/ttf.h"


void run_math_lib_tests()
{
    printf("\n\n");
    double x = -1.0;

    while (x < 1.0)
    {
        printf("%lf: %lf\n", x, acos(x));
        x += 0.1;
    }
}