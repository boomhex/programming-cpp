#include "strings.ih"


Strings &Strings::operator+=(std::string const &str)
{
    d_strings.push_back(str);
    return *this;
}
