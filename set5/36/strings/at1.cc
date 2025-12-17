#include "strings.ih"


std::string &Strings::at(size_t index)
{
    copyIdx(index);                     // COW
    return *d_vsp[index];
}
