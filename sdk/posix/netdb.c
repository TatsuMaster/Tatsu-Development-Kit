#include "netdb.h"


/******************************************************************************
 *
 * Private Access
 *
 *****************************************************************************/


static const char* _gai_error_msgs[] = {
    "Temporary failure in name resolution",
    "Bad value for ai_flags",
    "Non-recoverable failure in name resolution",
    "ai_family not supported",
    "Memory allocation failure",
    "Name or service not known",
    "Argument buffer overflow",
    "Servname not supported for ai_socktype",
    "ai_socktype not supported",
    "System error",
    "Unknown error"
};


/******************************************************************************
 *
 * Public Access
 *
 *****************************************************************************/


/******************************************************************************
 *
 * The gai_strerror() function returns a text string describing an error value
 * for the getaddrinfo() and getnameinfo() functions listed in the <netdb.h>
 * header.
 * When the ecode argument is one of the following values listed in the
 * <netdb.h> header:
 *
 *    [EAI_AGAIN]
 *    [EAI_BADFLAGS]
 *    [EAI_FAIL]
 *    [EAI_FAMILY]
 *    [EAI_MEMORY]
 *    [EAI_NONAME]
 *    [EAI_OVERFLOW]
 *    [EAI_SERVICE]
 *    [EAI_SOCKTYPE]
 *    [EAI_SYSTEM]
 *
 * The function return value points to a string describing the error. If the
 * argument is not one of those values listed above, the function returns a
 * pointer to a string whose contents indicate an unknown error.
 *
 * Upon successful completion, gai_strerror() returns a pointer to an
 * error string.
 *
*****************************************************************************/
const char *gai_strerror(int ecode)
{
    switch(ecode)
    {
        case EAI_AGAIN:
            return _gai_error_msgs[0];
        case EAI_BADFLAGS:
            return _gai_error_msgs[1];
        case EAI_FAIL:
            return _gai_error_msgs[2];
        case EAI_FAMILY:
            return _gai_error_msgs[3];
        case EAI_MEMORY:
            return _gai_error_msgs[4];
        case EAI_NONAME:
            return _gai_error_msgs[5];
        case EAI_OVERFLOW:
            return _gai_error_msgs[6];
        case EAI_SERVICE:
            return _gai_error_msgs[7];
        case EAI_SOCKTYPE:
            return _gai_error_msgs[8];
        case EAI_SYSTEM:
            return _gai_error_msgs[9];
        default:
            return _gai_error_msgs[10];
    }
}