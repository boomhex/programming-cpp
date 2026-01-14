#include "interactive.ih"

bool Interactive::isDate(string const &string)
{
    if (string.size() != 8 or string[2] != '-' or string[5] != '-')
        return false;

    // auto isdig = [](unsigned char c){ return std::isdigit(c); };
    for (std::size_t index = 0; index != string.size(); ++index)
    {
        if (index == 2 or index == 5)   // Do not check stripes
            continue;
        if (not isdigit(string[index]))
            return false;
    }
    return true;
}
