#include "main.ih"


void catchByVal()
{
    std::cout << "Showcase catch by val:\n";
    try
    {
        throwObj();
    }
    catch(Obj obj)
    {
        std::cout << "Caught by val\n";
        std::cout << "Caught ";
        whichCopy(obj);
    }
}
