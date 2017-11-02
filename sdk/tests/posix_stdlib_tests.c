#include "posix_stdlib_tests.h"

#include "../crt/limits.h"
#include "../posix/errno.h"
#include "../posix/stdlib.h"
#include "../../ttf/ttf.h"


static void test_abs()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("abs: Checking, if abs(0) returns 0", abs(0), 0);
    ASSERT_EQUALS("abs: Checking, if abs(1) returns 1", abs(1), 1);
    ASSERT_EQUALS("abs: Checking, if abs(-1) returns 1", abs(-1), 1);
    ASSERT_EQUALS("abs: Checking, if abs(1073741823) returns 1073741823", abs(1073741823), 1073741823);
    ASSERT_EQUALS("abs: Checking, if abs(-1073741824) returns 1073741824", abs(-1073741824), 1073741824);
    ASSERT_EQUALS("abs: Checking, if abs(2147483647) returns 2147483647", abs(2147483647), 2147483647);
    ASSERT_EQUALS("abs: Checking, if abs(-2147483648) returns 2147483648", abs(-2147483648), 2147483648);
    ASSERT_EQUALS("abs: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_labs()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("labs: Checking, if labs(0) returns 0", labs(0), 0);
    ASSERT_EQUALS("labs: Checking, if labs(1) returns 1", labs(1), 1);
    ASSERT_EQUALS("labs: Checking, if labs(-1) returns 1", labs(-1), 1);
    ASSERT_EQUALS("labs: Checking, if labs(1073741823) returns 1073741823", labs(1073741823), 1073741823);
    ASSERT_EQUALS("labs: Checking, if labs(-1073741824) returns 1073741824", labs(-1073741824), 1073741824);
    ASSERT_EQUALS("labs: Checking, if labs(2147483647) returns 2147483647", labs(2147483647), 2147483647);
    ASSERT_EQUALS("labs: Checking, if labs(-2147483648) returns 2147483648", labs(-2147483648), 2147483648);
    ASSERT_EQUALS("labs: Checking, if labs(4611686018427387902) returns 4611686018427387902", labs(4611686018427387902), 4611686018427387902);
    ASSERT_EQUALS("labs: Checking, if labs(-4611686018427387903) returns 4611686018427387903", labs(-4611686018427387903), 4611686018427387903);
    ASSERT_EQUALS("labs: Checking, if labs(9223372036854775807) returns 9223372036854775807", labs(9223372036854775807), 9223372036854775807);
    ASSERT_EQUALS("labs: Checking, if labs(-9223372036854775807) returns 9223372036854775807", labs(-9223372036854775807), 9223372036854775807);
    ASSERT_EQUALS("labs: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_llabs()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("llabs: Checking, if llabs(0) returns 0", llabs(0), 0);
    ASSERT_EQUALS("llabs: Checking, if llabs(1) returns 1", llabs(1), 1);
    ASSERT_EQUALS("llabs: Checking, if llabs(-1) returns 1", llabs(-1), 1);
    ASSERT_EQUALS("llabs: Checking, if llabs(1073741823) returns 1073741823", llabs(1073741823), 1073741823);
    ASSERT_EQUALS("llabs: Checking, if llabs(-1073741824) returns 1073741824", llabs(-1073741824), 1073741824);
    ASSERT_EQUALS("llabs: Checking, if llabs(2147483647) returns 2147483647", llabs(2147483647), 2147483647);
    ASSERT_EQUALS("llabs: Checking, if llabs(-2147483648) returns 2147483648", llabs(-2147483648), 2147483648);
    ASSERT_EQUALS("llabs: Checking, if llabs(4611686018427387902) returns 4611686018427387902", llabs(4611686018427387902), 4611686018427387902);
    ASSERT_EQUALS("llabs: Checking, if llabs(-4611686018427387903) returns 4611686018427387903", llabs(-4611686018427387903), 4611686018427387903);
    ASSERT_EQUALS("llabs: Checking, if llabs(9223372036854775807) returns 9223372036854775807", llabs(9223372036854775807), 9223372036854775807);
    ASSERT_EQUALS("llabs: Checking, if llabs(-9223372036854775807) returns 9223372036854775807", llabs(-9223372036854775807), 9223372036854775807);
    ASSERT_EQUALS("llabs: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_ldiv()
{
    const int pre_errno = errno;
    ldiv_t result = ldiv(17, 1);

    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 1)", result.quot, 17);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 1)", result.rem, 0);

    result = ldiv(17, 2);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 2)", result.quot, 8);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 2)", result.rem, 1);

    result = ldiv(17, 3);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 3)", result.quot, 5);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 3)", result.rem, 2);

    result = ldiv(17, 4);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 4)", result.quot, 4);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 4)", result.rem, 1);

    result = ldiv(17, 5);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 5)", result.quot, 3);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 5)", result.rem, 2);

    result = ldiv(17, 6);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 6)", result.quot, 2);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 6)", result.rem, 5);

    result = ldiv(17, 7);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 7)", result.quot, 2);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 7)", result.rem, 3);

    result = ldiv(17, 8);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 8)", result.quot, 2);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 8)", result.rem, 1);

    result = ldiv(17, 9);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 9)", result.quot, 1);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 9)", result.rem, 8);

    result = ldiv(17, 10);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 10)", result.quot, 1);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 10)", result.rem, 7);

    result = ldiv(17, 11);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 11)", result.quot, 1);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 11)", result.rem, 6);

    result = ldiv(17, 12);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 12)", result.quot, 1);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 12)", result.rem, 5);

    result = ldiv(17, 13);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 13)", result.quot, 1);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 13)", result.rem, 4);

    result = ldiv(17, 14);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 14)", result.quot, 1);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 14)", result.rem, 3);

    result = ldiv(17, 15);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 15)", result.quot, 1);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 15)", result.rem, 2);

    result = ldiv(17, 16);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 16)", result.quot, 1);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 16)", result.rem, 1);

    result = ldiv(17, 17);
    ASSERT_EQUALS("ldiv: Checking, quotient result of ldiv(17, 17)", result.quot, 1);
    ASSERT_EQUALS("ldiv: Checking, remainder result of ldiv(17, 17)", result.rem, 0);

    ASSERT_EQUALS("ldiv: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_lldiv()
{
    const int pre_errno = errno;
    lldiv_t result = lldiv(17, 1);

    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 1)", result.quot, 17);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 1)", result.rem, 0);

    result = lldiv(17, 2);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 2)", result.quot, 8);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 2)", result.rem, 1);

    result = lldiv(17, 3);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 3)", result.quot, 5);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 3)", result.rem, 2);

    result = lldiv(17, 4);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 4)", result.quot, 4);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 4)", result.rem, 1);

    result = lldiv(17, 5);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 5)", result.quot, 3);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 5)", result.rem, 2);

    result = lldiv(17, 6);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 6)", result.quot, 2);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 6)", result.rem, 5);

    result = lldiv(17, 7);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 7)", result.quot, 2);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 7)", result.rem, 3);

    result = lldiv(17, 8);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 8)", result.quot, 2);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 8)", result.rem, 1);

    result = lldiv(17, 9);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 9)", result.quot, 1);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 9)", result.rem, 8);

    result = lldiv(17, 10);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 10)", result.quot, 1);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 10)", result.rem, 7);

    result = lldiv(17, 11);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 11)", result.quot, 1);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 11)", result.rem, 6);

    result = lldiv(17, 12);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 12)", result.quot, 1);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 12)", result.rem, 5);

    result = lldiv(17, 13);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 13)", result.quot, 1);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 13)", result.rem, 4);

    result = lldiv(17, 14);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 14)", result.quot, 1);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 14)", result.rem, 3);

    result = lldiv(17, 15);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 15)", result.quot, 1);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 15)", result.rem, 2);

    result = lldiv(17, 16);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 16)", result.quot, 1);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 16)", result.rem, 1);

    result = lldiv(17, 17);
    ASSERT_EQUALS("lldiv: Checking, quotient result of lldiv(17, 17)", result.quot, 1);
    ASSERT_EQUALS("lldiv: Checking, remainder result of lldiv(17, 17)", result.rem, 0);

    ASSERT_EQUALS("lldiv: Checking, if errno is unmodified", pre_errno, errno);
}


// Check all functions of stdlib.h
void run_stdlib_tests()
{
    TEST_CASE("Test POSIX stdlib.h functions");

    test_abs();
    test_labs();
    test_llabs();

    test_ldiv();
    test_lldiv();
}
