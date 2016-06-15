#ifndef TTF_UNIX_H
#define TTF_UNIX_H

#include <stdio.h>
#include <sys/ioctl.h>

#include "../common/tdk_version.h"
#include "ttf_common.h"

#define SCREEN_OUTPUT printf

static struct winsize console_size;
static bool console_init = false;

int type_to_color[4] = { ALERT + 1, GOOD + 1, WARN + 1, INFO + 1 };

static void prepare_console_info()
{
    console_init = true;
    ioctl(0, TIOCGWINSZ, &console_size);
}


static void print_at(int x, const char* msg, int attributes)
{
    printf("%*s", x, msg);
}


static void print_result(const char* msg, msg_type_t type)
{
    if (!console_init)
        prepare_console_info();

    print_at(console_size.ws_col - 2, msg, 0);
}

#endif
