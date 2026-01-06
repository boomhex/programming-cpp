#include "strings.ih"

void Strings::enlarge()
{
    reserve(2 * d_cap);
}