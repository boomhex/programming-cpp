#include "main.ih"

void writeNrs(ostream &out, vector<Student> const &v, vector<size_t> const &idx)
{
    for (size_t i : idx)
        out << v[i].sNumber() << ' ' << v[i].grade() << '\n';
}