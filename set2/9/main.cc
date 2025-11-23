#include "demo/demo.h"
#include "iostream"

using namespace std;

int main()
try
{
    Demo demo{1};
}
catch (...)
{
    cerr << "main\n";
}
