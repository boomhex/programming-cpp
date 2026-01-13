#include "timer.ih"

Timer::Timer()
:
    d_start(now()),
    d_end(now()),                        // init to now AI
    d_hasTimed{ false }
{}