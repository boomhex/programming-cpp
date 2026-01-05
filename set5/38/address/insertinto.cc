#include "address.ih"

ostream &Address::insertInto(ostream &out)
{
    for (auto const &value: d_data) // d_data is the map 
    {
        out << value.first.first << "; " <<     // postal code
        value.first.second;                    // address
        for (string const &str: value.second) // the people (maybe
            out << "; " << str;               // define a function?)
        out << '\n';
    }
    return out;
}
