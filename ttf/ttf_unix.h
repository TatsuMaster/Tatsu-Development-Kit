#ifndef TTF_UNIX_H
#define TTF_UNIX_H

#include <stdio.h>
#include <ncurses.h>

#include "../common/tdk_version.h"
#include "ttf_common.h"

#define SCREEN_OUTPUT printw

static WINDOW* output_buffer = 0;

static int rows = 0;
static int cols = 0;

int type_to_color[4] = { ALERT + 1, GOOD + 1, WARN + 1, INFO + 1 };


static void cleanup()
{
    if (output_buffer)
    {
        printw("Press any key...");
        getch();
        endwin();
    }
}


static void prepare_console_info()
{
    initscr();
    curs_set(0);
    start_color();
    use_default_colors();
    init_pair(type_to_color[ALERT], COLOR_RED, -1);
    init_pair(type_to_color[GOOD], COLOR_GREEN, -1);
    init_pair(type_to_color[WARN], COLOR_YELLOW, -1);
    init_pair(type_to_color[INFO], COLOR_BLUE, -1);
    refresh();

    output_buffer = stdscr;
    getmaxyx(stdscr, rows, cols);
}


static void print_at(int x, const char* msg, int attributes)
{
    int ox, y;
    getyx(output_buffer, y, ox);
    attron(attributes);
    mvprintw(y, x, "%s", msg);
    attroff(attributes);
    refresh();
}


static void print_result(const char* msg, msg_type_t type)
{
    if (!output_buffer)
        prepare_console_info();
    else
        print_at(cols - 12, msg, COLOR_PAIR(type_to_color[type]));
}

#endif
