#include "bistream/bistream.h"
#include <fstream>

int main()
{
    std::ofstream one("one");
    std::ofstream two("two");

    BiStream ms(one, two);

    ms << "Hello world" << std::endl;
}
