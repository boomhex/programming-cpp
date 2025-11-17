#include "numbers.ih"

Numbers &&Numbers::operator-=(Numbers const &other)     &&
{
    sub(other);
    return std::move(*this);
}
