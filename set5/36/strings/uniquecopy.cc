#include "strings.ih"


void Strings::uniqueCopy(size_t size)
{
    shared_ptr<string []> tmp = shared_ptr<string []>{ new string[size] };

    for (size_t index = 0; index < d_size; ++index)
        tmp[index] = d_sp[index];

    d_sp = tmp;
}