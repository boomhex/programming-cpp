#include "lines.ih"

vector<string> const &Lines::get(size_t idx)
{
    // return empty vector if idx is out of range
    if (idx >= Safe::g_order.size()) 
        return Safe::empty;

    Lines const *ptr = Safe::g_order[idx];
    // return empty vector if the object was destructed
    if (ptr == nullptr)
        return Safe::empty;

    return Safe::g_lines.at(ptr);
}