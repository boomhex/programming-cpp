#include "strings.ih"

void Strings::copyIdx(size_t index)
{
    std::shared_ptr<std::string> &strp = d_vsp[index];

    if (not strp)                       // ensure strp is not a 0-ptr for deref
        strp = std::make_shared<std::string>();

    d_vsp[index] = std::make_shared<std::string>(*strp);
}
