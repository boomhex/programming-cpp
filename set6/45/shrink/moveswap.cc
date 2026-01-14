#include "shrink.ih"

void Shrink::moveSwap(vector<string> &vect)
{
    vector<string> temp(
        make_move_iterator(vect.begin()),
        make_move_iterator(vect.end())
    );
    temp.swap(vect);
}