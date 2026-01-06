#include "strings.ih"

void Strings::cow()
{
    if (d_sp.unique())
        return;     // already unique: do nothing

    uniqueCopy(d_cap);
}
