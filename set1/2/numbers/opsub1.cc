#include "numbers.ih"

Numbers &Numbers::operator-=(Numbers const &other)  &
{
    Numbers tmp{ other };
    std::move(tmp) -= other;
    return *this;
}
