#include "shrink.ih"

// static
void Shrink::handmadeMove(vector<string> &vect)
{
    vector<string> temp;
    temp.reserve(vect.size());

    for (size_t index = 0; index != vect.size(); ++index)
        temp.push_back(move(vect[index]));

    temp.swap(vect);
}