#include "ttf.h"

int main(int argc, char* argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    //
    // Init test system
    //

    TEST_SUITE_INIT();

    //
    // Self test
    //

    TEST_CASE("Test Framework Self Test");

    ASSERT_EQUALS("ASSERT_EQUALS Self Test", 0, 0);
    ASSERT_EQUALS_NOT("ASSERT_EQUALS_NOT Self Test", 0, 1);
    ASSERT_TRUE("ASSERT_TRUE Self Test", true);
    ASSERT_FALSE("ASSERT_FALSE Self Test", false);
    ASSERT_TYPE_SIZE("ASSERT_TYPE_SIZE Self Test", char, 1);
    ASSERT_NULL("ASSERT_NULL Self Test", 0);
    ASSERT_NOT_NULL("ASSERT_NOT_NULL Self Test", argv);
    ASSERT_GREATER("ASSERT_GREATER Self Test", 32768, 1024);
    ASSERT_LESS("ASSERT_GREATER Self Test", 1024, 32768);
    ASSERT_GREATER_EQUAL("ASSERT_GREATER_EQUAL Self Test (I)", 32768, 1024);
    ASSERT_GREATER_EQUAL("ASSERT_GREATER_EQUAL Self Test (II)", 32768, 32768);
    ASSERT_LESS_EQUAL("ASSERT_LESS_EQUAL Self Test (I)", 1024, 32768);
    ASSERT_LESS_EQUAL("ASSERT_LESS_EQUAL Self Test (II)", 1024, 1024);
    ASSERT_IN_RANGE("ASSERT_IN_RANGE Self TEST (I)", 1, 1, 3);
    ASSERT_IN_RANGE("ASSERT_IN_RANGE Self TEST (II)", 2, 1, 3);
    ASSERT_IN_RANGE("ASSERT_IN_RANGE Self TEST (III)", 3, 1, 3);

    //
    // Fail test
    //

    ASSERT_TRUE("Failing Test", false);

    //
    // Skip test
    //

    SKIP_TEST("Test SKIP_TEST");

    //
    // Summary
    //

    TEST_SUITE_END();

    return 0;
}
