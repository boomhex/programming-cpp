#include "timer.ih"

void Timer::checkTimed()
{
    if (not d_hasTimed)
        throw runtime_error("");
}