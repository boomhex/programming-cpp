#include "numbers.ih"


void Numbers::mult(int scalar)
{
    for (size_t index = 0; index != d_size; ++index)
        safeAt(index) *= scalar;
}
