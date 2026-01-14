#include "customIncrement.h"

customIncrement::customIncrement(unsigned value, unsigned step)
:
    value(value),
    step(step)
{}

// increment the value by step
customIncrement &customIncrement::operator++()
{
    value += step;
    return *this;
}

customIncrement::operator unsigned() const
{
    return value;
}
