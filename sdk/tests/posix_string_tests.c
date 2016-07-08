#include "posix_string_tests.h"

#include "../posix/errno.h"
#include "../posix/string.h"
#include "../../ttf/ttf.h"


static void test_strcpy()
{
    int pre_errno = errno;
    const char* src_buffer = "1234";
    char dest_buffer[10] = { 0, 1, 2, 3, 'A', 'B', 'C', 'D', 'E', 'F' };
    char* result = strcpy(dest_buffer, src_buffer);

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

    test_strcpy();
}