#include "posix_string_tests.h"

#include "../posix/errno.h"
#include "../posix/string.h"
#include "../../ttf/ttf.h"


static void test_memccpy()
{
    const int pre_errno = errno;
    const char* src_buffer_0 = "1234 4567";
    const char* src_buffer_1 = "1234 4567";
    char dest_buffer_0[10] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
    char dest_buffer_1[10] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
    const char* result_0 = memccpy(dest_buffer_0, src_buffer_0, 'X', 10);
    const char* result_1 = memccpy(dest_buffer_1, src_buffer_1, ' ', 10);

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
        dest_buffer_1[5] != src_buffer_1[5] &&
        dest_buffer_1[6] != src_buffer_1[6] &&
        dest_buffer_1[7] != src_buffer_1[7] &&
        dest_buffer_1[8] != src_buffer_1[8] &&
        dest_buffer_1[9] != src_buffer_1[9]);

    ASSERT_TRUE("memccpy: Checking, if buffer was filled correctly", content_test_1);
    ASSERT_EQUALS("memccpy: Checking, if result pointer is set correctly", result_1, dest_buffer_1 + 5);
    ASSERT_TRUE("memccpy: Checking, if source and destination buffer are equal", content_test_0);
    ASSERT_EQUALS("memccpy: Checking, if result pointer is 0, if there is no occurence of c", result_0, 0);
    ASSERT_EQUALS("memccpy: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_memchr()
{
    const int pre_errno = errno;
    const char* src_buffer = "1234 4567";
    const char* result_0 = memchr(src_buffer, ' ', 10);
    const char* result_1 = memchr(src_buffer, 'X', 10);
    const char* result_2 = memchr(src_buffer, ' ', 2);

    ASSERT_EQUALS("memchr: Checking, if result pointer is set correctly, if c was found in memory", result_0, src_buffer + 4);
    ASSERT_EQUALS("memchr: Checking, if result pointer is 0, if c was not found in memory", result_1, 0);
    ASSERT_EQUALS("memchr: Checking, if result pointer is 0, if c was not found in given range", result_2, 0);
    ASSERT_EQUALS("memchr: Checking, if errno is unmodified", pre_errno, errno);
}


static void  test_memcmp()
{
    const int pre_errno = errno;
    const char src_buffer_0[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const char src_buffer_1[10] = { 0, 1, 2, 3, 4, 9, 8, 7, 6, 5 };
    const char src_buffer_2[10] = { 0, 1, 2, 3, 4, 1, 1, 1, 1, 1 };
    const int result_0 = memcmp(src_buffer_0, src_buffer_1, 10);
    const int result_1 = memcmp(src_buffer_0, src_buffer_1, 5);
    const int result_2 = memcmp(src_buffer_0, src_buffer_2, 10);
    const int result_3 = memcmp(src_buffer_0, src_buffer_2, 5);

    ASSERT_LESS("memcmp: Checking, if result is less 0, if s1 contains the greater object", result_0, 0);
    ASSERT_EQUALS("memcmp: Checking, if result is 0, if s1 and s2 are equal", result_1, 0);
    ASSERT_GREATER("memcmp: Checking, if result is greater 0, if s1 contains the greater object", result_2, 0);
    ASSERT_EQUALS("memcmp: Checking, if result is 0, if specified range of s1 and s2 are equal", result_3, 0);
    ASSERT_EQUALS("memcmp: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_memcpy()
{
    const int pre_errno = errno;
    const char src_buffer_0[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const char src_buffer_1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    char dest_buffer_0[10] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
    char dest_buffer_1[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    char dest_buffer_2[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    const char* result_0 = memcpy(dest_buffer_0, src_buffer_0, 10);
    const char* result_1 = memcpy(dest_buffer_1, src_buffer_1, 5);
    const char* result_2 = memcpy(dest_buffer_2, src_buffer_0, 0);

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

    ASSERT_TRUE("memcpy: Checking, if full buffer copy works correctly", content_test_0);
    ASSERT_EQUALS("memcpy: Checking, if result pointer is set to s1 for full buffer copy", result_0, dest_buffer_0);
    ASSERT_TRUE("memcpy: Checking, if half buffer copy works correctly", content_test_1);
    ASSERT_EQUALS("memcpy: Checking, if result pointer is set to s1 for half buffer copy", result_1, dest_buffer_1);
    ASSERT_TRUE("memcpy: Checking, if zero copy works correctly", content_test_2);
    ASSERT_EQUALS("memcpy: Checking, if result pointer is set to s1 for zero copy", result_2, dest_buffer_2);
    ASSERT_EQUALS("memcpy: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_memset()
{
    const int pre_errno = errno;
    char dest_buffer[10] = { 0, 1, 2, 3, 'A', 'B', 'C', 'D', 'E', 'F' };
    const char* result = memset(dest_buffer, '0', 5);

    const bool content_test_0 = (
        dest_buffer[0] == '0' &&
        dest_buffer[1] == '0' &&
        dest_buffer[2] == '0' &&
        dest_buffer[3] == '0' &&
        dest_buffer[4] == '0');

    const bool content_test_1 = (
        dest_buffer[5] == 'B' &&
        dest_buffer[6] == 'C' &&
        dest_buffer[7] == 'D' &&
        dest_buffer[8] == 'E' &&
        dest_buffer[9] == 'F');

    ASSERT_TRUE("memset: Checking, if buffer content was copied correctly", content_test_0);
    ASSERT_TRUE("memset: Checking, if buffer content behind given limit was not modified", content_test_1);
    ASSERT_EQUALS("memset: Checking, if stpcpy return value equals address of the destination buffer", dest_buffer, result);
    ASSERT_EQUALS("memset: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_stpcpy()
{
    const int pre_errno = errno;
    const char* src_buffer = "1234";
    char dest_buffer[10] = { 0, 1, 2, 3, 'A', 'B', 'C', 'D', 'E', 'F' };
    const char* result = stpcpy(dest_buffer, src_buffer);

    // Do Not use strcmp...
    const bool content_test_0 = (
        dest_buffer[0] == src_buffer[0] &&
        dest_buffer[1] == src_buffer[1] &&
        dest_buffer[2] == src_buffer[2] &&
        dest_buffer[3] == src_buffer[3] &&
        dest_buffer[4] == src_buffer[4]);

    const bool content_test_1 = (
        dest_buffer[5] == 'B' &&
        dest_buffer[6] == 'C' &&
        dest_buffer[7] == 'D' &&
        dest_buffer[8] == 'E' &&
        dest_buffer[9] == 'F');

    ASSERT_TRUE("stpcpy: Checking, if buffer content was copied correctly", content_test_0);
    ASSERT_TRUE("stpcpy: Checking, if buffer content behind 0 termination was not modified", content_test_1);
    ASSERT_EQUALS("stpcpy: Checking, if stpcpy return value equals address of string end in destination buffer", dest_buffer + 4, result);
    ASSERT_EQUALS("stpcpy: Checking, if stpcpy destination buffer is 0 terminated", dest_buffer[4], 0);
    ASSERT_EQUALS("stpcpy: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_strcpy()
{
    const int pre_errno = errno;
    const char* src_buffer = "1234";
    char dest_buffer[10] = { 0, 1, 2, 3, 'A', 'B', 'C', 'D', 'E', 'F' };
    const char* result = strcpy(dest_buffer, src_buffer);

    // Do Not use strcmp...
    const bool content_test_0 = (
        dest_buffer[0] == src_buffer[0] &&
        dest_buffer[1] == src_buffer[1] &&
        dest_buffer[2] == src_buffer[2] &&
        dest_buffer[3] == src_buffer[3] &&
        dest_buffer[4] == src_buffer[4]);

    const bool content_test_1 = (
        dest_buffer[5] == 'B' &&
        dest_buffer[6] == 'C' &&
        dest_buffer[7] == 'D' &&
        dest_buffer[8] == 'E' &&
        dest_buffer[9] == 'F');

    ASSERT_TRUE("strcpy: Checking, if buffer content was copied correctly", content_test_0);
    ASSERT_TRUE("strcpy: Checking, if buffer content behind 0 termination was not modified", content_test_1);
    ASSERT_EQUALS("strcpy: Checking, if strcpy return value equals destination buffer address", dest_buffer, result);
    ASSERT_EQUALS("strcpy: Checking, if strcpy destination buffer is 0 terminated", dest_buffer[4], 0);
    ASSERT_EQUALS("strcpy: Checking, if errno is unmodified", pre_errno, errno);
}


// Check all functions of string.h
void run_string_lib_tests()
{
    TEST_CASE("Test POSIX string.h functions");

    test_memccpy();
    test_memchr();
    test_memcmp();
    test_memcpy();
    test_memset();
    test_stpcpy();
    test_strcpy();
}