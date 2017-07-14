#include "posix_arpa_inet_tests.h"

#include "../posix/errno.h"
#include "../posix/arpa/inet.h"
#include "../../ttf/ttf.h"


static void test_htons()
{
#ifdef __x86_64__
    const int pre_errno = errno;
    ASSERT_EQUALS("htons: Checking, if htons(0) return value equals 0", htons(0), 0);
    ASSERT_EQUALS("htons: Checking, if htons(42) return value equals 10752", htons(42), 10752);
    ASSERT_EQUALS("htons: Checking, if htons(1337) return value equals 14597", htons(1337), 14597);
    ASSERT_EQUALS("htons: Checking, if htons(65535) return value equals 65535", htons(65535), 65535);
    ASSERT_EQUALS("htons: Checking, if errno is unmodified", pre_errno, errno);
#else
    SKIP_TEST("htons: no tests defined for this architecture");
#endif
}


static void test_htonl()
{
#ifdef __x86_64__
    const int pre_errno = errno;
    ASSERT_EQUALS("htonl: Checking, if htonl(0) return value equals 0", htonl(0), 0);
    ASSERT_EQUALS("htonl: Checking, if htonl(42) return value equals 704643072", htonl(42), 704643072);
    ASSERT_EQUALS("htonl: Checking, if htonl(1337) return value equals 956628992", htonl(1337UL), 956628992UL);
    ASSERT_EQUALS("htonl: Checking, if htonl(65535) return value equals 4294901760", htonl(65535UL), 4294901760UL);
    ASSERT_EQUALS("htonl: Checking, if htonl(4294967295) return value equals 4294967295", htonl(4294967295UL), 4294967295UL);
    ASSERT_EQUALS("htonl: Checking, if errno is unmodified", pre_errno, errno);
#else
    SKIP_TEST("htonl: no tests defined for this architecture");
#endif
}


static void test_htonll()
{
#ifdef __x86_64__
    const int pre_errno = errno;
    ASSERT_EQUALS("htonll: Checking, if errno is unmodified", pre_errno, errno);
    ASSERT_EQUALS("htonll: Checking, if htonll(0) return value equals 0", htonll(0ULL), 0ULL);
    ASSERT_EQUALS("htonll: Checking, if htonll(42) return value equals 3026418949592973312", htonll(42ULL), 3026418949592973312ULL);
    ASSERT_EQUALS("htonll: Checking, if htonll(1337) return value equals 4108690235045445632", htonll(1337ULL), 4108690235045445632ULL);
    ASSERT_EQUALS("htonll: Checking, if htonll(65535) return value equals 18446462598732840960", htonll(65535ULL), 18446462598732840960ULL);
    ASSERT_EQUALS("htonll: Checking, if htonll(4294967295) return value equals 18446744069414584320", htonll(4294967295ULL), 18446744069414584320ULL);
    ASSERT_EQUALS("htonll: Checking, if htonll(18446744073709551615) return value equals 18446744073709551615", htonll(18446744073709551615ULL), 18446744073709551615ULL);
#else
    SKIP_TEST("htons: no tests defined for this architecture");
#endif
}


static void test_ntohs()
{
#ifdef __x86_64__
    const int pre_errno = errno;
    ASSERT_EQUALS("ntohs: Checking, if ntohs(0) return value equals 0", ntohs(0), 0);
    ASSERT_EQUALS("ntohs: Checking, if ntohs(10752) return value equals 42", ntohs(10752), 42);
    ASSERT_EQUALS("ntohs: Checking, if ntohs(14597) return value equals 1337", ntohs(14597), 1337);
    ASSERT_EQUALS("ntohs: Checking, if ntohs(65535) return value equals 65535", ntohs(65535), 65535);
    ASSERT_EQUALS("ntohs: Checking, if errno is unmodified", pre_errno, errno);
#else
    SKIP_TEST("ntohs: no tests defined for this architecture");
#endif
}


static void test_ntohl()
{
#ifdef __x86_64__
    const int pre_errno = errno;
    ASSERT_EQUALS("ntohl: Checking, if ntohl(0) return value equals 0", ntohl(0), 0);
    ASSERT_EQUALS("ntohl: Checking, if ntohl(704643072) return value equals 42", ntohl(704643072UL), 42UL);
    ASSERT_EQUALS("ntohl: Checking, if ntohl(956628992) return value equals 1337", ntohl(956628992UL), 1337UL);
    ASSERT_EQUALS("ntohl: Checking, if ntohl(4294901760) return value equals 65535", ntohl(4294901760UL), 65535UL);
    ASSERT_EQUALS("htonl: Checking, if ntohl(4294967295) return value equals 4294967295", ntohl(4294967295UL), 4294967295UL);
    ASSERT_EQUALS("ntohl: Checking, if errno is unmodified", pre_errno, errno);
#else
    SKIP_TEST("ntohl: no tests defined for this architecture");
#endif
}


