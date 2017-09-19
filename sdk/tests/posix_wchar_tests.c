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


// Check all functions of wchar.h
void run_wchar_lib_tests()
{
    TEST_CASE("Test POSIX wchar.h functions");

    test_wmemchr();
    test_wmemcmp();
}