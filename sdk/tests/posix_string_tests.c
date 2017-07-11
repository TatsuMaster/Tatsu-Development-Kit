#include "posix_string_tests.h"

#include "../posix/errno.h"
#include "../posix/signal.h"
#include "../posix/string.h"
#include "../../ttf/ttf.h"


static void test_memccpy()
{
    const int pre_errno = errno;
    const char* src_buffer_0 = "1234 4567";
    const char* src_buffer_1 = "1234 4567";
    char dest_buffer_0[10] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
    char dest_buffer_1[10] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
    const char* result_0 = memccpy(dest_buffer_0, src_buffer_0, 'X', 10);
    const char* result_1 = memccpy(dest_buffer_1, src_buffer_1, ' ', 10);

    const bool content_test_0 = (
        dest_buffer_0[0] == src_buffer_0[0] &&
        dest_buffer_0[1] == src_buffer_0[1] &&
        dest_buffer_0[2] == src_buffer_0[2] &&
        dest_buffer_0[3] == src_buffer_0[3] &&
        dest_buffer_0[4] == src_buffer_0[4] &&
        dest_buffer_0[5] == src_buffer_0[5] &&
        dest_buffer_0[6] == src_buffer_0[6] &&
        dest_buffer_0[7] == src_buffer_0[7] &&
        dest_buffer_0[8] == src_buffer_0[8] &&
        dest_buffer_0[9] == src_buffer_0[9]);

    const bool content_test_1 = (
        dest_buffer_1[0] == src_buffer_1[0] &&
        dest_buffer_1[1] == src_buffer_1[1] &&
        dest_buffer_1[2] == src_buffer_1[2] &&
        dest_buffer_1[3] == src_buffer_1[3] &&
        dest_buffer_1[4] == src_buffer_1[4] &&
        dest_buffer_1[5] != src_buffer_1[5] &&
        dest_buffer_1[6] != src_buffer_1[6] &&
        dest_buffer_1[7] != src_buffer_1[7] &&
        dest_buffer_1[8] != src_buffer_1[8] &&
        dest_buffer_1[9] != src_buffer_1[9]);

    ASSERT_TRUE("memccpy: Checking, if buffer was filled correctly", content_test_1);
    ASSERT_EQUALS("memccpy: Checking, if result pointer is set correctly", result_1, dest_buffer_1 + 5);
    ASSERT_TRUE("memccpy: Checking, if source and destination buffer are equal", content_test_0);
    ASSERT_EQUALS("memccpy: Checking, if result pointer is 0, if there is no occurence of c", result_0, 0);
    ASSERT_EQUALS("memccpy: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_memchr()
{
    const int pre_errno = errno;
    const char* src_buffer = "1234 4567";
    const char* result_0 = memchr(src_buffer, ' ', 10);
    const char* result_1 = memchr(src_buffer, 'X', 10);
    const char* result_2 = memchr(src_buffer, ' ', 2);

    ASSERT_EQUALS("memchr: Checking, if result pointer is set correctly, if c was found in memory", result_0, src_buffer + 4);
    ASSERT_EQUALS("memchr: Checking, if result pointer is 0, if c was not found in memory", result_1, 0);
    ASSERT_EQUALS("memchr: Checking, if result pointer is 0, if c was not found in given range", result_2, 0);
    ASSERT_EQUALS("memchr: Checking, if errno is unmodified", pre_errno, errno);
}


static void  test_memcmp()
{
    const int pre_errno = errno;
    const char src_buffer_0[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const char src_buffer_1[10] = { 0, 1, 2, 3, 4, 9, 8, 7, 6, 5 };
    const char src_buffer_2[10] = { 0, 1, 2, 3, 4, 1, 1, 1, 1, 1 };

    const int result_0 = memcmp(src_buffer_0, src_buffer_1, 10);
    const int result_1 = memcmp(src_buffer_0, src_buffer_1, 5);
    const int result_2 = memcmp(src_buffer_0, src_buffer_2, 10);
    const int result_3 = memcmp(src_buffer_0, src_buffer_2, 5);

    ASSERT_LESS("memcmp: Checking, if result is less 0, if s1 contains the greater object", result_0, 0);
    ASSERT_EQUALS("memcmp: Checking, if result is 0, if s1 and s2 are equal", result_1, 0);
    ASSERT_GREATER("memcmp: Checking, if result is greater 0, if s1 contains the greater object", result_2, 0);
    ASSERT_EQUALS("memcmp: Checking, if result is 0, if specified range of s1 and s2 are equal", result_3, 0);
    ASSERT_EQUALS("memcmp: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_memcpy()
{
    const int pre_errno = errno;
    const char src_buffer_0[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const char src_buffer_1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    char dest_buffer_0[10] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
    char dest_buffer_1[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    char dest_buffer_2[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    const char* result_0 = memcpy(dest_buffer_0, src_buffer_0, 10);
    const char* result_1 = memcpy(dest_buffer_1, src_buffer_1, 5);
    const char* result_2 = memcpy(dest_buffer_2, src_buffer_0, 0);

    const bool content_test_0 = (
        dest_buffer_0[0] == src_buffer_0[0] &&
        dest_buffer_0[1] == src_buffer_0[1] &&
        dest_buffer_0[2] == src_buffer_0[2] &&
        dest_buffer_0[3] == src_buffer_0[3] &&
        dest_buffer_0[4] == src_buffer_0[4] &&
        dest_buffer_0[5] == src_buffer_0[5] &&
        dest_buffer_0[6] == src_buffer_0[6] &&
        dest_buffer_0[7] == src_buffer_0[7] &&
        dest_buffer_0[8] == src_buffer_0[8] &&
        dest_buffer_0[9] == src_buffer_0[9]);

    const bool content_test_1 = (
        dest_buffer_1[0] == src_buffer_1[0] &&
        dest_buffer_1[1] == src_buffer_1[1] &&
        dest_buffer_1[2] == src_buffer_1[2] &&
        dest_buffer_1[3] == src_buffer_1[3] &&
        dest_buffer_1[4] == src_buffer_1[4] &&
        dest_buffer_1[5] == 1 &&
        dest_buffer_1[6] == 1 &&
        dest_buffer_1[7] == 1 &&
        dest_buffer_1[8] == 1 &&
        dest_buffer_1[9] == 1);

    const bool content_test_2 = (
        dest_buffer_2[0] == 1 &&
        dest_buffer_2[1] == 1 &&
        dest_buffer_2[2] == 1 &&
        dest_buffer_2[3] == 1 &&
        dest_buffer_2[4] == 1 &&
        dest_buffer_2[5] == 1 &&
        dest_buffer_2[6] == 1 &&
        dest_buffer_2[7] == 1 &&
        dest_buffer_2[8] == 1 &&
        dest_buffer_2[9] == 1);

    ASSERT_TRUE("memcpy: Checking, if full buffer copy works correctly", content_test_0);
    ASSERT_EQUALS("memcpy: Checking, if result pointer is set to s1 for full buffer copy", result_0, dest_buffer_0);
    ASSERT_TRUE("memcpy: Checking, if half buffer copy works correctly", content_test_1);
    ASSERT_EQUALS("memcpy: Checking, if result pointer is set to s1 for half buffer copy", result_1, dest_buffer_1);
    ASSERT_TRUE("memcpy: Checking, if zero copy works correctly", content_test_2);
    ASSERT_EQUALS("memcpy: Checking, if result pointer is set to s1 for zero copy", result_2, dest_buffer_2);
    ASSERT_EQUALS("memcpy: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_memset()
{
    const int pre_errno = errno;
    char dest_buffer[10] = { 0, 1, 2, 3, 'A', 'B', 'C', 'D', 'E', 'F' };
    const char* result = memset(dest_buffer, '0', 5);

    const bool content_test_0 = (
        dest_buffer[0] == '0' &&
        dest_buffer[1] == '0' &&
        dest_buffer[2] == '0' &&
        dest_buffer[3] == '0' &&
        dest_buffer[4] == '0');

    const bool content_test_1 = (
        dest_buffer[5] == 'B' &&
        dest_buffer[6] == 'C' &&
        dest_buffer[7] == 'D' &&
        dest_buffer[8] == 'E' &&
        dest_buffer[9] == 'F');

    ASSERT_TRUE("memset: Checking, if buffer content was copied correctly", content_test_0);
    ASSERT_TRUE("memset: Checking, if buffer content behind given limit was not modified", content_test_1);
    ASSERT_EQUALS("memset: Checking, if stpcpy return value equals address of the destination buffer", dest_buffer, result);
    ASSERT_EQUALS("memset: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_stpcpy()
{
    const int pre_errno = errno;
    const char* src_buffer = "1234";
    char dest_buffer[10] = { 0, 1, 2, 3, 'A', 'B', 'C', 'D', 'E', 'F' };
    const char* result = stpcpy(dest_buffer, src_buffer);

    // Do Not use strcmp...
    const bool content_test_0 = (
        dest_buffer[0] == src_buffer[0] &&
        dest_buffer[1] == src_buffer[1] &&
        dest_buffer[2] == src_buffer[2] &&
        dest_buffer[3] == src_buffer[3] &&
        dest_buffer[4] == src_buffer[4]);

    const bool content_test_1 = (
        dest_buffer[5] == 'B' &&
        dest_buffer[6] == 'C' &&
        dest_buffer[7] == 'D' &&
        dest_buffer[8] == 'E' &&
        dest_buffer[9] == 'F');

    ASSERT_TRUE("stpcpy: Checking, if buffer content was copied correctly", content_test_0);
    ASSERT_TRUE("stpcpy: Checking, if buffer content behind 0 termination was not modified", content_test_1);
    ASSERT_EQUALS("stpcpy: Checking, if stpcpy return value equals address of string end in destination buffer", dest_buffer + 4, result);
    ASSERT_EQUALS("stpcpy: Checking, if stpcpy destination buffer is 0 terminated", dest_buffer[4], 0);
    ASSERT_EQUALS("stpcpy: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_strcpy()
{
    const int pre_errno = errno;
    const char* src_buffer = "1234";
    char dest_buffer[10] = { 0, 1, 2, 3, 'A', 'B', 'C', 'D', 'E', 'F' };
    const char* result = strcpy(dest_buffer, src_buffer);

    // Do Not use strcmp...
    const bool content_test_0 = (
        dest_buffer[0] == src_buffer[0] &&
        dest_buffer[1] == src_buffer[1] &&
        dest_buffer[2] == src_buffer[2] &&
        dest_buffer[3] == src_buffer[3] &&
        dest_buffer[4] == src_buffer[4]);

    const bool content_test_1 = (
        dest_buffer[5] == 'B' &&
        dest_buffer[6] == 'C' &&
        dest_buffer[7] == 'D' &&
        dest_buffer[8] == 'E' &&
        dest_buffer[9] == 'F');

    ASSERT_TRUE("strcpy: Checking, if buffer content was copied correctly", content_test_0);
    ASSERT_TRUE("strcpy: Checking, if buffer content behind 0 termination was not modified", content_test_1);
    ASSERT_EQUALS("strcpy: Checking, if strcpy return value equals destination buffer address", dest_buffer, result);
    ASSERT_EQUALS("strcpy: Checking, if strcpy destination buffer is 0 terminated", dest_buffer[4], 0);
    ASSERT_EQUALS("strcpy: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_stpncpy()
{
    const int pre_errno = errno;
    const char* src_buffer = "1234";
    char dest_buffer[11] = { 0, 1, 2, 3, 'A', 'B', 'C', 'D', 'E', 'F', 'X' };
    char dest_buffer_ext[11] = { 0, 1, 2, 3, 'A', 'B', 'C', 'D', 'E', 'F', 'X' };
    const char* result = stpncpy(dest_buffer, src_buffer, 10);
    const char* result2 = stpncpy(dest_buffer_ext, src_buffer, 3);

    // Do Not use strcmp...
    const bool content_test_0 = (
        dest_buffer[0] == src_buffer[0] &&
        dest_buffer[1] == src_buffer[1] &&
        dest_buffer[2] == src_buffer[2] &&
        dest_buffer[3] == src_buffer[3] &&
        dest_buffer[4] == src_buffer[4]);

    const bool content_test_1 = (
        dest_buffer[5] == 0 &&
        dest_buffer[6] == 0 &&
        dest_buffer[7] == 0 &&
        dest_buffer[8] == 0 &&
        dest_buffer[9] == 0 &&
        dest_buffer[10] == 'X');

    const bool content_test_2 = (
        dest_buffer_ext[0] == src_buffer[0] &&
        dest_buffer_ext[1] == src_buffer[1] &&
        dest_buffer_ext[2] == src_buffer[2] &&
        dest_buffer_ext[3] == 3 &&
        dest_buffer_ext[4] == 'A');

    result2 = stpncpy(dest_buffer_ext, src_buffer, 5);

    const bool content_test_3 = (
        dest_buffer_ext[0] == src_buffer[0] &&
        dest_buffer_ext[1] == src_buffer[1] &&
        dest_buffer_ext[2] == src_buffer[2] &&
        dest_buffer_ext[3] == src_buffer[3] &&
        dest_buffer_ext[4] == src_buffer[4]);

    ASSERT_TRUE("stpncpy: Checking, if buffer content was copied correctly", content_test_0);
    ASSERT_TRUE("stpncpy: Checking, if buffer content behind 0 termination was filled up with 0", content_test_1);
    ASSERT_TRUE("stpncpy: Checking, if stpncpy considers maxlen correctly", content_test_2);
    ASSERT_TRUE("stpncpy: Checking, if stpncpy considers maxlen correctly", content_test_3);
    ASSERT_EQUALS("stpncpy: Checking, if stpncpy return value equals end of destination buffer address", &dest_buffer[4], result);
    ASSERT_EQUALS("stpncpy: Checking, if stpncpy return value equals end of destination buffer address (II)", &dest_buffer_ext[4], result2);
    ASSERT_EQUALS("stpncpy: Checking, if stpncpy destination buffer is 0 terminated", dest_buffer[4], 0);
    ASSERT_EQUALS("stpncpy: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_strchr()
{
    const int pre_errno = errno;
    const char* buffer = "1234";

    ASSERT_EQUALS("strchr: Checking, if strchr detects character at position 0 correctly", strchr(buffer, '1'), buffer);
    ASSERT_EQUALS("strchr: Checking, if strchr detects character at position 1 correctly", strchr(buffer, '2'), buffer + 1);
    ASSERT_EQUALS("strchr: Checking, if strchr detects character at position 2 correctly", strchr(buffer, '3'), buffer + 2);
    ASSERT_EQUALS("strchr: Checking, if strchr detects character at position 3 correctly", strchr(buffer, '4'), buffer + 3);
    ASSERT_EQUALS("strchr: Checking, if strchr considers zero character correctly", strchr(buffer, 0), buffer + 4);
    ASSERT_EQUALS("strchr: Checking, if strchr returns NULL as long as there are no matches", strchr(buffer, 'X'), 0);
    ASSERT_EQUALS("strchr: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_strcmp()
{
    const int pre_errno = errno;
    const char* src_buffer_0 = "aabb";
    const char* src_buffer_1 = "aabbA";
    const char* src_buffer_2 = "aaBB";

    const int result_0 = strcmp(src_buffer_0, src_buffer_0);
    const int result_1 = strcmp(src_buffer_0, src_buffer_1);
    const int result_2 = strcmp(src_buffer_0, src_buffer_2);

    ASSERT_LESS("strcmp: Checking, if result is less 0, if s1 contains the greater object", result_1, 0);
    ASSERT_EQUALS("strcmp: Checking, if result is 0, if s1 and s2 are equal", result_0, 0);
    ASSERT_GREATER("strcmp: Checking, if result is greater 0, if s1 contains the greater object", result_2, 0);
    ASSERT_EQUALS("strcmp: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_strcspn()
{
    const int pre_errno = errno;
    const char* buffer = "fcba73";
    const char* keys = "1234567890";

    ASSERT_EQUALS("strcspn: Checking, if strcspn detects key characters correctly", strcspn(buffer, keys), 4);
    ASSERT_EQUALS("strcspn: Checking, if strcspn returns string length as long as there are no keys defined", strcspn(buffer, ""), 6);
    ASSERT_EQUALS("strcspn: Checking, if strcspn returns 0 as long as first character is part of keys", strcspn(buffer, "af"), 0);
    ASSERT_EQUALS("strcspn: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_strerror()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("strerror: Checking, if strerror return value for errno 0 is NULL", strsignal(0), 0);
    ASSERT_EQUALS("strerror: Checking, if errno is unmodified on sccessfull calls", pre_errno, errno);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EPERM is correct",
        strcmp(strerror(EPERM), "Operation not permitted"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOENT is correct",
        strcmp(strerror(ENOENT), "No such file or directory"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ESRCH is correct",
        strcmp(strerror(ESRCH), "No such process"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EINTR is correct",
        strcmp(strerror(EINTR), "Interrupted system call"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EIO is correct",
        strcmp(strerror(EIO), "Input/output error"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENXIO is correct",
        strcmp(strerror(ENXIO), "No such device or address"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for E2BIG is correct",
        strcmp(strerror(E2BIG), "Argument list too long"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOEXEC is correct",
        strcmp(strerror(ENOEXEC), "Exec format error"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EBADF is correct",
        strcmp(strerror(EBADF), "Bad file descriptor"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ECHILD is correct",
        strcmp(strerror(ECHILD), "No child processes"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EAGAIN is correct",
        strcmp(strerror(EAGAIN), "Resource temporarily unavailable"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EWOULDBLOCK is correct",
        strcmp(strerror(EWOULDBLOCK), "Resource temporarily unavailable"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOMEM is correct",
        strcmp(strerror(ENOMEM), "Cannot allocate memory"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EACCES is correct",
        strcmp(strerror(EACCES), "Permission denied"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EFAULT is correct",
        strcmp(strerror(EFAULT), "Bad address"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EBUSY is correct",
        strcmp(strerror(EBUSY), "Device or resource busy"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EEXIST is correct",
        strcmp(strerror(EEXIST), "File exists"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EXDEV is correct",
        strcmp(strerror(EXDEV), "Invalid cross-device link"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENODEV is correct",
        strcmp(strerror(ENODEV), "No such device"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOTDIR is correct",
        strcmp(strerror(ENOTDIR), "Not a directory"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EISDIR is correct",
        strcmp(strerror(EISDIR), "Is a directory"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EINVAL is correct",
        strcmp(strerror(EINVAL), "Invalid argument"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENFILE is correct",
        strcmp(strerror(ENFILE), "Too many open files in system"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EMFILE is correct",
        strcmp(strerror(EMFILE), "Too many open files"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOTTY is correct",
        strcmp(strerror(ENOTTY), "Inappropriate ioctl for device"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ETXTBSY is correct",
        strcmp(strerror(ETXTBSY), "Text file busy"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EFBIG is correct",
        strcmp(strerror(EFBIG), "File too large"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOSPC is correct",
        strcmp(strerror(ENOSPC), "No space left on device"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ESPIPE is correct",
        strcmp(strerror(ESPIPE), "Illegal seek"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EROFS is correct",
        strcmp(strerror(EROFS), "Read-only file system"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EMLINK is correct",
        strcmp(strerror(EMLINK), "Too many links"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EPIPE is correct",
        strcmp(strerror(EPIPE), "Broken pipe"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EDOM is correct",
        strcmp(strerror(EDOM), "Numerical argument out of domain"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ERANGE is correct",
        strcmp(strerror(ERANGE), "Numerical result out of range"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EDEADLK is correct",
        strcmp(strerror(EDEADLK), "Resource deadlock avoided"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENAMETOOLONG is correct",
        strcmp(strerror(ENAMETOOLONG), "File name too long"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOLCK is correct",
        strcmp(strerror(ENOLCK), "No locks available"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOSYS is correct",
        strcmp(strerror(ENOSYS), "Function not implemented"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOTEMPTY is correct",
        strcmp(strerror(ENOTEMPTY), "Directory not empty"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ELOOP is correct",
        strcmp(strerror(ELOOP), "Too many levels of symbolic links"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOMSG is correct",
        strcmp(strerror(ENOMSG), "No message of desired type"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EIDRM is correct",
        strcmp(strerror(EIDRM), "Identifier removed"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOSTR is correct",
        strcmp(strerror(ENOSTR), "Device not a stream"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENODATA is correct",
        strcmp(strerror(ENODATA), "No data available"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ETIME is correct",
        strcmp(strerror(ETIME), "Timer expired"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOSR is correct",
        strcmp(strerror(ENOSR), "Out of streams resources"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOLINK is correct",
        strcmp(strerror(ENOLINK), "Link has been severed"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EPROTO is correct",
        strcmp(strerror(EPROTO), "Protocol error"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EMULTIHOP is correct",
        strcmp(strerror(EMULTIHOP), "Multihop attempted"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EBADMSG is correct",
        strcmp(strerror(EBADMSG), "Bad message"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EOVERFLOW is correct",
        strcmp(strerror(EOVERFLOW), "Value too large for defined data type"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EILSEQ is correct",
        strcmp(strerror(EILSEQ), "Invalid or incomplete multibyte or wide character"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOTSOCK is correct",
        strcmp(strerror(ENOTSOCK), "Socket operation on non-socket"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EDESTADDRREQ is correct",
        strcmp(strerror(EDESTADDRREQ), "Destination address required"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EMSGSIZE is correct",
        strcmp(strerror(EMSGSIZE), "Message too long"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EPROTOTYPE is correct",
        strcmp(strerror(EPROTOTYPE), "Protocol wrong type for socket"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOPROTOOPT is correct",
        strcmp(strerror(ENOPROTOOPT), "Protocol not available"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EPROTONOSUPPORT is correct",
        strcmp(strerror(EPROTONOSUPPORT), "Protocol not supported"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOTSUP is correct",
        strcmp(strerror(ENOTSUP), "Operation not supported"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EOPNOTSUPP is correct",
        strcmp(strerror(EOPNOTSUPP), "Operation not supported"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EAFNOSUPPORT is correct",
        strcmp(strerror(EAFNOSUPPORT), "Address family not supported by protocol"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EADDRINUSE is correct",
        strcmp(strerror(EADDRINUSE), "Address already in use"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EADDRNOTAVAIL is correct",
        strcmp(strerror(EADDRNOTAVAIL), "Cannot assign requested address"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENETDOWN is correct",
        strcmp(strerror(ENETDOWN), "Network is down"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENETUNREACH is correct",
        strcmp(strerror(ENETUNREACH), "Network is unreachable"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENETRESET is correct",
        strcmp(strerror(ENETRESET), "Network dropped connection on reset"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ECONNABORTED is correct",
        strcmp(strerror(ECONNABORTED), "Software caused connection abort"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ECONNRESET is correct",
        strcmp(strerror(ECONNRESET), "Connection reset by peer"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOBUFS is correct",
        strcmp(strerror(ENOBUFS), "No buffer space available"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EISCONN is correct",
        strcmp(strerror(EISCONN), "Transport endpoint is already connected"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOTCONN is correct",
        strcmp(strerror(ENOTCONN), "Transport endpoint is not connected"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ETIMEDOUT is correct",
        strcmp(strerror(ETIMEDOUT), "Connection timed out"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ECONNREFUSED is correct",
        strcmp(strerror(ECONNREFUSED), "Connection refused"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EHOSTUNREACH is correct",
        strcmp(strerror(EHOSTUNREACH), "No route to host"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EALREADY is correct",
        strcmp(strerror(EALREADY), "Operation already in progress"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EINPROGRESS is correct",
        strcmp(strerror(EINPROGRESS), "Operation now in progress"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ESTALE is correct",
        strcmp(strerror(ESTALE), "Stale file handle"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EDQUOT is correct",
        strcmp(strerror(EDQUOT), "Disk quota exceeded"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ECANCELED is correct",
        strcmp(strerror(ECANCELED), "Operation canceled"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for EOWNERDEAD is correct",
        strcmp(strerror(EOWNERDEAD), "Owner died"), 0);
    ASSERT_EQUALS("strerror: Checking, if strerror return value for ENOTRECOVERABLE is correct",
        strcmp(strerror(ENOTRECOVERABLE), "State not recoverable"), 0);


    ASSERT_EQUALS("strerror: Checking, if negative errno results to return value NULL", strsignal(-1), 0);
    ASSERT_EQUALS("strerror: Checking, if invalid errno results to return value NULL", strsignal(4711), 0);
    ASSERT_EQUALS("strerror: Checking, if errno is set to EINVAL using invalid strerror value", errno, EINVAL);
}


static void test_strlen()
{
    const int pre_errno = errno;
    const char* buffer_0 = "ABCDEFGHIJ";
    const char* buffer_1 = "ABCDE\0GHIJ";
    const char* buffer_2 = "";

    ASSERT_EQUALS("strlen: Checking, if strlen return value equals string length", strlen(buffer_0), 10);
    ASSERT_EQUALS("strlen: Checking, if strlen detects '0' character correctly", strlen(buffer_1), 5);
    ASSERT_EQUALS("strlen: Checking, if strlen applied on an empty string returns zero", strlen(buffer_2), 0);
    ASSERT_EQUALS("strlen: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_strncmp()
{
    const int pre_errno = errno;
    const char* src_buffer_0 = "aabb";
    const char* src_buffer_1 = "aabbA";
    const char* src_buffer_2 = "aaBB";

    const int result_0 = strncmp(src_buffer_0, src_buffer_0, 5);
    const int result_1 = strncmp(src_buffer_0, src_buffer_1, 5);
    const int result_2 = strncmp(src_buffer_0, src_buffer_2, 5);
    const int result_3 = strncmp(src_buffer_0, src_buffer_1, 4);

    ASSERT_LESS("strncmp: Checking, if result is less 0, if s1 contains the greater object", result_1, 0);
    ASSERT_EQUALS("strncmp: Checking, if result is 0, if s1 and s2 are equal", result_0, 0);
    ASSERT_GREATER("strncmp: Checking, if result is greater 0, if s1 contains the greater object", result_2, 0);
    ASSERT_EQUALS("strncmp: Checking, if maxlen was considered correctly", result_3, 0);
    ASSERT_EQUALS("strncmp: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_strncpy()
{
    const int pre_errno = errno;
    const char* src_buffer = "1234";
    char dest_buffer[11] = { 0, 1, 2, 3, 'A', 'B', 'C', 'D', 'E', 'F', 'X' };
    char dest_buffer_ext[11] = { 0, 1, 2, 3, 'A', 'B', 'C', 'D', 'E', 'F', 'X' };
    const char* result = strncpy(dest_buffer, src_buffer, 10);
    result = strncpy(dest_buffer_ext, src_buffer, 3);

    // Do Not use strcmp...
    const bool content_test_0 = (
        dest_buffer[0] == src_buffer[0] &&
        dest_buffer[1] == src_buffer[1] &&
        dest_buffer[2] == src_buffer[2] &&
        dest_buffer[3] == src_buffer[3] &&
        dest_buffer[4] == src_buffer[4]);

    const bool content_test_1 = (
        dest_buffer[5] == 0 &&
        dest_buffer[6] == 0 &&
        dest_buffer[7] == 0 &&
        dest_buffer[8] == 0 &&
        dest_buffer[9] == 0 &&
        dest_buffer[10] == 'X');

    const bool content_test_2 = (
        dest_buffer_ext[0] == src_buffer[0] &&
        dest_buffer_ext[1] == src_buffer[1] &&
        dest_buffer_ext[2] == src_buffer[2] &&
        dest_buffer_ext[3] == 3 &&
        dest_buffer_ext[4] == 'A');

    result = strncpy(dest_buffer_ext, src_buffer, 5);

    const bool content_test_3 = (
        dest_buffer_ext[0] == src_buffer[0] &&
        dest_buffer_ext[1] == src_buffer[1] &&
        dest_buffer_ext[2] == src_buffer[2] &&
        dest_buffer_ext[3] == src_buffer[3] &&
        dest_buffer_ext[4] == src_buffer[4]);

    ASSERT_TRUE("strncpy: Checking, if buffer content was copied correctly", content_test_0);
    ASSERT_TRUE("strncpy: Checking, if buffer content behind 0 termination was filled up with 0", content_test_1);
    ASSERT_TRUE("strncpy: Checking, if strncpy considers maxlen correctly", content_test_2);
    ASSERT_TRUE("strncpy: Checking, if strncpy considers maxlen correctly", content_test_3);
    ASSERT_EQUALS("strncpy: Checking, if strcpy return value equals destination buffer address", dest_buffer_ext, result);
    ASSERT_EQUALS("strncpy: Checking, if strcpy destination buffer is 0 terminated", dest_buffer[4], 0);
    ASSERT_EQUALS("strncpy: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_strnlen()
{
    const int pre_errno = errno;
    const char* buffer_0 = "ABCDEFGHIJ";
    const char* buffer_1 = "ABCDE\0GHIJ";
    const char* buffer_2 = "";

    ASSERT_EQUALS("strnlen: Checking, if strnlen return value equals string length", strnlen(buffer_0, 20), 10);
    ASSERT_EQUALS("strnlen: Checking, if strnlen detects '0' character correctly", strnlen(buffer_1, 20), 5);
    ASSERT_EQUALS("strnlen: Checking, if strnlen applied on an empty string returns zero", strnlen(buffer_2, 20), 0);
    ASSERT_EQUALS("strnlen: Checkling if strnlen considers maxlen correctly", strnlen(buffer_0, 5), 5);
    ASSERT_EQUALS("strnlen: Checkling if strnlen considers maxlen correctly (II)", strnlen(buffer_1, 2), 2);
    ASSERT_EQUALS("strnlen: Checkling if strnlen considers maxlen of 0 correctly", strnlen(buffer_0, 0), 0);
    ASSERT_EQUALS("strnlen: Checking, if errno is unmodified", pre_errno, errno);
}


static void test_strsignal()
{
    const int pre_errno = errno;

    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for signum 0 is NULL", strsignal(0), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for signum 16 is NULL", strsignal(16), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for signum 28 is NULL", strsignal(28), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for signum 30 is NULL", strsignal(30), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGABRT is correct",
        strcmp(strsignal(SIGABRT), "Process abort signal."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGALRM is correct",
        strcmp(strsignal(SIGALRM), "Alarm clock."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGBUS is correct",
        strcmp(strsignal(SIGBUS), "Access to an undefined portion of a memory object."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGCHLD is correct",
        strcmp(strsignal(SIGCHLD), "Child process terminated, stopped, or continued."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGCONT is correct",
        strcmp(strsignal(SIGCONT), "Continue executing, if stopped."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGFPE is correct",
        strcmp(strsignal(SIGFPE), "Erroneous arithmetic operation."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGHUP is correct",
        strcmp(strsignal(SIGHUP), "Hangup."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGILL is correct",
        strcmp(strsignal(SIGILL), "Illegal instruction."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGINT is correct",
        strcmp(strsignal(SIGINT), "Terminal interrupt signal."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGKILL is correct",
        strcmp(strsignal(SIGKILL), "Kill (cannot be caught or ignored)."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGPIPE is correct",
        strcmp(strsignal(SIGPIPE), "Write on a pipe with no one to read it."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGQUIT is correct",
        strcmp(strsignal(SIGQUIT), "Terminal quit signal."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGSEGV is correct",
        strcmp(strsignal(SIGSEGV), "Invalid memory reference."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGSTOP is correct",
        strcmp(strsignal(SIGSTOP), "Stop executing (cannot be caught or ignored)."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGTERM is correct",
        strcmp(strsignal(SIGTERM), "Termination signal."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGTSTP is correct",
        strcmp(strsignal(SIGTSTP), "Terminal stop signal."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGTTIN is correct",
        strcmp(strsignal(SIGTTIN), "Background process attempting read."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGTTOU is correct",
        strcmp(strsignal(SIGTTOU), "Background process attempting write."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGUSR1 is correct",
        strcmp(strsignal(SIGUSR1), "User-defined signal 1."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGUSR2 is correct",
        strcmp(strsignal(SIGUSR2), "User-defined signal 2."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGPOLL is correct",
        strcmp(strsignal(SIGPOLL), "Pollable event."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGPROF is correct",
        strcmp(strsignal(SIGPROF), "Profiling timer expired."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGSYS is correct",
        strcmp(strsignal(SIGSYS), "Bad system call."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGTRAP is correct",
        strcmp(strsignal(SIGTRAP), "Trace/breakpoint trap."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGURG is correct",
        strcmp(strsignal(SIGURG), "High bandwidth data is available at a socket."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGVTALRM is correct",
        strcmp(strsignal(SIGVTALRM), "Virtual timer expired."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGXCPU is correct",
        strcmp(strsignal(SIGXCPU), "CPU time limit exceeded."), 0);
    ASSERT_EQUALS("strsignal: Checking, if strsignal return value for SIGXFSZ is correct",
        strcmp(strsignal(SIGXFSZ), "File size limit exceeded."), 0);
    ASSERT_EQUALS("strsignal: Checking, if errno is unmodified on successfull calls", pre_errno, errno);
    ASSERT_EQUALS("strsignal: Checking, if negative signum results to return value NULL", strsignal(-1), 0);
    ASSERT_EQUALS("strsignal: Checking, if invalid signum results to return value NULL", strsignal(4711), 0);
    ASSERT_EQUALS("strsignal: Checking, if errno is set to EINVAL using invalid signum value", errno, EINVAL);

    errno = 0;
}


// Check all functions of string.h
void run_string_lib_tests()
{
    TEST_CASE("Test POSIX string.h functions");

    test_memccpy();
    test_memchr();
    test_memcmp();
    test_memcpy();
    test_memset();
    test_stpcpy();
    test_stpncpy();
    test_strchr();
    test_strcmp();
    test_strcpy();
    test_strcspn();
    test_strerror();
    test_strlen();
    test_strncmp();
    test_strncpy();
    test_strnlen();
    test_strsignal();
}
