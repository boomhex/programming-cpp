#include "address.ih"


bool Address::match(string const &prefix, string const &postalCode)
{
    if (prefix.length() > postalCode.length())  // prefix is not part of
        return false;                           // postal if its bigger

    for (size_t index = 0; index != prefix.length(); ++index)
    {
        if (postalCode[index] != prefix[index])
            return false;
    }
    return true;
}
