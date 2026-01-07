#include "shrink.ih"

void Shrink::time(FunPtr fun)
{
    Timer timer{ d_out };
    (*fun)(d_vect);
}
