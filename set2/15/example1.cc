#include <iostream>

class obj
{
    public:
        obj();
        ~obj();
};
obj::obj()  
{ 
    std::cout << "Inner constructor\n"; 
}
obj::~obj() 
{
    std::cout << "Inner destructor\n"; 
}

void func()
{
    obj object;   // local object
    std::cout << "func: something went wrong, calling exit...\n";
    std::exit(1);   // terminate: no stack unwinding, no automatic call of ~obj, violating RAII
}

int main()
{
    func();
    std::cout << "main: end (never reached)\n"; // this functionality of the program is never reached
}
