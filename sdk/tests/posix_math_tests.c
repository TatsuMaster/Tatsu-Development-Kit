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


static void test_copysign()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("copysign: Checking, if copysign(1.0, -1.0) returns -1.0", copysign(1.0, -1.0), -1.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(42.0, -1.0) returns -42.0", copysign(42.0, -1.0), -42.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(1337.0, -0.0) returns -1337.0", copysign(1337.0, -0.0), -1337.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(1.0, 1.0) returns 1.0", copysign(1.0, 1.0), 1.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(42.0, 1.0) returns 42.0", copysign(42.0, 1.0), 42.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(1337.0, 0.0) returns 1337.0", copysign(1337.0, 0.0), 1337.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(0.0, 0.0) returns 0.0", copysign(0.0, 0.0), 0.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(0.0, -0.0) returns -0.0", copysign(0.0, -0.0), -0.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(-1.0, -1.0) returns -1.0", copysign(-1.0, -1.0), -1.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(-42.0, -1.0) returns -42.0", copysign(-42.0, -1.0), -42.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(-1337.0, -0.0) returns -1337.0", copysign(-1337.0, -0.0), -1337.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(-1.0, 1.0) returns 1.0", copysign(-1.0, 1.0), 1.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(-42.0, 1.0) returns 42.0", copysign(-42.0, 1.0), 42.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(-1337.0, 0.0) returns 1337.0", copysign(-1337.0, 0.0), 1337.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(-0.0, 0.0) returns 0.0", copysign(-0.0, 0.0), 0.0);
    ASSERT_EQUALS("copysign: Checking, if copysign(-0.0, -0.0) returns -0.0", copysign(-0.0, -0.0), -0.0);

    ASSERT_EQUALS("copysign: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_copysignf()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("copysignf: Checking, if copysignf(1.0f, -1.0f) returns -1.0f", copysignf(1.0f, -1.0f), -1.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(42.0f, -1.0f) returns -42.0f", copysignf(42.0f, -1.0f), -42.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(1337.0f, -0.0f) returns -1337.0f", copysignf(1337.0f, -0.0f), -1337.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(1.0f, 1.0f) returns 1.0f", copysignf(1.0f, 1.0f), 1.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(42.0f, 1.0f) returns 42.0f", copysignf(42.0f, 1.0f), 42.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(1337.0f, 0.0f) returns 1337.0f", copysignf(1337.0f, 0.0f), 1337.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(0.0f, 0.0f) returns 0.0f", copysignf(0.0f, 0.0f), 0.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(0.0f, -0.0f) returns -0.0f", copysignf(0.0f, -0.0f), -0.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(-1.0f, -1.0f) returns -1.0f", copysignf(-1.0f, -1.0f), -1.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(-42.0f, -1.0f) returns -42.0f", copysignf(-42.0f, -1.0f), -42.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(-1337.0f, -0.0f) returns -1337.0f", copysignf(-1337.0f, -0.0f), -1337.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(-1.0f, 1.0f) returns 1.0f", copysignf(-1.0f, 1.0f), 1.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(-42.0f, 1.0f) returns 42.0f", copysignf(-42.0f, 1.0f), 42.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(-1337.0f, 0.0f) returns 1337.0f", copysignf(-1337.0f, 0.0f), 1337.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(-0.0f, 0.0f) returns 0.0f", copysignf(-0.0f, 0.0f), 0.0f);
    ASSERT_EQUALS("copysignf: Checking, if copysignf(-0.0f, -0.0f) returns -0.0f", copysignf(-0.0f, -0.0f), -0.0f);

    ASSERT_EQUALS("copysignf: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_copysignl()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("copysignl: Checking, if copysignl(1.0, -1.0) returns -1.0", copysignl(1.0, -1.0), -1.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(42.0, -1.0) returns -42.0", copysignl(42.0, -1.0), -42.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(1337.0, -0.0) returns -1337.0", copysignl(1337.0, -0.0), -1337.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(1.0, 1.0) returns 1.0", copysignl(1.0, 1.0), 1.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(42.0, 1.0) returns 42.0", copysignl(42.0, 1.0), 42.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(1337.0, 0.0) returns 1337.0", copysignl(1337.0, 0.0), 1337.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(0.0, 0.0) returns 0.0", copysignl(0.0, 0.0), 0.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(0.0, -0.0) returns -0.0", copysignl(0.0, -0.0), -0.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(-1.0, -1.0) returns -1.0", copysignl(-1.0, -1.0), -1.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(-42.0, -1.0) returns -42.0", copysignl(-42.0, -1.0), -42.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(-1337.0, -0.0) returns -1337.0", copysignl(-1337.0, -0.0), -1337.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(-1.0, 1.0) returns 1.0", copysignl(-1.0, 1.0), 1.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(-42.0, 1.0) returns 42.0", copysignl(-42.0, 1.0), 42.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(-1337.0, 0.0) returns 1337.0", copysignl(-1337.0, 0.0), 1337.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(-0.0, 0.0) returns 0.0", copysignl(-0.0, 0.0), 0.0);
    ASSERT_EQUALS("copysignl: Checking, if copysignl(-0.0, -0.0) returns -0.0", copysignl(-0.0, -0.0), -0.0);

    ASSERT_EQUALS("copysignl: Checking, if errno is unmodified", pre_errno, errno);
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


static void test_lrint()
{
    const int pre_errno = errno;

    fesetround(FE_TONEAREST);
    ASSERT_EQUALS("lrint: Checking, if lrint(-1.0) returns -1 for rounding mode FE_TONEAREST", lrint(-1.0), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.9) returns -1 for rounding mode FE_TONEAREST", lrint(-0.9), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.8) returns -1 for rounding mode FE_TONEAREST", lrint(-0.8), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.7) returns -1 for rounding mode FE_TONEAREST", lrint(-0.7), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.6) returns -1 for rounding mode FE_TONEAREST", lrint(-0.6), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.5) returns -0 for rounding mode FE_TONEAREST", lrint(-0.5), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.4) returns -0 for rounding mode FE_TONEAREST", lrint(-0.4), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.3) returns -0 for rounding mode FE_TONEAREST", lrint(-0.3), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.2) returns -0 for rounding mode FE_TONEAREST", lrint(-0.2), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.1) returns -0 for rounding mode FE_TONEAREST", lrint(-0.1), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.0) returns -0 for rounding mode FE_TONEAREST", lrint(-0.0), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.0) returns 0 for rounding mode FE_TONEAREST", lrint(0.0), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.1) returns 0 for rounding mode FE_TONEAREST", lrint(0.1), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.2) returns 0 for rounding mode FE_TONEAREST", lrint(0.2), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.3) returns 0 for rounding mode FE_TONEAREST", lrint(0.3), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.4) returns 0 for rounding mode FE_TONEAREST", lrint(0.4), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.5) returns 0 for rounding mode FE_TONEAREST", lrint(0.5), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.6) returns 1 for rounding mode FE_TONEAREST", lrint(0.6), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.7) returns 1 for rounding mode FE_TONEAREST", lrint(0.7), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.8) returns 1 for rounding mode FE_TONEAREST", lrint(0.8), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.9) returns 1 for rounding mode FE_TONEAREST", lrint(0.9), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(1.0) returns 1 for rounding mode FE_TONEAREST", lrint(1.0), 1);

    fesetround(FE_DOWNWARD);
    ASSERT_EQUALS("lrint: Checking, if lrint(-1.0) returns -1 for rounding mode FE_DOWNWARD", lrint(-1.0), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.9) returns -1 for rounding mode FE_DOWNWARD", lrint(-0.9), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.8) returns -1 for rounding mode FE_DOWNWARD", lrint(-0.8), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.7) returns -1 for rounding mode FE_DOWNWARD", lrint(-0.7), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.6) returns -1 for rounding mode FE_DOWNWARD", lrint(-0.6), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.5) returns -1 for rounding mode FE_DOWNWARD", lrint(-0.5), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.4) returns -1 for rounding mode FE_DOWNWARD", lrint(-0.4), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.3) returns -1 for rounding mode FE_DOWNWARD", lrint(-0.3), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.2) returns -1 for rounding mode FE_DOWNWARD", lrint(-0.2), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.1) returns -1 for rounding mode FE_DOWNWARD", lrint(-0.1), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.0) returns -0 for rounding mode FE_DOWNWARD", lrint(-0.0), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.0) returns 0 for rounding mode FE_DOWNWARD", lrint(0.0), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.1) returns 0 for rounding mode FE_DOWNWARD", lrint(0.1), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.2) returns 0 for rounding mode FE_DOWNWARD", lrint(0.2), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.3) returns 0 for rounding mode FE_DOWNWARD", lrint(0.3), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.4) returns 0 for rounding mode FE_DOWNWARD", lrint(0.4), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.5) returns 0 for rounding mode FE_DOWNWARD", lrint(0.5), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.6) returns 0 for rounding mode FE_DOWNWARD", lrint(0.6), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.7) returns 0 for rounding mode FE_DOWNWARD", lrint(0.7), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.8) returns 0 for rounding mode FE_DOWNWARD", lrint(0.8), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.9) returns 0 for rounding mode FE_DOWNWARD", lrint(0.9), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(1.0) returns 1 for rounding mode FE_DOWNWARD", lrint(1.0), 1);

    fesetround(FE_UPWARD);
    ASSERT_EQUALS("lrint: Checking, if lrint(-1.0) returns -1 for rounding mode FE_UPWARD", lrint(-1.0), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.9) returns -0 for rounding mode FE_UPWARD", lrint(-0.9), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.8) returns -0 for rounding mode FE_UPWARD", lrint(-0.8), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.7) returns -0 for rounding mode FE_UPWARD", lrint(-0.7), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.6) returns -0 for rounding mode FE_UPWARD", lrint(-0.6), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.5) returns -0 for rounding mode FE_UPWARD", lrint(-0.5), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.4) returns -0 for rounding mode FE_UPWARD", lrint(-0.4), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.3) returns -0 for rounding mode FE_UPWARD", lrint(-0.3), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.2) returns -0 for rounding mode FE_UPWARD", lrint(-0.2), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.1) returns -0 for rounding mode FE_UPWARD", lrint(-0.1), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.0) returns -0 for rounding mode FE_UPWARD", lrint(-0.0), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.0) returns 0 for rounding mode FE_UPWARD", lrint(0.0), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.1) returns 1 for rounding mode FE_UPWARD", lrint(0.1), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.2) returns 1 for rounding mode FE_UPWARD", lrint(0.2), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.3) returns 1 for rounding mode FE_UPWARD", lrint(0.3), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.4) returns 1 for rounding mode FE_UPWARD", lrint(0.4), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.5) returns 1 for rounding mode FE_UPWARD", lrint(0.5), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.6) returns 1 for rounding mode FE_UPWARD", lrint(0.6), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.7) returns 1 for rounding mode FE_UPWARD", lrint(0.7), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.8) returns 1 for rounding mode FE_UPWARD", lrint(0.8), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.9) returns 1 for rounding mode FE_UPWARD", lrint(0.9), 1);
    ASSERT_EQUALS("lrint: Checking, if lrint(1.0) returns 1 for rounding mode FE_UPWARD", lrint(1.0), 1);

    fesetround(FE_TOWARDZERO);
    ASSERT_EQUALS("lrint: Checking, if lrint(-1.0) returns -1 for rounding mode FE_TOWARDZERO", lrint(-1.0), -1);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.9) returns -0 for rounding mode FE_TOWARDZERO", lrint(-0.9), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.8) returns -0 for rounding mode FE_TOWARDZERO", lrint(-0.8), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.7) returns -0 for rounding mode FE_TOWARDZERO", lrint(-0.7), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.6) returns -0 for rounding mode FE_TOWARDZERO", lrint(-0.6), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.5) returns -0 for rounding mode FE_TOWARDZERO", lrint(-0.5), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.4) returns -0 for rounding mode FE_TOWARDZERO", lrint(-0.4), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.3) returns -0 for rounding mode FE_TOWARDZERO", lrint(-0.3), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.2) returns -0 for rounding mode FE_TOWARDZERO", lrint(-0.2), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.1) returns -0 for rounding mode FE_TOWARDZERO", lrint(-0.1), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(-0.0) returns -0 for rounding mode FE_TOWARDZERO", lrint(-0.0), -0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.0) returns 0 for rounding mode FE_TOWARDZERO", lrint(0.0), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.1) returns 0 for rounding mode FE_TOWARDZERO", lrint(0.1), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.2) returns 0 for rounding mode FE_TOWARDZERO", lrint(0.2), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.3) returns 0 for rounding mode FE_TOWARDZERO", lrint(0.3), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.4) returns 0 for rounding mode FE_TOWARDZERO", lrint(0.4), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.5) returns 0 for rounding mode FE_TOWARDZERO", lrint(0.5), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.6) returns 0 for rounding mode FE_TOWARDZERO", lrint(0.6), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.7) returns 0 for rounding mode FE_TOWARDZERO", lrint(0.7), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.8) returns 0 for rounding mode FE_TOWARDZERO", lrint(0.8), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(0.9) returns 0 for rounding mode FE_TOWARDZERO", lrint(0.9), 0);
    ASSERT_EQUALS("lrint: Checking, if lrint(1.0) returns 1 for rounding mode FE_TOWARDZERO", lrint(1.0), 1);

    ASSERT_EQUALS("lrint: Checking, if errno is unmodified", pre_errno, errno);

    fesetround(FE_TONEAREST);
}


