#include "main.ih"


void catchRethrow()
{
    std::cout << "Showcase rethrow\n";

    try
    {
        rethrow();
    }
    catch (Obj const &obj)
    {
        std::cout << "Caught rethrow by ref\n";
        std::cout << "Caught ";
        whichCopy(obj);
    }
}