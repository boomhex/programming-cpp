#include "shrink.ih"

void Shrink::process(string const &msg, FunPtr fun)
{
    reset();
    d_out << msg << ' ';
    time(fun);
    report();
}
