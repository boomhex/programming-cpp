#include <iostream>

class obj
{
    public:
        obj();
        ~obj();
};

obj::obj()
{
    std::cout << "obj constructor\n";
}

obj::~obj()
{
    std::cout << "obj destructor\n";
}

void func()
{
    obj object;   // local object
    std::cout << "func: something went wrong, throwing exception...\n";
    throw std::string{"func failed"};   // stack unwinding, calling the objects destructor
}

int main()
{
    try
    {
        func();
    }
    catch (std::string str )
    {
        std::cout << "main: caught exception: " << str << '\n';
    }
    
    std::cout << "main: end\n";  // the program still executes
}
