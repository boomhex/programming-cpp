#include "strings.ih"


void Strings::resize(size_t size)
{
    if (size > d_cap)
        reserve(size);
    
    if (size > d_size)
    {
        for (std::size_t i = d_size; i < size; ++i)
            d_strings[i] = string{};    // init string for empty slots
    }

    d_size = size;  // No need to delete unused memory
}                   // initialized elements above new size, are capacity
