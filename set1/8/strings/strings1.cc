#include "strings.ih"

Strings::Strings()
:
    d_size(0),
    d_str(nullptr),
    d_shared(new size_t(1))
{}