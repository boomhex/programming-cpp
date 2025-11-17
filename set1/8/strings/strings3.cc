#include "strings.ih"

Strings::Strings(char **environLike)
:
    d_size(0),
    d_str(nullptr),
    d_shared(new size_t(1))
{
    while (*environLike)
        *this += *environLike++;
}
