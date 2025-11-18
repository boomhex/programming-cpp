#include "numbers.ih"

bool Numbers::isEqual(Numbers const &other) const
{
    if (size() != other.size())   // check compatible sizes
        return false;

    for (size_t idx = 0; idx != other.size(); ++idx)   // el wise equality check.
        if (safeAt(idx) != other[idx])
            return false;
    return true;
}
