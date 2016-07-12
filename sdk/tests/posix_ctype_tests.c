#include "posix_ctype_tests.h"

#include "../posix/errno.h"
#include "../posix/ctype.h"
#include "../../ttf/ttf.h"


static void test_isascii()
{
    int pre_errno = errno;
    int character_value = 0;

    for (; character_value < 128; ++character_value)
    {
        ASSERT_EQUALS("isascii: Checking, if qualified character code gets classified as ASCII character", isascii(character_value), 1);
    }

    ASSERT_EQUALS("isascii: Checking, if unqualified character code gets not classified as ASCII character", isascii(character_value), 0);
    ASSERT_EQUALS("isascii: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_islower()
{
    int pre_errno = errno;
    int character_value = 97;

    for (; character_value < 123; ++character_value)
    {
        ASSERT_EQUALS("islower: Checking, if qualified character code gets classified as lower character", islower(character_value), 1);
    }

    ASSERT_EQUALS("islower: Checking, if unqualified character code gets not classified as lower character", islower(character_value), 0);
    ASSERT_EQUALS("islower: Checking, if unqualified character code gets not classified as lower character", islower(96), 0);
    ASSERT_EQUALS("islower: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_isupper()
{
    int pre_errno = errno;
    int character_value = 65;

    for (; character_value < 91; ++character_value)
    {
        ASSERT_EQUALS("isupper: Checking, if qualified character code gets classified as upper character", isupper(character_value), 1);
    }

    ASSERT_EQUALS("isupper: Checking, if unqualified character code gets not classified as upper character", isupper(character_value), 0);
    ASSERT_EQUALS("isupper: Checking, if unqualified character code gets not classified as upper character", isupper(64), 0);
    ASSERT_EQUALS("isupper: Checking, if errno is unmodified", pre_errno, errno);
}


// Check all functions of ctype.h
void run_posix_ctype_tests()
{
    TEST_CASE("Test POSIX ctype.h functions");

    test_isascii();
    test_islower();
    test_isupper();
}
