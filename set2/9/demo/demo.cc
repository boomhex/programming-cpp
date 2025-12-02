#include "demo.ih"

Demo::Demo(int value)
try
:
    Demo::Demo()            // added                   
{
    throw value;
}
catch (int val)                     
{
    cerr << "value: " << val << "\n";    
}