static void test_lrintf()
{
    const int pre_errno = errno;

    fesetround(FE_TONEAREST);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-1.0f) returns -1 for rounding mode FE_TONEAREST", lrintf(-1.0f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.9f) returns -1 for rounding mode FE_TONEAREST", lrintf(-0.9f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.8f) returns -1 for rounding mode FE_TONEAREST", lrintf(-0.8f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.7f) returns -1 for rounding mode FE_TONEAREST", lrintf(-0.7f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.6f) returns -1 for rounding mode FE_TONEAREST", lrintf(-0.6f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.5f) returns -0 for rounding mode FE_TONEAREST", lrintf(-0.5f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.4f) returns -0 for rounding mode FE_TONEAREST", lrintf(-0.4f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.3f) returns -0 for rounding mode FE_TONEAREST", lrintf(-0.3f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.2f) returns -0 for rounding mode FE_TONEAREST", lrintf(-0.2f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.1f) returns -0 for rounding mode FE_TONEAREST", lrintf(-0.1f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.0f) returns -0 for rounding mode FE_TONEAREST", lrintf(-0.0f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.0f) returns 0 for rounding mode FE_TONEAREST", lrintf(0.0f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.1f) returns 0 for rounding mode FE_TONEAREST", lrintf(0.1f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.2f) returns 0 for rounding mode FE_TONEAREST", lrintf(0.2f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.3f) returns 0 for rounding mode FE_TONEAREST", lrintf(0.3f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.4f) returns 0 for rounding mode FE_TONEAREST", lrintf(0.4f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.5f) returns 0 for rounding mode FE_TONEAREST", lrintf(0.5f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.6f) returns 1 for rounding mode FE_TONEAREST", lrintf(0.6f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.7f) returns 1 for rounding mode FE_TONEAREST", lrintf(0.7f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.8f) returns 1 for rounding mode FE_TONEAREST", lrintf(0.8f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.9f) returns 1 for rounding mode FE_TONEAREST", lrintf(0.9f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(1.0f) returns 1 for rounding mode FE_TONEAREST", lrintf(1.0f), 1);

    fesetround(FE_DOWNWARD);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-1.0f) returns -1 for rounding mode FE_DOWNWARD", lrintf(-1.0f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.9f) returns -1 for rounding mode FE_DOWNWARD", lrintf(-0.9f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.8f) returns -1 for rounding mode FE_DOWNWARD", lrintf(-0.8f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.7f) returns -1 for rounding mode FE_DOWNWARD", lrintf(-0.7f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.6f) returns -1 for rounding mode FE_DOWNWARD", lrintf(-0.6f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.5f) returns -1 for rounding mode FE_DOWNWARD", lrintf(-0.5f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.4f) returns -1 for rounding mode FE_DOWNWARD", lrintf(-0.4f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.3f) returns -1 for rounding mode FE_DOWNWARD", lrintf(-0.3f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.2f) returns -1 for rounding mode FE_DOWNWARD", lrintf(-0.2f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.1f) returns -1 for rounding mode FE_DOWNWARD", lrintf(-0.1f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.0f) returns -0 for rounding mode FE_DOWNWARD", lrintf(-0.0f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.0f) returns 0 for rounding mode FE_DOWNWARD", lrintf(0.0f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.1f) returns 0 for rounding mode FE_DOWNWARD", lrintf(0.1f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.2f) returns 0 for rounding mode FE_DOWNWARD", lrintf(0.2f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.3f) returns 0 for rounding mode FE_DOWNWARD", lrintf(0.3f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.4f) returns 0 for rounding mode FE_DOWNWARD", lrintf(0.4f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.5f) returns 0 for rounding mode FE_DOWNWARD", lrintf(0.5f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.6f) returns 0 for rounding mode FE_DOWNWARD", lrintf(0.6f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.7f) returns 0 for rounding mode FE_DOWNWARD", lrintf(0.7f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.8f) returns 0 for rounding mode FE_DOWNWARD", lrintf(0.8f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.9f) returns 0 for rounding mode FE_DOWNWARD", lrintf(0.9f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(1.0f) returns 1 for rounding mode FE_DOWNWARD", lrintf(1.0f), 1);

    fesetround(FE_UPWARD);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-1.0f) returns -1 for rounding mode FE_UPWARD", lrintf(-1.0f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.9f) returns -0 for rounding mode FE_UPWARD", lrintf(-0.9f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.8f) returns -0 for rounding mode FE_UPWARD", lrintf(-0.8f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.7f) returns -0 for rounding mode FE_UPWARD", lrintf(-0.7f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.6f) returns -0 for rounding mode FE_UPWARD", lrintf(-0.6f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.5f) returns -0 for rounding mode FE_UPWARD", lrintf(-0.5f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.4f) returns -0 for rounding mode FE_UPWARD", lrintf(-0.4f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.3f) returns -0 for rounding mode FE_UPWARD", lrintf(-0.3f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.2f) returns -0 for rounding mode FE_UPWARD", lrintf(-0.2f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.1f) returns -0 for rounding mode FE_UPWARD", lrintf(-0.1f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.0f) returns -0 for rounding mode FE_UPWARD", lrintf(-0.0f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.0f) returns 0 for rounding mode FE_UPWARD", lrintf(0.0f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.1f) returns 1 for rounding mode FE_UPWARD", lrintf(0.1f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.2f) returns 1 for rounding mode FE_UPWARD", lrintf(0.2f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.3f) returns 1 for rounding mode FE_UPWARD", lrintf(0.3f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.4f) returns 1 for rounding mode FE_UPWARD", lrintf(0.4f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.5f) returns 1 for rounding mode FE_UPWARD", lrintf(0.5f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.6f) returns 1 for rounding mode FE_UPWARD", lrintf(0.6f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.7f) returns 1 for rounding mode FE_UPWARD", lrintf(0.7f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.8f) returns 1 for rounding mode FE_UPWARD", lrintf(0.8f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.9f) returns 1 for rounding mode FE_UPWARD", lrintf(0.9f), 1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(1.0f) returns 1 for rounding mode FE_UPWARD", lrintf(1.0f), 1);

    fesetround(FE_TOWARDZERO);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-1.0f) returns -1 for rounding mode FE_TOWARDZERO", lrintf(-1.0f), -1);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.9f) returns -0 for rounding mode FE_TOWARDZERO", lrintf(-0.9f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.8f) returns -0 for rounding mode FE_TOWARDZERO", lrintf(-0.8f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.7f) returns -0 for rounding mode FE_TOWARDZERO", lrintf(-0.7f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.6f) returns -0 for rounding mode FE_TOWARDZERO", lrintf(-0.6f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.5f) returns -0 for rounding mode FE_TOWARDZERO", lrintf(-0.5f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.4f) returns -0 for rounding mode FE_TOWARDZERO", lrintf(-0.4f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.3f) returns -0 for rounding mode FE_TOWARDZERO", lrintf(-0.3f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.2f) returns -0 for rounding mode FE_TOWARDZERO", lrintf(-0.2f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.1f) returns -0 for rounding mode FE_TOWARDZERO", lrintf(-0.1f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(-0.0f) returns -0 for rounding mode FE_TOWARDZERO", lrintf(-0.0f), -0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.0f) returns 0 for rounding mode FE_TOWARDZERO", lrintf(0.0f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.1f) returns 0 for rounding mode FE_TOWARDZERO", lrintf(0.1f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.2f) returns 0 for rounding mode FE_TOWARDZERO", lrintf(0.2f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.3f) returns 0 for rounding mode FE_TOWARDZERO", lrintf(0.3f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.4f) returns 0 for rounding mode FE_TOWARDZERO", lrintf(0.4f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.5f) returns 0 for rounding mode FE_TOWARDZERO", lrintf(0.5f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.6f) returns 0 for rounding mode FE_TOWARDZERO", lrintf(0.6f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.7f) returns 0 for rounding mode FE_TOWARDZERO", lrintf(0.7f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.8f) returns 0 for rounding mode FE_TOWARDZERO", lrintf(0.8f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(0.9f) returns 0 for rounding mode FE_TOWARDZERO", lrintf(0.9f), 0);
    ASSERT_EQUALS("lrintf: Checking, if lrintf(1.0f) returns 1 for rounding mode FE_TOWARDZERO", lrintf(1.0f), 1);

    ASSERT_EQUALS("lrintf: Checking, if errno is unmodified", pre_errno, errno);

    fesetround(FE_TONEAREST);
}


static void test_lrintl()
{
    const int pre_errno = errno;

    fesetround(FE_TONEAREST);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-1.0) returns -1 for rounding mode FE_TONEAREST", lrintl(-1.0), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.9) returns -1 for rounding mode FE_TONEAREST", lrintl(-0.9), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.8) returns -1 for rounding mode FE_TONEAREST", lrintl(-0.8), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.7) returns -1 for rounding mode FE_TONEAREST", lrintl(-0.7), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.6) returns -1 for rounding mode FE_TONEAREST", lrintl(-0.6), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.5) returns -0 for rounding mode FE_TONEAREST", lrintl(-0.5), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.4) returns -0 for rounding mode FE_TONEAREST", lrintl(-0.4), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.3) returns -0 for rounding mode FE_TONEAREST", lrintl(-0.3), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.2) returns -0 for rounding mode FE_TONEAREST", lrintl(-0.2), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.1) returns -0 for rounding mode FE_TONEAREST", lrintl(-0.1), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.0) returns -0 for rounding mode FE_TONEAREST", lrintl(-0.0), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.0) returns 0 for rounding mode FE_TONEAREST", lrintl(0.0), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.1) returns 0 for rounding mode FE_TONEAREST", lrintl(0.1), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.2) returns 0 for rounding mode FE_TONEAREST", lrintl(0.2), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.3) returns 0 for rounding mode FE_TONEAREST", lrintl(0.3), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.4) returns 0 for rounding mode FE_TONEAREST", lrintl(0.4), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.5) returns 0 for rounding mode FE_TONEAREST", lrintl(0.5), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.6) returns 1 for rounding mode FE_TONEAREST", lrintl(0.6), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.7) returns 1 for rounding mode FE_TONEAREST", lrintl(0.7), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.8) returns 1 for rounding mode FE_TONEAREST", lrintl(0.8), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.9) returns 1 for rounding mode FE_TONEAREST", lrintl(0.9), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(1.0) returns 1 for rounding mode FE_TONEAREST", lrintl(1.0), 1);

    fesetround(FE_DOWNWARD);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-1.0) returns -1 for rounding mode FE_DOWNWARD", lrintl(-1.0), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.9) returns -1 for rounding mode FE_DOWNWARD", lrintl(-0.9), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.8) returns -1 for rounding mode FE_DOWNWARD", lrintl(-0.8), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.7) returns -1 for rounding mode FE_DOWNWARD", lrintl(-0.7), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.6) returns -1 for rounding mode FE_DOWNWARD", lrintl(-0.6), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.5) returns -1 for rounding mode FE_DOWNWARD", lrintl(-0.5), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.4) returns -1 for rounding mode FE_DOWNWARD", lrintl(-0.4), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.3) returns -1 for rounding mode FE_DOWNWARD", lrintl(-0.3), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.2) returns -1 for rounding mode FE_DOWNWARD", lrintl(-0.2), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.1) returns -1 for rounding mode FE_DOWNWARD", lrintl(-0.1), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.0) returns -0 for rounding mode FE_DOWNWARD", lrintl(-0.0), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.0) returns 0 for rounding mode FE_DOWNWARD", lrintl(0.0), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.1) returns 0 for rounding mode FE_DOWNWARD", lrintl(0.1), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.2) returns 0 for rounding mode FE_DOWNWARD", lrintl(0.2), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.3) returns 0 for rounding mode FE_DOWNWARD", lrintl(0.3), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.4) returns 0 for rounding mode FE_DOWNWARD", lrintl(0.4), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.5) returns 0 for rounding mode FE_DOWNWARD", lrintl(0.5), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.6) returns 0 for rounding mode FE_DOWNWARD", lrintl(0.6), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.7) returns 0 for rounding mode FE_DOWNWARD", lrintl(0.7), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.8) returns 0 for rounding mode FE_DOWNWARD", lrintl(0.8), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.9) returns 0 for rounding mode FE_DOWNWARD", lrintl(0.9), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(1.0) returns 1 for rounding mode FE_DOWNWARD", lrintl(1.0), 1);

    fesetround(FE_UPWARD);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-1.0) returns -1 for rounding mode FE_UPWARD", lrintl(-1.0), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.9) returns -0 for rounding mode FE_UPWARD", lrintl(-0.9), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.8) returns -0 for rounding mode FE_UPWARD", lrintl(-0.8), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.7) returns -0 for rounding mode FE_UPWARD", lrintl(-0.7), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.6) returns -0 for rounding mode FE_UPWARD", lrintl(-0.6), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.5) returns -0 for rounding mode FE_UPWARD", lrintl(-0.5), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.4) returns -0 for rounding mode FE_UPWARD", lrintl(-0.4), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.3) returns -0 for rounding mode FE_UPWARD", lrintl(-0.3), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.2) returns -0 for rounding mode FE_UPWARD", lrintl(-0.2), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.1) returns -0 for rounding mode FE_UPWARD", lrintl(-0.1), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.0) returns -0 for rounding mode FE_UPWARD", lrintl(-0.0), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.0) returns 0 for rounding mode FE_UPWARD", lrintl(0.0), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.1) returns 1 for rounding mode FE_UPWARD", lrintl(0.1), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.2) returns 1 for rounding mode FE_UPWARD", lrintl(0.2), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.3) returns 1 for rounding mode FE_UPWARD", lrintl(0.3), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.4) returns 1 for rounding mode FE_UPWARD", lrintl(0.4), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.5) returns 1 for rounding mode FE_UPWARD", lrintl(0.5), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.6) returns 1 for rounding mode FE_UPWARD", lrintl(0.6), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.7) returns 1 for rounding mode FE_UPWARD", lrintl(0.7), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.8) returns 1 for rounding mode FE_UPWARD", lrintl(0.8), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.9) returns 1 for rounding mode FE_UPWARD", lrintl(0.9), 1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(1.0) returns 1 for rounding mode FE_UPWARD", lrintl(1.0), 1);

    fesetround(FE_TOWARDZERO);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-1.0) returns -1 for rounding mode FE_TOWARDZERO", lrintl(-1.0), -1);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.9) returns -0 for rounding mode FE_TOWARDZERO", lrintl(-0.9), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.8) returns -0 for rounding mode FE_TOWARDZERO", lrintl(-0.8), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.7) returns -0 for rounding mode FE_TOWARDZERO", lrintl(-0.7), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.6) returns -0 for rounding mode FE_TOWARDZERO", lrintl(-0.6), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.5) returns -0 for rounding mode FE_TOWARDZERO", lrintl(-0.5), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.4) returns -0 for rounding mode FE_TOWARDZERO", lrintl(-0.4), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.3) returns -0 for rounding mode FE_TOWARDZERO", lrintl(-0.3), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.2) returns -0 for rounding mode FE_TOWARDZERO", lrintl(-0.2), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.1) returns -0 for rounding mode FE_TOWARDZERO", lrintl(-0.1), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(-0.0) returns -0 for rounding mode FE_TOWARDZERO", lrintl(-0.0), -0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.0) returns 0 for rounding mode FE_TOWARDZERO", lrintl(0.0), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.1) returns 0 for rounding mode FE_TOWARDZERO", lrintl(0.1), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.2) returns 0 for rounding mode FE_TOWARDZERO", lrintl(0.2), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.3) returns 0 for rounding mode FE_TOWARDZERO", lrintl(0.3), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.4) returns 0 for rounding mode FE_TOWARDZERO", lrintl(0.4), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.5) returns 0 for rounding mode FE_TOWARDZERO", lrintl(0.5), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.6) returns 0 for rounding mode FE_TOWARDZERO", lrintl(0.6), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.7) returns 0 for rounding mode FE_TOWARDZERO", lrintl(0.7), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.8) returns 0 for rounding mode FE_TOWARDZERO", lrintl(0.8), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(0.9) returns 0 for rounding mode FE_TOWARDZERO", lrintl(0.9), 0);
    ASSERT_EQUALS("lrintl: Checking, if lrintl(1.0) returns 1 for rounding mode FE_TOWARDZERO", lrintl(1.0), 1);

    ASSERT_EQUALS("lrintl: Checking, if errno is unmodified", pre_errno, errno);

    fesetround(FE_TONEAREST);
}


