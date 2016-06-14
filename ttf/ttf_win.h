 #ifndef TTF_WIN_H
#define TTF_WIN_H

#include <windows.h>
#include <stdio.h>

#include "../common/tdk_version.h"
#include "ttf_common.h"

static CONSOLE_SCREEN_BUFFER_INFO console_info;

WORD type_to_color[4] = {
    FOREGROUND_RED,
    FOREGROUND_GREEN,
    FOREGROUND_INTENSITY,
    FOREGROUND_BLUE
};


static void prepare_console_info()
{
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &console_info))
    {
        console_info.dwSize.X = 80;
        console_info.dwSize.Y = 25;
    }
}


static void print_at(int x, const char* msg, const WORD* attributes, DWORD attr_len)
{
    COORD coord;
    DWORD result;
    prepare_console_info();

    coord.X = x;
    coord.Y = console_info.dwCursorPosition.Y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("%s", msg);

    if (attributes)
        WriteConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attributes, attr_len, coord, &result);
}


static void print_result(const char* msg, msg_type_t type)
{
    // TODO: Nur einmal machen!
    WORD attributes[8];

    for (int i = 0; i < 8; ++i)
        attributes[i] = type_to_color[type];

    print_at(console_info.dwSize.X - 12, msg, attributes, 8);
}

#endif
