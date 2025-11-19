#include "numbers.ih"


void Numbers::sub(Numbers const &other)
{
    if (not equalSize(other))   // check size
        return;

    for (size_t index = 0; index != d_size; ++index)
        safeAt(index) -= other[index];  // element subtraction
}
