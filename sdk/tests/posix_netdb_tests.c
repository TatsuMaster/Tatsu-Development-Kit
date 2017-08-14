#include "posix_netdb_tests.h"

#include "../posix/errno.h"
#include "../posix/netdb.h"
#include "../posix/string.h"
#include "../../ttf/ttf.h"


static void test_netdb_definitions()
{
    ASSERT_EQUALS("Checking, if EAI_AGAIN is defined correctly", EAI_AGAIN, -3);
    ASSERT_EQUALS("Checking, if EAI_BADFLAGS is defined correctly", EAI_BADFLAGS, -1);
    ASSERT_EQUALS("Checking, if EAI_FAIL is defined correctly", EAI_FAIL, -4);
    ASSERT_EQUALS("Checking, if EAI_FAMILY is defined correctly", EAI_FAMILY, -6);
    ASSERT_EQUALS("Checking, if EAI_MEMORY is defined correctly", EAI_MEMORY, -10);
    ASSERT_EQUALS("Checking, if EAI_NONAME is defined correctly", EAI_NONAME, -2);
    ASSERT_EQUALS("Checking, if EAI_SERVICE is defined correctly", EAI_SERVICE, -8);
    ASSERT_EQUALS("Checking, if EAI_SOCKTYPE is defined correctly", EAI_SOCKTYPE, -7);
    ASSERT_EQUALS("Checking, if EAI_SYSTEM is defined correctly", EAI_SYSTEM, -11);
    ASSERT_EQUALS("Checking, if EAI_OVERFLOW is defined correctly", EAI_OVERFLOW, -12);
}


static void test_gai_strerror()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("gai_strerror: Checking, if gai_strerror return value for EAI_AGAIN is valid",
        strcmp(gai_strerror(EAI_AGAIN), "Temporary failure in name resolution"), 0);
    ASSERT_EQUALS("gai_strerror: Checking, if gai_strerror return value for EAI_BADFLAGS is valid",
        strcmp(gai_strerror(EAI_BADFLAGS), "Bad value for ai_flags"), 0);
    ASSERT_EQUALS("gai_strerror: Checking, if gai_strerror return value for EAI_FAIL is valid",
        strcmp(gai_strerror(EAI_FAIL), "Non-recoverable failure in name resolution"), 0);
    ASSERT_EQUALS("gai_strerror: Checking, if gai_strerror return value for EAI_FAMILY is valid",
        strcmp(gai_strerror(EAI_FAMILY), "ai_family not supported"), 0);
    ASSERT_EQUALS("gai_strerror: Checking, if gai_strerror return value for EAI_MEMORY is valid",
        strcmp(gai_strerror(EAI_MEMORY), "Memory allocation failure"), 0);
    ASSERT_EQUALS("gai_strerror: Checking, if gai_strerror return value for EAI_NONAME is valid",
        strcmp(gai_strerror(EAI_NONAME), "Name or service not known"), 0);
    ASSERT_EQUALS("gai_strerror: Checking, if gai_strerror return value for EAI_SERVICE is valid",
        strcmp(gai_strerror(EAI_SERVICE), "Servname not supported for ai_socktype"), 0);
    ASSERT_EQUALS("gai_strerror: Checking, if gai_strerror return value for EAI_SOCKTYPE is valid",
        strcmp(gai_strerror(EAI_SOCKTYPE), "ai_socktype not supported"), 0);
    ASSERT_EQUALS("gai_strerror: Checking, if gai_strerror return value for EAI_SYSTEM is valid",
        strcmp(gai_strerror(EAI_SYSTEM), "System error"), 0);
    ASSERT_EQUALS("gai_strerror: Checking, if gai_strerror return value for EAI_OVERFLOW is valid",
        strcmp(gai_strerror(EAI_OVERFLOW), "Argument buffer overflow"), 0);
    ASSERT_EQUALS("gai_strerror: Checking, if gai_strerror return value for 1337 is valid",
        strcmp(gai_strerror(1337), "Unknown error"), 0);
    ASSERT_EQUALS("gai_strerror: Checking, if errno is unmodified", pre_errno, errno);
}


// Check netdb definitions and functions
void run_posix_netdb_tests()
{
    TEST_CASE("Test POSIX netdb.h functions");

    test_netdb_definitions();

    test_gai_strerror();
}