static void test_lround()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("lround: Checking, if lround(-1.0) returns -1", lround(-1.0), -1);
    ASSERT_EQUALS("lround: Checking, if lround(-0.9) returns -1", lround(-0.9), -1);
    ASSERT_EQUALS("lround: Checking, if lround(-0.8) returns -1", lround(-0.8), -1);
    ASSERT_EQUALS("lround: Checking, if lround(-0.7) returns -1", lround(-0.7), -1);
    ASSERT_EQUALS("lround: Checking, if lround(-0.6) returns -1", lround(-0.6), -1);
    ASSERT_EQUALS("lround: Checking, if lround(-0.5) returns -1", lround(-0.5), -1);
    ASSERT_EQUALS("lround: Checking, if lround(-0.4) returns 0", lround(-0.4), -0);
    ASSERT_EQUALS("lround: Checking, if lround(-0.3) returns 0", lround(-0.3), -0);
    ASSERT_EQUALS("lround: Checking, if lround(-0.2) returns 0", lround(-0.2), -0);
    ASSERT_EQUALS("lround: Checking, if lround(-0.1) returns 0", lround(-0.1), -0);
    ASSERT_EQUALS("lround: Checking, if lround(-0.0) returns 0", lround(-0.0), -0);
    ASSERT_EQUALS("lround: Checking, if lround(0.0) returns 0", lround(0.0), 0);
    ASSERT_EQUALS("lround: Checking, if lround(0.1) returns 0", lround(0.1), 0);
    ASSERT_EQUALS("lround: Checking, if lround(0.2) returns 0", lround(0.2), 0);
    ASSERT_EQUALS("lround: Checking, if lround(0.3) returns 0", lround(0.3), 0);
    ASSERT_EQUALS("lround: Checking, if lround(0.4) returns 0", lround(0.4), 0);
    ASSERT_EQUALS("lround: Checking, if lround(0.5) returns 1", lround(0.5), 1);
    ASSERT_EQUALS("lround: Checking, if lround(0.6) returns 1", lround(0.6), 1);
    ASSERT_EQUALS("lround: Checking, if lround(0.7) returns 1", lround(0.7), 1);
    ASSERT_EQUALS("lround: Checking, if lround(0.8) returns 1", lround(0.8), 1);
    ASSERT_EQUALS("lround: Checking, if lround(0.9) returns 1", lround(0.9), 1);
    ASSERT_EQUALS("lround: Checking, if lround(1.0) returns 1", lround(1.0), 1);
    ASSERT_EQUALS("lround: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_lroundf()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("lroundf: Checking, if lroundf(-1.0f) returns -1", lroundf(-1.0f), -1);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(-0.9f) returns -1", lroundf(-0.9f), -1);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(-0.8f) returns -1", lroundf(-0.8f), -1);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(-0.7f) returns -1", lroundf(-0.7f), -1);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(-0.6f) returns -1", lroundf(-0.6f), -1);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(-0.5f) returns -1", lroundf(-0.5f), -1);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(-0.4f) returns 0", lroundf(-0.4f), -0);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(-0.3f) returns 0", lroundf(-0.3f), -0);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(-0.2f) returns 0", lroundf(-0.2f), -0);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(-0.1f) returns 0", lroundf(-0.1f), -0);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(-0.0f) returns 0", lroundf(-0.0f), -0);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(0.0f) returns 0", lroundf(0.0f), 0);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(0.1f) returns 0", lroundf(0.1f), 0);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(0.2f) returns 0", lroundf(0.2f), 0);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(0.3f) returns 0", lroundf(0.3f), 0);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(0.4f) returns 0", lroundf(0.4f), 0);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(0.5f) returns 1", lroundf(0.5f), 1);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(0.6f) returns 1", lroundf(0.6f), 1);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(0.7f) returns 1", lroundf(0.7f), 1);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(0.8f) returns 1", lroundf(0.8f), 1);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(0.9f) returns 1", lroundf(0.9f), 1);
    ASSERT_EQUALS("lroundf: Checking, if lroundf(1.0f) returns 1", lroundf(1.0f), 1);
    ASSERT_EQUALS("lroundf: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_lroundl()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("lroundl: Checking, if lroundl(-1.0) returns -1", lroundl(-1.0), -1);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(-0.9) returns -1", lroundl(-0.9), -1);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(-0.8) returns -1", lroundl(-0.8), -1);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(-0.7) returns -1", lroundl(-0.7), -1);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(-0.6) returns -1", lroundl(-0.6), -1);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(-0.5) returns -1", lroundl(-0.5), -1);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(-0.4) returns 0", lroundl(-0.4), -0);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(-0.3) returns 0", lroundl(-0.3), -0);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(-0.2) returns 0", lroundl(-0.2), -0);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(-0.1) returns 0", lroundl(-0.1), -0);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(-0.0) returns 0", lroundl(-0.0), -0);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(0.0) returns 0", lroundl(0.0), 0);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(0.1) returns 0", lroundl(0.1), 0);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(0.2) returns 0", lroundl(0.2), 0);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(0.3) returns 0", lroundl(0.3), 0);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(0.4) returns 0", lroundl(0.4), 0);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(0.5) returns 1", lroundl(0.5), 1);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(0.6) returns 1", lroundl(0.6), 1);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(0.7) returns 1", lroundl(0.7), 1);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(0.8) returns 1", lroundl(0.8), 1);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(0.9) returns 1", lroundl(0.9), 1);
    ASSERT_EQUALS("lroundl: Checking, if lroundl(1.0) returns 1", lroundl(1.0), 1);
    ASSERT_EQUALS("lroundl: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_llrint()
{
    const int pre_errno = errno;

    fesetround(FE_TONEAREST);
    ASSERT_EQUALS("llrint: Checking, if llrint(-1.0) returns -1 for rounding mode FE_TONEAREST", llrint(-1.0), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.9) returns -1 for rounding mode FE_TONEAREST", llrint(-0.9), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.8) returns -1 for rounding mode FE_TONEAREST", llrint(-0.8), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.7) returns -1 for rounding mode FE_TONEAREST", llrint(-0.7), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.6) returns -1 for rounding mode FE_TONEAREST", llrint(-0.6), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.5) returns -0 for rounding mode FE_TONEAREST", llrint(-0.5), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.4) returns -0 for rounding mode FE_TONEAREST", llrint(-0.4), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.3) returns -0 for rounding mode FE_TONEAREST", llrint(-0.3), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.2) returns -0 for rounding mode FE_TONEAREST", llrint(-0.2), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.1) returns -0 for rounding mode FE_TONEAREST", llrint(-0.1), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.0) returns -0 for rounding mode FE_TONEAREST", llrint(-0.0), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.0) returns 0 for rounding mode FE_TONEAREST", llrint(0.0), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.1) returns 0 for rounding mode FE_TONEAREST", llrint(0.1), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.2) returns 0 for rounding mode FE_TONEAREST", llrint(0.2), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.3) returns 0 for rounding mode FE_TONEAREST", llrint(0.3), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.4) returns 0 for rounding mode FE_TONEAREST", llrint(0.4), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.5) returns 0 for rounding mode FE_TONEAREST", llrint(0.5), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.6) returns 1 for rounding mode FE_TONEAREST", llrint(0.6), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.7) returns 1 for rounding mode FE_TONEAREST", llrint(0.7), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.8) returns 1 for rounding mode FE_TONEAREST", llrint(0.8), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.9) returns 1 for rounding mode FE_TONEAREST", llrint(0.9), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(1.0) returns 1 for rounding mode FE_TONEAREST", llrint(1.0), 1);

    fesetround(FE_DOWNWARD);
    ASSERT_EQUALS("llrint: Checking, if llrint(-1.0) returns -1 for rounding mode FE_DOWNWARD", llrint(-1.0), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.9) returns -1 for rounding mode FE_DOWNWARD", llrint(-0.9), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.8) returns -1 for rounding mode FE_DOWNWARD", llrint(-0.8), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.7) returns -1 for rounding mode FE_DOWNWARD", llrint(-0.7), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.6) returns -1 for rounding mode FE_DOWNWARD", llrint(-0.6), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.5) returns -1 for rounding mode FE_DOWNWARD", llrint(-0.5), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.4) returns -1 for rounding mode FE_DOWNWARD", llrint(-0.4), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.3) returns -1 for rounding mode FE_DOWNWARD", llrint(-0.3), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.2) returns -1 for rounding mode FE_DOWNWARD", llrint(-0.2), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.1) returns -1 for rounding mode FE_DOWNWARD", llrint(-0.1), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.0) returns -0 for rounding mode FE_DOWNWARD", llrint(-0.0), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.0) returns 0 for rounding mode FE_DOWNWARD", llrint(0.0), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.1) returns 0 for rounding mode FE_DOWNWARD", llrint(0.1), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.2) returns 0 for rounding mode FE_DOWNWARD", llrint(0.2), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.3) returns 0 for rounding mode FE_DOWNWARD", llrint(0.3), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.4) returns 0 for rounding mode FE_DOWNWARD", llrint(0.4), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.5) returns 0 for rounding mode FE_DOWNWARD", llrint(0.5), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.6) returns 0 for rounding mode FE_DOWNWARD", llrint(0.6), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.7) returns 0 for rounding mode FE_DOWNWARD", llrint(0.7), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.8) returns 0 for rounding mode FE_DOWNWARD", llrint(0.8), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.9) returns 0 for rounding mode FE_DOWNWARD", llrint(0.9), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(1.0) returns 1 for rounding mode FE_DOWNWARD", llrint(1.0), 1);

    fesetround(FE_UPWARD);
    ASSERT_EQUALS("llrint: Checking, if llrint(-1.0) returns -1 for rounding mode FE_UPWARD", llrint(-1.0), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.9) returns -0 for rounding mode FE_UPWARD", llrint(-0.9), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.8) returns -0 for rounding mode FE_UPWARD", llrint(-0.8), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.7) returns -0 for rounding mode FE_UPWARD", llrint(-0.7), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.6) returns -0 for rounding mode FE_UPWARD", llrint(-0.6), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.5) returns -0 for rounding mode FE_UPWARD", llrint(-0.5), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.4) returns -0 for rounding mode FE_UPWARD", llrint(-0.4), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.3) returns -0 for rounding mode FE_UPWARD", llrint(-0.3), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.2) returns -0 for rounding mode FE_UPWARD", llrint(-0.2), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.1) returns -0 for rounding mode FE_UPWARD", llrint(-0.1), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.0) returns -0 for rounding mode FE_UPWARD", llrint(-0.0), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.0) returns 0 for rounding mode FE_UPWARD", llrint(0.0), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.1) returns 1 for rounding mode FE_UPWARD", llrint(0.1), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.2) returns 1 for rounding mode FE_UPWARD", llrint(0.2), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.3) returns 1 for rounding mode FE_UPWARD", llrint(0.3), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.4) returns 1 for rounding mode FE_UPWARD", llrint(0.4), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.5) returns 1 for rounding mode FE_UPWARD", llrint(0.5), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.6) returns 1 for rounding mode FE_UPWARD", llrint(0.6), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.7) returns 1 for rounding mode FE_UPWARD", llrint(0.7), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.8) returns 1 for rounding mode FE_UPWARD", llrint(0.8), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.9) returns 1 for rounding mode FE_UPWARD", llrint(0.9), 1);
    ASSERT_EQUALS("llrint: Checking, if llrint(1.0) returns 1 for rounding mode FE_UPWARD", llrint(1.0), 1);

    fesetround(FE_TOWARDZERO);
    ASSERT_EQUALS("llrint: Checking, if llrint(-1.0) returns -1 for rounding mode FE_TOWARDZERO", llrint(-1.0), -1);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.9) returns -0 for rounding mode FE_TOWARDZERO", llrint(-0.9), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.8) returns -0 for rounding mode FE_TOWARDZERO", llrint(-0.8), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.7) returns -0 for rounding mode FE_TOWARDZERO", llrint(-0.7), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.6) returns -0 for rounding mode FE_TOWARDZERO", llrint(-0.6), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.5) returns -0 for rounding mode FE_TOWARDZERO", llrint(-0.5), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.4) returns -0 for rounding mode FE_TOWARDZERO", llrint(-0.4), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.3) returns -0 for rounding mode FE_TOWARDZERO", llrint(-0.3), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.2) returns -0 for rounding mode FE_TOWARDZERO", llrint(-0.2), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.1) returns -0 for rounding mode FE_TOWARDZERO", llrint(-0.1), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(-0.0) returns -0 for rounding mode FE_TOWARDZERO", llrint(-0.0), -0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.0) returns 0 for rounding mode FE_TOWARDZERO", llrint(0.0), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.1) returns 0 for rounding mode FE_TOWARDZERO", llrint(0.1), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.2) returns 0 for rounding mode FE_TOWARDZERO", llrint(0.2), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.3) returns 0 for rounding mode FE_TOWARDZERO", llrint(0.3), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.4) returns 0 for rounding mode FE_TOWARDZERO", llrint(0.4), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.5) returns 0 for rounding mode FE_TOWARDZERO", llrint(0.5), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.6) returns 0 for rounding mode FE_TOWARDZERO", llrint(0.6), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.7) returns 0 for rounding mode FE_TOWARDZERO", llrint(0.7), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.8) returns 0 for rounding mode FE_TOWARDZERO", llrint(0.8), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(0.9) returns 0 for rounding mode FE_TOWARDZERO", llrint(0.9), 0);
    ASSERT_EQUALS("llrint: Checking, if llrint(1.0) returns 1 for rounding mode FE_TOWARDZERO", llrint(1.0), 1);

    ASSERT_EQUALS("llrint: Checking, if errno is unmodified", pre_errno, errno);

    fesetround(FE_TONEAREST);
}


