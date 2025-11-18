#include "numbers.ih"

Numbers operator/(Numbers const &lhs, int divisor)
{
    Numbers copy{ lhs };
    return copy /= divisor;
}
