#include "shrink.ih"

void Shrink::reset()
{
    d_vect = vector<string>(0);
    for (size_t itemNo = 0; itemNo != d_size; ++itemNo)
        d_vect.push_back(d_str);
}
