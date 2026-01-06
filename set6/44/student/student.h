#ifndef INCLUDED_STUDENT_
#define INCLUDED_STUDENT_

#include <string>

class Student
{
    std::string d_name;
    std::string d_lastName;
    size_t d_sNumber;
    float d_grade;

    public:
        std::string const &name() const;
        std::string const &lastName() const;
        std::size_t sNumber() const;
        double grade() const;

        friend std::istream &operator>>(std::istream &in, Student &s);
};

inline std::string const &Student::name() const 
{ 
    return d_name; 
}

inline std::string const &Student::lastName() const 
{ 
    return d_lastName; 
}

inline std::size_t Student::sNumber() const 
{ 
    return d_sNumber; 
}

inline double Student::grade() const
{
    return d_grade;
}
#endif