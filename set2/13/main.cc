#include "maxfour/maxfour.h"
#include <iostream>
int main() 
try
{
    MaxFour *arr = new MaxFour[10];   // throws when constructing 5th element

    delete[] arr;                     // Never reached, but safe practice
}
catch (std::length_error const &lerror)
{
    std::cerr << lerror.what();
}