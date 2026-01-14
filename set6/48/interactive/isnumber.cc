#include "interactive.ih"

bool Interactive::isNumber(string const &string)
{
    if (string.empty())
        return false;

    return all_of(string.begin(), string.end(),
                [](unsigned char c)
                {
                    return isdigit(c);
                }
            );
}