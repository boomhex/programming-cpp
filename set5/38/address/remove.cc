#include "address.ih"

size_t Address::remove(string const &postalCode)
{
    // loop through elements and remove matches
    for (auto begin = d_data.begin(); begin != d_data.end(); )
    {
        if (match(postalCode, begin->first.first))
            begin = d_data.erase(begin);
        else
            ++begin;                    // only increase ptr if nothing removed
    }                                   // removal already goes to next ptr
    return size();
}
