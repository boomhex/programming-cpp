#include "strings.ih"


Strings const Strings::operator()(char const *sep)
{
    Strings copy{ *this };
    copy.d_sep = string{ sep };        // replace separator
    return copy;
}
