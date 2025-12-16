#include "strings.ih"


void Strings::add(std::string const &str)
{
    if (d_size == d_cap)
        enlarge();

    d_str[d_size] = str;
    ++d_size;
}
