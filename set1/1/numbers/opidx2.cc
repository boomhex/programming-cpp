#include "numbers.ih"

int const &Numbers::operator[](size_t index)  const
{
    return safeAt(index);
}
