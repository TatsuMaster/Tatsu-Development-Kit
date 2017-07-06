#include "../../ttf/ttf.h"
#include "posix_tests.h"
#include "crt_tests.h"


int main(int argc, char* argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    //
    // Init test system
    //

    TEST_SUITE_INIT();

    //
    // Run POSIX API tests
    //

    run_posix_tests();

    //
    // Run C runtime tests
    //

    run_crt_tests();


    //
    // Summary
    //

    TEST_SUITE_END();

    return 0;
}
