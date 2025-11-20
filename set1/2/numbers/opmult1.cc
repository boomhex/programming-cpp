#include "numbers.ih"

Numbers operator*(Numbers const &lhs, int scalar)
{
    Numbers copy{ lhs };
    return copy *= scalar;
}
