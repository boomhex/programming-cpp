#include "factory.ih"

void Factory::revert(Stack &train)
{
    size_t nCarsOnSide = d_side.size();
    for (size_t idx = 0; idx != nCarsOnSide; ++idx)
    {
        put(train, d_side, 1);
        put(d_rhs, train, 1);
    }
    put(train, d_rhs, nCarsOnSide);
}