#include "strings.ih"

std::string const &Strings::at(size_t index) const
{
    return safeat(index);
}
