#include "strings.ih"


void only2(ostream &out, Strings const &strings, size_t index)
{
    if (index > 1)          // only insert less than 2nd string
        return;
    out << strings.at(index);

    if (index + 1 != 2)     // insert separator in all but last
        out << ", and: ";
}
