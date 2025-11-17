#include "strings.ih"

Strings &Strings::operator+=(std::string const &next)
{
    cow();
    
    std::string *tmp = duplicateAndEnlarge();   // make room for the next string
    tmp[d_size] = next;                         // store next

    delete[] d_str;                             // free old array
    d_str = tmp;
    ++d_size;

    return *this;
}
