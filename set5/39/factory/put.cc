#include "factory.ih"

void Factory::put(Stack &to, Stack &from, size_t nCars)
{
    for (size_t idx = 0; idx != nCars; ++idx)
    {
        to.push(from.top());
        from.pop();
    }
}