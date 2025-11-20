#include "strings.ih"


Strings const &Strings::operator()(char const *sep)
{
    d_sep = string{ sep };        // replace separator
    return *this;
}
