#include "factory.ih"

void Factory::reverse(Train &train)
{
    for (size_t ordered = 0; ordered != train.cars().size();)
    {
        size_t order = min(d_sideSize, train.cars().size() - ordered);
        put(d_side, train.cars(), order);
        put(d_rhs,  train.cars(), train.cars().size() - ordered);
        revert(train.cars());
        put(train.cars(), d_rhs,  d_rhs.size());
        ordered += order;
    }
}