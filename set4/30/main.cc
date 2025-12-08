#include "bistream/bistream.h"
#include <fstream>

int main()
{
    std::ofstream one("one");
    std::ofstream two("two");

    BiStream ms(one, two);

    ms << "Hello world" << std::endl;
    // Flushing files


    // std::ofstream outfile ("test.txt");

    // for (int n=0; n<100; ++n)
    // {
    //     ms << n;
    //     ms.flush();
    // }
    // ms.close();

}