static void test_llrintf()
{
    const int pre_errno = errno;

    fesetround(FE_TONEAREST);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-1.0f) returns -1 for rounding mode FE_TONEAREST", llrintf(-1.0f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.9f) returns -1 for rounding mode FE_TONEAREST", llrintf(-0.9f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.8f) returns -1 for rounding mode FE_TONEAREST", llrintf(-0.8f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.7f) returns -1 for rounding mode FE_TONEAREST", llrintf(-0.7f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.6f) returns -1 for rounding mode FE_TONEAREST", llrintf(-0.6f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.5f) returns -0 for rounding mode FE_TONEAREST", llrintf(-0.5f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.4f) returns -0 for rounding mode FE_TONEAREST", llrintf(-0.4f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.3f) returns -0 for rounding mode FE_TONEAREST", llrintf(-0.3f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.2f) returns -0 for rounding mode FE_TONEAREST", llrintf(-0.2f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.1f) returns -0 for rounding mode FE_TONEAREST", llrintf(-0.1f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.0f) returns -0 for rounding mode FE_TONEAREST", llrintf(-0.0f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.0f) returns 0 for rounding mode FE_TONEAREST", llrintf(0.0f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.1f) returns 0 for rounding mode FE_TONEAREST", llrintf(0.1f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.2f) returns 0 for rounding mode FE_TONEAREST", llrintf(0.2f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.3f) returns 0 for rounding mode FE_TONEAREST", llrintf(0.3f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.4f) returns 0 for rounding mode FE_TONEAREST", llrintf(0.4f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.5f) returns 0 for rounding mode FE_TONEAREST", llrintf(0.5f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.6f) returns 1 for rounding mode FE_TONEAREST", llrintf(0.6f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.7f) returns 1 for rounding mode FE_TONEAREST", llrintf(0.7f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.8f) returns 1 for rounding mode FE_TONEAREST", llrintf(0.8f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.9f) returns 1 for rounding mode FE_TONEAREST", llrintf(0.9f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(1.0f) returns 1 for rounding mode FE_TONEAREST", llrintf(1.0f), 1);

    fesetround(FE_DOWNWARD);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-1.0f) returns -1 for rounding mode FE_DOWNWARD", llrintf(-1.0f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.9f) returns -1 for rounding mode FE_DOWNWARD", llrintf(-0.9f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.8f) returns -1 for rounding mode FE_DOWNWARD", llrintf(-0.8f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.7f) returns -1 for rounding mode FE_DOWNWARD", llrintf(-0.7f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.6f) returns -1 for rounding mode FE_DOWNWARD", llrintf(-0.6f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.5f) returns -1 for rounding mode FE_DOWNWARD", llrintf(-0.5f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.4f) returns -1 for rounding mode FE_DOWNWARD", llrintf(-0.4f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.3f) returns -1 for rounding mode FE_DOWNWARD", llrintf(-0.3f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.2f) returns -1 for rounding mode FE_DOWNWARD", llrintf(-0.2f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.1f) returns -1 for rounding mode FE_DOWNWARD", llrintf(-0.1f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.0f) returns -0 for rounding mode FE_DOWNWARD", llrintf(-0.0f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.0f) returns 0 for rounding mode FE_DOWNWARD", llrintf(0.0f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.1f) returns 0 for rounding mode FE_DOWNWARD", llrintf(0.1f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.2f) returns 0 for rounding mode FE_DOWNWARD", llrintf(0.2f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.3f) returns 0 for rounding mode FE_DOWNWARD", llrintf(0.3f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.4f) returns 0 for rounding mode FE_DOWNWARD", llrintf(0.4f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.5f) returns 0 for rounding mode FE_DOWNWARD", llrintf(0.5f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.6f) returns 0 for rounding mode FE_DOWNWARD", llrintf(0.6f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.7f) returns 0 for rounding mode FE_DOWNWARD", llrintf(0.7f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.8f) returns 0 for rounding mode FE_DOWNWARD", llrintf(0.8f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.9f) returns 0 for rounding mode FE_DOWNWARD", llrintf(0.9f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(1.0f) returns 1 for rounding mode FE_DOWNWARD", llrintf(1.0f), 1);

    fesetround(FE_UPWARD);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-1.0f) returns -1 for rounding mode FE_UPWARD", llrintf(-1.0f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.9f) returns -0 for rounding mode FE_UPWARD", llrintf(-0.9f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.8f) returns -0 for rounding mode FE_UPWARD", llrintf(-0.8f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.7f) returns -0 for rounding mode FE_UPWARD", llrintf(-0.7f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.6f) returns -0 for rounding mode FE_UPWARD", llrintf(-0.6f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.5f) returns -0 for rounding mode FE_UPWARD", llrintf(-0.5f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.4f) returns -0 for rounding mode FE_UPWARD", llrintf(-0.4f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.3f) returns -0 for rounding mode FE_UPWARD", llrintf(-0.3f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.2f) returns -0 for rounding mode FE_UPWARD", llrintf(-0.2f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.1f) returns -0 for rounding mode FE_UPWARD", llrintf(-0.1f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.0f) returns -0 for rounding mode FE_UPWARD", llrintf(-0.0f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.0f) returns 0 for rounding mode FE_UPWARD", llrintf(0.0f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.1f) returns 1 for rounding mode FE_UPWARD", llrintf(0.1f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.2f) returns 1 for rounding mode FE_UPWARD", llrintf(0.2f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.3f) returns 1 for rounding mode FE_UPWARD", llrintf(0.3f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.4f) returns 1 for rounding mode FE_UPWARD", llrintf(0.4f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.5f) returns 1 for rounding mode FE_UPWARD", llrintf(0.5f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.6f) returns 1 for rounding mode FE_UPWARD", llrintf(0.6f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.7f) returns 1 for rounding mode FE_UPWARD", llrintf(0.7f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.8f) returns 1 for rounding mode FE_UPWARD", llrintf(0.8f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.9f) returns 1 for rounding mode FE_UPWARD", llrintf(0.9f), 1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(1.0f) returns 1 for rounding mode FE_UPWARD", llrintf(1.0f), 1);

    fesetround(FE_TOWARDZERO);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-1.0f) returns -1 for rounding mode FE_TOWARDZERO", llrintf(-1.0f), -1);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.9f) returns -0 for rounding mode FE_TOWARDZERO", llrintf(-0.9f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.8f) returns -0 for rounding mode FE_TOWARDZERO", llrintf(-0.8f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.7f) returns -0 for rounding mode FE_TOWARDZERO", llrintf(-0.7f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.6f) returns -0 for rounding mode FE_TOWARDZERO", llrintf(-0.6f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.5f) returns -0 for rounding mode FE_TOWARDZERO", llrintf(-0.5f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.4f) returns -0 for rounding mode FE_TOWARDZERO", llrintf(-0.4f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.3f) returns -0 for rounding mode FE_TOWARDZERO", llrintf(-0.3f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.2f) returns -0 for rounding mode FE_TOWARDZERO", llrintf(-0.2f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.1f) returns -0 for rounding mode FE_TOWARDZERO", llrintf(-0.1f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(-0.0f) returns -0 for rounding mode FE_TOWARDZERO", llrintf(-0.0f), -0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.0f) returns 0 for rounding mode FE_TOWARDZERO", llrintf(0.0f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.1f) returns 0 for rounding mode FE_TOWARDZERO", llrintf(0.1f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.2f) returns 0 for rounding mode FE_TOWARDZERO", llrintf(0.2f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.3f) returns 0 for rounding mode FE_TOWARDZERO", llrintf(0.3f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.4f) returns 0 for rounding mode FE_TOWARDZERO", llrintf(0.4f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.5f) returns 0 for rounding mode FE_TOWARDZERO", llrintf(0.5f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.6f) returns 0 for rounding mode FE_TOWARDZERO", llrintf(0.6f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.7f) returns 0 for rounding mode FE_TOWARDZERO", llrintf(0.7f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.8f) returns 0 for rounding mode FE_TOWARDZERO", llrintf(0.8f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(0.9f) returns 0 for rounding mode FE_TOWARDZERO", llrintf(0.9f), 0);
    ASSERT_EQUALS("llrintf: Checking, if llrintf(1.0f) returns 1 for rounding mode FE_TOWARDZERO", llrintf(1.0f), 1);

    ASSERT_EQUALS("llrintf: Checking, if errno is unmodified", pre_errno, errno);

    fesetround(FE_TONEAREST);
}


static void test_llrintl()
{
    const int pre_errno = errno;

    fesetround(FE_TONEAREST);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-1.0) returns -1 for rounding mode FE_TONEAREST", llrintl(-1.0), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.9) returns -1 for rounding mode FE_TONEAREST", llrintl(-0.9), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.8) returns -1 for rounding mode FE_TONEAREST", llrintl(-0.8), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.7) returns -1 for rounding mode FE_TONEAREST", llrintl(-0.7), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.6) returns -1 for rounding mode FE_TONEAREST", llrintl(-0.6), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.5) returns -0 for rounding mode FE_TONEAREST", llrintl(-0.5), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.4) returns -0 for rounding mode FE_TONEAREST", llrintl(-0.4), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.3) returns -0 for rounding mode FE_TONEAREST", llrintl(-0.3), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.2) returns -0 for rounding mode FE_TONEAREST", llrintl(-0.2), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.1) returns -0 for rounding mode FE_TONEAREST", llrintl(-0.1), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.0) returns -0 for rounding mode FE_TONEAREST", llrintl(-0.0), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.0) returns 0 for rounding mode FE_TONEAREST", llrintl(0.0), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.1) returns 0 for rounding mode FE_TONEAREST", llrintl(0.1), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.2) returns 0 for rounding mode FE_TONEAREST", llrintl(0.2), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.3) returns 0 for rounding mode FE_TONEAREST", llrintl(0.3), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.4) returns 0 for rounding mode FE_TONEAREST", llrintl(0.4), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.5) returns 0 for rounding mode FE_TONEAREST", llrintl(0.5), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.6) returns 1 for rounding mode FE_TONEAREST", llrintl(0.6), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.7) returns 1 for rounding mode FE_TONEAREST", llrintl(0.7), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.8) returns 1 for rounding mode FE_TONEAREST", llrintl(0.8), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.9) returns 1 for rounding mode FE_TONEAREST", llrintl(0.9), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(1.0) returns 1 for rounding mode FE_TONEAREST", llrintl(1.0), 1);

    fesetround(FE_DOWNWARD);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-1.0) returns -1 for rounding mode FE_DOWNWARD", llrintl(-1.0), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.9) returns -1 for rounding mode FE_DOWNWARD", llrintl(-0.9), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.8) returns -1 for rounding mode FE_DOWNWARD", llrintl(-0.8), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.7) returns -1 for rounding mode FE_DOWNWARD", llrintl(-0.7), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.6) returns -1 for rounding mode FE_DOWNWARD", llrintl(-0.6), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.5) returns -1 for rounding mode FE_DOWNWARD", llrintl(-0.5), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.4) returns -1 for rounding mode FE_DOWNWARD", llrintl(-0.4), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.3) returns -1 for rounding mode FE_DOWNWARD", llrintl(-0.3), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.2) returns -1 for rounding mode FE_DOWNWARD", llrintl(-0.2), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.1) returns -1 for rounding mode FE_DOWNWARD", llrintl(-0.1), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.0) returns -0 for rounding mode FE_DOWNWARD", llrintl(-0.0), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.0) returns 0 for rounding mode FE_DOWNWARD", llrintl(0.0), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.1) returns 0 for rounding mode FE_DOWNWARD", llrintl(0.1), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.2) returns 0 for rounding mode FE_DOWNWARD", llrintl(0.2), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.3) returns 0 for rounding mode FE_DOWNWARD", llrintl(0.3), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.4) returns 0 for rounding mode FE_DOWNWARD", llrintl(0.4), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.5) returns 0 for rounding mode FE_DOWNWARD", llrintl(0.5), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.6) returns 0 for rounding mode FE_DOWNWARD", llrintl(0.6), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.7) returns 0 for rounding mode FE_DOWNWARD", llrintl(0.7), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.8) returns 0 for rounding mode FE_DOWNWARD", llrintl(0.8), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.9) returns 0 for rounding mode FE_DOWNWARD", llrintl(0.9), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(1.0) returns 1 for rounding mode FE_DOWNWARD", llrintl(1.0), 1);

    fesetround(FE_UPWARD);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-1.0) returns -1 for rounding mode FE_UPWARD", llrintl(-1.0), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.9) returns -0 for rounding mode FE_UPWARD", llrintl(-0.9), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.8) returns -0 for rounding mode FE_UPWARD", llrintl(-0.8), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.7) returns -0 for rounding mode FE_UPWARD", llrintl(-0.7), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.6) returns -0 for rounding mode FE_UPWARD", llrintl(-0.6), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.5) returns -0 for rounding mode FE_UPWARD", llrintl(-0.5), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.4) returns -0 for rounding mode FE_UPWARD", llrintl(-0.4), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.3) returns -0 for rounding mode FE_UPWARD", llrintl(-0.3), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.2) returns -0 for rounding mode FE_UPWARD", llrintl(-0.2), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.1) returns -0 for rounding mode FE_UPWARD", llrintl(-0.1), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.0) returns -0 for rounding mode FE_UPWARD", llrintl(-0.0), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.0) returns 0 for rounding mode FE_UPWARD", llrintl(0.0), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.1) returns 1 for rounding mode FE_UPWARD", llrintl(0.1), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.2) returns 1 for rounding mode FE_UPWARD", llrintl(0.2), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.3) returns 1 for rounding mode FE_UPWARD", llrintl(0.3), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.4) returns 1 for rounding mode FE_UPWARD", llrintl(0.4), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.5) returns 1 for rounding mode FE_UPWARD", llrintl(0.5), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.6) returns 1 for rounding mode FE_UPWARD", llrintl(0.6), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.7) returns 1 for rounding mode FE_UPWARD", llrintl(0.7), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.8) returns 1 for rounding mode FE_UPWARD", llrintl(0.8), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.9) returns 1 for rounding mode FE_UPWARD", llrintl(0.9), 1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(1.0) returns 1 for rounding mode FE_UPWARD", llrintl(1.0), 1);

    fesetround(FE_TOWARDZERO);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-1.0) returns -1 for rounding mode FE_TOWARDZERO", llrintl(-1.0), -1);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.9) returns -0 for rounding mode FE_TOWARDZERO", llrintl(-0.9), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.8) returns -0 for rounding mode FE_TOWARDZERO", llrintl(-0.8), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.7) returns -0 for rounding mode FE_TOWARDZERO", llrintl(-0.7), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.6) returns -0 for rounding mode FE_TOWARDZERO", llrintl(-0.6), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.5) returns -0 for rounding mode FE_TOWARDZERO", llrintl(-0.5), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.4) returns -0 for rounding mode FE_TOWARDZERO", llrintl(-0.4), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.3) returns -0 for rounding mode FE_TOWARDZERO", llrintl(-0.3), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.2) returns -0 for rounding mode FE_TOWARDZERO", llrintl(-0.2), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.1) returns -0 for rounding mode FE_TOWARDZERO", llrintl(-0.1), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(-0.0) returns -0 for rounding mode FE_TOWARDZERO", llrintl(-0.0), -0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.0) returns 0 for rounding mode FE_TOWARDZERO", llrintl(0.0), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.1) returns 0 for rounding mode FE_TOWARDZERO", llrintl(0.1), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.2) returns 0 for rounding mode FE_TOWARDZERO", llrintl(0.2), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.3) returns 0 for rounding mode FE_TOWARDZERO", llrintl(0.3), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.4) returns 0 for rounding mode FE_TOWARDZERO", llrintl(0.4), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.5) returns 0 for rounding mode FE_TOWARDZERO", llrintl(0.5), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.6) returns 0 for rounding mode FE_TOWARDZERO", llrintl(0.6), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.7) returns 0 for rounding mode FE_TOWARDZERO", llrintl(0.7), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.8) returns 0 for rounding mode FE_TOWARDZERO", llrintl(0.8), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(0.9) returns 0 for rounding mode FE_TOWARDZERO", llrintl(0.9), 0);
    ASSERT_EQUALS("llrintl: Checking, if llrintl(1.0) returns 1 for rounding mode FE_TOWARDZERO", llrintl(1.0), 1);

    ASSERT_EQUALS("llrintl: Checking, if errno is unmodified", pre_errno, errno);

    fesetround(FE_TONEAREST);
}


