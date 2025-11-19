#include "numbers.ih"

void Numbers::div(int divisor)
{
    if (zeroDivisionError(divisor)) // check validity
        return;
                                    // divide elements
    for (size_t index = 0; index != d_size; ++index)
        safeAt(index) /= divisor;
}
