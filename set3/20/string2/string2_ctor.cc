#include "string2.ih"

String2::String2(size_t count, string const &str)
:
    std::string()
{
    this->reserve(count * str.size());

    for (size_t idx = 0; idx != count; ++idx)
        *this += str;
}