#include "posix_math_tests.h"

#include "../posix/errno.h"
#include "../posix/math.h"
#include "../../ttf/ttf.h"


void run_math_lib_tests()
{
    double x = -1.0;
    float  y = -1.0;
    long double z = -1.0;

    printf("\n\nSingle Precision Test\n");

    while(y < 1.0)
    {
        printf("%f: %f\n", y, acosf(y));
        y += 0.1;
    }

    printf("\n\nDouble Precision Test\n");

    while(x < 1.0)
    {
        printf("%lf: %lf\n", x, acos(x));
        x += 0.1;
    }

    printf("\n\nExtended Precision Test\n");

    while(z < 1.0)
    {
        printf("%Le: %Le\n", z, acosl(z));
        z += 0.1;
    }

    printf("\n\nlong double: %ld", sizeof(long double));
}
