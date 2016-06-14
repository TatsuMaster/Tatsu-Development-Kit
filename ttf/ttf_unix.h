#ifndef TTF_UNIX_H
#define TTF_UNIX_H

#include <stdio.h>

#include "../common/tdk_version.h"
#include "ttf_common.h"


static void prepare_console_info()
{
}


static void print_at(int x, const char* msg)
{
    printf("%s", msg);
}


static void print_result(const char* msg, msg_type_t type)
{
    print_at(0, msg);
}

#endif