static void test_llround()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("llround: Checking, if llround(-1.0) returns -1", llround(-1.0), -1);
    ASSERT_EQUALS("llround: Checking, if llround(-0.9) returns -1", llround(-0.9), -1);
    ASSERT_EQUALS("llround: Checking, if llround(-0.8) returns -1", llround(-0.8), -1);
    ASSERT_EQUALS("llround: Checking, if llround(-0.7) returns -1", llround(-0.7), -1);
    ASSERT_EQUALS("llround: Checking, if llround(-0.6) returns -1", llround(-0.6), -1);
    ASSERT_EQUALS("llround: Checking, if llround(-0.5) returns -1", llround(-0.5), -1);
    ASSERT_EQUALS("llround: Checking, if llround(-0.4) returns 0", llround(-0.4), -0);
    ASSERT_EQUALS("llround: Checking, if llround(-0.3) returns 0", llround(-0.3), -0);
    ASSERT_EQUALS("llround: Checking, if llround(-0.2) returns 0", llround(-0.2), -0);
    ASSERT_EQUALS("llround: Checking, if llround(-0.1) returns 0", llround(-0.1), -0);
    ASSERT_EQUALS("llround: Checking, if llround(-0.0) returns 0", llround(-0.0), -0);
    ASSERT_EQUALS("llround: Checking, if llround(0.0) returns 0", llround(0.0), 0);
    ASSERT_EQUALS("llround: Checking, if llround(0.1) returns 0", llround(0.1), 0);
    ASSERT_EQUALS("llround: Checking, if llround(0.2) returns 0", llround(0.2), 0);
    ASSERT_EQUALS("llround: Checking, if llround(0.3) returns 0", llround(0.3), 0);
    ASSERT_EQUALS("llround: Checking, if llround(0.4) returns 0", llround(0.4), 0);
    ASSERT_EQUALS("llround: Checking, if llround(0.5) returns 1", llround(0.5), 1);
    ASSERT_EQUALS("llround: Checking, if llround(0.6) returns 1", llround(0.6), 1);
    ASSERT_EQUALS("llround: Checking, if llround(0.7) returns 1", llround(0.7), 1);
    ASSERT_EQUALS("llround: Checking, if llround(0.8) returns 1", llround(0.8), 1);
    ASSERT_EQUALS("llround: Checking, if llround(0.9) returns 1", llround(0.9), 1);
    ASSERT_EQUALS("llround: Checking, if llround(1.0) returns 1", llround(1.0), 1);
    ASSERT_EQUALS("llround: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_llroundf()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("llroundf: Checking, if llroundf(-1.0f) returns -1", llroundf(-1.0f), -1);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(-0.9f) returns -1", llroundf(-0.9f), -1);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(-0.8f) returns -1", llroundf(-0.8f), -1);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(-0.7f) returns -1", llroundf(-0.7f), -1);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(-0.6f) returns -1", llroundf(-0.6f), -1);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(-0.5f) returns -1", llroundf(-0.5f), -1);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(-0.4f) returns 0", llroundf(-0.4f), -0);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(-0.3f) returns 0", llroundf(-0.3f), -0);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(-0.2f) returns 0", llroundf(-0.2f), -0);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(-0.1f) returns 0", llroundf(-0.1f), -0);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(-0.0f) returns 0", llroundf(-0.0f), -0);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(0.0f) returns 0", llroundf(0.0f), 0);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(0.1f) returns 0", llroundf(0.1f), 0);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(0.2f) returns 0", llroundf(0.2f), 0);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(0.3f) returns 0", llroundf(0.3f), 0);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(0.4f) returns 0", llroundf(0.4f), 0);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(0.5f) returns 1", llroundf(0.5f), 1);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(0.6f) returns 1", llroundf(0.6f), 1);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(0.7f) returns 1", llroundf(0.7f), 1);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(0.8f) returns 1", llroundf(0.8f), 1);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(0.9f) returns 1", llroundf(0.9f), 1);
    ASSERT_EQUALS("llroundf: Checking, if llroundf(1.0f) returns 1", llroundf(1.0f), 1);
    ASSERT_EQUALS("llroundf: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_llroundl()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("llroundl: Checking, if llroundl(-1.0) returns -1", llroundl(-1.0), -1);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(-0.9) returns -1", llroundl(-0.9), -1);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(-0.8) returns -1", llroundl(-0.8), -1);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(-0.7) returns -1", llroundl(-0.7), -1);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(-0.6) returns -1", llroundl(-0.6), -1);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(-0.5) returns -1", llroundl(-0.5), -1);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(-0.4) returns 0", llroundl(-0.4), -0);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(-0.3) returns 0", llroundl(-0.3), -0);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(-0.2) returns 0", llroundl(-0.2), -0);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(-0.1) returns 0", llroundl(-0.1), -0);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(-0.0) returns 0", llroundl(-0.0), -0);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(0.0) returns 0", llroundl(0.0), 0);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(0.1) returns 0", llroundl(0.1), 0);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(0.2) returns 0", llroundl(0.2), 0);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(0.3) returns 0", llroundl(0.3), 0);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(0.4) returns 0", llroundl(0.4), 0);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(0.5) returns 1", llroundl(0.5), 1);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(0.6) returns 1", llroundl(0.6), 1);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(0.7) returns 1", llroundl(0.7), 1);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(0.8) returns 1", llroundl(0.8), 1);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(0.9) returns 1", llroundl(0.9), 1);
    ASSERT_EQUALS("llroundl: Checking, if llroundl(1.0) returns 1", llroundl(1.0), 1);
    ASSERT_EQUALS("llroundl: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_rint()
{
    const int pre_errno = errno;

    fesetround(FE_TONEAREST);
    ASSERT_EQUALS("rint: Checking, if rint(-1.0) returns -1.0 for rounding mode FE_TONEAREST", rint(-1.0), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.9) returns -1.0 for rounding mode FE_TONEAREST", rint(-0.9), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.8) returns -1.0 for rounding mode FE_TONEAREST", rint(-0.8), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.7) returns -1.0 for rounding mode FE_TONEAREST", rint(-0.7), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.6) returns -1.0 for rounding mode FE_TONEAREST", rint(-0.6), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.5) returns -0.0 for rounding mode FE_TONEAREST", rint(-0.5), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.4) returns -0.0 for rounding mode FE_TONEAREST", rint(-0.4), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.3) returns -0.0 for rounding mode FE_TONEAREST", rint(-0.3), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.2) returns -0.0 for rounding mode FE_TONEAREST", rint(-0.2), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.1) returns -0.0 for rounding mode FE_TONEAREST", rint(-0.1), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.0) returns -0.0 for rounding mode FE_TONEAREST", rint(-0.0), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.0) returns 0.0 for rounding mode FE_TONEAREST", rint(0.0), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.1) returns 0.0 for rounding mode FE_TONEAREST", rint(0.1), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.2) returns 0.0 for rounding mode FE_TONEAREST", rint(0.2), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.3) returns 0.0 for rounding mode FE_TONEAREST", rint(0.3), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.4) returns 0.0 for rounding mode FE_TONEAREST", rint(0.4), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.5) returns 0.0 for rounding mode FE_TONEAREST", rint(0.5), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.6) returns 1.0 for rounding mode FE_TONEAREST", rint(0.6), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.7) returns 1.0 for rounding mode FE_TONEAREST", rint(0.7), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.8) returns 1.0 for rounding mode FE_TONEAREST", rint(0.8), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.9) returns 1.0 for rounding mode FE_TONEAREST", rint(0.9), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(1.0) returns 1.0 for rounding mode FE_TONEAREST", rint(1.0), 1.0);

    fesetround(FE_DOWNWARD);
    ASSERT_EQUALS("rint: Checking, if rint(-1.0) returns -1.0 for rounding mode FE_DOWNWARD", rint(-1.0), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.9) returns -1.0 for rounding mode FE_DOWNWARD", rint(-0.9), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.8) returns -1.0 for rounding mode FE_DOWNWARD", rint(-0.8), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.7) returns -1.0 for rounding mode FE_DOWNWARD", rint(-0.7), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.6) returns -1.0 for rounding mode FE_DOWNWARD", rint(-0.6), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.5) returns -1.0 for rounding mode FE_DOWNWARD", rint(-0.5), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.4) returns -1.0 for rounding mode FE_DOWNWARD", rint(-0.4), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.3) returns -1.0 for rounding mode FE_DOWNWARD", rint(-0.3), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.2) returns -1.0 for rounding mode FE_DOWNWARD", rint(-0.2), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.1) returns -1.0 for rounding mode FE_DOWNWARD", rint(-0.1), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.0) returns -0.0 for rounding mode FE_DOWNWARD", rint(-0.0), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.0) returns 0.0 for rounding mode FE_DOWNWARD", rint(0.0), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.1) returns 0.0 for rounding mode FE_DOWNWARD", rint(0.1), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.2) returns 0.0 for rounding mode FE_DOWNWARD", rint(0.2), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.3) returns 0.0 for rounding mode FE_DOWNWARD", rint(0.3), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.4) returns 0.0 for rounding mode FE_DOWNWARD", rint(0.4), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.5) returns 0.0 for rounding mode FE_DOWNWARD", rint(0.5), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.6) returns 0.0 for rounding mode FE_DOWNWARD", rint(0.6), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.7) returns 0.0 for rounding mode FE_DOWNWARD", rint(0.7), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.8) returns 0.0 for rounding mode FE_DOWNWARD", rint(0.8), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.9) returns 0.0 for rounding mode FE_DOWNWARD", rint(0.9), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(1.0) returns 1.0 for rounding mode FE_DOWNWARD", rint(1.0), 1.0);

    fesetround(FE_UPWARD);
    ASSERT_EQUALS("rint: Checking, if rint(-1.0) returns -1.0 for rounding mode FE_UPWARD", rint(-1.0), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.9) returns -0.0 for rounding mode FE_UPWARD", rint(-0.9), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.8) returns -0.0 for rounding mode FE_UPWARD", rint(-0.8), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.7) returns -0.0 for rounding mode FE_UPWARD", rint(-0.7), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.6) returns -0.0 for rounding mode FE_UPWARD", rint(-0.6), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.5) returns -0.0 for rounding mode FE_UPWARD", rint(-0.5), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.4) returns -0.0 for rounding mode FE_UPWARD", rint(-0.4), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.3) returns -0.0 for rounding mode FE_UPWARD", rint(-0.3), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.2) returns -0.0 for rounding mode FE_UPWARD", rint(-0.2), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.1) returns -0.0 for rounding mode FE_UPWARD", rint(-0.1), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.0) returns -0.0 for rounding mode FE_UPWARD", rint(-0.0), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.0) returns 0.0 for rounding mode FE_UPWARD", rint(0.0), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.1) returns 1.0 for rounding mode FE_UPWARD", rint(0.1), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.2) returns 1.0 for rounding mode FE_UPWARD", rint(0.2), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.3) returns 1.0 for rounding mode FE_UPWARD", rint(0.3), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.4) returns 1.0 for rounding mode FE_UPWARD", rint(0.4), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.5) returns 1.0 for rounding mode FE_UPWARD", rint(0.5), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.6) returns 1.0 for rounding mode FE_UPWARD", rint(0.6), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.7) returns 1.0 for rounding mode FE_UPWARD", rint(0.7), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.8) returns 1.0 for rounding mode FE_UPWARD", rint(0.8), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.9) returns 1.0 for rounding mode FE_UPWARD", rint(0.9), 1.0);
    ASSERT_EQUALS("rint: Checking, if rint(1.0) returns 1.0 for rounding mode FE_UPWARD", rint(1.0), 1.0);

    fesetround(FE_TOWARDZERO);
    ASSERT_EQUALS("rint: Checking, if rint(-1.0) returns -1.0 for rounding mode FE_TOWARDZERO", rint(-1.0), -1.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.9) returns -0.0 for rounding mode FE_TOWARDZERO", rint(-0.9), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.8) returns -0.0 for rounding mode FE_TOWARDZERO", rint(-0.8), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.7) returns -0.0 for rounding mode FE_TOWARDZERO", rint(-0.7), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.6) returns -0.0 for rounding mode FE_TOWARDZERO", rint(-0.6), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.5) returns -0.0 for rounding mode FE_TOWARDZERO", rint(-0.5), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.4) returns -0.0 for rounding mode FE_TOWARDZERO", rint(-0.4), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.3) returns -0.0 for rounding mode FE_TOWARDZERO", rint(-0.3), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.2) returns -0.0 for rounding mode FE_TOWARDZERO", rint(-0.2), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.1) returns -0.0 for rounding mode FE_TOWARDZERO", rint(-0.1), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(-0.0) returns -0.0 for rounding mode FE_TOWARDZERO", rint(-0.0), -0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.0) returns 0.0 for rounding mode FE_TOWARDZERO", rint(0.0), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.1) returns 0.0 for rounding mode FE_TOWARDZERO", rint(0.1), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.2) returns 0.0 for rounding mode FE_TOWARDZERO", rint(0.2), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.3) returns 0.0 for rounding mode FE_TOWARDZERO", rint(0.3), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.4) returns 0.0 for rounding mode FE_TOWARDZERO", rint(0.4), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.5) returns 0.0 for rounding mode FE_TOWARDZERO", rint(0.5), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.6) returns 0.0 for rounding mode FE_TOWARDZERO", rint(0.6), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.7) returns 0.0 for rounding mode FE_TOWARDZERO", rint(0.7), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.8) returns 0.0 for rounding mode FE_TOWARDZERO", rint(0.8), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(0.9) returns 0.0 for rounding mode FE_TOWARDZERO", rint(0.9), 0.0);
    ASSERT_EQUALS("rint: Checking, if rint(1.0) returns 1.0 for rounding mode FE_TOWARDZERO", rint(1.0), 1.0);

    ASSERT_EQUALS("rint: Checking, if errno is unmodified", pre_errno, errno);

    fesetround(FE_TONEAREST);
}


