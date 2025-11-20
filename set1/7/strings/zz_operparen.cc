#include "strings.ih"


Strings const &Strings::operator()(void (*manip)(ostream &,
                                                    Strings const &, size_t))
{
    d_manip = manip;    // replace manipulator function w/ custom fun
    return *this;
}
