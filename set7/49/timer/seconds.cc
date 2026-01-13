#include "timer.ih"

size_t Timer::seconds()
{
    checkTimed();

    size_t lastedSeconds = chrono::duration_cast<std::chrono::seconds>
                                                (d_end - d_start).count();
    return lastedSeconds;
}