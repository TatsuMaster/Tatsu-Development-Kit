#include "posix_unistd_tests.h"

#include "../posix/errno.h"
#include "../posix/unistd.h"
#include "../posix/string.h"
#include "../../ttf/ttf.h"


static void test_swab()
{
    char src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    char dest[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char dest_expected[10] = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8};

    char dest2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char dest2_expected[10] = {1, 0, 3, 2, 5, 4, 7, 6, 0, 0};

    char dest3[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char dest3_expected[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    const int pre_errno = errno;

    swab(src, dest, 10);
    ASSERT_EQUALS("swab: Checking, if the function works for even nbytes", memcmp(dest, dest_expected, 10), 0);

    swab(src, dest2, 9);
    ASSERT_EQUALS("swab: Checking, if the function works for odd nbytes", memcmp(dest2, dest2_expected, 10), 0);

    swab(src, dest3, -10);
    ASSERT_EQUALS("swab: Checking, if the function works for negative nbytes", memcmp(dest3, dest3_expected, 10), 0);

    swab(src, dest3, -10);
    ASSERT_EQUALS("swab: Checking, if the function works for 0 nbytes", memcmp(dest3, dest3_expected, 10), 0);

    ASSERT_EQUALS("swab: Checking, if errno is unmodified", pre_errno, errno);
}


// Check all functions of unistd.h
void run_unistd_tests()
{
    TEST_CASE("Test POSIX unistd.h functions");

    test_swab();
}