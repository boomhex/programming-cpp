#include "address.ih"


tuple<string, string, string> Address::extractInfo(string const &line)  const
{
    size_t first = line.find(';');        // find separator symbol
    size_t second = line.find(';', first + 1);

                                        // input is of invalid format
    if (first == string::npos or second == string::npos)    
        throw std::runtime_error("Invalid input");

    string item1 = line.substr(0, first);
    string item2 = line.substr(first + 1, second - first - 1);
    string item3 = line.substr(second + 1);

    trim(item1);                        // preprocess items by removing
    trim(item2);                        // leading and trailing ws
    trim(item3);

    return {item1, item2, item3};
}
