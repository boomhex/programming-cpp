#include "numbers.ih"


Numbers &&Numbers::operator+=(Numbers const &other)  &&
{
    add(other);
    return std::move(*this);
}
