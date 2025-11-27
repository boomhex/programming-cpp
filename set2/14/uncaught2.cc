#include "main.ih"

namespace fs = std::filesystem;

int main()
{
    TempFile tmp;

    std::cout << "Before conversion:\n";
    std::cout << "temp file: " << tmp.name() << '\n';
    std::cout << "exists? " << std::boolalpha << fs::exists(tmp.name()) << '\n';

    fstream fs = tmp;

    std::cout << "After conversion:\n";
    std::cout << "temp file: " << tmp.name() << '\n';
    std::cout << "exists? " << std::boolalpha << fs::exists(tmp.name()) << '\n';

    fs << "Write to deleted file.\n";
    throwFun();   // throws, not caught

    std::cout << "This line is never reached\n";
}
