#include "main.ih"


namespace fs = std::filesystem;

int main()
{
    fs::path nameCopy = "";

    try {
        TempFile tmp(".", "temp.tmp");
        nameCopy = tmp.name();

        std::cout << "Before throwFun() throws:\n";
        std::cout << "temp file: " << nameCopy << '\n';
        std::cout << "exists? " << std::boolalpha << fs::exists(nameCopy) << '\n';

        throwFun();     // throws

        std::cout << "This line is never reached\n";
    }
    catch (std::string const &str) {
        std::cout << "Caught exception: " << str << "\n\n";
    }

    std::cout << "After catch:\n";
    std::cout << "temp file: " << nameCopy << '\n';
    std::cout << "exists? " << std::boolalpha << fs::exists(nameCopy) << '\n';
}
