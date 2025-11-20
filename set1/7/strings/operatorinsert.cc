#include "strings.ih"


ostream &operator<<(ostream &out, Strings const &strings)
{
    strings.insertInto(out);    // insert it into stream
    return out;
}