static void test_ntohll()
{
#ifdef __x86_64__
    const int pre_errno = errno;
    ASSERT_EQUALS("ntohll: Checking, if ntohll(0) return value equals 0", ntohll(0ULL), 0ULL);
    ASSERT_EQUALS("ntohll: Checking, if ntohll(3026418949592973312) return value equals 42", ntohll(3026418949592973312ULL), 42ULL);
    ASSERT_EQUALS("ntohll: Checking, if ntohll(4108690235045445632) return value equals 1337", ntohll(4108690235045445632ULL), 1337ULL);
    ASSERT_EQUALS("ntohll: Checking, if ntohll(18446462598732840960) return value equals 65535", ntohll(18446462598732840960ULL), 65535ULL);
    ASSERT_EQUALS("ntohll: Checking, if ntohll(18446744069414584320) return value equals 4294967295", ntohll(18446744069414584320ULL), 4294967295ULL);
    ASSERT_EQUALS("ntohll: Checking, if ntohll(18446744073709551615) return value equals 18446744073709551615", ntohll(18446744073709551615ULL), 18446744073709551615ULL);
    ASSERT_EQUALS("ntohll: Checking, if errno is unmodified", pre_errno, errno);
#else
    SKIP_TEST("ntohll: no tests defined for this architecture");
#endif
}


static void test_ntohtonx()
{
#ifdef __x86_64__
    const int pre_errno = errno;
    ASSERT_EQUALS("xtoys: Checking, if ntohs(htons(0)) return value equals 0", ntohs(htons(0)), 0);
    ASSERT_EQUALS("xtoys: Checking, if ntohs(htons(42)) return value equals 42", ntohs(htons(42)), 42);
    ASSERT_EQUALS("xtoys: Checking, if ntohs(htons(1337)) return value equals 1337", ntohs(htons(1337)), 1337);
    ASSERT_EQUALS("xtoys: Checking, if ntohs(htons(65535)) return value equals 65535", ntohs(htons(65535)), 65535);
    ASSERT_EQUALS("xtoys: Checking, if ntohl(htonl(0)) return value equals 0", ntohl(htonl(0UL)), 0UL);
    ASSERT_EQUALS("xtoys: Checking, if ntohl(htonl(42)) return value equals 42", ntohl(htonl(42UL)), 42UL);
    ASSERT_EQUALS("xtoys: Checking, if ntohl(htonl(1337)) return value equals 1337", ntohl(htonl(1337UL)), 1337UL);
    ASSERT_EQUALS("xtoys: Checking, if ntohl(htonl(65535)) return value equals 65535", ntohl(htonl(65535UL)), 65535UL);
    ASSERT_EQUALS("xtoys: Checking, if ntohl(htonl(4294967295)) return value equals 4294967295", htonl(ntohl(4294967295UL)), 4294967295UL);
    ASSERT_EQUALS("xtoys: Checking, if ntohll(htonll(0)) return value equals 0", ntohll(htonll(0ULL)), 0ULL);
    ASSERT_EQUALS("xtoys: Checking, if ntohll(htonll(42)) return value equals 42", ntohll(htonll(42ULL)), 42ULL);
    ASSERT_EQUALS("xtoys: Checking, if ntohll(htonll(1337)) return value equals 1337", ntohll(htonll(1337ULL)), 1337ULL);
    ASSERT_EQUALS("xtoys: Checking, if ntohll(htonll(65535)) return value equals 65535", ntohll(htonll(65535ULL)), 65535ULL);
    ASSERT_EQUALS("xtoys: Checking, if ntohll(htonll(4294967295)) return value equals 4294967295", ntohll(htonll(4294967295ULL)), 4294967295ULL);
    ASSERT_EQUALS("xtoys: Checking, if ntohll(htonll(18446744073709551615)) return value equals 18446744073709551615", ntohll(htonll(18446744073709551615ULL)), 18446744073709551615ULL);
    ASSERT_EQUALS("xtoys: Checking, if errno is unmodified", pre_errno, errno);
#else
    SKIP_TEST("xtoys: no tests defined for this architecture");
#endif
}


// Check all functions of arpa/inet.h
void run_posix_arpa_inet_tests()
{
    TEST_CASE("Test POSIX arpa/inet.h functions");

    test_htons();
    test_htonl();
    test_htonll();
    test_ntohs();
    test_ntohl();
    test_ntohll();
    test_ntohtonx();
}
