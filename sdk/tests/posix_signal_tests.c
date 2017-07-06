#include "posix_signal_tests.h"

#include "../posix/signal.h"
#include "../../ttf/ttf.h"


// Check signal definitions
void run_posix_signal_tests()
{
    TEST_CASE("Test POSIX signal.h definitions");

    ASSERT_EQUALS("Checking, if SIGABRT is defined correctly", SIGABRT, 6);
    ASSERT_EQUALS("Checking, if SIGALRM is defined correctly", SIGALRM, 14);
    ASSERT_EQUALS("Checking, if SIGFPE is defined correctly", SIGFPE, 8);
    ASSERT_EQUALS("Checking, if SIGHUP is defined correctly", SIGHUP, 1);
    ASSERT_EQUALS("Checking, if SIGILL is defined correctly", SIGILL, 4);
    ASSERT_EQUALS("Checking, if SIGINT is defined correctly", SIGINT, 2);
    ASSERT_EQUALS("Checking, if SIGKILL is defined correctly", SIGKILL, 9);
    ASSERT_EQUALS("Checking, if SIGPIPE is defined correctly", SIGPIPE, 13);
    ASSERT_EQUALS("Checking, if SIGQUIT is defined correctly", SIGQUIT, 3);
    ASSERT_EQUALS("Checking, if SIGSEGV is defined correctly", SIGSEGV, 11);
    ASSERT_EQUALS("Checking, if SIGTERM is defined correctly", SIGTERM, 15);
    ASSERT_EQUALS("Checking, if SIGUSR1 is defined correctly", SIGUSR1, 10);
    ASSERT_EQUALS("Checking, if SIGUSR2 is defined correctly", SIGUSR2, 12);
    ASSERT_EQUALS("Checking, if SIGCHLD is defined correctly", SIGCHLD, 17);
    ASSERT_EQUALS("Checking, if SIGCONT is defined correctly", SIGCONT, 18);
    ASSERT_EQUALS("Checking, if SIGSTOP is defined correctly", SIGSTOP, 19);
    ASSERT_EQUALS("Checking, if SIGTSTP is defined correctly", SIGTSTP, 20);
    ASSERT_EQUALS("Checking, if SIGTTIN is defined correctly", SIGTTIN, 21);
    ASSERT_EQUALS("Checking, if SIGTTOU is defined correctly", SIGTTOU, 22);
    ASSERT_EQUALS("Checking, if SIGBUS is defined correctly", SIGBUS, 7);
    ASSERT_EQUALS("Checking, if SIGPOLL is defined correctly", SIGPOLL, 29);
    ASSERT_EQUALS("Checking, if SIGPROF is defined correctly", SIGPROF, 27);
    ASSERT_EQUALS("Checking, if SIGSYS is defined correctly", SIGSYS, 31);
    ASSERT_EQUALS("Checking, if SIGTRAP is defined correctly", SIGTRAP, 5);
    ASSERT_EQUALS("Checking, if SIGURG is defined correctly", SIGURG, 23);
    ASSERT_EQUALS("Checking, if SIGVTALRM is defined correctly", SIGVTALRM, 26);
    ASSERT_EQUALS("Checking, if SIGXCPU is defined correctly", SIGXCPU, 24);
    ASSERT_EQUALS("Checking, if SIGXFSZ is defined correctly", SIGXFSZ, 25);
}
