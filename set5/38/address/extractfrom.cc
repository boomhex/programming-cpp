#include "address.ih"


void Address::extractFrom(istream &in)
{
    string line;
    while (getline(in, line))
        processLine(line);              // puts line into map
}
