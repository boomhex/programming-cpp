#include "strings.ih"

ostream &operator<<(ostream &out, Strings strings)
{
    strings.insertInto(out);
}