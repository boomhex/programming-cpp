#include "strings.ih"


void Strings::enlarge()
{
    reserve(d_cap * 2);
}
