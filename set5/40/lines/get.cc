#include "lines.ih"

vector<string> const &Lines::get()
{
    return Safe::g_lines.at(this);
}