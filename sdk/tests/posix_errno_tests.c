#include "posix_ctype_tests.h"

#include "../posix/errno.h"
#include "../../ttf/ttf.h"


// Check errno definitions
void run_posix_errno_tests()
{
    TEST_CASE("Test POSIX errno.h definitions");

    ASSERT_EQUALS("Checking, if E2BIG is defined correctly", E2BIG, 0x07);
    ASSERT_EQUALS("Checking, if EACCES is defined correctly", EACCES, 0x0D);
    ASSERT_EQUALS("Checking, if EADDRINUSE is defined correctly", EADDRINUSE, 0x62);
    ASSERT_EQUALS("Checking, if EADDRNOTAVAIL is defined correctly", EADDRNOTAVAIL, 0x63);
    ASSERT_EQUALS("Checking, if EAFNOSUPPORT is defined correctly", EAFNOSUPPORT, 0x61);
    ASSERT_EQUALS("Checking, if EAGAIN is defined correctly", EAGAIN, 0x0B);
    ASSERT_EQUALS("Checking, if EALREADY is defined correctly", EALREADY, 0x72);
    ASSERT_EQUALS("Checking, if EBADF is defined correctly", EBADF, 0x09);
    ASSERT_EQUALS("Checking, if EBADMSG is defined correctly", EBADMSG, 0x4A);
    ASSERT_EQUALS("Checking, if EBUSY is defined correctly", EBUSY, 0x10);
    ASSERT_EQUALS("Checking, if ECANCELED is defined correctly", ECANCELED, 0x7D);
    ASSERT_EQUALS("Checking, if ECHILD is defined correctly", ECHILD, 0x0A);
    ASSERT_EQUALS("Checking, if ECONNABORTED is defined correctly", ECONNABORTED, 0x67);
    ASSERT_EQUALS("Checking, if ECONNREFUSED is defined correctly", ECONNREFUSED, 0x6F);
    ASSERT_EQUALS("Checking, if ECONNRESET is defined correctly", ECONNRESET, 0x68);
    ASSERT_EQUALS("Checking, if EDEADLK is defined correctly", EDEADLK, 0x23);
    ASSERT_EQUALS("Checking, if EDESTADDRREQ is defined correctly", EDESTADDRREQ, 0x59);
    ASSERT_EQUALS("Checking, if EDOM is defined correctly", EDOM, 0x21);
    ASSERT_EQUALS("Checking, if EDQUOT is defined correctly", EDQUOT, 0x7A);
    ASSERT_EQUALS("Checking, if EEXIST is defined correctly", EEXIST, 0x11);
    ASSERT_EQUALS("Checking, if EFAULT is defined correctly", EFAULT, 0x0E);
    ASSERT_EQUALS("Checking, if EFBIG is defined correctly", EFBIG, 0x1B);
    ASSERT_EQUALS("Checking, if EHOSTUNREACH is defined correctly", EHOSTUNREACH, 0x71);
    ASSERT_EQUALS("Checking, if EIDRM is defined correctly", EIDRM, 0x2B);
    ASSERT_EQUALS("Checking, if EILSEQ is defined correctly", EILSEQ, 0x54);
    ASSERT_EQUALS("Checking, if EINPROGRESS is defined correctly", EINPROGRESS, 0x73);
    ASSERT_EQUALS("Checking, if EINTR is defined correctly", EINTR, 0x04);
    ASSERT_EQUALS("Checking, if EINVAL is defined correctly", EINVAL, 0x16);
    ASSERT_EQUALS("Checking, if EIO is defined correctly", EIO, 0x05);
    ASSERT_EQUALS("Checking, if EISCONN is defined correctly", EISCONN, 0x6A);
    ASSERT_EQUALS("Checking, if EISDIR is defined correctly", EISDIR, 0x15);
    ASSERT_EQUALS("Checking, if ELOOP is defined correctly", ELOOP, 0x28);
    ASSERT_EQUALS("Checking, if EMFILE is defined correctly", EMFILE, 0x18);
    ASSERT_EQUALS("Checking, if EMLINK is defined correctly", EMLINK, 0x1F);
    ASSERT_EQUALS("Checking, if EMSGSIZE is defined correctly", EMSGSIZE, 0x5A);
    ASSERT_EQUALS("Checking, if EMULTIHOP is defined correctly", EMULTIHOP, 0x48);
    ASSERT_EQUALS("Checking, if ENAMETOOLONG is defined correctly", ENAMETOOLONG, 0x24);
    ASSERT_EQUALS("Checking, if ENETDOWN is defined correctly", ENETDOWN, 0x64);
    ASSERT_EQUALS("Checking, if ENETRESET is defined correctly", ENETRESET, 0x66);
    ASSERT_EQUALS("Checking, if ENETUNREACH is defined correctly", ENETUNREACH, 0x65);
    ASSERT_EQUALS("Checking, if ENFILE is defined correctly", ENFILE, 0x17);
    ASSERT_EQUALS("Checking, if ENOBUFS is defined correctly", ENOBUFS, 0x69);
    ASSERT_EQUALS("Checking, if ENODATA is defined correctly", ENODATA, 0x3D);
    ASSERT_EQUALS("Checking, if ENODEV is defined correctly", ENODEV, 0x13);
    ASSERT_EQUALS("Checking, if ENOENT is defined correctly", ENOENT, 0x02);
    ASSERT_EQUALS("Checking, if ENOEXEC is defined correctly", ENOEXEC, 0x08);
    ASSERT_EQUALS("Checking, if ENOLCK is defined correctly", ENOLCK, 0x25);
    ASSERT_EQUALS("Checking, if ENOLINK is defined correctly", ENOLINK, 0x43);
    ASSERT_EQUALS("Checking, if ENOMEM is defined correctly", ENOMEM, 0x0C);
    ASSERT_EQUALS("Checking, if ENOMSG is defined correctly", ENOMSG, 0x2A);
    ASSERT_EQUALS("Checking, if ENOPROTOOPT is defined correctly", ENOPROTOOPT, 0x5C);
    ASSERT_EQUALS("Checking, if ENOSPC is defined correctly", ENOSPC, 0x1C);
    ASSERT_EQUALS("Checking, if ENOSR is defined correctly", ENOSR, 0x3F);
    ASSERT_EQUALS("Checking, if ENOSTR is defined correctly", ENOSTR, 0x3C);
    ASSERT_EQUALS("Checking, if ENOSYS is defined correctly", ENOSYS, 0x26);
    ASSERT_EQUALS("Checking, if ENOTCONN is defined correctly", ENOTCONN, 0x6B);
    ASSERT_EQUALS("Checking, if ENOTDIR is defined correctly", ENOTDIR, 0x14);
    ASSERT_EQUALS("Checking, if ENOTEMPTY is defined correctly", ENOTEMPTY, 0x27);
    ASSERT_EQUALS("Checking, if ENOTRECOVERABLE is defined correctly", ENOTRECOVERABLE, 0x83);
    ASSERT_EQUALS("Checking, if ENOTSOCK is defined correctly", ENOTSOCK, 0x58);
    ASSERT_EQUALS("Checking, if ENOTSUP is defined correctly", ENOTSUP, 0x5F);
    ASSERT_EQUALS("Checking, if ENOTTY is defined correctly", ENOTTY, 0x19);
    ASSERT_EQUALS("Checking, if ENXIO is defined correctly", ENXIO, 0x06);
    ASSERT_EQUALS("Checking, if EOPNOTSUPP is defined correctly", EOPNOTSUPP, 0x5F);
    ASSERT_EQUALS("Checking, if EOVERFLOW is defined correctly", EOVERFLOW, 0x4B);
    ASSERT_EQUALS("Checking, if EOWNERDEAD is defined correctly", EOWNERDEAD, 0x82);
    ASSERT_EQUALS("Checking, if EPERM is defined correctly", EPERM, 0x01);
    ASSERT_EQUALS("Checking, if EPIPE is defined correctly", EPIPE, 0x20);
    ASSERT_EQUALS("Checking, if EPROTO is defined correctly", EPROTO, 0x47);
    ASSERT_EQUALS("Checking, if EPROTONOSUPPORT is defined correctly", EPROTONOSUPPORT, 0x5D);
    ASSERT_EQUALS("Checking, if EPROTOTYPE is defined correctly", EPROTOTYPE, 0x5B);
    ASSERT_EQUALS("Checking, if ERANGE is defined correctly", ERANGE, 0x22);
    ASSERT_EQUALS("Checking, if EROFS is defined correctly", EROFS, 0x1E);
    ASSERT_EQUALS("Checking, if ESPIPE is defined correctly", ESPIPE, 0x1D);
    ASSERT_EQUALS("Checking, if ESRCH is defined correctly", ESRCH, 0x03);
    ASSERT_EQUALS("Checking, if ESTALE is defined correctly", ESTALE, 0x74);
    ASSERT_EQUALS("Checking, if ETIME is defined correctly", ETIME, 0x3E);
    ASSERT_EQUALS("Checking, if ETIMEDOUT is defined correctly", ETIMEDOUT, 0x6E);
    ASSERT_EQUALS("Checking, if ETXTBSY is defined correctly", ETXTBSY, 0x1A);
    ASSERT_EQUALS("Checking, if EWOULDBLOCK is defined correctly", EWOULDBLOCK, 0x0B);
    ASSERT_EQUALS("Checking, if EXDEV is defined correctly", EXDEV, 0x12);
}