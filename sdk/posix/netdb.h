#ifndef NETDB_H
#define NETDB_H

#define EAI_AGAIN    -3
#define EAI_BADFLAGS -1
#define EAI_FAIL     -4
#define EAI_FAMILY   -6
#define EAI_MEMORY   -10
#define EAI_NONAME   -2
#define EAI_SERVICE  -8
#define EAI_SOCKTYPE -7
#define EAI_SYSTEM   -11
#define EAI_OVERFLOW -12


const char *gai_strerror(int ecode);

#endif
