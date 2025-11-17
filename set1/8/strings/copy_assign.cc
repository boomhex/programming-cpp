#include "strings.ih"

Strings &Strings::operator=(Strings const &rhs)
{
    if (this == &rhs)
        return *this;

    ++*rhs.d_shared;        // protect against self-assignment & exceptions

    if (--*d_shared == 0)
    {
        delete[] d_str;
        delete d_shared;
    }

    d_str    = rhs.d_str;
    d_size   = rhs.d_size;
    d_shared = rhs.d_shared;

    return *this;
}