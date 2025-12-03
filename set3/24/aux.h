#ifndef AUX_H
#define AUX_H

#include <fstream>

class Aux
{
    protected:
    std::ofstream d_out_stream;

public:
    Aux(std::string const &name);
};

#endif