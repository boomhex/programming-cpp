#include "timer.ih"

void Timer::display(ostream &out)
{
    checkTimed();                       // ensure timer has ran

    time_t time_st = chrono::system_clock::to_time_t(d_start);
    time_t time_end = chrono::system_clock::to_time_t(d_end);

    out << "Starting time: " << ctime(&time_st); 
    out << "Starting time: " << ctime(&time_end);
}
