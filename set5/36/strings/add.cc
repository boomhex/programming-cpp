#include "strings.ih"


void Strings::add(std::string const &str)
{
    d_vsp.push_back(std::make_shared<std::string>(str));
}
