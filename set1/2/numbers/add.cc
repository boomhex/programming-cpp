#include "numbers.ih"


void Numbers::add(Numbers const &other)
{
    if (not equalSize(other))                       // check compatibility
        return;

    for (size_t index = 0; index != d_size; ++index)    // add
        safeAt(index) += other[index];
}
