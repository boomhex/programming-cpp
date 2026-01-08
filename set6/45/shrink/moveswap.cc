#include "shrink.ih"
#include <iterator>

void Shrink::moveSwap(vector<string> &vect)
{
    vector<string> temp;
    temp.reserve(vect.size());

    temp.insert(
        temp.end(),
        make_move_iterator(vect.begin()),
        make_move_iterator(vect.end())
    );
    temp.swap(vect);
}