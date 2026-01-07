#include "timer.ih"

Timer::~Timer()
{
    size_t endMs = nowMs();
    size_t elapsed = endMs - d_start;
    d_out << elapsed;
}
