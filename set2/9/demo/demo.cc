#include "demo.ih"

Demo::Demo(int value)
//try                                       // Original try location
{
    try                                     // changed try location
    {
        throw value;
    }
    catch (int val)                         // changed catch location
    {
        cerr << "value: " << val << "\n";   
    }
}
// catch (int val)                          // Original catch location
// {
//     //cerr << "value: " << val << "\n";    
// }