#include "strings/strings.h"
#include <iostream>


int main(int argc, char **argv, char **environ)
{;
    // size_t i = argc;
    Strings strings{environ};
    std::cout << strings.size() << '\n';
}
