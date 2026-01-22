#include "main.ih"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    
    string arg = argv[1];     // get program agument

    // get current time from system clock
    const system_clock::time_point now = system_clock::now();

    // print the current time
    printTimes(now);

    // calculate new time with argument
    const system_clock::time_point newTime = now + calcTime(arg);

    // print new time
    printTimes(newTime);
}