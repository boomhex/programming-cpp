#include "strings.ih"


Strings::Strings(size_t argc, char **argv)
:
    d_strings(argc)
{
    fill(argv);
}
