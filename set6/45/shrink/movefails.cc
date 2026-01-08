#include "shrink.ih"

//static
void Shrink::moveFails(vector<string> &vect)
{
    move(vect).swap(vect);
}
