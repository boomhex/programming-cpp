#include "strings.ih"


Strings::Strings(size_t argc, char **argv)
:
    d_size(argc),
    d_cap(argc),
    d_str(new std::string[d_size])
{
    fill(argv);
}