#include "numbers.ih"

bool Numbers::equalSize(Numbers const &other)
{
    if (d_size != other.size())
    {
        cerr << "Incompatible size of: " <<
        d_size << " with size: " << other.size() << '\n';
        return false;
    }
    return true;
}