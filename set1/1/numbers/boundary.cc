#include "numbers.ih"

bool Numbers::boundary(size_t index) const
{
    if (index < d_size)
        return true;
    std::cerr  << "Numbers: boundary exceeded, index = " <<
            index << ", should be < " << d_size << '\n';
    return false;
}
