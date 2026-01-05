#include "address.ih"


istream &Address::extractFrom(istream &in)
{
    string line;
    while (getline(in, line))
        processLine(line);              // puts line into map
    return in;
}
