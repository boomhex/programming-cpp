#include "strings.ih"

Strings::Strings(Strings &&tmp)
:
    d_str(tmp.d_str),
    d_size(tmp.d_size)
{
    tmp.d_str = 0;
    tmp.d_size = 0;
}
