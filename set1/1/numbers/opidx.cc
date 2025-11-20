#include "numbers.ih"

int &Numbers::safeAt(size_t index)   const
{
    if (not boundary(index))
        index = 0;
    return d_nums[index];
}
