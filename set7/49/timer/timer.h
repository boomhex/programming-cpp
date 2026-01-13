#ifndef INCLUDED_TIMER
#define INCLUDED_TIMER

#include <chrono>
#include <iosfwd>

class Timer
{
    std::chrono::system_clock::time_point d_start;
    std::chrono::system_clock::time_point d_end;
    bool d_hasTimed;

    public:
        Timer();

        void start();
        void stop();
        void reset();                   // unused in exercise, but nice to have
        void display(std::ostream &out);
        size_t seconds();
    private:
        void checkTimed();
        std::chrono::system_clock::time_point now();    // inline
};

inline std::chrono::system_clock::time_point Timer::now()
{
    return std::chrono::system_clock::now();
}

inline void Timer::start()
{
    d_start = now();
}

inline void Timer::stop()
{
    d_end = now();
    d_hasTimed = true;
}

inline void Timer::reset()
{
    d_hasTimed = false;
}

#endif