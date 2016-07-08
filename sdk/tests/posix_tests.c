#include "posix_errno_tests.h"
#include "posix_string_tests.h"


void run_posix_tests()
{
    // Check errno definitions
    run_posix_errno_tests();

    // Check all functions of string.h
    run_string_lib_tests();
}
