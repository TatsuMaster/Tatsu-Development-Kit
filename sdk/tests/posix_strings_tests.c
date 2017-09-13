#include "posix_strings_tests.h"

#include "../posix/errno.h"
#include "../posix/strings.h"
#include "../../ttf/ttf.h"


static void test_ffs()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("swab: Checking, if ffs(0) returns 0", ffs(0), 0);
    ASSERT_EQUALS("swab: Checking, if ffs(1) returns 1", ffs(1), 1);
    ASSERT_EQUALS("swab: Checking, if ffs(2) returns 2", ffs(2), 2);
    ASSERT_EQUALS("swab: Checking, if ffs(4) returns 3", ffs(4), 3);
    ASSERT_EQUALS("swab: Checking, if ffs(8) returns 4", ffs(8), 4);
    ASSERT_EQUALS("swab: Checking, if ffs(16) returns 5", ffs(16), 5);
    ASSERT_EQUALS("swab: Checking, if ffs(32) returns 6", ffs(32), 6);
    ASSERT_EQUALS("swab: Checking, if ffs(64) returns 7", ffs(64), 7);
    ASSERT_EQUALS("swab: Checking, if ffs(128) returns 8", ffs(128), 8);
    ASSERT_EQUALS("swab: Checking, if ffs(256) returns 9", ffs(256), 9);
    ASSERT_EQUALS("swab: Checking, if ffs(512) returns 10", ffs(512), 10);
    ASSERT_EQUALS("swab: Checking, if ffs(1024) returns 11", ffs(1024), 11);
    ASSERT_EQUALS("swab: Checking, if ffs(2048) returns 12", ffs(2048), 12);
    ASSERT_EQUALS("swab: Checking, if ffs(4096) returns 13", ffs(4096), 13);
    ASSERT_EQUALS("swab: Checking, if ffs(8192) returns 14", ffs(8192), 14);
    ASSERT_EQUALS("swab: Checking, if ffs(16384) returns 15", ffs(16384), 15);
    ASSERT_EQUALS("swab: Checking, if ffs(32768) returns 16", ffs(32768), 16);
    ASSERT_EQUALS("swab: Checking, if ffs(65536) returns 17", ffs(65536), 17);
    ASSERT_EQUALS("swab: Checking, if ffs(131072) returns 18", ffs(131072), 18);
    
    ASSERT_EQUALS("ffs: Checking, if errno is unmodified", pre_errno, errno);
}


// Check all functions of unistd.h
void run_strings_tests()
{
    TEST_CASE("Test POSIX strings.h functions");

    test_ffs();
}