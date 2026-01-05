#include "address.ih"


istream &operator>>(istream &in, Address &add)
{
    return add.extractFrom(in);
}
