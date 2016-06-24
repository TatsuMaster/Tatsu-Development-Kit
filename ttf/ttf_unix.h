#ifndef TTF_UNIX_H
#define TTF_UNIX_H

#include <stdio.h>
#include <stdarg.h>
#include <sys/ioctl.h>

#include "../common/tdk_version.h"
#include "ttf_common.h"

#define SCREEN_OUTPUT printf
#define STORED_SCREEN_OUTPUT print_and_record_line

static struct winsize console_size;
static bool console_init = false;
static size_t line_length = 0;
static char line_buffer[4096];

int type_to_color[4] = { ALERT + 1, GOOD + 1, WARN + 1, INFO + 1 };


static void print_and_record_line(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    line_length = vsnprintf(line_buffer, 4096, format, args);
    line_buffer[line_length] = 0;
    va_end(args);

    if (line_length > console_size.ws_col)
        printf("%.*s", console_size.ws_col, line_buffer);
    else
        printf("%s", line_buffer);
}

static void prepare_console_info()
{
    console_init = true;
    ioctl(0, TIOCGWINSZ, &console_size);
}


static void print_at(int x, const char* msg, int attributes)
{
    int space_value = x - line_length;
    if(space_value > -1)
        printf("\r%s%*s", line_buffer, space_value, msg);
    else
        printf("\r%s%s", line_buffer, msg);
}


static void print_result(const char* msg, msg_type_t type)
{
    if (!console_init)
        prepare_console_info();

    print_at(console_size.ws_col - 2, msg, 0);
}

#endif
