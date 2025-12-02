#include <iostream>

using namespace std;

class Obj
{
    public:
        Obj();
        ~Obj();
};

Obj::Obj()
{
    cout << "Obj constructor\n";
}

Obj::~Obj()
{
    cout << "Obj destructor\n";
}

void func()
{
    Obj object;   // local Object
    cout << "func: something went wrong, throwing exception...\n";
    throw string{"func failed"};   // stack unwinding, calling the Objects destructor
}

int main()
{
    try
    {
        func();
    }
    catch (string str )
    {
        cout << "main: caught exception: " << str << '\n';
    }
    
    cout << "main: end\n";  // the program still executes
}
