#include "strings.ih"

Strings::Proxy &Strings::Proxy::operator=(std::string const &value)
{
    d_owner.cow();                               // ensure unique data
    d_owner.d_str[d_index] = value;             // now safe to modify
    return *this;
}