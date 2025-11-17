#include "numbers.ih"


void Numbers::sub(Numbers const &other)
{
    if (not equalSize(other))
        return;

    for (size_t index = 0; index != d_size; ++index)
        opIdx(index) += other[index];

    return;
}
