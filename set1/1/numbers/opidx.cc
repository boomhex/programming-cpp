#include "numbers.ih"

int &Numbers::opIdx(size_t index)   const
{
    boundary(index);
    return d_nums[index];
}
