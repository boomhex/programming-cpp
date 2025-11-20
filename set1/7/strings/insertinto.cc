#include "strings.ih"


ostream &Strings::insertInto(ostream &out)  const
{
    for (size_t index = 0; index != d_size; ++index)
        d_manip(out, *this, index);     // insert each index into the stream

    resetInsertion();
    return out;
}
