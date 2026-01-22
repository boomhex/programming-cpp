#include "main.ih"
void printTimes(system_clock::time_point const time)
{
    const time_t ptime = system_clock::to_time_t(time);

    cout << put_time(localtime(&ptime), "%c %Z") << '\n'
         << put_time(gmtime(&ptime), "%c %Z") << '\n';
}