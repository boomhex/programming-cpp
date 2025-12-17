#include "strings.ih"

void Strings::reserve(std::size_t nr)
{
    if (nr <= d_cap)
        return;

    std::unique_ptr<std::string[]> tmp = rawStrings(nr);

    for (std::size_t i = 0; i != d_size; ++i)
        tmp[i] = std::move(d_str[i]);   // move strings to new storage

    d_str = std::move(tmp);
    d_cap = nr;
}
