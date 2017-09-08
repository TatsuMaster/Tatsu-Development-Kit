#include "posix_math_tests.h"

#include "../posix/fenv.h"
#include "../posix/errno.h"
#include "../posix/math.h"
#include "../../ttf/ttf.h"


static void test_acos()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("acos: Checking, if return value of acos(-1.0) is correct", acos(-1.0), 3.13, 3.15);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(-0.9) is correct", acos(-0.9), 2.68, 2.70);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(-0.8) is correct", acos(-0.8), 2.48, 2.51);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(-0.7) is correct", acos(-0.7), 2.33, 2.35);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(-0.6) is correct", acos(-0.6), 2.19, 2.22);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(-0.5) is correct", acos(-0.5), 2.06, 2.10);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(-0.4) is correct", acos(-0.4), 1.95, 1.99);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(-0.3) is correct", acos(-0.3), 1.85, 1.88);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(-0.2) is correct", acos(-0.2), 1.75, 1.78);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(-0.1) is correct", acos(-0.1), 1.65, 1.68);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(0.0) is correct", acos(0.0), 1.56, 1.58);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(0.1) is correct", acos(0.1), 1.46, 1.48);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(0.2) is correct", acos(0.2), 1.35, 1.39);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(0.3) is correct", acos(0.3), 1.25, 1.29);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(0.4) is correct", acos(0.4), 1.14, 1.18);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(0.5) is correct", acos(0.5), 1.00, 1.10);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(0.6) is correct", acos(0.6), 0.91, 0.94);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(0.7) is correct", acos(0.7), 0.78, 0.80);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(0.8) is correct", acos(0.8), 0.62, 0.65);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(0.9) is correct", acos(0.9), 0.43, 0.46);
    ASSERT_IN_RANGE("acos: Checking, if return value of acos(1.0) is correct", acos(1.0), 0.00, 0.10);
    ASSERT_EQUALS("acos: Checking, if errno is unmodified", pre_errno, errno);

    acos(-1.2);
    ASSERT_EQUALS("acos: Checking, if errno is set to ERANGE for acos calls using numbers < -1.0", ERANGE, errno);
    ASSERT_EQUALS("acos: Checking, if FE_INVALID and FE_UNDERFLOW are raised for acos calls using numbers < -1.0", fetestexcept(FE_INVALID | FE_UNDERFLOW), (FE_INVALID | FE_UNDERFLOW));

    errno = 0;
    feclearexcept(FE_ALL_EXCEPT);

    acos(1.2);
    ASSERT_EQUALS("acos: Checking, if errno is set to ERANGE for acos calls using numbers > 1.0", ERANGE, errno);
    ASSERT_EQUALS("acos: Checking, if FE_INVALID and FE_OVERFLOW are raised for acos calls using numbers > 1.0", fetestexcept(FE_INVALID | FE_OVERFLOW), (FE_INVALID | FE_OVERFLOW));

    errno = 0;
    feclearexcept(FE_ALL_EXCEPT);
}


static void test_acosf()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(-1.0f) is correct", acosf(-1.0f), 3.13f, 3.15f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(-0.9f) is correct", acosf(-0.9f), 2.68f, 2.70f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(-0.8f) is correct", acosf(-0.8f), 2.48f, 2.51f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(-0.7f) is correct", acosf(-0.7f), 2.33f, 2.35f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(-0.6f) is correct", acosf(-0.6f), 2.19f, 2.22f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(-0.5f) is correct", acosf(-0.5f), 2.06f, 2.10f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(-0.4f) is correct", acosf(-0.4f), 1.95f, 1.99f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(-0.3f) is correct", acosf(-0.3f), 1.85f, 1.88f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(-0.2f) is correct", acosf(-0.2f), 1.75f, 1.78f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(-0.1f) is correct", acosf(-0.1f), 1.65f, 1.68f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(0.0f) is correct", acosf(0.0f), 1.56f, 1.58f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(0.1f) is correct", acosf(0.1f), 1.46f, 1.48f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(0.2f) is correct", acosf(0.2f), 1.35f, 1.39f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(0.3f) is correct", acosf(0.3f), 1.25f, 1.29f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(0.4f) is correct", acosf(0.4f), 1.14f, 1.18f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(0.5f) is correct", acosf(0.5f), 1.00f, 1.10f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(0.6f) is correct", acosf(0.6f), 0.91f, 0.94f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(0.7f) is correct", acosf(0.7f), 0.78f, 0.80f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(0.8f) is correct", acosf(0.8f), 0.62f, 0.65f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(0.9f) is correct", acosf(0.9f), 0.43f, 0.46f);
    ASSERT_IN_RANGE("acosf: Checking, if return value of acosf(1.0f) is correct", acosf(1.0f), 0.00f, 0.10f);
    ASSERT_EQUALS("acosf: Checking, if errno is unmodified", pre_errno, errno);

    acosf(-1.2f);
    ASSERT_EQUALS("acosf: Checking, if errno is set to ERANGE for acosf calls using numbers < -1.0", ERANGE, errno);
    ASSERT_EQUALS("acosf: Checking, if FE_INVALID and FE_UNDERFLOW are raised for acosf calls using numbers < -1.0", fetestexcept(FE_INVALID | FE_UNDERFLOW), (FE_INVALID | FE_UNDERFLOW));

    errno = 0;
    feclearexcept(FE_ALL_EXCEPT);

    acosf(1.2f);
    ASSERT_EQUALS("acosf: Checking, if errno is set to ERANGE for acosf calls using numbers > 1.0", ERANGE, errno);
    ASSERT_EQUALS("acosf: Checking, if FE_INVALID and FE_OVERFLOW are raised for acosf calls using numbers > 1.0", fetestexcept(FE_INVALID | FE_OVERFLOW), (FE_INVALID | FE_OVERFLOW));

    errno = 0;
    feclearexcept(FE_ALL_EXCEPT);
}


