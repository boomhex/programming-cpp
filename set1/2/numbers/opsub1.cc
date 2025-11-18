#include "numbers.ih"

Numbers &Numbers::operator-=(Numbers const &other)  &
{
    Numbers tmp{ other };
    std::move(tmp) -= other;
    swap(tmp);
    return *this;
}
