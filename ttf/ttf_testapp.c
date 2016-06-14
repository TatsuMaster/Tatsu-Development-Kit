#include "ttf.h"

int main(int argc, char* argv[])
{
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

    //
    // Fail test
    //

    ASSERT_TRUE("Failing Test", false);

	//
	// Summary
	//

    TEST_SUITE_END();

	return 0;
}
