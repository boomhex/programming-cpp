#include "strings.ih"


void Strings::reserve(size_t newCap)
{
    if (newCap <= d_cap)
        return;

    unique_ptr<string []> tmp = make_unique<string []>(newCap);

    for (size_t index = 0; index < d_size; ++index)
        tmp[index] = std::move(d_strings[index]);

    d_strings = std::move(tmp);
    d_cap = newCap;
}
