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


void run_math_lib_tests()
{
    TEST_CASE("Test POSIX math.h functions");

    // TODO: Check definitions!
    test_acos();
    test_acosf();
    test_acosl();
}
