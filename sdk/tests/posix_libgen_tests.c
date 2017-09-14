#include "posix_libgen_tests.h"

#include "../posix/errno.h"
#include "../posix/libgen.h"
#include "../posix/string.h"
#include "../../ttf/ttf.h"


static void test_basename()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("basename: Checking, if basename(\"/storage/msd0\") returns \"msd0\"", strcmp(basename("/storage/msd0"), "msd0"), 0);
    ASSERT_EQUALS("basename: Checking, if basename(\"/storage/\") returns \"storage\"", strcmp(basename("/storage/"), "storage"), 0);
    ASSERT_EQUALS("basename: Checking, if basename(\"/\") returns \"/\"", strcmp(basename("/"), "/"), 0);
    ASSERT_EQUALS("basename: Checking, if basename(\"///\") returns \"/\"", strcmp(basename("///"), "/"), 0);
    ASSERT_EQUALS("basename: Checking, if basename(\"//storage//msd0//\") returns \"msd0\"", strcmp(basename("//storage//msd0//"), "msd0"), 0);
    ASSERT_EQUALS("basename: Checking, if basename(\"\") returns \".\"", strcmp(basename(""), "."), 0);
    ASSERT_EQUALS("basename: Checking, if basename(NULL) returns \".\"", strcmp(basename(0), "."), 0);
    ASSERT_EQUALS("basename: Checking, if errno is unmodified", pre_errno, errno);
}


// Check all functions of libgen.h
#include <stdio.h>
void run_libgen_tests()
{
    TEST_CASE("Test POSIX libgen.h functions");

    test_basename();
}
