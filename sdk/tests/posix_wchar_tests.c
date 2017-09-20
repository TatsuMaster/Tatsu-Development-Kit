#include "posix_wchar_tests.h"

#include "../posix/errno.h"
#include "../posix/wchar.h"
#include "../../ttf/ttf.h"


static void test_wmemchr()
{
    const int pre_errno = errno;
    const wchar_t src_buffer[10] = {1, 2, 3, 4, 0, 4, 5, 6, 7, 9};
    const wchar_t* result_0 = wmemchr(src_buffer, 0, 10);
    const wchar_t* result_1 = wmemchr(src_buffer, 27, 10);
    const wchar_t* result_2 = wmemchr(src_buffer, 0, 2);
    const wchar_t* result_3 = wmemchr(src_buffer, 0, 0);

    ASSERT_EQUALS("wmemchr: Checking, if result pointer is set correctly, if wc was found in memory", result_0, &src_buffer[4]);
    ASSERT_EQUALS("wmemchr: Checking, if result pointer is 0, if wc was not found in memory", result_1, 0);
    ASSERT_EQUALS("wmemchr: Checking, if result pointer is 0, if wc was not found in given range", result_2, 0);
    ASSERT_EQUALS("wmemchr: Checking, if result pointer is 0, if parameter n is set to 0", result_3, 0);
    ASSERT_EQUALS("wmemchr: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_wmemcmp()
{
    const int pre_errno = errno;
    const wchar_t src_buffer_0[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const wchar_t src_buffer_1[10] = { 0, 1, 2, 3, 4, 9, 8, 7, 6, 5 };
    const wchar_t src_buffer_2[10] = { 0, 1, 2, 3, 4, 1, 1, 1, 1, 1 };

    const int result_0 = wmemcmp(src_buffer_0, src_buffer_1, 10);
    const int result_1 = wmemcmp(src_buffer_0, src_buffer_1, 5);
    const int result_2 = wmemcmp(src_buffer_0, src_buffer_2, 10);
    const int result_3 = wmemcmp(src_buffer_0, src_buffer_2, 5);
    const int result_4 = wmemcmp(src_buffer_0, src_buffer_2, 0);

    ASSERT_LESS("wmemcmp: Checking, if result is less 0, if ws1 contains the greater object", result_0, 0);
    ASSERT_EQUALS("wmemcmp: Checking, if result is 0, if ws1 and ws2 are equal", result_1, 0);
    ASSERT_GREATER("wmemcmp: Checking, if result is greater 0, if ws1 contains the greater object", result_2, 0);
    ASSERT_EQUALS("wmemcmp: Checking, if result is 0, if specified range of ws1 and ws2 are equal", result_3, 0);
    ASSERT_EQUALS("wmemcmp: Checking, if result is 0, if parameter n is set to 0", result_4, 0);
    ASSERT_EQUALS("wmemcmp: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_wmemcpy()
{
    const int pre_errno = errno;
    const wchar_t src_buffer_0[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const wchar_t src_buffer_1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    wchar_t dest_buffer_0[10] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
    wchar_t dest_buffer_1[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    wchar_t dest_buffer_2[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    const wchar_t* result_0 = wmemcpy(dest_buffer_0, src_buffer_0, 10);
    const wchar_t* result_1 = wmemcpy(dest_buffer_1, src_buffer_1, 5);
    const wchar_t* result_2 = wmemcpy(dest_buffer_2, src_buffer_0, 0);

    const bool content_test_0 = (
        dest_buffer_0[0] == src_buffer_0[0] &&
        dest_buffer_0[1] == src_buffer_0[1] &&
        dest_buffer_0[2] == src_buffer_0[2] &&
        dest_buffer_0[3] == src_buffer_0[3] &&
        dest_buffer_0[4] == src_buffer_0[4] &&
        dest_buffer_0[5] == src_buffer_0[5] &&
        dest_buffer_0[6] == src_buffer_0[6] &&
        dest_buffer_0[7] == src_buffer_0[7] &&
        dest_buffer_0[8] == src_buffer_0[8] &&
        dest_buffer_0[9] == src_buffer_0[9]);

    const bool content_test_1 = (
        dest_buffer_1[0] == src_buffer_1[0] &&
        dest_buffer_1[1] == src_buffer_1[1] &&
        dest_buffer_1[2] == src_buffer_1[2] &&
        dest_buffer_1[3] == src_buffer_1[3] &&
        dest_buffer_1[4] == src_buffer_1[4] &&
        dest_buffer_1[5] == 1 &&
        dest_buffer_1[6] == 1 &&
        dest_buffer_1[7] == 1 &&
        dest_buffer_1[8] == 1 &&
        dest_buffer_1[9] == 1);

    const bool content_test_2 = (
        dest_buffer_2[0] == 1 &&
        dest_buffer_2[1] == 1 &&
        dest_buffer_2[2] == 1 &&
        dest_buffer_2[3] == 1 &&
        dest_buffer_2[4] == 1 &&
        dest_buffer_2[5] == 1 &&
        dest_buffer_2[6] == 1 &&
        dest_buffer_2[7] == 1 &&
        dest_buffer_2[8] == 1 &&
        dest_buffer_2[9] == 1);

    ASSERT_TRUE("wmemcpy: Checking, if full buffer copy works correctly", content_test_0);
    ASSERT_EQUALS("wmemcpy: Checking, if result pointer is set to s1 for full buffer copy", result_0, dest_buffer_0);
    ASSERT_TRUE("wmemcpy: Checking, if half buffer copy works correctly", content_test_1);
    ASSERT_EQUALS("wmemcpy: Checking, if result pointer is set to s1 for half buffer copy", result_1, dest_buffer_1);
    ASSERT_TRUE("wmemcpy: Checking, if zero copy works correctly", content_test_2);
    ASSERT_EQUALS("wmemcpy: Checking, if result pointer is set to s1 for zero copy", result_2, dest_buffer_2);
    ASSERT_EQUALS("wmemcpy: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_wmemset()
{
    const int pre_errno = errno;
    wchar_t dest_buffer[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const wchar_t* result = wmemset(dest_buffer, 0, 5);

    const bool content_test_0 = (
        dest_buffer[0] == 0 &&
        dest_buffer[1] == 0 &&
        dest_buffer[2] == 0 &&
        dest_buffer[3] == 0 &&
        dest_buffer[4] == 0);

    const bool content_test_1 = (
        dest_buffer[5] == 5 &&
        dest_buffer[6] == 6 &&
        dest_buffer[7] == 7 &&
        dest_buffer[8] == 8 &&
        dest_buffer[9] == 9);

    ASSERT_TRUE("wmemset: Checking, if buffer content was copied correctly", content_test_0);
    ASSERT_TRUE("wmemset: Checking, if buffer content behind given limit was not modified", content_test_1);
    ASSERT_EQUALS("wmemset: Checking, if stpcpy return value equals address of the destination buffer", dest_buffer, result);
    ASSERT_EQUALS("wmemset: Checking, if errno is unmodified", pre_errno, errno);
}


// Check all functions of wchar.h
void run_wchar_lib_tests()
{
    TEST_CASE("Test POSIX wchar.h functions");

    test_wmemchr();
    test_wmemcmp();
    test_wmemcpy();
    test_wmemset();
}