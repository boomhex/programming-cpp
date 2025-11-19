#include "strings/strings.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    Strings strings(argc, argv);

    cout << "std:\n" << 
                strings << "\n"
            "separated by spaces:\n" << 
                strings(" ") << "\n"
            "only 2 strings, separated by text:\n" << 
                strings(only2) << "\n"
            "std:\n" << 
                strings << '\n';
}