static void test_acosl()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(-1.0) is correct", acosl(-1.0), 3.13, 3.15);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(-0.9) is correct", acosl(-0.9), 2.68, 2.70);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(-0.8) is correct", acosl(-0.8), 2.48, 2.51);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(-0.7) is correct", acosl(-0.7), 2.33, 2.35);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(-0.6) is correct", acosl(-0.6), 2.19, 2.22);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(-0.5) is correct", acosl(-0.5), 2.06, 2.10);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(-0.4) is correct", acosl(-0.4), 1.95, 1.99);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(-0.3) is correct", acosl(-0.3), 1.85, 1.88);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(-0.2) is correct", acosl(-0.2), 1.75, 1.78);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(-0.1) is correct", acosl(-0.1), 1.65, 1.68);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(0.0) is correct", acosl(0.0), 1.56, 1.58);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(0.1) is correct", acosl(0.1), 1.46, 1.48);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(0.2) is correct", acosl(0.2), 1.35, 1.39);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(0.3) is correct", acosl(0.3), 1.25, 1.29);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(0.4) is correct", acosl(0.4), 1.14, 1.18);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(0.5) is correct", acosl(0.5), 1.00, 1.10);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(0.6) is correct", acosl(0.6), 0.91, 0.94);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(0.7) is correct", acosl(0.7), 0.78, 0.80);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(0.8) is correct", acosl(0.8), 0.62, 0.65);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(0.9) is correct", acosl(0.9), 0.43, 0.46);
    ASSERT_IN_RANGE("acosl: Checking, if return value of acosl(1.0) is correct", acosl(1.0), 0.00, 0.10);
    ASSERT_EQUALS("acosl: Checking, if errno is unmodified", pre_errno, errno);

    acosl(-1.2);
    ASSERT_EQUALS("acosl: Checking, if errno is set to ERANGE for acosl calls using numbers < -1.0", ERANGE, errno);
    ASSERT_EQUALS("acosl: Checking, if FE_INVALID and FE_UNDERFLOW are raised for acosl calls using numbers < -1.0", fetestexcept(FE_INVALID | FE_UNDERFLOW), (FE_INVALID | FE_UNDERFLOW));

    errno = 0;
    feclearexcept(FE_ALL_EXCEPT);

    acosl(1.2);
    ASSERT_EQUALS("acosl: Checking, if errno is set to ERANGE for acosl calls using numbers > 1.0", ERANGE, errno);
    ASSERT_EQUALS("acosl: Checking, if FE_INVALID and FE_OVERFLOW are raised for acosl calls using numbers > 1.0", fetestexcept(FE_INVALID | FE_OVERFLOW), (FE_INVALID | FE_OVERFLOW));

    errno = 0;
    feclearexcept(FE_ALL_EXCEPT);
}


