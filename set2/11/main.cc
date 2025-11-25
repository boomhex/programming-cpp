#include "main.ih"


int main()
{
    catchByRef();
    std::cout << '\n';
    catchByVal();
    std::cout << '\n';
    catchRethrow();
}
