#include "strings.ih"


Strings::Strings()
:
    d_size(0),
    d_cap(1),
    d_strings(make_unique<string []>(d_cap))
{}
