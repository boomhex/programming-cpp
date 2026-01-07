#ifndef INCLUDED_TIMER_
#define INCLUDED_TIMER_

#include <iosfwd>

class Timer
{
    std::ostream &d_out;
    size_t  d_start;                    // -> time in nanosecs

    public:
        Timer(std::ostream &out);
        ~Timer();                       // inserts the elapsed time into out
    private:
        static size_t nowMs();          // ih
};

#endif