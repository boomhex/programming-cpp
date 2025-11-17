#include "numbers.ih"


Numbers &Numbers::operator+=(Numbers const &other)  &
{
    Numbers tmp{ *this };
    std::move(tmp) += other;
    swap(tmp);
    return *this;
}
