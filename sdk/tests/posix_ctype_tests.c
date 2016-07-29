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


static void test_isalnum()
{
    int pre_errno = errno;
    int character_value = 48;

    for (; character_value < 58; ++character_value)
    {
        ASSERT_EQUALS("isalnum: Checking, if qualified character code gets classified as alpha numeric character", isalnum(character_value), 1);
    }

    ASSERT_EQUALS("isalnum: Checking, if unqualified character code gets not classified as alpha numeric character", isalnum(47), 0);
    ASSERT_EQUALS("isalnum: Checking, if unqualified character code gets not classified as alpha numeric character", isalnum(58), 0);

    for (character_value = 65; character_value < 91; ++character_value)
    {
        ASSERT_EQUALS("isalnum: Checking, if qualified character code gets classified as alpha numeric character", isalnum(character_value), 1);
    }

    ASSERT_EQUALS("isalnum: Checking, if unqualified character code gets not classified as alpha numeric character", isalnum(64), 0);
    ASSERT_EQUALS("isalnum: Checking, if unqualified character code gets not classified as alpha numeric character", isalnum(91), 0);

    for (character_value = 97; character_value < 123; ++character_value)
    {
        ASSERT_EQUALS("isalnum: Checking, if qualified character code gets classified as alpha numeric character", isalnum(character_value), 1);
    }

    ASSERT_EQUALS("isalnum: Checking, if unqualified character code gets not classified as alpha numeric character", isalnum(96), 0);
    ASSERT_EQUALS("isalnum: Checking, if unqualified character code gets not classified as alpha numeric character", isalnum(123), 0);

    ASSERT_EQUALS("isalnum: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_isalpha()
{
    int pre_errno = errno;
    int character_value = 65;

    for (; character_value < 91; ++character_value)
    {
        ASSERT_EQUALS("isalpha: Checking, if qualified character code gets classified as alpha character", isalpha(character_value), 1);
    }

    ASSERT_EQUALS("isalpha: Checking, if unqualified character code gets not classified as alpha character", isalpha(64), 0);
    ASSERT_EQUALS("isalpha: Checking, if unqualified character code gets not classified as alpha character", isalpha(91), 0);

    for (character_value = 97; character_value < 123; ++character_value)
    {
        ASSERT_EQUALS("isalpha: Checking, if qualified character code gets classified as alpha character", isalpha(character_value), 1);
    }

    ASSERT_EQUALS("isalpha: Checking, if unqualified character code gets not classified as alpha character", isalpha(96), 0);
    ASSERT_EQUALS("isalpha: Checking, if unqualified character code gets not classified as alpha character", isalpha(123), 0);

    ASSERT_EQUALS("isalpha: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_isblank()
{
    int pre_errno = errno;

    ASSERT_EQUALS("isblank: Checking, if qualified character code gets classified as blank character", isblank(9), 1);
    ASSERT_EQUALS("isblank: Checking, if unqualified character code gets not classified as blank character", isblank(8), 0);
    ASSERT_EQUALS("isblank: Checking, if unqualified character code gets not classified as blank character", isblank(10), 0);
    ASSERT_EQUALS("isblank: Checking, if qualified character code gets classified as blank character", isblank(32), 1);
    ASSERT_EQUALS("isblank: Checking, if unqualified character code gets not classified as blank character", isblank(31), 0);
    ASSERT_EQUALS("isblank: Checking, if unqualified character code gets not classified as blank character", isblank(33), 0);
    ASSERT_EQUALS("isblank: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_iscntrl()
{
    int pre_errno = errno;
    int character_value = 0;

    for (; character_value < 32; ++character_value)
    {
        ASSERT_EQUALS("iscntrl: Checking, if qualified character code gets classified as control character", iscntrl(character_value), 1);
    }

    ASSERT_EQUALS("iscntrl: Checking, if unqualified character code gets not classified as control character", iscntrl(-1), 0);
    ASSERT_EQUALS("iscntrl: Checking, if unqualified character code gets not classified as control character", iscntrl(32), 0);
    ASSERT_EQUALS("iscntrl: Checking, if qualified character code gets classified as control character", iscntrl(127), 1);
    ASSERT_EQUALS("iscntrl: Checking, if unqualified character code gets not classified as control character", iscntrl(126), 0);
    ASSERT_EQUALS("iscntrl: Checking, if unqualified character code gets not classified as control character", iscntrl(128), 0);
    ASSERT_EQUALS("iscntrl: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_isdigit()
{
    int pre_errno = errno;
    int character_value = 48;

    for (; character_value < 58; ++character_value)
    {
        ASSERT_EQUALS("isdigit: Checking, if qualified character code gets classified as digit character", isdigit(character_value), 1);
    }

    ASSERT_EQUALS("isdigit: Checking, if unqualified character code gets not classified as digit character", isdigit(47), 0);
    ASSERT_EQUALS("isdigit: Checking, if unqualified character code gets not classified as digit character", isdigit(59), 0);
    ASSERT_EQUALS("isdigit: Checking, if errno is unmodified", pre_errno, errno);
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


static void test_isprint()
{
    int pre_errno = errno;
    int character_value = 32;

    for (; character_value < 127; ++character_value)
    {
        ASSERT_EQUALS("isprint: Checking, if qualified character code gets classified as printable character", isprint(character_value), 1);
    }

    ASSERT_EQUALS("isprint: Checking, if unqualified character code gets not classified as printable character", isprint(31), 0);
    ASSERT_EQUALS("isprint: Checking, if unqualified character code gets not classified as printable character", isprint(127), 0);
    ASSERT_EQUALS("isprint: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_ispunct()
{
    int pre_errno = errno;
    int character_value = 33;

    for (; character_value < 48; ++character_value)
    {
        ASSERT_EQUALS("ispunct: Checking, if qualified character code gets classified as punct character", ispunct(character_value), 1);
    }

    ASSERT_EQUALS("ispunct: Checking, if unqualified character code gets not classified as punct character", ispunct(32), 0);
    ASSERT_EQUALS("ispunct: Checking, if unqualified character code gets not classified as punct character", ispunct(48), 0);

    for (character_value = 58; character_value < 65; ++character_value)
    {
        ASSERT_EQUALS("ispunct: Checking, if qualified character code gets classified as punct character", ispunct(character_value), 1);
    }

    ASSERT_EQUALS("ispunct: Checking, if unqualified character code gets not classified as punct character", ispunct(57), 0);
    ASSERT_EQUALS("ispunct: Checking, if unqualified character code gets not classified as punct character", ispunct(65), 0);

    for (character_value = 91; character_value < 97; ++character_value)
    {
        ASSERT_EQUALS("ispunct: Checking, if qualified character code gets classified as punct character", ispunct(character_value), 1);
    }

    ASSERT_EQUALS("ispunct: Checking, if unqualified character code gets not classified as punct character", ispunct(90), 0);
    ASSERT_EQUALS("ispunct: Checking, if unqualified character code gets not classified as punct character", ispunct(97), 0);

    for (character_value = 123; character_value < 127; ++character_value)
    {
        ASSERT_EQUALS("ispunct: Checking, if qualified character code gets classified as punct character", ispunct(character_value), 1);
    }

    ASSERT_EQUALS("ispunct: Checking, if unqualified character code gets not classified as punct character", ispunct(122), 0);
    ASSERT_EQUALS("ispunct: Checking, if unqualified character code gets not classified as punct character", ispunct(127), 0);

    ASSERT_EQUALS("ispunct: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_isspace()
{
    int pre_errno = errno;
    int character_value = 9;

    for (; character_value < 14; ++character_value)
    {
        ASSERT_EQUALS("isspace: Checking, if qualified character code gets classified as spacing character", isspace(character_value), 1);
    }

    ASSERT_EQUALS("isspace: Checking, if unqualified character code gets not classified as spacing character", isspace(8), 0);
    ASSERT_EQUALS("isspace: Checking, if unqualified character code gets not classified as spacing character", isspace(15), 0);
    ASSERT_EQUALS("isspace: Checking, if qualified character code gets classified as spacing character", isspace(32), 1);
    ASSERT_EQUALS("isspace: Checking, if unqualified character code gets not classified as spacing character", isspace(31), 0);
    ASSERT_EQUALS("isspace: Checking, if unqualified character code gets not classified as spacing character", isspace(33), 0);
    ASSERT_EQUALS("isspace: Checking, if errno is unmodified", pre_errno, errno);
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


static void test_toascii()
{
    int pre_errno = errno;

    ASSERT_EQUALS("toascii: Checking, if toascii(60) returns 60", toascii(60), 60);
    ASSERT_EQUALS("toascii: Checking, if toascii(1517) returns (1517 & 0x7f)", toascii(1517), (1517 & 0x7f));
    ASSERT_EQUALS("toascii: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_tolower()
{
    int pre_errno = errno;

    ASSERT_EQUALS("tolower: Checking, if tolower('A') returns 'a'", tolower('A'), 'a');
    ASSERT_EQUALS("tolower: Checking, if tolower('M') returns 'm'", tolower('M'), 'm');
    ASSERT_EQUALS("tolower: Checking, if tolower('Z') returns 'z'", tolower('Z'), 'z');
    ASSERT_EQUALS("tolower: Checking, if tolower('@') returns '@'", tolower('@'), '@');
    ASSERT_EQUALS("tolower: Checking, if tolower('&') returns '&'", tolower('&'), '&');
    ASSERT_EQUALS("tolower: Checking, if tolower('a') returns 'a'", tolower('a'), 'a');
    ASSERT_EQUALS("tolower: Checking, if tolower('m') returns 'm'", tolower('m'), 'm');
    ASSERT_EQUALS("tolower: Checking, if tolower('z') returns 'z'", tolower('z'), 'z');
    ASSERT_EQUALS("tolower: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_toupper()
{
    int pre_errno = errno;

    ASSERT_EQUALS("toupper: Checking, if toupper('a') returns 'A'", toupper('a'), 'A');
    ASSERT_EQUALS("toupper: Checking, if toupper('m') returns 'M'", toupper('m'), 'M');
    ASSERT_EQUALS("toupper: Checking, if toupper('z') returns 'Z'", toupper('z'), 'Z');
    ASSERT_EQUALS("toupper: Checking, if toupper('@') returns '@'", toupper('@'), '@');
    ASSERT_EQUALS("toupper: Checking, if toupper('&') returns '&'", toupper('&'), '&');
    ASSERT_EQUALS("toupper: Checking, if toupper('A') returns 'A'", toupper('A'), 'A');
    ASSERT_EQUALS("toupper: Checking, if toupper('M') returns 'M'", toupper('M'), 'M');
    ASSERT_EQUALS("toupper: Checking, if toupper('Z') returns 'Z'", toupper('Z'), 'Z');
    ASSERT_EQUALS("toupper: Checking, if errno is unmodified", pre_errno, errno);
}


static void test__tolower()
{
    int pre_errno = errno;

    ASSERT_EQUALS("_tolower: Checking, if _tolower('A') returns 'a'", _tolower('A'), 'a');
    ASSERT_EQUALS("_tolower: Checking, if _tolower('M') returns 'm'", _tolower('M'), 'm');
    ASSERT_EQUALS("_tolower: Checking, if _tolower('Z') returns 'z'", _tolower('Z'), 'z');
    ASSERT_EQUALS("_tolower: Checking, if _tolower('@') returns '@'", _tolower('@'), '@');
    ASSERT_EQUALS("_tolower: Checking, if _tolower('&') returns '&'", _tolower('&'), '&');
    ASSERT_EQUALS("_tolower: Checking, if _tolower('a') returns 'a'", _tolower('a'), 'a');
    ASSERT_EQUALS("_tolower: Checking, if _tolower('m') returns 'm'", _tolower('m'), 'm');
    ASSERT_EQUALS("_tolower: Checking, if _tolower('z') returns 'z'", _tolower('z'), 'z');
    ASSERT_EQUALS("_tolower: Checking, if errno is unmodified", pre_errno, errno);
}


static void test__toupper()
{
    int pre_errno = errno;

    ASSERT_EQUALS("_toupper: Checking, if _toupper('a') returns 'A'", _toupper('a'), 'A');
    ASSERT_EQUALS("_toupper: Checking, if _toupper('m') returns 'M'", _toupper('m'), 'M');
    ASSERT_EQUALS("_toupper: Checking, if _toupper('z') returns 'Z'", _toupper('z'), 'Z');
    ASSERT_EQUALS("_toupper: Checking, if _toupper('@') returns '@'", _toupper('@'), '@');
    ASSERT_EQUALS("_toupper: Checking, if _toupper('&') returns '&'", _toupper('&'), '&');
    ASSERT_EQUALS("_toupper: Checking, if _toupper('A') returns 'A'", _toupper('A'), 'A');
    ASSERT_EQUALS("_toupper: Checking, if _toupper('M') returns 'M'", _toupper('M'), 'M');
    ASSERT_EQUALS("_toupper: Checking, if _toupper('Z') returns 'Z'", _toupper('Z'), 'Z');
    ASSERT_EQUALS("_toupper: Checking, if errno is unmodified", pre_errno, errno);
}


// Check all functions of ctype.h
void run_posix_ctype_tests()
{
    TEST_CASE("Test POSIX ctype.h functions");

    test_isascii();
    test_isalnum();
    test_isalpha();
    test_isblank();
    test_iscntrl();
    test_isdigit();
    test_islower();
    test_isprint();
    test_ispunct();
    test_isspace();
    test_isupper();
    test_toascii();
    test_tolower();
    test_toupper();
    test__tolower();
    test__toupper();
}