static void test_cos()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("cos: Checking, if cos(-(2 * M_PI)) returns 1.0", cos(-(2 * M_PI)), 0.9, 1.1);
    ASSERT_IN_RANGE("cos: Checking, if cos(-(3 * M_PI_2)) returns 0.0", cos(-(3 * M_PI_2)), -0.1, 0.1);
    ASSERT_IN_RANGE("cos: Checking, if cos(-M_PI) returns -1.0", cos(-M_PI), -1.1, -0.9);
    ASSERT_IN_RANGE("cos: Checking, if cos(-M_PI_2) returns 0.0", cos(-M_PI_2), -0.1, 0.1);
    ASSERT_IN_RANGE("cos: Checking, if cos(0.0) returns 1.0", cos(0.0), 0.9, 1.1);
    ASSERT_IN_RANGE("cos: Checking, if cos(M_PI_2) returns 0.0", cos(M_PI_2), -0.1, 0.1);
    ASSERT_IN_RANGE("cos: Checking, if cos(M_PI) returns -1.0", cos(M_PI), -1.1, -0.9);
    ASSERT_IN_RANGE("cos: Checking, if cos(3 * M_PI_2) returns 0.0", cos(3 * M_PI_2), -0.1, 0.1);
    ASSERT_IN_RANGE("cos: Checking, if cos(2 * M_PI) returns 1.0", cos(2 * M_PI), 0.9, 1.1);
    ASSERT_EQUALS("cos: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_cosf()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("cosf: Checking, if cosf(-(2 * M_PI)) returns 1.0f", cosf(-(2 * M_PI)), 0.9f, 1.1f);
    ASSERT_IN_RANGE("cosf: Checking, if cosf(-(3 * M_PI_2)) returns 0.0f", cosf(-(3 * M_PI_2)), -0.1f, 0.1f);
    ASSERT_IN_RANGE("cosf: Checking, if cosf(-M_PI) returns -1.0f", cosf(-M_PI), -1.1f, -0.9f);
    ASSERT_IN_RANGE("cosf: Checking, if cosf(-M_PI_2) returns 0.0f", cosf(-M_PI_2), -0.1f, 0.1f);
    ASSERT_IN_RANGE("cosf: Checking, if cosf(0.0f) returns 1.0f", cosf(0.0), 0.9f, 1.1f);
    ASSERT_IN_RANGE("cosf: Checking, if cosf(M_PI_2) returns 0.0f", cosf(M_PI_2), -0.1f, 0.1f);
    ASSERT_IN_RANGE("cosf: Checking, if cosf(M_PI) returns -1.0f", cosf(M_PI), -1.1f, -0.9f);
    ASSERT_IN_RANGE("cosf: Checking, if cosf(3 * M_PI_2) returns 0.0f", cosf(3 * M_PI_2), -0.1f, 0.1f);
    ASSERT_IN_RANGE("cosf: Checking, if cosf(2 * M_PI) returns 1.0f", cosf(2 * M_PI), 0.9f, 1.1f);
    ASSERT_EQUALS("cosf: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_cosl()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("cosl: Checking, if cosl(-(2 * M_PI)) returns 1.0", cosl(-(2 * M_PI)), 0.9, 1.1);
    ASSERT_IN_RANGE("cosl: Checking, if cosl(-(3 * M_PI_2)) returns 0.0", cosl(-(3 * M_PI_2)), -0.1, 0.1);
    ASSERT_IN_RANGE("cosl: Checking, if cosl(-M_PI) returns -1.0", cosl(-M_PI), -1.1, -0.9);
    ASSERT_IN_RANGE("cosl: Checking, if cosl(-M_PI_2) returns 0.0", cosl(-M_PI_2), -0.1, 0.1);
    ASSERT_IN_RANGE("cosl: Checking, if cosl(0.0f) returns 1.0", cosl(0.0), 0.9, 1.1);
    ASSERT_IN_RANGE("cosl: Checking, if cosl(M_PI_2) returns 0.0", cosl(M_PI_2), -0.1, 0.1);
    ASSERT_IN_RANGE("cosl: Checking, if cosl(M_PI) returns -1.0", cosl(M_PI), -1.1, -0.9);
    ASSERT_IN_RANGE("cosl: Checking, if cosl(3 * M_PI_2) returns 0.0", cosl(3 * M_PI_2), -0.1, 0.1);
    ASSERT_IN_RANGE("cosl: Checking, if cosl(2 * M_PI) returns 1.0", cosl(2 * M_PI), 0.9, 1.1);
    ASSERT_EQUALS("cosl: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_ceil()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("ceil: Checking, if ceil(0.5) returns 1.0", ceil(0.5), 1.0);
    ASSERT_EQUALS("ceil: Checking, if ceil(1.5) returns 2.0", ceil(1.5), 2.0);
    ASSERT_EQUALS("ceil: Checking, if ceil(1.6) returns 2.0", ceil(1.6), 2.0);
    ASSERT_EQUALS("ceil: Checking, if ceil(0.4) returns 1.0", ceil(0.4), 1.0);
    ASSERT_EQUALS("ceil: Checking, if ceil(17.13339) returns 18.0", ceil(17.13339), 18.0);
    ASSERT_EQUALS("ceil: Checking, if ceil(17.93339) returns 18.0", ceil(17.93339), 18.0);
    ASSERT_EQUALS("ceil: Checking, if ceil(-0.5) returns -0.0", ceil(-0.5), -0.0);
    ASSERT_EQUALS("ceil: Checking, if ceil(-1.5) returns -1.0", ceil(-1.5), -1.0);
    ASSERT_EQUALS("ceil: Checking, if ceil(-1.6) returns -1.0", ceil(-1.6), -1.0);
    ASSERT_EQUALS("ceil: Checking, if ceil(-0.4) returns -0.0", ceil(-0.4), -0.0);
    ASSERT_EQUALS("ceil: Checking, if ceil(-17.13339) returns -17.0", ceil(-17.13339), -17.0);
    ASSERT_EQUALS("ceil: Checking, if ceil(-17.93339) returns -17.0", ceil(-17.93339), -17.0);
    ASSERT_EQUALS("ceil: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_ceilf()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("ceilf: Checking, if ceilf(0.5f) returns 1.0f", ceilf(0.5f), 1.0f);
    ASSERT_EQUALS("ceilf: Checking, if ceilf(1.5f) returns 2.0f", ceilf(1.5f), 2.0f);
    ASSERT_EQUALS("ceilf: Checking, if ceilf(1.6f) returns 2.0f", ceilf(1.6f), 2.0f);
    ASSERT_EQUALS("ceilf: Checking, if ceilf(0.4f) returns 1.0f", ceilf(0.4f), 1.0f);
    ASSERT_EQUALS("ceilf: Checking, if ceilf(17.13339f) returns 18.0f", ceilf(17.13339f), 18.0f);
    ASSERT_EQUALS("ceilf: Checking, if ceilf(17.93339f) returns 18.0f", ceilf(17.93339f), 18.0f);
    ASSERT_EQUALS("ceilf: Checking, if ceilf(-0.5f) returns -0.0f", ceilf(-0.5f), -0.0f);
    ASSERT_EQUALS("ceilf: Checking, if ceilf(-1.5f) returns -1.0f", ceilf(-1.5f), -1.0f);
    ASSERT_EQUALS("ceilf: Checking, if ceilf(-1.6f) returns -1.0f", ceilf(-1.6f), -1.0f);
    ASSERT_EQUALS("ceilf: Checking, if ceilf(-0.4f) returns -0.0f", ceilf(-0.4f), -0.0f);
    ASSERT_EQUALS("ceilf: Checking, if ceilf(-17.13339f) returns -17.0f", ceilf(-17.13339f), -17.0f);
    ASSERT_EQUALS("ceilf: Checking, if ceilf(-17.93339f) returns -17.0f", ceilf(-17.93339f), -17.0f);
    ASSERT_EQUALS("ceilf: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_ceill()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("ceill: Checking, if ceill(0.5) returns 1.0", ceill(0.5), 1.0);
    ASSERT_EQUALS("ceill: Checking, if ceill(1.5) returns 2.0", ceill(1.5), 2.0);
    ASSERT_EQUALS("ceill: Checking, if ceill(1.6) returns 2.0", ceill(1.6), 2.0);
    ASSERT_EQUALS("ceill: Checking, if ceill(0.4) returns 1.0", ceill(0.4), 1.0);
    ASSERT_EQUALS("ceill: Checking, if ceill(17.13339) returns 18.0", ceill(17.13339), 18.0);
    ASSERT_EQUALS("ceill: Checking, if ceill(17.93339) returns 18.0", ceill(17.93339), 18.0);
    ASSERT_EQUALS("ceill: Checking, if ceill(-0.5) returns -0.0", ceill(-0.5), -0.0);
    ASSERT_EQUALS("ceill: Checking, if ceill(-1.5) returns -1.0", ceill(-1.5), -1.0);
    ASSERT_EQUALS("ceill: Checking, if ceill(-1.6) returns -1.0", ceill(-1.6), -1.0);
    ASSERT_EQUALS("ceill: Checking, if ceill(-0.4) returns -0.0", ceill(-0.4), -0.0);
    ASSERT_EQUALS("ceill: Checking, if ceill(-17.13339) returns -17.0", ceill(-17.13339), -17.0);
    ASSERT_EQUALS("ceill: Checking, if ceill(-17.93339) returns -17.0", ceill(-17.93339), -17.0);
    ASSERT_EQUALS("ceill: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_fabs()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("fabs: Checking, if fabs(0.0) returns 0.0", fabs(0.0), 0.0);
    ASSERT_EQUALS("fabs: Checking, if fabs(1.0) returns 1.0", fabs(1.0), 1.0);
    ASSERT_EQUALS("fabs: Checking, if fabs(-1.0) returns 1.0", fabs(-1.0), 1.0);
    ASSERT_EQUALS("fabs: Checking, if fabs(47.11) returns 47.11", fabs(47.11), 47.11);
    ASSERT_EQUALS("fabs: Checking, if fabs(-47.11) returns 47.11", fabs(-47.11), 47.11);
    ASSERT_EQUALS("fabs: Checking, if fabs(128.256) returns 128.256", fabs(128.256), 128.256);
    ASSERT_EQUALS("fabs: Checking, if fabs(-128.256) returns 128.256", fabs(-128.256), 128.256);
    ASSERT_EQUALS("fabs: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_fabsf()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("fabs: Checking, if fabsf(0.0f) returns 0.0f", fabsf(0.0f), 0.0f);
    ASSERT_EQUALS("fabs: Checking, if fabsf(1.0f) returns 1.0f", fabsf(1.0f), 1.0f);
    ASSERT_EQUALS("fabs: Checking, if fabsf(-1.0f) returns 1.0f", fabsf(-1.0f), 1.0f);
    ASSERT_EQUALS("fabs: Checking, if fabsf(47.11f) returns 47.11f", fabsf(47.11f), 47.11f);
    ASSERT_EQUALS("fabs: Checking, if fabsf(-47.11f) returns 47.11f", fabsf(-47.11f), 47.11f);
    ASSERT_EQUALS("fabs: Checking, if fabsf(128.256f) returns 128.256f", fabsf(128.256f), 128.256f);
    ASSERT_EQUALS("fabs: Checking, if fabsf(-128.256f) returns 128.256f", fabsf(-128.256f), 128.256f);
    ASSERT_EQUALS("labs: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_fabsl()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("fabsl: Checking, if fabsl(0.0) returns 0.0", fabsl(0.0), 0.0);
    ASSERT_EQUALS("fabsl: Checking, if fabsl(1.0) returns 1.0", fabsl(1.0), 1.0);
    ASSERT_EQUALS("fabsl: Checking, if fabsl(-1.0) returns 1.0", fabsl(-1.0), 1.0);
    ASSERT_EQUALS("fabsl: Checking, if fabsl(47.11) returns 47.11", fabsl(47.11), 47.11);
    ASSERT_EQUALS("fabsl: Checking, if fabsl(-47.11) returns 47.11", fabsl(-47.11), 47.11);
    ASSERT_EQUALS("fabsl: Checking, if fabsl(128.256) returns 128.256", fabsl(128.256), 128.256);
    ASSERT_EQUALS("fabsl: Checking, if fabsl(-128.256) returns 128.256", fabsl(-128.256), 128.256);
    ASSERT_EQUALS("fabsl: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_floor()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("floor: Checking, if floor(0.5) returns 0.0", floor(0.5), 0.0);
    ASSERT_EQUALS("floor: Checking, if floor(1.5) returns 1.0", floor(1.5), 1.0);
    ASSERT_EQUALS("floor: Checking, if floor(1.6) returns 1.0", floor(1.6), 1.0);
    ASSERT_EQUALS("floor: Checking, if floor(0.4) returns 0.0", floor(0.4), 0.0);
    ASSERT_EQUALS("floor: Checking, if floor(17.13339) returns 17.0", floor(17.13339), 17.0);
    ASSERT_EQUALS("floor: Checking, if floor(17.93339) returns 17.0", floor(17.93339), 17.0);
    ASSERT_EQUALS("floor: Checking, if floor(-0.5) returns -1.0", floor(-0.5), -1.0);
    ASSERT_EQUALS("floor: Checking, if floor(-1.5) returns -2.0", floor(-1.5), -2.0);
    ASSERT_EQUALS("floor: Checking, if floor(-1.6) returns -2.0", floor(-1.6), -2.0);
    ASSERT_EQUALS("floor: Checking, if floor(-0.4) returns -1.0", floor(-0.4), -1.0);
    ASSERT_EQUALS("floor: Checking, if floor(-17.13339) returns -18.0", floor(-17.13339), -18.0);
    ASSERT_EQUALS("floor: Checking, if floor(-17.93339) returns -18.0", floor(-17.93339), -18.0);
    ASSERT_EQUALS("floor: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_floorf()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("floorf: Checking, if floorf(0.5f) returns 0.0f", floorf(0.5f), 0.0f);
    ASSERT_EQUALS("floorf: Checking, if floorf(1.5f) returns 1.0f", floorf(1.5f), 1.0f);
    ASSERT_EQUALS("floorf: Checking, if floorf(1.6f) returns 1.0f", floorf(1.6f), 1.0f);
    ASSERT_EQUALS("floorf: Checking, if floorf(0.4f) returns 0.0f", floorf(0.4f), 0.0f);
    ASSERT_EQUALS("floorf: Checking, if floorf(17.13339f) returns 17.0f", floorf(17.13339f), 17.0f);
    ASSERT_EQUALS("floorf: Checking, if floorf(17.93339f) returns 17.0f", floorf(17.93339f), 17.0f);
    ASSERT_EQUALS("floorf: Checking, if floorf(-0.5f) returns -1.0f", floorf(-0.5f), -1.0f);
    ASSERT_EQUALS("floorf: Checking, if floorf(-1.5f) returns -2.0f", floorf(-1.5f), -2.0f);
    ASSERT_EQUALS("floorf: Checking, if floorf(-1.6f) returns -2.0f", floorf(-1.6f), -2.0f);
    ASSERT_EQUALS("floorf: Checking, if floorf(-0.4f) returns -1.0f", floorf(-0.4f), -1.0f);
    ASSERT_EQUALS("floorf: Checking, if floorf(-17.13339f) returns -18.0f", floorf(-17.13339f), -18.0f);
    ASSERT_EQUALS("floorf: Checking, if floorf(-17.93339f) returns -18.0f", floorf(-17.93339f), -18.0f);
    ASSERT_EQUALS("floorf: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_floorl()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("floorl: Checking, if floorl(0.5) returns 0.0", floorl(0.5), 0.0);
    ASSERT_EQUALS("floorl: Checking, if floorl(1.5) returns 1.0", floorl(1.5), 1.0);
    ASSERT_EQUALS("floorl: Checking, if floorl(1.6) returns 1.0", floorl(1.6), 1.0);
    ASSERT_EQUALS("floorl: Checking, if floorl(0.4) returns 0.0", floorl(0.4), 0.0);
    ASSERT_EQUALS("floorl: Checking, if floorl(17.13339) returns 17.0", floorl(17.13339), 17.0);
    ASSERT_EQUALS("floorl: Checking, if floorl(17.93339) returns 17.0", floorl(17.93339), 17.0);
    ASSERT_EQUALS("floorl: Checking, if floorl(-0.5) returns -1.0", floorl(-0.5), -1.0);
    ASSERT_EQUALS("floorl: Checking, if floorl(-1.5) returns -2.0", floorl(-1.5), -2.0);
    ASSERT_EQUALS("floorl: Checking, if floorl(-1.6) returns -2.0", floorl(-1.6), -2.0);
    ASSERT_EQUALS("floorl: Checking, if floorl(-0.4) returns -1.0", floorl(-0.4), -1.0);
    ASSERT_EQUALS("floorl: Checking, if floorl(-17.13339) returns -18.0", floorl(-17.13339), -18.0);
    ASSERT_EQUALS("floorl: Checking, if floorl(-17.93339) returns -18.0", floorl(-17.93339), -18.0);
    ASSERT_EQUALS("floorl: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_fmax()
{
    const int pre_errno = errno;
    
    ASSERT_EQUALS("fmax: Checking, if fmax(-1.0, 0.0) returns 0.0", fmax(-1.0, 0.0), 0.0);
    ASSERT_EQUALS("fmax: Checking, if fmax(1.0, 0.0) returns 1.0", fmax(1.0, 0.0), 1.0);
    ASSERT_EQUALS("fmax: Checking, if fmax(1.0, -1.0) returns 1.0", fmax(1.0, -1.0), 1.0);
    ASSERT_EQUALS("fmax: Checking, if fmax(1.0, 21.0) returns 21.0", fmax(1.0, 21.0), 21.0);
    ASSERT_EQUALS("fmax: Checking, if fmax(0.0, 0.0) returns 0.0", fmax(0.0, 0.0), 0.0);
    ASSERT_EQUALS("fmax: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_fmaxf()
{
    const int pre_errno = errno;
    
    ASSERT_EQUALS("fmaxf: Checking, if fmaxf(-1.0, 0.0) returns 0.0", fmaxf(-1.0, 0.0), 0.0);
    ASSERT_EQUALS("fmaxf: Checking, if fmaxf(1.0, 0.0) returns 1.0", fmaxf(1.0, 0.0), 1.0);
    ASSERT_EQUALS("fmaxf: Checking, if fmaxf(1.0, -1.0) returns 1.0", fmaxf(1.0, -1.0), 1.0);
    ASSERT_EQUALS("fmaxf: Checking, if fmaxf(1.0, 21.0) returns 21.0", fmaxf(1.0, 21.0), 21.0);
    ASSERT_EQUALS("fmaxf: Checking, if fmaxf(0.0, 0.0) returns 0.0", fmaxf(0.0, 0.0), 0.0);
    ASSERT_EQUALS("fmaxf: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_fmaxl()
{
    const int pre_errno = errno;
    
    ASSERT_EQUALS("fmaxl: Checking, if fmaxl(-1.0, 0.0) returns 0.0", fmaxl(-1.0, 0.0), 0.0);
    ASSERT_EQUALS("fmaxl: Checking, if fmaxl(1.0, 0.0) returns 1.0", fmaxl(1.0, 0.0), 1.0);
    ASSERT_EQUALS("fmaxl: Checking, if fmaxl(1.0, -1.0) returns 1.0", fmaxl(1.0, -1.0), 1.0);
    ASSERT_EQUALS("fmaxl: Checking, if fmaxl(1.0, 21.0) returns 21.0", fmaxl(1.0, 21.0), 21.0);
    ASSERT_EQUALS("fmaxl: Checking, if fmaxl(0.0, 0.0) returns 0.0", fmaxl(0.0, 0.0), 0.0);
    ASSERT_EQUALS("fmaxl: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_fmin()
{
    const int pre_errno = errno;
    
    ASSERT_EQUALS("fmin: Checking, if fmin(-1.0, 0.0) returns 0.0", fmin(-1.0, 0.0), -1.0);
    ASSERT_EQUALS("fmin: Checking, if fmin(1.0, 0.0) returns 1.0", fmin(1.0, 0.0), 0.0);
    ASSERT_EQUALS("fmin: Checking, if fmin(1.0, -1.0) returns 1.0", fmin(1.0, -1.0), -1.0);
    ASSERT_EQUALS("fmin: Checking, if fmin(1.0, 21.0) returns 21.0", fmin(1.0, 21.0), 1.0);
    ASSERT_EQUALS("fmin: Checking, if fmin(0.0, 0.0) returns 0.0", fmin(0.0, 0.0), 0.0);
    ASSERT_EQUALS("fmin: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_fminf()
{
    const int pre_errno = errno;
    
    ASSERT_EQUALS("fminf: Checking, if fminf(-1.0, 0.0) returns 0.0", fminf(-1.0, 0.0), -1.0);
    ASSERT_EQUALS("fminf: Checking, if fminf(1.0, 0.0) returns 1.0", fminf(1.0, 0.0), 0.0);
    ASSERT_EQUALS("fminf: Checking, if fminf(1.0, -1.0) returns 1.0", fminf(1.0, -1.0), -1.0);
    ASSERT_EQUALS("fminf: Checking, if fminf(1.0, 21.0) returns 21.0", fminf(1.0, 21.0), 1.0);
    ASSERT_EQUALS("fminf: Checking, if fminf(0.0, 0.0) returns 0.0", fminf(0.0, 0.0), 0.0);
    ASSERT_EQUALS("fminf: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_fminl()
{
    const int pre_errno = errno;
    
    ASSERT_EQUALS("fminl: Checking, if fminl(-1.0, 0.0) returns 0.0", fminl(-1.0, 0.0), -1.0);
    ASSERT_EQUALS("fminl: Checking, if fminl(1.0, 0.0) returns 1.0", fminl(1.0, 0.0), 0.0);
    ASSERT_EQUALS("fminl: Checking, if fminl(1.0, -1.0) returns 1.0", fminl(1.0, -1.0), -1.0);
    ASSERT_EQUALS("fminl: Checking, if fminl(1.0, 21.0) returns 21.0", fminl(1.0, 21.0), 1.0);
    ASSERT_EQUALS("fminl: Checking, if fminl(0.0, 0.0) returns 0.0", fminl(0.0, 0.0), 0.0);
    ASSERT_EQUALS("fminl: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_fmod()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("fmod: Checking, if fmod(0.5, M_PI) returns 0.5", fmod(0.5, M_PI), 0.499, 0.501);
    ASSERT_IN_RANGE("fmod: Checking, if fmod(1.5, M_PI) returns 1.5", fmod(1.5, M_PI), 1.499, 1.501);
    ASSERT_IN_RANGE("fmod: Checking, if fmod(1.6, M_PI) returns 1.6", fmod(1.6, M_PI), 1.599, 1.601);
    ASSERT_IN_RANGE("fmod: Checking, if fmod(0.4, M_PI) returns 0.4", fmod(0.4, M_PI), 0.399, 0.401);
    ASSERT_IN_RANGE("fmod: Checking, if fmod(17.13339, M_PI) returns 1.425427", fmod(17.13339, M_PI), 1.424, 1.426);
    ASSERT_IN_RANGE("fmod: Checking, if fmod(17.93339, M_PI) returns 2.225427", fmod(17.93339, M_PI), 2.224, 2.226);
    ASSERT_IN_RANGE("fmod: Checking, if fmod(-0.5, M_PI) returns 2.641593", fmod(-0.5, M_PI), 2.640, 2.642);
    ASSERT_IN_RANGE("fmod: Checking, if fmod(-1.5, M_PI) returns 1.641593", fmod(-1.5, M_PI), 1.640, 1.642);
    ASSERT_IN_RANGE("fmod: Checking, if fmod(-1.6, M_PI) returns 1.541593", fmod(-1.6, M_PI), 1.540, 1.542);
    ASSERT_IN_RANGE("fmod: Checking, if fmod(-0.4, M_PI) returns 2.741593", fmod(-0.4, M_PI), 2.740, 2.742);
    ASSERT_IN_RANGE("fmod: Checking, if fmod(-17.13339, M_PI) returns 1.716166", fmod(-17.13339, M_PI), 1.715, 1.717);
    ASSERT_IN_RANGE("fmod: Checking, if fmod(-17.93339, M_PI) returns 0.916166", fmod(-17.93339, M_PI), 0.915, 0.917);
    ASSERT_EQUALS("fmod: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_fmodf()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("fmodf: Checking, if fmodf(0.5f, M_PI) returns 0.5f", fmodf(0.5f, M_PI), 0.499f, 0.501f);
    ASSERT_IN_RANGE("fmodf: Checking, if fmodf(1.5f, M_PI) returns 1.5f", fmodf(1.5f, M_PI), 1.499f, 1.501f);
    ASSERT_IN_RANGE("fmodf: Checking, if fmodf(1.6f, M_PI) returns 1.6f", fmodf(1.6f, M_PI), 1.599f, 1.601f);
    ASSERT_IN_RANGE("fmodf: Checking, if fmodf(0.4f, M_PI) returns 0.4f", fmodf(0.4f, M_PI), 0.399f, 0.401f);
    ASSERT_IN_RANGE("fmodf: Checking, if fmodf(17.13339f, M_PI) returns 1.425427f", fmodf(17.13339f, M_PI), 1.424f, 1.426f);
    ASSERT_IN_RANGE("fmodf: Checking, if fmodf(17.93339f, M_PI) returns 2.225427f", fmodf(17.93339f, M_PI), 2.224f, 2.226f);
    ASSERT_IN_RANGE("fmodf: Checking, if fmodf(-0.5f, M_PI) returns 2.641593f", fmodf(-0.5f, M_PI), 2.640f, 2.642f);
    ASSERT_IN_RANGE("fmodf: Checking, if fmodf(-1.5f, M_PI) returns 1.641593f", fmodf(-1.5f, M_PI), 1.640f, 1.642f);
    ASSERT_IN_RANGE("fmodf: Checking, if fmodf(-1.6f, M_PI) returns 1.541593f", fmodf(-1.6f, M_PI), 1.540f, 1.542f);
    ASSERT_IN_RANGE("fmodf: Checking, if fmodf(-0.4f, M_PI) returns 2.741593f", fmodf(-0.4f, M_PI), 2.740f, 2.742f);
    ASSERT_IN_RANGE("fmodf: Checking, if fmodf(-17.13339f, M_PI) returns 1.716166f", fmodf(-17.13339f, M_PI), 1.715f, 1.717f);
    ASSERT_IN_RANGE("fmodf: Checking, if fmodf(-17.93339f, M_PI) returns 0.916166f", fmodf(-17.93339f, M_PI), 0.915f, 0.917f);
    ASSERT_EQUALS("fmodf: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_fmodl()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("fmodl: Checking, if fmodl(0.5, M_PI) returns 0.5", fmodl(0.5, M_PI), 0.499, 0.501);
    ASSERT_IN_RANGE("fmodl: Checking, if fmodl(1.5, M_PI) returns 1.5", fmodl(1.5, M_PI), 1.499, 1.501);
    ASSERT_IN_RANGE("fmodl: Checking, if fmodl(1.6, M_PI) returns 1.6", fmodl(1.6, M_PI), 1.599, 1.601);
    ASSERT_IN_RANGE("fmodl: Checking, if fmodl(0.4, M_PI) returns 0.4", fmodl(0.4, M_PI), 0.399, 0.401);
    ASSERT_IN_RANGE("fmodl: Checking, if fmodl(17.13339, M_PI) returns 1.425427", fmodl(17.13339, M_PI), 1.424, 1.426);
    ASSERT_IN_RANGE("fmodl: Checking, if fmodl(17.93339, M_PI) returns 2.225427", fmodl(17.93339, M_PI), 2.224, 2.226);
    ASSERT_IN_RANGE("fmodl: Checking, if fmodl(-0.5, M_PI) returns 2.641593", fmodl(-0.5, M_PI), 2.640, 2.642);
    ASSERT_IN_RANGE("fmodl: Checking, if fmodl(-1.5, M_PI) returns 1.641593", fmodl(-1.5, M_PI), 1.640, 1.642);
    ASSERT_IN_RANGE("fmodl: Checking, if fmodl(-1.6, M_PI) returns 1.541593", fmodl(-1.6, M_PI), 1.540, 1.542);
    ASSERT_IN_RANGE("fmodl: Checking, if fmodl(-0.4, M_PI) returns 2.741593", fmodl(-0.4, M_PI), 2.740, 2.742);
    ASSERT_IN_RANGE("fmodl: Checking, if fmodl(-17.13339, M_PI) returns 1.716166", fmodl(-17.13339, M_PI), 1.715, 1.717);
    ASSERT_IN_RANGE("fmodl: Checking, if fmodl(-17.93339, M_PI) returns 0.916166", fmodl(-17.93339, M_PI), 0.915, 0.917);
    ASSERT_EQUALS("fmodl: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_sin()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("sin: Checking, if sin(-(2 * M_PI)) returns 0.0", sin(-(2 * M_PI)), -0.1, 0.1);
    ASSERT_EQUALS("sin: Checking, if sin(-(3 * M_PI_2)) returns 1.0", sin(-(3 * M_PI_2)), 1.0);
    ASSERT_IN_RANGE("sin: Checking, if sin(-M_PI) returns 0.0", sin(-M_PI), -0.1, 0.1);
    ASSERT_EQUALS("sin: Checking, if sin(-M_PI_2) returns -1.0", sin(-M_PI_2), -1.0);
    ASSERT_IN_RANGE("sin: Checking, if sin(0.0) returns 0.0", sin(0.0), -0.1, 0.1);
    ASSERT_EQUALS("sin: Checking, if sin(M_PI_2) returns 1.0", sin(M_PI_2), 1.0);
    ASSERT_IN_RANGE("sin: Checking, if sin(M_PI) returns 0.0", sin(M_PI), -0.1, 0.1);
    ASSERT_EQUALS("sin: Checking, if sin(3 * M_PI_2) returns -1.0", sin(3 * M_PI_2), -1.0);
    ASSERT_IN_RANGE("sin: Checking, if sin(2 * M_PI) returns 0.0", sin(2 * M_PI), -0.1, 0.1);
    ASSERT_EQUALS("sin: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_sinf()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("sinf: Checking, if sinf(-(2 * M_PI)) returns 0.0f", sinf(-(2 * M_PI)), -0.1f, 0.1f);
    ASSERT_IN_RANGE("sinf: Checking, if sinf(-(3 * M_PI_2)) returns 1.0f", sinf(-(3 * M_PI_2)), 0.9f, 1.1f);
    ASSERT_IN_RANGE("sinf: Checking, if sinf(-M_PI) returns 0.0f", sinf(-M_PI), -0.1f, 0.1f);
    ASSERT_IN_RANGE("sinf: Checking, if sinf(-M_PI_2) returns -1.0f", sinf(-M_PI_2), -1.1f, -0.9f);
    ASSERT_IN_RANGE("sinf: Checking, if sinf(0.0f) returns 0.0f", sinf(0.0), -0.1f, 0.1f);
    ASSERT_IN_RANGE("sinf: Checking, if sinf(M_PI_2) returns 1.0f", sinf(M_PI_2), 0.9f, 1.1f);
    ASSERT_IN_RANGE("sinf: Checking, if sinf(M_PI) returns 0.0f", sinf(M_PI), -0.1f, 0.1f);
    ASSERT_IN_RANGE("sinf: Checking, if sinf(3 * M_PI_2) returns -1.0f", sinf(3 * M_PI_2), -1.1f, -0.9f);
    ASSERT_IN_RANGE("sinf: Checking, if sinf(2 * M_PI) returns 0.0f", sinf(2 * M_PI), -0.1f, 0.1f);
    ASSERT_EQUALS("sinf: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_sinl()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("sinl: Checking, if sinl(-(2 * M_PI)) returns 0.0", sinl(-(2 * M_PI)), 0.0, 0.0001);
    ASSERT_IN_RANGE("sinl: Checking, if sinl(-(3 * M_PI_2)) returns 1.0", sinl(-(3 * M_PI_2)), 1.0, 1.0001);
    ASSERT_IN_RANGE("sinl: Checking, if sinl(-M_PI) returns 0.0", sinl(-M_PI), -0.0001, 0.0001);
    ASSERT_IN_RANGE("sinl: Checking, if sinl(-M_PI_2) returns -1.0", sinl(-M_PI_2), -1.1, -0.9);
    ASSERT_IN_RANGE("sinl: Checking, if sinl(0.0) returns 0.0", sinl(0.0), -0.0001, 0.0001);
    ASSERT_IN_RANGE("sinl: Checking, if sinl(M_PI_2) returns 1.0", sinl(M_PI_2), 1.0, 1.0001);
    ASSERT_IN_RANGE("sinl: Checking, if sinl(M_PI) returns 0.0", sinl(M_PI), -0.0001, 0.0001);
    ASSERT_IN_RANGE("sinl: Checking, if sinl(3 * M_PI_2) returns -1.0", sinl(3 * M_PI_2), -1.1, -0.9);
    ASSERT_IN_RANGE("sinl: Checking, if sinl(2 * M_PI) returns 0.0", sinl(2 * M_PI), -0.0001, 0.0001);
    ASSERT_EQUALS("sinl: Checking, if errno is unmodified", pre_errno, errno);
}


// Check all functions of math.h
void run_math_lib_tests()
{
    TEST_CASE("Test POSIX math.h functions");

    // TODO: Check definitions!
    test_acos();
    test_acosf();
    test_acosl();

    test_cos();
    test_cosf();
    test_cosl();

    test_ceil();
    test_ceilf();
    test_ceill();

    test_fabs();
    test_fabsf();
    test_fabsl();

    test_floor();
    test_floorf();
    test_floorl();

    test_fmax();
    test_fmaxf();
    test_fmaxl();

    test_fmin();
    test_fminf();
    test_fminl();

    test_fmod();
    test_fmodf();
    test_fmodl();

    test_sin();
    test_sinf();
    test_sinl();
}
