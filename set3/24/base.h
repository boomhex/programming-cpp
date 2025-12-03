#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base
{
    std::ostream &d_out;

    public:
        Base(std::ostream &out);    // assigns out to d_out

        // other members
};

#endif