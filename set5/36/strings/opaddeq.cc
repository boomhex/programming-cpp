#include "strings.ih"


Strings &Strings::operator+=(std::string const &str)
{
    add(str);
    return *this;
}