#include "obj.ih"


std::ostream &operator<<(std::ostream &out, Obj const &obj)
{
    out << obj.copyNo();
    return out;
}
