#ifndef TTF_H
#define TTF_H

#include <stdio.h>
#include <time.h>

#include "../common/params.h"

#ifndef NULL
#define NULL 0
#endif

#ifndef true
#define true 1
#define TRUE true
#endif

#ifndef false
#define false 0
#define FALSE false
#endif

#ifndef bool
#define bool char
#endif

#ifdef WIN32
#include "ttf_win.h"
#else
#include "ttf_unix.h"
#endif

static unsigned t_step_counter       = 0;
static unsigned t_step_pass_counter  = 0;
static unsigned t_step_fail_counter  = 0;
static unsigned t_step_error_counter = 0;

static clock_t begin;
static clock_t end;

#define _display_ts_name(ts_name) STORED_SCREEN_OUTPUT("  Test Step %d:  %s...", t_step_counter, ts_name); print_result("[ .... ]\r", WARN);
#define _eval_condition(condition) if (condition) { print_result("[ PASS ]\n", GOOD); ++t_step_pass_counter; } else { print_result("[ FAIL ]\n", ALERT); ++t_step_fail_counter; }

#define TEST_SUITE_INIT() begin = clock(); prepare_console_info(); t_step_counter = 0; t_step_pass_counter = 0; t_step_fail_counter = 0; SCREEN_OUTPUT("Tatsu Test Framework - TDK Version %d.%d.%d\n", TDK_MAJOR_VERSION, TDK_MINOR_VERSION, TDK_PATCH_LEVEL);
#define TEST_SUITE_END() end = clock(); SCREEN_OUTPUT("\n\nExecuted %d test steps in %f seconds\n\n", t_step_counter, (double)(end - begin) / CLOCKS_PER_SEC); SCREEN_OUTPUT("Tests passed: %d\nTests failed: %d\nTest errors : %d\n\n", t_step_pass_counter, t_step_fail_counter, 0);

#define TEST_CASE(name) SCREEN_OUTPUT("\nRunning Test Case: %s\n", name);

#define ASSERT_EQUALS(ts_name, value, other) _display_ts_name(ts_name); ++t_step_counter; _eval_condition(value == other)
#define ASSERT_EQUALS_NOT(ts_name, value, other) _display_ts_name(ts_name); ++t_step_counter; _eval_condition(value != other)

#define ASSERT_TRUE(ts_name, value) ASSERT_EQUALS(ts_name, value, true)
#define ASSERT_FALSE(ts_name, value) ASSERT_EQUALS(ts_name, value, false)

#define ASSERT_NULL(ts_name, pointer) ASSERT_EQUALS(ts_name, pointer, NULL)
#define ASSERT_NOT_NULL(ts_name, pointer) ASSERT_EQUALS_NOT(ts_name, pointer, NULL)

#define ASSERT_GREATER(ts_name, value, other) _display_ts_name(ts_name); ++t_step_counter; _eval_condition(value > other)
#define ASSERT_LESS(ts_name, value, other) _display_ts_name(ts_name); ++t_step_counter; _eval_condition(value < other)

#define ASSERT_GREATER_EQUAL(ts_name, value, other) _display_ts_name(ts_name); ++t_step_counter; _eval_condition(value >= other)
#define ASSERT_LESS_EQUAL(ts_name, value, other) _display_ts_name(ts_name); ++t_step_counter; _eval_condition(value <= other)

#define ASSERT_TYPE_SIZE(ts_name, type, size) ASSERT_EQUALS(ts_name, sizeof(type), size)

#endif
