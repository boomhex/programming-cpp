#include "main.ih"


Obj::Obj(Obj const &other)
:
    d_ident(other.d_ident),
    d_copy(other.d_copy + 1)
{
    std::cout << "copy no. " << d_copy << " made for obj w/ ident "
    << d_ident << '\n';
}
