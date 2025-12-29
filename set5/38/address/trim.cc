#include "address.ih"


void Address::trim(string &str) const
{
    size_t start = str.find_first_not_of(" \t");
    size_t end   = str.find_last_not_of(" \t");
    str = (start == string::npos) ? "" : str.substr(start, end - start + 1);
}
