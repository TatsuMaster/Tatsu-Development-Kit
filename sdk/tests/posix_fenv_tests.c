#include "posix_fenv_tests.h"

#include "../posix/errno.h"
#include "../posix/fenv.h"
#include "../../ttf/ttf.h"


static void test_definitions()
{
    ASSERT_EQUALS("Checking, if FE_DIVBYZERO is defined correctly", FE_DIVBYZERO, 4);
    ASSERT_EQUALS("Checking, if FE_INEXACT is defined correctly", FE_INEXACT, 32);
    ASSERT_EQUALS("Checking, if FE_INVALID is defined correctly", FE_INVALID, 1);
    ASSERT_EQUALS("Checking, if FE_OVERFLOW is defined correctly", FE_OVERFLOW, 8);
    ASSERT_EQUALS("Checking, if FE_UNDERFLOW is defined correctly", FE_UNDERFLOW, 16);
    ASSERT_EQUALS("Checking, if FE_DOWNWARD is defined correctly", FE_DOWNWARD, 1024);
    ASSERT_EQUALS("Checking, if FE_TONEAREST is defined correctly", FE_TONEAREST, 0);
    ASSERT_EQUALS("Checking, if FE_TOWARDZERO is defined correctly", FE_TOWARDZERO, 3072);
    ASSERT_EQUALS("Checking, if FE_UPWARD is defined correctly", FE_UPWARD, 2048);
    ASSERT_EQUALS("Checking, if FE_ALL_EXCEPT is defined correctly", FE_ALL_EXCEPT, 3133);
}


static void test_feclearexcept()
{
    const int pre_errno = errno;
    ASSERT_EQUALS("feclearexcept: Checking, if feclearexcept(FE_UNDERFLOW | FE_DIVBYZERO) returns 0, if no exceptions occurred", feclearexcept(FE_UNDERFLOW | FE_DIVBYZERO), 0);
    feraiseexcept(FE_UNDERFLOW | FE_DIVBYZERO);
    ASSERT_EQUALS("feclearexcept: Checking, if feclearexcept() removes all specified exceptions (I)", feclearexcept(FE_DIVBYZERO), 0);
    ASSERT_EQUALS("feclearexcept: Checking, if feclearexcept() removes all specified exceptions (II)", fetestexcept(FE_UNDERFLOW | FE_DIVBYZERO), FE_UNDERFLOW);
    ASSERT_EQUALS("feclearexcept: Checking, if errno is unmodified", pre_errno, errno);
    feclearexcept(FE_ALL_EXCEPT);
}


static void test_fetestexcept()
{
    const int pre_errno = errno;
    ASSERT_EQUALS("fetestexcept: Checking, if fetestexcept(FE_UNDERFLOW | FE_DIVBYZERO) returns 0, if exceptions did not occur", fetestexcept(FE_UNDERFLOW | FE_DIVBYZERO), 0);
    feraiseexcept(FE_DIVBYZERO);
    ASSERT_EQUALS("fetestexcept: Checking, if fetestexcept(FE_UNDERFLOW | FE_DIVBYZERO) returns the values, if exceptions did occur (I)", fetestexcept(FE_UNDERFLOW | FE_DIVBYZERO), (FE_DIVBYZERO));
    feraiseexcept(FE_UNDERFLOW | FE_DIVBYZERO);
    ASSERT_EQUALS("fetestexcept: Checking, if fetestexcept(FE_UNDERFLOW | FE_DIVBYZERO) returns the values, if exceptions did occur (II)", fetestexcept(FE_UNDERFLOW | FE_DIVBYZERO), (FE_UNDERFLOW | FE_DIVBYZERO));
    ASSERT_EQUALS("fetestexcept: Checking, if fetestexcept() tests no other exception values", fetestexcept(FE_INEXACT | FE_INVALID | FE_OVERFLOW | FE_DOWNWARD | FE_TONEAREST | FE_TOWARDZERO | FE_UPWARD), 0);
    ASSERT_EQUALS("fetestexcept: Checking, if errno is unmodified", pre_errno, errno);
    feclearexcept(FE_ALL_EXCEPT);
}


static void test_feraiseexcept()
{
    const int pre_errno = errno;
    ASSERT_EQUALS("feraiseexcept: Checking, if feraiseexcept(FE_UNDERFLOW | FE_DIVBYZERO) returns 0", feraiseexcept(FE_UNDERFLOW | FE_DIVBYZERO), 0);
    ASSERT_EQUALS("feraiseexcept: Checking, if feraiseexcept(FE_UNDERFLOW | FE_DIVBYZERO) sets the exception values", fetestexcept(FE_UNDERFLOW | FE_DIVBYZERO), (FE_UNDERFLOW | FE_DIVBYZERO));
    ASSERT_EQUALS("feraiseexcept: Checking, if feraiseexcept(FE_UNDERFLOW | FE_DIVBYZERO) sets no other exception values", fetestexcept(FE_INEXACT | FE_INVALID | FE_OVERFLOW | FE_DOWNWARD | FE_TONEAREST | FE_TOWARDZERO | FE_UPWARD), 0);
    ASSERT_EQUALS("feraiseexcept: Checking, if errno is unmodified", pre_errno, errno);
    feclearexcept(FE_ALL_EXCEPT);
}


// Check fenv functions
void run_fenv_tests()
{
    TEST_CASE("Test POSIX fenv.h functions");

    test_definitions();
    test_feclearexcept();
    test_fetestexcept();
    test_feraiseexcept();
}