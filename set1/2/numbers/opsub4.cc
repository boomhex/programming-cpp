#include "numbers.ih"

Numbers operator-(Numbers &&lhs, Numbers const &rhs)
{
    return std::move(lhs) += rhs;
}
