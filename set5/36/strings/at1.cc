#include "strings.ih"


std::string &Strings::at(size_t index)
{
    cow();
    return safeat(index);
}
