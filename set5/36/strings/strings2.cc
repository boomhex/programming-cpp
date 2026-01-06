#include "strings.ih"


Strings::Strings(size_t argc, char **argv)
:
    d_size(argc),
    d_cap(argc),
    d_sp(shared_ptr<string []>{ new string[d_cap] })
{
    fill(argv);
}
