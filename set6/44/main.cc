#include "main.ih"

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;

    vector<Student> students = read(argv[1]);

    sort(students.begin(), students.end(),
         [](Student const &a, Student const &b)
         {
             return lowerStr(a.lastName()) < lowerStr(b.lastName());
         });

    vector<size_t> idx(students.size());
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(),
         [&](size_t i, size_t j)
         {
             return students[i].sNumber() < students[j].sNumber();
         });

    writeNames(cout, students);
    cout << '\n';
    writeNrs(cout, students, idx);
}