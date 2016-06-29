#include "ttf.h"

static unsigned t_step_counter = 0;
static unsigned t_step_pass_counter = 0;
static unsigned t_step_skip_counter = 0;
static unsigned t_step_fail_counter = 0;
static unsigned t_step_error_counter = 0;


unsigned step_counter()
{
    return t_step_counter;
}


void step_increment()
{
    ++t_step_counter;
}


unsigned pass_counter()
{
    return t_step_pass_counter;
}


void pass_increment()
{
    ++t_step_pass_counter;
}


unsigned skip_counter()
{
    return t_step_skip_counter;
}


void skip_increment()
{
    ++t_step_skip_counter;
}


unsigned fail_counter()
{
    return t_step_fail_counter;
}


void fail_increment()
{
    ++t_step_fail_counter;
}


unsigned error_counter()
{
    return t_step_error_counter;
}


void error_increment()
{
    ++t_step_error_counter;
}
