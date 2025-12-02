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
    cout << "func: something went wrong, calling exit...\n";
    exit(1);   // terminate: no stack unwinding, no automatic call of ~Obj, violating RAII
}

int main()
{
    func();
    cout << "main: end (never reached)\n"; // this functionality of the program is never reached
}
