#include "strings.ih"


void Strings::reserve(size_t num)
{
    if (num <= d_cap)   // already on size, do nothing
        return;

    uniqueCopy(num);

    d_cap = num;
}
