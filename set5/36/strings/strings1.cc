#include "strings.ih"


Strings::Strings()
:
    d_size(0),
    d_cap(1),
    d_str(rawStrings(d_cap))
{}
