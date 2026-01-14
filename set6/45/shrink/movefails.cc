#include "shrink.ih"

//static
void Shrink::moveFails(vector<string> &vect)
{
    vector<string> tmp(move(vect));
    tmp.swap(vect);
}
