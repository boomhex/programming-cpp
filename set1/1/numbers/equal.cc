#include "numbers.ih"

bool operator==(Numbers const &lhs, Numbers const &rhs)
{
    if (not lhs.size() == rhs.size())   // check compatible sizes
        return false;

    for (size_t idx = 0; idx < lhs.size(); ++idx)   // el wise equality check.
        if (lhs[idx] != rhs[idx])
            return false;
    return true;
}