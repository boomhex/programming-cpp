#include <iostream>

class Base 
{
    std::string firstname;

    public:
        Base();
        ~Base();
        void const print(const std::string &msg);
        std::string const getFirstName () ;
        
};

class Derived : public Base 
{
  std::string surname;

public:
    Derived()
    {
        print("the first name is" + Base::getFirstName());  
    }
    ~Derived() 
    {
        print("the surname was: " + surname);  
    }
};

