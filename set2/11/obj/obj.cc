#include "obj.ih"


Obj::Obj(size_t ident)
:
    d_ident(ident),
    d_copy(0)
{
    std::cout << "Obj with ident " << d_ident << " constructed\n";
}
