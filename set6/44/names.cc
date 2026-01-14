#include "main.ih"

void writeNames(ostream &out, vector<Student> &vec)
{
    sort(vec.begin(), vec.end(),
         [](Student const &stu1, Student const &stu2)
         {
             return strcasecmp(stu1.lastName().c_str(),
                               stu2.lastName().c_str()) < 0;
         });

    for (Student const &student : vec)
        out << student.name() 
            << ' ' << student.sNumber() 
            << ' ' << student.grade() 
            << '\n';
}

