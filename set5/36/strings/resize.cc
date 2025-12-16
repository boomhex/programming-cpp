#include "strings.ih"

void Strings::resize(std::size_t nr)
{
    if (nr <= d_size)
    {
        d_size = nr;
        return;
    }

    // Growing
    reserve(nr);                         // ensure capacity
    // Elements from d_size..nr-1 are already default-constructed strings.
    d_size = nr;
}
