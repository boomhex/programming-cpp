#include "strings.ih"


std::string &Strings::operator[](size_t index)
{
    return at(index);
}