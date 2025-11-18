#include "numbers.ih"

int &Numbers::operator[](size_t index)
{
    return safeAt(index);
}
