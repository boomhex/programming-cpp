#include "address.ih"


void Address::processLine(string const &line)
{
    auto [postal, address, name] = extractInfo(line);

    // put in unordered map
}