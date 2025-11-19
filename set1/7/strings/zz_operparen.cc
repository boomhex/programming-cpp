#include "strings.ih"


Strings const Strings::operator()(void (*manip)(ostream &,
                                                    Strings const &, size_t))
{
    Strings copy{ *this };
    copy.d_manip = manip;    // replace manipulator function w/ custom
    return copy;
}
