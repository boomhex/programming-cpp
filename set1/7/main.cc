#include "strings/strings.h"
#include <iostream>

using namespace std;

void only2(ostream &out, Strings const &strings, size_t index)
{
    if (index > 1)
        return;
    out << strings.at(index);

    if (index + 1 != 2)    // insert separator in all but last
        out << ", and: ";
}


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
