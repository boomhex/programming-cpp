#include "numbers.ih"

int &Numbers::operatorIndex(size_t index)   const
{
    boundary(index);
    return d_nums[index];
}
