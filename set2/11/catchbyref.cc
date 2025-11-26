#include "main.ih"


void catchByRef()
{
    std::cout << "Showcase catch by ref:\n";
    try
    {
        throwObj();
    }
    catch(Obj &obj)
    {
        std::cout << "Caught by ref\n";
        std::cout << "Caught ";
        whichCopy(obj);
    }
}

