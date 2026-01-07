#include "shrink.ih"

//static
void Shrink::copySwap(vector<string> &vect)
{
    vector<string>(vect).swap(vect);
}
