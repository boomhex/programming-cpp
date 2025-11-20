#include "strings.ih"


void Strings::stdInsertion(ostream &out, Strings const &strings, size_t index)
{
    out << strings.at(index) << strings.d_sep;
}
