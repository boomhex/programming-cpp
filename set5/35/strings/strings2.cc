#include "strings.ih"


Strings::Strings(size_t argc, char **argv)
:
    d_size(argc),
    d_cap(argc),
    d_strings(make_unique<string []>(argc))
{
    fill(argv);
}
