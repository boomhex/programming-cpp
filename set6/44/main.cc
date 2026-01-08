#include "main.ih"

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;

    vector<Student> students = read(argv[1]);

    sort(students.begin(), students.end(),
         [](Student const &stu1, Student const &stu2)
         {
             return strcasecmp(stu1.lastName().c_str(),
                               stu2.lastName().c_str()) < 0;
         });

    vector<size_t> idx(students.size());
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(),
         [&](size_t idx, size_t jdx)
         {
             return students[idx].sNumber() < students[jdx].sNumber();
         });

    writeNames(cout, students);
    writeNrs(cout, students, idx);
}