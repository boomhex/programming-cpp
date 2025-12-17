#include "strings.ih"


std::string &Strings::safeat(size_t index)    const
{
    if (index >= size())
        throw std::out_of_range("Index out of range");

    return *d_vsp[index];
}
