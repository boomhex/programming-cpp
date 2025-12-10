#include "multi.ih"

Multi::Multi()
//:
    //Basic(3)              // always Calls Basic(int number)
    //Basic()                 // calls Basic()
{
    cout << "multi()\n";
    cout << static_cast<Basic *>(this) << '\n';
    // cout << static_cast<Basic *>(static_cast<Deriv1 *>(this)) << '\n';
    // cout << static_cast<Basic *>(static_cast<Deriv2 *>(this)) << '\n';
}