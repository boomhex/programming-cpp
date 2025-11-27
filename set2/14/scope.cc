#include "main.ih"

int main()
{
    fs::path nameCopy = "";

    if (true)
    {
        TempFile tmp;
        nameCopy = tmp.name();

        std::cout << "Inside scope block:\n";
        std::cout << "temp file name: " << tmp.name() << '\n';
        std::cout << "exists? " << std::boolalpha << fs::exists(nameCopy) << "\n\n";
    } // tmp goes out of scope here, destructor should remove file

    std::cout << "After scope:\n";
    std::cout << "temp file name: " << nameCopy << '\n';
    std::cout << "exists? " << std::boolalpha << fs::exists(nameCopy) << '\n';
}
