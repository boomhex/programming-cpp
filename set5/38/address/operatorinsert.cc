#include "address.ih"


ostream &operator<<(ostream &out, Address &add)
{
    return add.insertInto(out);
}