static void test_rintf()
{
    const int pre_errno = errno;

    fesetround(FE_TONEAREST);
    ASSERT_EQUALS("rintf: Checking, if rintf(-1.0f) returns -1.0f for rounding mode FE_TONEAREST", rintf(-1.0f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.9f) returns -1.0f for rounding mode FE_TONEAREST", rintf(-0.9f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.8f) returns -1.0f for rounding mode FE_TONEAREST", rintf(-0.8f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.7f) returns -1.0f for rounding mode FE_TONEAREST", rintf(-0.7f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.6f) returns -1.0f for rounding mode FE_TONEAREST", rintf(-0.6f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.5f) returns -0.0f for rounding mode FE_TONEAREST", rintf(-0.5f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.4f) returns -0.0f for rounding mode FE_TONEAREST", rintf(-0.4f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.3f) returns -0.0f for rounding mode FE_TONEAREST", rintf(-0.3f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.2f) returns -0.0f for rounding mode FE_TONEAREST", rintf(-0.2f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.1f) returns -0.0f for rounding mode FE_TONEAREST", rintf(-0.1f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.0f) returns -0.0f for rounding mode FE_TONEAREST", rintf(-0.0f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.0f) returns 0.0f for rounding mode FE_TONEAREST", rintf(0.0f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.1f) returns 0.0f for rounding mode FE_TONEAREST", rintf(0.1f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.2f) returns 0.0f for rounding mode FE_TONEAREST", rintf(0.2f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.3f) returns 0.0f for rounding mode FE_TONEAREST", rintf(0.3f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.4f) returns 0.0f for rounding mode FE_TONEAREST", rintf(0.4f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.5f) returns 0.0f for rounding mode FE_TONEAREST", rintf(0.5f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.6f) returns 1.0f for rounding mode FE_TONEAREST", rintf(0.6f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.7f) returns 1.0f for rounding mode FE_TONEAREST", rintf(0.7f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.8f) returns 1.0f for rounding mode FE_TONEAREST", rintf(0.8f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.9f) returns 1.0f for rounding mode FE_TONEAREST", rintf(0.9f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(1.0f) returns 1.0f for rounding mode FE_TONEAREST", rintf(1.0f), 1.0f);

    fesetround(FE_DOWNWARD);
    ASSERT_EQUALS("rintf: Checking, if rintf(-1.0f) returns -1.0f for rounding mode FE_DOWNWARD", rintf(-1.0f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.9f) returns -1.0f for rounding mode FE_DOWNWARD", rintf(-0.9f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.8f) returns -1.0f for rounding mode FE_DOWNWARD", rintf(-0.8f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.7f) returns -1.0f for rounding mode FE_DOWNWARD", rintf(-0.7f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.6f) returns -1.0f for rounding mode FE_DOWNWARD", rintf(-0.6f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.5f) returns -1.0f for rounding mode FE_DOWNWARD", rintf(-0.5f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.4f) returns -1.0f for rounding mode FE_DOWNWARD", rintf(-0.4f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.3f) returns -1.0f for rounding mode FE_DOWNWARD", rintf(-0.3f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.2f) returns -1.0f for rounding mode FE_DOWNWARD", rintf(-0.2f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.1f) returns -1.0f for rounding mode FE_DOWNWARD", rintf(-0.1f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.0f) returns -0.0f for rounding mode FE_DOWNWARD", rintf(-0.0f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.0f) returns 0.0f for rounding mode FE_DOWNWARD", rintf(0.0f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.1f) returns 0.0f for rounding mode FE_DOWNWARD", rintf(0.1f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.2f) returns 0.0f for rounding mode FE_DOWNWARD", rintf(0.2f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.3f) returns 0.0f for rounding mode FE_DOWNWARD", rintf(0.3f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.4f) returns 0.0f for rounding mode FE_DOWNWARD", rintf(0.4f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.5f) returns 0.0f for rounding mode FE_DOWNWARD", rintf(0.5f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.6f) returns 0.0f for rounding mode FE_DOWNWARD", rintf(0.6f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.7f) returns 0.0f for rounding mode FE_DOWNWARD", rintf(0.7f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.8f) returns 0.0f for rounding mode FE_DOWNWARD", rintf(0.8f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.9f) returns 0.0f for rounding mode FE_DOWNWARD", rintf(0.9f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(1.0f) returns 1.0f for rounding mode FE_DOWNWARD", rintf(1.0f), 1.0f);

    fesetround(FE_UPWARD);
    ASSERT_EQUALS("rintf: Checking, if rintf(-1.0f) returns -1.0f for rounding mode FE_UPWARD", rintf(-1.0f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.9f) returns -0.0f for rounding mode FE_UPWARD", rintf(-0.9f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.8f) returns -0.0f for rounding mode FE_UPWARD", rintf(-0.8f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.7f) returns -0.0f for rounding mode FE_UPWARD", rintf(-0.7f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.6f) returns -0.0f for rounding mode FE_UPWARD", rintf(-0.6f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.5f) returns -0.0f for rounding mode FE_UPWARD", rintf(-0.5f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.4f) returns -0.0f for rounding mode FE_UPWARD", rintf(-0.4f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.3f) returns -0.0f for rounding mode FE_UPWARD", rintf(-0.3f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.2f) returns -0.0f for rounding mode FE_UPWARD", rintf(-0.2f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.1f) returns -0.0f for rounding mode FE_UPWARD", rintf(-0.1f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.0f) returns -0.0f for rounding mode FE_UPWARD", rintf(-0.0f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.0f) returns 0.0f for rounding mode FE_UPWARD", rintf(0.0f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.1f) returns 1.0f for rounding mode FE_UPWARD", rintf(0.1f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.2f) returns 1.0f for rounding mode FE_UPWARD", rintf(0.2f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.3f) returns 1.0f for rounding mode FE_UPWARD", rintf(0.3f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.4f) returns 1.0f for rounding mode FE_UPWARD", rintf(0.4f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.5f) returns 1.0f for rounding mode FE_UPWARD", rintf(0.5f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.6f) returns 1.0f for rounding mode FE_UPWARD", rintf(0.6f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.7f) returns 1.0f for rounding mode FE_UPWARD", rintf(0.7f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.8f) returns 1.0f for rounding mode FE_UPWARD", rintf(0.8f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.9f) returns 1.0f for rounding mode FE_UPWARD", rintf(0.9f), 1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(1.0f) returns 1.0f for rounding mode FE_UPWARD", rintf(1.0f), 1.0f);

    fesetround(FE_TOWARDZERO);
    ASSERT_EQUALS("rintf: Checking, if rintf(-1.0f) returns -1.0f for rounding mode FE_TOWARDZERO", rintf(-1.0f), -1.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.9f) returns -0.0f for rounding mode FE_TOWARDZERO", rintf(-0.9f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.8f) returns -0.0f for rounding mode FE_TOWARDZERO", rintf(-0.8f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.7f) returns -0.0f for rounding mode FE_TOWARDZERO", rintf(-0.7f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.6f) returns -0.0f for rounding mode FE_TOWARDZERO", rintf(-0.6f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.5f) returns -0.0f for rounding mode FE_TOWARDZERO", rintf(-0.5f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.4f) returns -0.0f for rounding mode FE_TOWARDZERO", rintf(-0.4f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.3f) returns -0.0f for rounding mode FE_TOWARDZERO", rintf(-0.3f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.2f) returns -0.0f for rounding mode FE_TOWARDZERO", rintf(-0.2f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.1f) returns -0.0f for rounding mode FE_TOWARDZERO", rintf(-0.1f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(-0.0f) returns -0.0f for rounding mode FE_TOWARDZERO", rintf(-0.0f), -0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.0f) returns 0.0f for rounding mode FE_TOWARDZERO", rintf(0.0f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.1f) returns 0.0f for rounding mode FE_TOWARDZERO", rintf(0.1f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.2f) returns 0.0f for rounding mode FE_TOWARDZERO", rintf(0.2f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.3f) returns 0.0f for rounding mode FE_TOWARDZERO", rintf(0.3f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.4f) returns 0.0f for rounding mode FE_TOWARDZERO", rintf(0.4f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.5f) returns 0.0f for rounding mode FE_TOWARDZERO", rintf(0.5f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.6f) returns 0.0f for rounding mode FE_TOWARDZERO", rintf(0.6f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.7f) returns 0.0f for rounding mode FE_TOWARDZERO", rintf(0.7f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.8f) returns 0.0f for rounding mode FE_TOWARDZERO", rintf(0.8f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(0.9f) returns 0.0f for rounding mode FE_TOWARDZERO", rintf(0.9f), 0.0f);
    ASSERT_EQUALS("rintf: Checking, if rintf(1.0f) returns 1.0f for rounding mode FE_TOWARDZERO", rintf(1.0f), 1.0f);

    ASSERT_EQUALS("rintf: Checking, if errno is unmodified", pre_errno, errno);

    fesetround(FE_TONEAREST);
}


static void test_rintl()
{
    const int pre_errno = errno;

    fesetround(FE_TONEAREST);
    ASSERT_EQUALS("rintl: Checking, if rintl(-1.0) returns -1.0 for rounding mode FE_TONEAREST", rintl(-1.0), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.9) returns -1.0 for rounding mode FE_TONEAREST", rintl(-0.9), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.8) returns -1.0 for rounding mode FE_TONEAREST", rintl(-0.8), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.7) returns -1.0 for rounding mode FE_TONEAREST", rintl(-0.7), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.6) returns -1.0 for rounding mode FE_TONEAREST", rintl(-0.6), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.5) returns -0.0 for rounding mode FE_TONEAREST", rintl(-0.5), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.4) returns -0.0 for rounding mode FE_TONEAREST", rintl(-0.4), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.3) returns -0.0 for rounding mode FE_TONEAREST", rintl(-0.3), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.2) returns -0.0 for rounding mode FE_TONEAREST", rintl(-0.2), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.1) returns -0.0 for rounding mode FE_TONEAREST", rintl(-0.1), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.0) returns -0.0 for rounding mode FE_TONEAREST", rintl(-0.0), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.0) returns 0.0 for rounding mode FE_TONEAREST", rintl(0.0), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.1) returns 0.0 for rounding mode FE_TONEAREST", rintl(0.1), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.2) returns 0.0 for rounding mode FE_TONEAREST", rintl(0.2), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.3) returns 0.0 for rounding mode FE_TONEAREST", rintl(0.3), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.4) returns 0.0 for rounding mode FE_TONEAREST", rintl(0.4), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.5) returns 0.0 for rounding mode FE_TONEAREST", rintl(0.5), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.6) returns 1.0 for rounding mode FE_TONEAREST", rintl(0.6), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.7) returns 1.0 for rounding mode FE_TONEAREST", rintl(0.7), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.8) returns 1.0 for rounding mode FE_TONEAREST", rintl(0.8), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.9) returns 1.0 for rounding mode FE_TONEAREST", rintl(0.9), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(1.0) returns 1.0 for rounding mode FE_TONEAREST", rintl(1.0), 1.0);

    fesetround(FE_DOWNWARD);
    ASSERT_EQUALS("rintl: Checking, if rintl(-1.0) returns -1.0 for rounding mode FE_DOWNWARD", rintl(-1.0), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.9) returns -1.0 for rounding mode FE_DOWNWARD", rintl(-0.9), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.8) returns -1.0 for rounding mode FE_DOWNWARD", rintl(-0.8), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.7) returns -1.0 for rounding mode FE_DOWNWARD", rintl(-0.7), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.6) returns -1.0 for rounding mode FE_DOWNWARD", rintl(-0.6), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.5) returns -1.0 for rounding mode FE_DOWNWARD", rintl(-0.5), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.4) returns -1.0 for rounding mode FE_DOWNWARD", rintl(-0.4), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.3) returns -1.0 for rounding mode FE_DOWNWARD", rintl(-0.3), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.2) returns -1.0 for rounding mode FE_DOWNWARD", rintl(-0.2), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.1) returns -1.0 for rounding mode FE_DOWNWARD", rintl(-0.1), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.0) returns -0.0 for rounding mode FE_DOWNWARD", rintl(-0.0), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.0) returns 0.0 for rounding mode FE_DOWNWARD", rintl(0.0), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.1) returns 0.0 for rounding mode FE_DOWNWARD", rintl(0.1), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.2) returns 0.0 for rounding mode FE_DOWNWARD", rintl(0.2), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.3) returns 0.0 for rounding mode FE_DOWNWARD", rintl(0.3), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.4) returns 0.0 for rounding mode FE_DOWNWARD", rintl(0.4), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.5) returns 0.0 for rounding mode FE_DOWNWARD", rintl(0.5), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.6) returns 0.0 for rounding mode FE_DOWNWARD", rintl(0.6), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.7) returns 0.0 for rounding mode FE_DOWNWARD", rintl(0.7), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.8) returns 0.0 for rounding mode FE_DOWNWARD", rintl(0.8), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.9) returns 0.0 for rounding mode FE_DOWNWARD", rintl(0.9), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(1.0) returns 1.0 for rounding mode FE_DOWNWARD", rintl(1.0), 1.0);

    fesetround(FE_UPWARD);
    ASSERT_EQUALS("rintl: Checking, if rintl(-1.0) returns -1.0 for rounding mode FE_UPWARD", rintl(-1.0), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.9) returns -0.0 for rounding mode FE_UPWARD", rintl(-0.9), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.8) returns -0.0 for rounding mode FE_UPWARD", rintl(-0.8), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.7) returns -0.0 for rounding mode FE_UPWARD", rintl(-0.7), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.6) returns -0.0 for rounding mode FE_UPWARD", rintl(-0.6), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.5) returns -0.0 for rounding mode FE_UPWARD", rintl(-0.5), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.4) returns -0.0 for rounding mode FE_UPWARD", rintl(-0.4), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.3) returns -0.0 for rounding mode FE_UPWARD", rintl(-0.3), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.2) returns -0.0 for rounding mode FE_UPWARD", rintl(-0.2), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.1) returns -0.0 for rounding mode FE_UPWARD", rintl(-0.1), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.0) returns -0.0 for rounding mode FE_UPWARD", rintl(-0.0), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.0) returns 0.0 for rounding mode FE_UPWARD", rintl(0.0), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.1) returns 1.0 for rounding mode FE_UPWARD", rintl(0.1), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.2) returns 1.0 for rounding mode FE_UPWARD", rintl(0.2), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.3) returns 1.0 for rounding mode FE_UPWARD", rintl(0.3), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.4) returns 1.0 for rounding mode FE_UPWARD", rintl(0.4), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.5) returns 1.0 for rounding mode FE_UPWARD", rintl(0.5), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.6) returns 1.0 for rounding mode FE_UPWARD", rintl(0.6), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.7) returns 1.0 for rounding mode FE_UPWARD", rintl(0.7), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.8) returns 1.0 for rounding mode FE_UPWARD", rintl(0.8), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.9) returns 1.0 for rounding mode FE_UPWARD", rintl(0.9), 1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(1.0) returns 1.0 for rounding mode FE_UPWARD", rintl(1.0), 1.0);

    fesetround(FE_TOWARDZERO);
    ASSERT_EQUALS("rintl: Checking, if rintl(-1.0) returns -1.0 for rounding mode FE_TOWARDZERO", rintl(-1.0), -1.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.9) returns -0.0 for rounding mode FE_TOWARDZERO", rintl(-0.9), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.8) returns -0.0 for rounding mode FE_TOWARDZERO", rintl(-0.8), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.7) returns -0.0 for rounding mode FE_TOWARDZERO", rintl(-0.7), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.6) returns -0.0 for rounding mode FE_TOWARDZERO", rintl(-0.6), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.5) returns -0.0 for rounding mode FE_TOWARDZERO", rintl(-0.5), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.4) returns -0.0 for rounding mode FE_TOWARDZERO", rintl(-0.4), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.3) returns -0.0 for rounding mode FE_TOWARDZERO", rintl(-0.3), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.2) returns -0.0 for rounding mode FE_TOWARDZERO", rintl(-0.2), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.1) returns -0.0 for rounding mode FE_TOWARDZERO", rintl(-0.1), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(-0.0) returns -0.0 for rounding mode FE_TOWARDZERO", rintl(-0.0), -0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.0) returns 0.0 for rounding mode FE_TOWARDZERO", rintl(0.0), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.1) returns 0.0 for rounding mode FE_TOWARDZERO", rintl(0.1), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.2) returns 0.0 for rounding mode FE_TOWARDZERO", rintl(0.2), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.3) returns 0.0 for rounding mode FE_TOWARDZERO", rintl(0.3), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.4) returns 0.0 for rounding mode FE_TOWARDZERO", rintl(0.4), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.5) returns 0.0 for rounding mode FE_TOWARDZERO", rintl(0.5), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.6) returns 0.0 for rounding mode FE_TOWARDZERO", rintl(0.6), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.7) returns 0.0 for rounding mode FE_TOWARDZERO", rintl(0.7), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.8) returns 0.0 for rounding mode FE_TOWARDZERO", rintl(0.8), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(0.9) returns 0.0 for rounding mode FE_TOWARDZERO", rintl(0.9), 0.0);
    ASSERT_EQUALS("rintl: Checking, if rintl(1.0) returns 1.0 for rounding mode FE_TOWARDZERO", rintl(1.0), 1.0);

    ASSERT_EQUALS("rintl: Checking, if errno is unmodified", pre_errno, errno);

    fesetround(FE_TONEAREST);
}


