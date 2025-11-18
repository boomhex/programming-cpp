#include "numbers.ih"


void Numbers::swap(Numbers &other)
{
    std::swap(d_nums, other.d_nums);
    std::swap(d_size, other.d_size);
}