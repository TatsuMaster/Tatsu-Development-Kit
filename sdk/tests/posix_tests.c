#include "posix_arpa_inet_tests.h"
#include "posix_ctype_tests.h"
#include "posix_errno_tests.h"
#include "posix_fenv_tests.h"
#include "posix_math_tests.h"
#include "posix_netdb_tests.h"
#include "posix_signal_tests.h"
#include "posix_stdlib_tests.h"
#include "posix_string_tests.h"
#include "posix_strings_tests.h"
#include "posix_unistd_tests.h"
#include "posix_libgen_tests.h"
#include "posix_wchar_tests.h"


void run_posix_tests()
{
    // Check all functions of ctype.h
    run_posix_arpa_inet_tests();

    // Check all functions of ctype.h
    run_posix_ctype_tests();

    // Check errno definitions
    run_posix_errno_tests();

    // Check fenv functions
    run_fenv_tests();

    // Check signal definitions
    run_posix_signal_tests();

    // Check all functions of math.h
    run_math_lib_tests();

    // Check all functions of netdb.h
    run_posix_netdb_tests();

    // Check all functions of stdlib.h
    run_stdlib_tests();

    // Check all functions of string.h
    run_string_lib_tests();

    // Check all functions of unistd.h
    run_unistd_tests();

    // Check all functions of strings.h
    run_strings_tests();

    // Check all functions of libgen.h
    run_libgen_tests();

    // Check all functions of wchar.h
    run_wchar_lib_tests();
}
