#ifndef TTF_UNIX_H
#define TTF_UNIX_H

#include <stdio.h>
#include <stdarg.h>
#include <sys/ioctl.h>

#include "../common/tdk_version.h"
#include "ttf_common.h"

#define SCREEN_OUTPUT printf
#define STORED_SCREEN_OUTPUT print_and_record_line

void print_and_record_line(const char* format, ...);
void prepare_console_info();
void print_at(int x, const char* msg, const char* attributes);
void print_result(const char* msg, msg_type_t type);

#endif
