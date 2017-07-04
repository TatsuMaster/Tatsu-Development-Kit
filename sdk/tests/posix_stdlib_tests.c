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


// Check all functions of stdlib.h
void run_stdlib_tests()
{
    TEST_CASE("Test POSIX stdlib.h functions");

    test_abs();
    test_labs();
    test_llabs();
}
