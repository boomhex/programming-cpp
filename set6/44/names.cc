#include "main.ih"

void writeNames(ostream &out, vector<Student> const &vec)
{
    for (Student const &student : vec)
        out << student.name() 
            << ' ' << student.sNumber() 
            << ' ' << student.grade() 
            << '\n';
}

