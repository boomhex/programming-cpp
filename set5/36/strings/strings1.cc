#include "strings.ih"


Strings::Strings()
:
    d_size(0),
    d_cap(1),
    d_sp(shared_ptr<string []>{ new string[d_cap] })
{}
