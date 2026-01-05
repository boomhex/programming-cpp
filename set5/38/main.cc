#include "address/address.h"
#include <iostream>

int main()
{
    Address address;
    
    std::cout << "Input:\n";
    // put in test file
    std::cin >> address;

    std::cout << "Data size: " << address.size() << '\n';

    // output addresses
    std::cout << address;

    std::cout << "After removal of 88---- postal code:\n";

    // remove dummy "88" prefix
    std::cout << "Data size: " << address.remove("88") << '\n';

    // output again
    std::cout << address;
}
// Input:
// Data size: 3
// 8831ZP; Haarlemmerkade 3; John Doe
// 0824DL; DisneyStreet 1; Mickey Mouse
// 8891DD; DuckStreet 13; Donald Duck; Katherine Duck
// After removal of 88---- postal code:
// Data size: 1
// 0824DL; DisneyStreet 1; Mickey Mouse
