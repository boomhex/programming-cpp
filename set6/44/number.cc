#include "main.ih"

void writeNrs(ostream &out, 
              vector<Student> const &vec)
{
    vector<size_t> idx(vec.size());
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(),
         [&](size_t idx, size_t jdx)
         {
             return vec[idx].sNumber() < vec[jdx].sNumber();
         });

    for (size_t num : idx)
        out << vec[num].sNumber() << ' ' << vec[num].grade() << '\n';
}