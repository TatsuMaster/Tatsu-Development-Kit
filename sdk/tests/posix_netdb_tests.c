#include "posix_netdb_tests.h"

#include "../posix/netdb.h"
#include "../../ttf/ttf.h"


// Check netdb definitions
void run_posix_netdb_tests()
{
    TEST_CASE("Test POSIX netdb.h functions");

    ASSERT_EQUALS("Checking, if EAI_AGAIN is defined correctly", EAI_AGAIN, -3);
    ASSERT_EQUALS("Checking, if EAI_BADFLAGS is defined correctly", EAI_BADFLAGS, -1);
    ASSERT_EQUALS("Checking, if EAI_FAIL is defined correctly", EAI_FAIL, -4);
    ASSERT_EQUALS("Checking, if EAI_FAMILY is defined correctly", EAI_FAMILY, -6);
    ASSERT_EQUALS("Checking, if EAI_MEMORY is defined correctly", EAI_MEMORY, -10);
    ASSERT_EQUALS("Checking, if EAI_NONAME is defined correctly", EAI_NONAME, -2);
    ASSERT_EQUALS("Checking, if EAI_SERVICE is defined correctly", EAI_SERVICE, -8);
    ASSERT_EQUALS("Checking, if EAI_SOCKTYPE is defined correctly", EAI_SOCKTYPE, -7);
    ASSERT_EQUALS("Checking, if EAI_OVERFLOW is defined correctly", EAI_OVERFLOW, -12);
}
