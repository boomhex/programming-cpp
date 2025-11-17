#include "strings.ih"

std::ostream &operator<<(std::ostream &out, Strings::Proxy const &proxy)
{
    // Uses the conversion operator to const std::string&
    return out << static_cast<std::string const &>(proxy);
}