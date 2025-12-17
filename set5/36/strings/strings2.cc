#include "strings.ih"


Strings::Strings(size_t argc, char **argv)
:
    d_size(argc),
    d_cap(argc ? argc : 1),         // Force capacity of 1, for enlarging
    d_str(rawStrings(d_cap))
{
    fill(argv);
}
