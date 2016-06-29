#ifndef ERRNO_H
#define ERRNO_H


int errno;


#define E2BIG           0x07
#define EACCES          0x0D
#define EADDRINUSE      0x62
#define EADDRNOTAVAIL   0x63
#define EAFNOSUPPORT    0x61
#define EAGAIN          0x0B
#define EALREADY        0x72
#define EBADF           0x09
#define EBADMSG         0x4A
#define EBUSY           0x10
#define ECANCELED       0x7D
#define ECHILD          0x0A
#define ECONNABORTED    0x67
#define ECONNREFUSED    0x6F
#define ECONNRESET      0x68
#define EDEADLK         0x23
#define EDESTADDRREQ    0x59
#define EDOM            0x21
#define EDQUOT          0x7A
#define EEXIST          0x11
#define EFAULT          0x0E
#define EFBIG           0x1B
#define EHOSTUNREACH    0x71
#define EIDRM           0x2B
#define EILSEQ          0x54
#define EINPROGRESS     0x73
#define EINTR           0x04
#define EINVAL          0x16
#define EIO             0x05
#define EISCONN         0x6A
#define EISDIR          0x15
#define ELOOP           0x28
#define EMFILE          0x18
#define EMLINK          0x1F
#define EMSGSIZE        0x5A
#define EMULTIHOP       0x48
#define ENAMETOOLONG    0x24
#define ENETDOWN        0x64
#define ENETRESET       0x66
#define ENETUNREACH     0x65
#define ENFILE          0x17
#define ENOBUFS         0x69
#define ENODATA         0x3D
#define ENODEV          0x13
#define ENOENT          0x02
#define ENOEXEC         0x08
#define ENOLCK          0x25
#define ENOLINK         0x43
#define ENOMEM          0x0C
#define ENOMSG          0x2A
#define ENOPROTOOPT     0x5C
#define ENOSPC          0x1C
#define ENOSR           0x3F
#define ENOSTR          0x3C
#define ENOSYS          0x26
#define ENOTCONN        0x6B
#define ENOTDIR         0x14
#define ENOTEMPTY       0x27
#define ENOTRECOVERABLE 0x83
#define ENOTSOCK        0x58
#define ENOTSUP         0x5F
#define ENOTTY          0x19
#define ENXIO           0x06
#define EOPNOTSUPP      0x5F
#define EOVERFLOW       0x4B
#define EOWNERDEAD      0x82
#define EPERM           0x01
#define EPIPE           0x20
#define EPROTO          0x47
#define EPROTONOSUPPORT 0x5D
#define EPROTOTYPE      0x5B
#define ERANGE          0x22
#define EROFS           0x1E
#define ESPIPE          0x1D
#define ESRCH           0x03
#define ESTALE          0x74
#define ETIME           0x3E
#define ETIMEDOUT       0x6E
#define ETXTBSY         0x1A
#define EWOULDBLOCK     0x0B
#define EXDEV           0x12

#endif