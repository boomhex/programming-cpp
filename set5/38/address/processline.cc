#include "address.ih"


void Address::processLine(string const &line)
{
    auto [postal, address, name] = extractInfo(line);

    d_data[{postal, address}].push_back(name);
}
