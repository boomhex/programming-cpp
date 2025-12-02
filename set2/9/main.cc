#include "demo/demo.h"
#include "iostream"

using namespace std;

int main()
try
{
    Demo demo{1};
} // destructor is called here
catch (...)
{
    cerr << "main\n";
}
