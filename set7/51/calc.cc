#include "main.ih"
chrono::system_clock::duration calcTime(string const &arg)
{
    char unit = arg.back();
    string num = arg.substr(0, arg.size() - 1);
    int value = stoi(num);
    switch(unit)
    {
    case 's':
        return chrono::seconds{value};
    case 'm':
        return chrono::minutes{value};
    case 'h':
        return chrono::hours{value};
    default:
        throw runtime_error("invalid char");
    }
}