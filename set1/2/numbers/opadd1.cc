#include "numbers.ih"


Numbers &Numbers::operator+=(Numbers const &other)  &
{
    Numbers copy{ *this };
    std::move(copy) += other;
    swap(copy);
    return *this;
}
