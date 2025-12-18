#include "strings.ih"


std::string const &Strings::operator[](size_t index) const
{
    return at(index);
}
