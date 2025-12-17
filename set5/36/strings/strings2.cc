#include "strings.ih"


Strings::Strings(size_t argc, char **argv)
:
    d_vsp(argc)     // argc nullptrs
{
    fill(argv);
}
