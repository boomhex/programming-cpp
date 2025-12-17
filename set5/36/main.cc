#include "strings/strings.h"
#include <iostream>


int main(int argc, char **argv, char **environ)
{
    Strings strings{environ};
 
    Strings strings2 { strings };
    Strings strings3 = std::move(strings2);
    std::cout << strings3.size() << '\n';
    std::cout << strings3.size() << '\n';
    std::cout << strings2.size() << '\n';
    std::cout << strings.size() << '\n';
}
