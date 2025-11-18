#include "numbers.ih"

bool Numbers::zeroDivisionError(int divisor)
{
    if (divisor != 0)
        return false;

    std::cerr << "Division by not allowed.\n";
    return true;
}
