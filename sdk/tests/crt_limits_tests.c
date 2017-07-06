#include "crt_limits_tests.h"

#include "../crt/limits.h"
#include "../../ttf/ttf.h"


// Check limit definitions
void run_crt_limits_tests()
{
    TEST_CASE("Test C runtime limits.h definitions");

    ASSERT_EQUALS("Checking, if CHAR_BIT is defined correctly", CHAR_BIT, 8);
    ASSERT_EQUALS("Checking, if SCHAR_MIN is defined correctly", SCHAR_MIN, -128);
    ASSERT_EQUALS("Checking, if SCHAR_MAX is defined correctly", SCHAR_MAX, 127);
    ASSERT_EQUALS("Checking, if UCHAR_MAX is defined correctly", UCHAR_MAX, 255);
    ASSERT_EQUALS("Checking, if CHAR_MIN is defined correctly", CHAR_MIN, SCHAR_MIN);
    ASSERT_EQUALS("Checking, if CHAR_MAX is defined correctly", CHAR_MAX, SCHAR_MAX);
    ASSERT_EQUALS("Checking, if SHRT_MIN is defined correctly", SHRT_MIN, -32768);
    ASSERT_EQUALS("Checking, if SHRT_MAX is defined correctly", SHRT_MAX, 32767);
    ASSERT_EQUALS("Checking, if USHRT_MAX is defined correctly", USHRT_MAX, 65535);
    ASSERT_EQUALS("Checking, if INT_MIN is defined correctly", INT_MIN, -32768);
    ASSERT_EQUALS("Checking, if INT_MAX is defined correctly", INT_MAX, 32767);
    ASSERT_EQUALS("Checking, if UINT_MAX is defined correctly", UINT_MAX, 65535);
    ASSERT_EQUALS("Checking, if LONG_MIN is defined correctly", LONG_MIN, -2147483648);
    ASSERT_EQUALS("Checking, if LONG_MAX is defined correctly", LONG_MAX, 2147483647);
    ASSERT_EQUALS("Checking, if ULONG_MAX is defined correctly", ULONG_MAX, 4294967295);
    ASSERT_EQUALS("Checking, if LLONG_MIN is defined correctly", LLONG_MIN, -9223372036854775807LL);
    ASSERT_EQUALS("Checking, if LLONG_MAX is defined correctly", LLONG_MAX, 9223372036854775807LL);
    ASSERT_EQUALS("Checking, if ULLONG_MAX is defined correctly", ULLONG_MAX, 18446744073709551615ULL);
}
