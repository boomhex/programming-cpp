#include "main.ih"

size_t multiples(vector<size_t> const &vs)
{
    vector<size_t> uniq;
    uniq.reserve(vs.size());        // make unique vector of size vs

    // make a unique copy, only containing unique values
    unique_copy(vs.begin(), vs.end(), back_inserter(uniq)); 

    return vs.size() - uniq.size();     // this give the nr of multiples
}