static void test_round()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("round: Checking, if round(-1.0) returns -1.0", round(-1.0), -1.0);
    ASSERT_EQUALS("round: Checking, if round(-0.9) returns -1.0", round(-0.9), -1.0);
    ASSERT_EQUALS("round: Checking, if round(-0.8) returns -1.0", round(-0.8), -1.0);
    ASSERT_EQUALS("round: Checking, if round(-0.7) returns -1.0", round(-0.7), -1.0);
    ASSERT_EQUALS("round: Checking, if round(-0.6) returns -1.0", round(-0.6), -1.0);
    ASSERT_EQUALS("round: Checking, if round(-0.5) returns -1.0", round(-0.5), -1.0);
    ASSERT_EQUALS("round: Checking, if round(-0.4) returns -0.0", round(-0.4), -0.0);
    ASSERT_EQUALS("round: Checking, if round(-0.3) returns -0.0", round(-0.3), -0.0);
    ASSERT_EQUALS("round: Checking, if round(-0.2) returns -0.0", round(-0.2), -0.0);
    ASSERT_EQUALS("round: Checking, if round(-0.1) returns -0.0", round(-0.1), -0.0);
    ASSERT_EQUALS("round: Checking, if round(-0.0) returns -0.0", round(-0.0), -0.0);
    ASSERT_EQUALS("round: Checking, if round(0.0) returns 0.0", round(0.0), 0.0);
    ASSERT_EQUALS("round: Checking, if round(0.1) returns 0.0", round(0.1), 0.0);
    ASSERT_EQUALS("round: Checking, if round(0.2) returns 0.0", round(0.2), 0.0);
    ASSERT_EQUALS("round: Checking, if round(0.3) returns 0.0", round(0.3), 0.0);
    ASSERT_EQUALS("round: Checking, if round(0.4) returns 0.0", round(0.4), 0.0);
    ASSERT_EQUALS("round: Checking, if round(0.5) returns 1.0", round(0.5), 1.0);
    ASSERT_EQUALS("round: Checking, if round(0.6) returns 1.0", round(0.6), 1.0);
    ASSERT_EQUALS("round: Checking, if round(0.7) returns 1.0", round(0.7), 1.0);
    ASSERT_EQUALS("round: Checking, if round(0.8) returns 1.0", round(0.8), 1.0);
    ASSERT_EQUALS("round: Checking, if round(0.9) returns 1.0", round(0.9), 1.0);
    ASSERT_EQUALS("round: Checking, if round(1.0) returns 1.0", round(1.0), 1.0);
    ASSERT_EQUALS("round: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_roundf()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("roundf: Checking, if roundf(-1.0f) returns -1.0f", roundf(-1.0f), -1.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(-0.9f) returns -1.0f", roundf(-0.9f), -1.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(-0.8f) returns -1.0f", roundf(-0.8f), -1.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(-0.7f) returns -1.0f", roundf(-0.7f), -1.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(-0.6f) returns -1.0f", roundf(-0.6f), -1.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(-0.5f) returns -1.0f", roundf(-0.5f), -1.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(-0.4f) returns -0.0f", roundf(-0.4f), -0.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(-0.3f) returns -0.0f", roundf(-0.3f), -0.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(-0.2f) returns -0.0f", roundf(-0.2f), -0.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(-0.1f) returns -0.0f", roundf(-0.1f), -0.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(-0.0f) returns -0.0f", roundf(-0.0f), -0.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(0.0f) returns 0.0f", roundf(0.0f), 0.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(0.1f) returns 0.0f", roundf(0.1f), 0.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(0.2f) returns 0.0f", roundf(0.2f), 0.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(0.3f) returns 0.0f", roundf(0.3f), 0.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(0.4f) returns 0.0f", roundf(0.4f), 0.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(0.5f) returns 1.0f", roundf(0.5f), 1.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(0.6f) returns 1.0f", roundf(0.6f), 1.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(0.7f) returns 1.0f", roundf(0.7f), 1.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(0.8f) returns 1.0f", roundf(0.8f), 1.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(0.9f) returns 1.0f", roundf(0.9f), 1.0f);
    ASSERT_EQUALS("roundf: Checking, if roundf(1.0f) returns 1.0f", roundf(1.0f), 1.0f);
    ASSERT_EQUALS("roundf: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_roundl()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("roundl: Checking, if roundl(-1.0) returns -1.0", roundl(-1.0), -1.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(-0.9) returns -1.0", roundl(-0.9), -1.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(-0.8) returns -1.0", roundl(-0.8), -1.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(-0.7) returns -1.0", roundl(-0.7), -1.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(-0.6) returns -1.0", roundl(-0.6), -1.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(-0.5) returns -1.0", roundl(-0.5), -1.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(-0.4) returns -0.0", roundl(-0.4), -0.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(-0.3) returns -0.0", roundl(-0.3), -0.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(-0.2) returns -0.0", roundl(-0.2), -0.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(-0.1) returns -0.0", roundl(-0.1), -0.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(-0.0) returns -0.0", roundl(-0.0), -0.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(0.0) returns 0.0", roundl(0.0), 0.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(0.1) returns 0.0", roundl(0.1), 0.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(0.2) returns 0.0", roundl(0.2), 0.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(0.3) returns 0.0", roundl(0.3), 0.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(0.4) returns 0.0", roundl(0.4), 0.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(0.5) returns 1.0", roundl(0.5), 1.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(0.6) returns 1.0", roundl(0.6), 1.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(0.7) returns 1.0", roundl(0.7), 1.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(0.8) returns 1.0", roundl(0.8), 1.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(0.9) returns 1.0", roundl(0.9), 1.0);
    ASSERT_EQUALS("roundl: Checking, if roundl(1.0) returns 1.0", roundl(1.0), 1.0);
    ASSERT_EQUALS("roundl: Checking, if errno is unmodified", pre_errno, errno);
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


static void test_tan()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("tan: Checking, if tan(-(2 * M_PI)) returns 0.0", tan(-(2 * M_PI)), -0.0001, 0.0001);
    ASSERT_IN_RANGE("tan: Checking, if tan(-(3 * M_PI_2)) returns a very low number", tan(-(3 * M_PI_2)), -6000000000000000.000000, -5000000000000000.000000);
    ASSERT_IN_RANGE("tan: Checking, if tan(-M_PI) returns 0.0", tan(-M_PI), -0.0001, 0.0001);
    ASSERT_IN_RANGE("tan: Checking, if tan(-M_PI_2) returns a very low number", tan(-M_PI_2), -17000000000000000.000000, -16000000000000000.000000);
    ASSERT_IN_RANGE("tan: Checking, if tan(0.0) returns 0.0", tan(0.0), -0.0001, 0.0001);
    ASSERT_IN_RANGE("tan: Checking, if tan(M_PI_2) returns a very high number", tan(M_PI_2), 16000000000000000.000000, 17000000000000000.000000);
    ASSERT_IN_RANGE("tan: Checking, if tan(M_PI) returns 0.0", tan(M_PI), -0.0001, 0.0001);
    ASSERT_IN_RANGE("tan: Checking, if tan(3 * M_PI_2) returns a very high number", tan(3 * M_PI_2), 5000000000000000.000000, 6000000000000000.000000);
    ASSERT_IN_RANGE("tan: Checking, if tan(2 * M_PI) returns 0.0", tan(2 * M_PI), -0.0001, 0.0001);
    ASSERT_EQUALS("tan: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_tanf()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("tanf: Checking, if tanf(-(2 * M_PI)) returns 0.0f", tanf(-(2 * M_PI)), -0.0001, 0.0001);
    ASSERT_IN_RANGE("tanf: Checking, if tanf(-(3 * M_PI_2)) returns a very high number", tanf(-(3 * M_PI_2)), 80000000.000000f, 90000000.000000f);
    ASSERT_IN_RANGE("tanf: Checking, if tanf(-M_PI) returns 0.0f", tanf(-M_PI), -0.0001f, 0.0001f);
    ASSERT_IN_RANGE("tanf: Checking, if tanf(-M_PI_2) returns a very high number", tanf(-M_PI_2), 20000000.000000f, 30000000.000000f);
    ASSERT_IN_RANGE("tanf: Checking, if tanf(0.0) returns 0.0f", tanf(0.0), -0.0001f, 0.0001f);
    ASSERT_IN_RANGE("tanf: Checking, if tanf(M_PI_2) returns a very low number", tanf(M_PI_2), -30000000.000000f, 20000000.000000f);
    ASSERT_IN_RANGE("tanf: Checking, if tanf(M_PI) returns 0.0f", tanf(M_PI), -0.0001f, 0.0001f);
    ASSERT_IN_RANGE("tanf: Checking, if tanf(3 * M_PI_2) returns a very low number", tanf(3 * M_PI_2), -90000000.000000f, -80000000.000000f);
    ASSERT_IN_RANGE("tanf: Checking, if tanf(2 * M_PI) returns 0.0f", tanf(2 * M_PI), -0.0001f, 0.0001f);
    ASSERT_EQUALS("tanf: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_tanl()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("tanl: Checking, if tanl(-(2 * M_PI)) returns 0.0", tanl(-(2 * M_PI)), -0.0001, 0.0001);
    ASSERT_IN_RANGE("tanl: Checking, if tanl(-(3 * M_PI_2)) returns a very low number", tanl(-(3 * M_PI_2)), -6000000000000000.000000, -5000000000000000.000000);
    ASSERT_IN_RANGE("tanl: Checking, if tanl(-M_PI) returns 0.0", tanl(-M_PI), -0.0001, 0.0001);
    ASSERT_IN_RANGE("tanl: Checking, if tanl(-M_PI_2) returns a very low number", tanl(-M_PI_2), -17000000000000000.000000, -16000000000000000.000000);
    ASSERT_IN_RANGE("tanl: Checking, if tanl(0.0) returns 0.0", tanl(0.0), -0.0001, 0.0001);
    ASSERT_IN_RANGE("tanl: Checking, if tanl(M_PI_2) returns a very high number", tanl(M_PI_2), 16000000000000000.000000, 17000000000000000.000000);
    ASSERT_IN_RANGE("tanl: Checking, if tanl(M_PI) returns 0.0", tanl(M_PI), -0.0001, 0.0001);
    ASSERT_IN_RANGE("tanl: Checking, if tanl(3 * M_PI_2) returns a very high number", tanl(3 * M_PI_2), 5000000000000000.000000, 6000000000000000.000000);
    ASSERT_IN_RANGE("tanl: Checking, if tanl(2 * M_PI) returns 0.0", tanl(2 * M_PI), -0.0001, 0.0001);
    ASSERT_EQUALS("tanl: Checking, if errno is unmodified", pre_errno, errno);
}


static float generate_nan()
{
    /*
     * A compiler independent way to generate a NaN value.
     * We need to perform a little hack here, because modern compilers
     * would optimize "regular" calculated NaN values.
     * This should work on any processor which uses the IEEE 754 floating point format.
     *
     * nan_raw = 0x7FBFFFFF (sign bit 0, a = 0, rest of bits 1)
     */
    static int nan_raw = 0x7FBFFFFF;
    return *(float*)&nan_raw;
}


static void test_isnan()
{
    const int pre_errno = errno;

    ASSERT_FALSE("isnan: Checking, if isnan(42.0) returns 0", isnan(42.0));
    ASSERT_FALSE("isnan: Checking, if isnan(-42.0) returns 0", isnan(-42.0));
    ASSERT_FALSE("isnan: Checking, if isnan(0.0) returns 0", isnan(0.0));
    ASSERT_TRUE("isnan: Checking, if isnan(0x7FBFFFFF) returns 1", isnan(generate_nan()));
    ASSERT_EQUALS("isnan: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_isless()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("isless: Checking, if isless(42.0, 43.0) returns 1", isless(42.0, 43.0), 1);
    ASSERT_EQUALS("isless: Checking, if isless(-42.0, 42.0) returns 1", isless(-42.0, 42.0), 1);
    ASSERT_EQUALS("isless: Checking, if isless(42.0, 41.0) returns 0", isless(42.0, 41.0), 0);
    ASSERT_EQUALS("isless: Checking, if isless(-42.0, -43.0) returns 0", isless(-42.0, -43.0), 0);
    ASSERT_EQUALS("isless: Checking, if isless(0.0, 0.0) returns 0", isless(0.0, 0.0), 0);
    ASSERT_EQUALS("isless: Checking, if isless returns 0, if x is NaN", isless(generate_nan(), -1.0f), 0);
    ASSERT_EQUALS("isless: Checking, if isless returns 0, if y is NaN", isless( -1.0f, generate_nan()), 0);
    ASSERT_EQUALS("isless: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_islessequal()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("islessequal: Checking, if islessequal(42.0, 43.0) returns 1", islessequal(42.0, 43.0), 1);
    ASSERT_EQUALS("islessequal: Checking, if islessequal(-42.0, 42.0) returns 1", islessequal(-42.0, 42.0), 1);
    ASSERT_EQUALS("islessequal: Checking, if islessequal(42.0, 41.0) returns 0", islessequal(42.0, 41.0), 0);
    ASSERT_EQUALS("islessequal: Checking, if islessequal(-42.0, -43.0) returns 0", islessequal(-42.0, -43.0), 0);
    ASSERT_EQUALS("islessequal: Checking, if islessequal(0.0, 0.0) returns 1", islessequal(0.0, 0.0), 1);
    ASSERT_EQUALS("islessequal: Checking, if islessequal returns 0, if x is NaN", islessequal(generate_nan(), -1.0f), 0);
    ASSERT_EQUALS("islessequal: Checking, if islessequal returns 0, if y is NaN", islessequal( -1.0f, generate_nan()), 0);
    ASSERT_EQUALS("islessequal: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_islessgreater()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("islessgreater: Checking, if islessgreater(42.0, 43.0) returns 1", islessgreater(42.0, 43.0), 1);
    ASSERT_EQUALS("islessgreater: Checking, if islessgreater(-42.0, 42.0) returns 1", islessgreater(-42.0, 42.0), 1);
    ASSERT_EQUALS("islessgreater: Checking, if islessgreater(42.0, 41.0) returns 1", islessgreater(42.0, 41.0), 1);
    ASSERT_EQUALS("islessgreater: Checking, if islessgreater(-42.0, -43.0) returns 1", islessgreater(-42.0, -43.0), 1);
    ASSERT_EQUALS("islessgreater: Checking, if islessgreater(0.0, 0.0) returns 0", islessgreater(0.0, 0.0), 0);
    ASSERT_EQUALS("islessgreater: Checking, if islessgreater returns 0, if x is NaN", islessgreater(generate_nan(), -1.0f), 0);
    ASSERT_EQUALS("islessgreater: Checking, if islessgreater returns 0, if y is NaN", islessgreater( -1.0f, generate_nan()), 0);
    ASSERT_EQUALS("islessgreater: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_isgreater()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("isgreater: Checking, if isgreater(42.0, 43.0) returns 0", isgreater(42.0, 43.0), 0);
    ASSERT_EQUALS("isgreater: Checking, if isgreater(-42.0, 42.0) returns 0", isgreater(-42.0, 42.0), 0);
    ASSERT_EQUALS("isgreater: Checking, if isgreater(42.0, 41.0) returns 1", isgreater(42.0, 41.0), 1);
    ASSERT_EQUALS("isgreater: Checking, if isgreater(-42.0, -43.0) returns 1", isgreater(-42.0, -43.0), 1);
    ASSERT_EQUALS("isgreater: Checking, if isgreater(0.0, 0.0) returns 0", isgreater(0.0, 0.0), 0);
    ASSERT_EQUALS("isgreater: Checking, if isgreater returns 0, if x is NaN", isgreater(generate_nan(), -1.0f), 0);
    ASSERT_EQUALS("isgreater: Checking, if isgreater returns 0, if y is NaN", isgreater( -1.0f, generate_nan()), 0);
    ASSERT_EQUALS("isgreater: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_isgreaterequal()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("isgreaterequal: Checking, if isgreaterequal(42.0, 43.0) returns 0", isgreaterequal(42.0, 43.0), 0);
    ASSERT_EQUALS("isgreaterequal: Checking, if isgreaterequal(-42.0, 42.0) returns 0", isgreaterequal(-42.0, 42.0), 0);
    ASSERT_EQUALS("isgreaterequal: Checking, if isgreaterequal(42.0, 41.0) returns 1", isgreaterequal(42.0, 41.0), 1);
    ASSERT_EQUALS("isgreaterequal: Checking, if isgreaterequal(-42.0, -43.0) returns 1", isgreaterequal(-42.0, -43.0), 1);
    ASSERT_EQUALS("isgreaterequal: Checking, if isgreaterequal(0.0, 0.0) returns 1", isgreaterequal(0.0, 0.0), 1);
    ASSERT_EQUALS("isgreaterequal: Checking, if isgreaterequal returns 0, if x is NaN", isgreaterequal(generate_nan(), -1.0f), 0);
    ASSERT_EQUALS("isgreaterequal: Checking, if isgreaterequal returns 0, if y is NaN", isgreaterequal( -1.0f, generate_nan()), 0);
    ASSERT_EQUALS("isgreaterequal: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_trunc()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("trunc: Checking, if trunc(-2.0) returns -2.0", trunc(-2.0), -2.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-1.9) returns -1.9", trunc(-1.9), -1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-1.8) returns -1.8", trunc(-1.8), -1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-1.7) returns -1.7", trunc(-1.7), -1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-1.6) returns -1.6", trunc(-1.6), -1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-1.5) returns -1.5", trunc(-1.5), -1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-1.4) returns -1.4", trunc(-1.4), -1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-1.3) returns -1.3", trunc(-1.3), -1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-1.2) returns -1.2", trunc(-1.2), -1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-1.1) returns -1.1", trunc(-1.1), -1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-1.0) returns -1.0", trunc(-1.0), -1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-0.9) returns -0.9", trunc(-0.9), -0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-0.8) returns -0.8", trunc(-0.8), -0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-0.7) returns -0.7", trunc(-0.7), -0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-0.6) returns -0.6", trunc(-0.6), -0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-0.5) returns -0.5", trunc(-0.5), -0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-0.4) returns -0.4", trunc(-0.4), -0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-0.3) returns -0.3", trunc(-0.3), -0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-0.2) returns -0.2", trunc(-0.2), -0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-0.1) returns -0.1", trunc(-0.1), -0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(-0.0) returns -0.0", trunc(-0.0), -0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(0.0) returns 0.0", trunc(0.0), 0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(0.1) returns 0.1", trunc(0.1), 0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(0.2) returns 0.2", trunc(0.2), 0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(0.3) returns 0.3", trunc(0.3), 0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(0.4) returns 0.4", trunc(0.4), 0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(0.5) returns 0.5", trunc(0.5), 0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(0.6) returns 0.6", trunc(0.6), 0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(0.7) returns 0.7", trunc(0.7), 0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(0.8) returns 0.8", trunc(0.8), 0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(0.9) returns 0.9", trunc(0.9), 0.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(1.0) returns 1.0", trunc(1.0), 1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(1.1) returns 1.1", trunc(1.1), 1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(1.2) returns 1.2", trunc(1.2), 1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(1.3) returns 1.3", trunc(1.3), 1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(1.4) returns 1.4", trunc(1.4), 1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(1.5) returns 1.5", trunc(1.5), 1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(1.6) returns 1.6", trunc(1.6), 1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(1.7) returns 1.7", trunc(1.7), 1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(1.8) returns 1.8", trunc(1.8), 1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(1.9) returns 1.9", trunc(1.9), 1.0);
    ASSERT_EQUALS("trunc: Checking, if trunc(2.0) returns 2.0", trunc(2.0), 2.0);
    ASSERT_EQUALS("trunc: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_truncf()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("truncf: Checking, if truncf(-2.0f) returns -2.0f", truncf(-2.0f), -2.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-1.9f) returns -1.9f", truncf(-1.9f), -1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-1.8f) returns -1.8f", truncf(-1.8f), -1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-1.7f) returns -1.7f", truncf(-1.7f), -1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-1.6f) returns -1.6f", truncf(-1.6f), -1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-1.5f) returns -1.5f", truncf(-1.5f), -1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-1.4f) returns -1.4f", truncf(-1.4f), -1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-1.3f) returns -1.3f", truncf(-1.3f), -1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-1.2f) returns -1.2f", truncf(-1.2f), -1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-1.1f) returns -1.1f", truncf(-1.1f), -1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-1.0f) returns -1.0f", truncf(-1.0f), -1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-0.9f) returns -0.9f", truncf(-0.9f), -0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-0.8f) returns -0.8f", truncf(-0.8f), -0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-0.7f) returns -0.7f", truncf(-0.7f), -0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-0.6f) returns -0.6f", truncf(-0.6f), -0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-0.5f) returns -0.5f", truncf(-0.5f), -0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-0.4f) returns -0.4f", truncf(-0.4f), -0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-0.3f) returns -0.3f", truncf(-0.3f), -0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-0.2f) returns -0.2f", truncf(-0.2f), -0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-0.1f) returns -0.1f", truncf(-0.1f), -0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(-0.0f) returns -0.0f", truncf(-0.0f), -0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(0.0f) returns 0.0f", truncf(0.0f), 0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(0.1f) returns 0.1f", truncf(0.1f), 0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(0.2f) returns 0.2f", truncf(0.2f), 0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(0.3f) returns 0.3f", truncf(0.3f), 0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(0.4f) returns 0.4f", truncf(0.4f), 0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(0.5f) returns 0.5f", truncf(0.5f), 0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(0.6f) returns 0.6f", truncf(0.6f), 0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(0.7f) returns 0.7f", truncf(0.7f), 0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(0.8f) returns 0.8f", truncf(0.8f), 0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(0.9f) returns 0.9f", truncf(0.9f), 0.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(1.0f) returns 1.0f", truncf(1.0f), 1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(1.1f) returns 1.1f", truncf(1.1f), 1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(1.2f) returns 1.2f", truncf(1.2f), 1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(1.3f) returns 1.3f", truncf(1.3f), 1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(1.4f) returns 1.4f", truncf(1.4f), 1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(1.5f) returns 1.5f", truncf(1.5f), 1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(1.6f) returns 1.6f", truncf(1.6f), 1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(1.7f) returns 1.7f", truncf(1.7f), 1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(1.8f) returns 1.8f", truncf(1.8f), 1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(1.9f) returns 1.9f", truncf(1.9f), 1.0f);
    ASSERT_EQUALS("truncf: Checking, if truncf(2.0f) returns 2.0f", truncf(2.0f), 2.0f);
    ASSERT_EQUALS("truncf: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_truncl()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("truncl: Checking, if truncl(-2.0) returns -2.0", truncl(-2.0), -2.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-1.9) returns -1.9", truncl(-1.9), -1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-1.8) returns -1.8", truncl(-1.8), -1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-1.7) returns -1.7", truncl(-1.7), -1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-1.6) returns -1.6", truncl(-1.6), -1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-1.5) returns -1.5", truncl(-1.5), -1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-1.4) returns -1.4", truncl(-1.4), -1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-1.3) returns -1.3", truncl(-1.3), -1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-1.2) returns -1.2", truncl(-1.2), -1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-1.1) returns -1.1", truncl(-1.1), -1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-1.0) returns -1.0", truncl(-1.0), -1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-0.9) returns -0.9", truncl(-0.9), -0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-0.8) returns -0.8", truncl(-0.8), -0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-0.7) returns -0.7", truncl(-0.7), -0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-0.6) returns -0.6", truncl(-0.6), -0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-0.5) returns -0.5", truncl(-0.5), -0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-0.4) returns -0.4", truncl(-0.4), -0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-0.3) returns -0.3", truncl(-0.3), -0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-0.2) returns -0.2", truncl(-0.2), -0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-0.1) returns -0.1", truncl(-0.1), -0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(-0.0) returns -0.0", truncl(-0.0), -0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(0.0) returns 0.0", truncl(0.0), 0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(0.1) returns 0.1", truncl(0.1), 0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(0.2) returns 0.2", truncl(0.2), 0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(0.3) returns 0.3", truncl(0.3), 0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(0.4) returns 0.4", truncl(0.4), 0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(0.5) returns 0.5", truncl(0.5), 0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(0.6) returns 0.6", truncl(0.6), 0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(0.7) returns 0.7", truncl(0.7), 0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(0.8) returns 0.8", truncl(0.8), 0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(0.9) returns 0.9", truncl(0.9), 0.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(1.0) returns 1.0", truncl(1.0), 1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(1.1) returns 1.1", truncl(1.1), 1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(1.2) returns 1.2", truncl(1.2), 1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(1.3) returns 1.3", truncl(1.3), 1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(1.4) returns 1.4", truncl(1.4), 1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(1.5) returns 1.5", truncl(1.5), 1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(1.6) returns 1.6", truncl(1.6), 1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(1.7) returns 1.7", truncl(1.7), 1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(1.8) returns 1.8", truncl(1.8), 1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(1.9) returns 1.9", truncl(1.9), 1.0);
    ASSERT_EQUALS("truncl: Checking, if truncl(2.0) returns 2.0", truncl(2.0), 2.0);
    ASSERT_EQUALS("truncl: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_remainder()
{
    const int pre_errno = errno;

    ASSERT_IN_RANGE("remainder: Checking, if remainder(+5.1, +3.0) returns -0.9", remainder(5.1, 3), -0.99, -0.79);
    ASSERT_IN_RANGE("remainder: Checking, if remainder(-5.1, +3.0) returns 0.9", remainder(-5.1, 3), 0.79, 0.99);
    ASSERT_IN_RANGE("remainder: Checking, if remainder(+5.1, -3.0) returns -0.9", remainder(5.1, -3), -0.99, -0.79);
    ASSERT_IN_RANGE("remainder: Checking, if remainder(-5.1, -3.0) returns 0.9", remainder(-5.1, -3), 0.79, 0.99);
    ASSERT_EQUALS("remainder: Checking, if remainder(0.0, +1.0) returns 0.0", remainder(0.0, 1.0), 0.0);
    ASSERT_EQUALS("remainder: Checking, if remainder(-0.0, +1.0) returns -0.0", remainder(-0.0, 1.0), -0.0);
    ASSERT_EQUALS("remainder: Checking, if errno is unmodified on valid input", pre_errno, errno);

    feclearexcept(FE_ALL_EXCEPT);
    ASSERT_EQUALS("remainder: Checking, if remainder(+5.1, 0.0) returns 0.0", remainder(5.1, 0.0), 0.0);
    ASSERT_EQUALS("remainder: Checking, if errno is set to EDOM", errno, EDOM);
    ASSERT_EQUALS("remainder: Checking, if FE_INVALID gets raised", fetestexcept(FE_INVALID), FE_INVALID);

    feclearexcept(FE_ALL_EXCEPT);
}


static void test_remainderf()
{
    const int pre_errno = errno;
    
    ASSERT_IN_RANGE("remainderf: Checking, if remainderf(+5.1f, +3.0f) returns -0.9f", remainderf(5.1f, 3.0f), -0.99f, -0.79f);
    ASSERT_IN_RANGE("remainderf: Checking, if remainderf(-5.1f, +3.0f) returns 0.9f", remainderf(-5.1f, 3.0f), 0.79f, 0.99f);
    ASSERT_IN_RANGE("remainderf: Checking, if remainderf(+5.1f, -3.0f) returns -0.9f", remainderf(5.1f, -3.0f), -0.99f, -0.79f);
    ASSERT_IN_RANGE("remainderf: Checking, if remainderf(-5.1f, -3.0f) returns 0.9f", remainderf(-5.1f, -3.0f), 0.79f, 0.99f);
    ASSERT_EQUALS("remainderf: Checking, if remainderf(0.0f, +1.0f) returns 0.0f", remainderf(0.0f, 1.0f), 0.0f);
    ASSERT_EQUALS("remainderf: Checking, if remainderf(-0.0f, +1.0f) returns -0.0f", remainderf(-0.0f, 1.0f), -0.0f);
    ASSERT_EQUALS("remainderf: Checking, if errno is unmodified on valid input", pre_errno, errno);

    feclearexcept(FE_ALL_EXCEPT);
    ASSERT_EQUALS("remainderf: Checking, if remainderf(+5.1f, 0.0f) returns 0.0f", remainderf(5.1f, 0.0f), 0.0f);
    ASSERT_EQUALS("remainderf: Checking, if errno is set to EDOM", errno, EDOM);
    ASSERT_EQUALS("remainderf: Checking, if FE_INVALID gets raised", fetestexcept(FE_INVALID), FE_INVALID);

    feclearexcept(FE_ALL_EXCEPT);
}


static void test_remainderl()
{
    const int pre_errno = errno;
    
    ASSERT_IN_RANGE("remainderl: Checking, if remainderl(+5.1, +3.0) returns -0.9", remainderl(5.1, 3), -0.99, -0.79);
    ASSERT_IN_RANGE("remainderl: Checking, if remainderl(-5.1, +3.0) returns 0.9", remainderl(-5.1, 3), 0.79, 0.99);
    ASSERT_IN_RANGE("remainderl: Checking, if remainderl(+5.1, -3.0) returns -0.9", remainderl(5.1, -3), -0.99, -0.79);
    ASSERT_IN_RANGE("remainderl: Checking, if remainderl(-5.1, -3.0) returns 0.9", remainderl(-5.1, -3), 0.79, 0.99);
    ASSERT_EQUALS("remainderl: Checking, if remainderl(0.0, +1.0) returns 0.0", remainderl(0.0, 1.0), 0.0);
    ASSERT_EQUALS("remainderl: Checking, if remainderl(-0.0, +1.0) returns -0.0", remainderl(-0.0, 1.0), -0.0);
    ASSERT_EQUALS("remainderl: Checking, if errno is unmodified on valid input", pre_errno, errno);

    feclearexcept(FE_ALL_EXCEPT);
    ASSERT_EQUALS("remainderl: Checking, if remainderl(+5.1, 0.0) returns 0.0", remainderl(5.1, 0.0), 0.0);
    ASSERT_EQUALS("remainderl: Checking, if errno is set to EDOM", errno, EDOM);
    ASSERT_EQUALS("remainderl: Checking, if FE_INVALID gets raised", fetestexcept(FE_INVALID), FE_INVALID);

    feclearexcept(FE_ALL_EXCEPT);
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

    test_copysign();
    test_copysignf();
    test_copysignl();

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

    test_lrint();
    test_lrintf();
    test_lrintl();

    test_lround();
    test_lroundf();
    test_lroundl();

    test_llrint();
    test_llrintf();
    test_llrintl();

    test_llround();
    test_llroundf();
    test_llroundl();

    test_rint();
    test_rintf();
    test_rintl();

    test_round();
    test_roundf();
    test_roundl();

    test_sin();
    test_sinf();
    test_sinl();

    test_tan();
    test_tanf();
    test_tanl();

    test_isnan();
    test_isless();
    test_islessequal();
    test_islessgreater();
    test_isgreater();
    test_isgreaterequal();

    test_trunc();
    test_truncf();
    test_truncl();

    test_remainder();
    test_remainderf();
    test_remainderl();
}
