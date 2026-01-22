#include "main.ih"
system_clock::duration calcTime(string &arg)
{
    const char unit = arg.back();         // get time unit
    // make the rest of the string an interger
    const int value = stoi(arg.erase(arg.size() - 1));  

    switch(unit)    // switch to make the interger it respective time duration
    {
    case 's':
        return seconds{value};
    case 'm':
        return minutes{value};
    case 'h':
        return hours{value};
    default:
        throw runtime_error("invalid char");
    }
}