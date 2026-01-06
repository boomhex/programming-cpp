#include "main.ih"

vector<Student> read(char const *fn)
{
    ifstream in(fn);
    vector<Student> vec;
    Student student;
    while (in >> student)
        vec.push_back(student);
    return vec;
}