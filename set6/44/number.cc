#include "main.ih"

void writeNrs(ostream &out, 
              vector<Student> const &vec, 
              vector<size_t> const &idx)
{
    for (size_t num : idx)
        out << vec[num].sNumber() << ' ' << vec[num].grade() << '\n';
}