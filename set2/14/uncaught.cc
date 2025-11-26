#include "main.ih"

namespace fs = std::filesystem;

int main()
{
    TempFile tmp(".", "temp.tmp");

    std::cout << "Before conversion:\n";
    std::cout << "temp file: " << tmp.name() << '\n';
    std::cout << "exists? " << std::boolalpha << fs::exists(tmp.name()) << '\n';

    throwFun();   // throws, not caught

    std::cout << "This line is never reached\n";
}
