#include "strings.ih"


std::unique_ptr<std::string[]> Strings::rawStrings(std::size_t n)
{
    return std::make_unique<std::string[]>(n);
}

