#include "main.ih"


void rethrow()
{
    try
    {
        throwObj();
    }
    catch (Obj const &obj)
    {
        std::cout << "Caught throw by ref in rethrow\n";
        std::cout << "Caught ";
        whichCopy(obj);
        throw;
    }
}
