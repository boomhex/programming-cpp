#ifndef DERIVED_H
#define DERIVED_H

#include "base.h"
#include "aux.h"
#include <iostream>
#include <fstream>

class Derived : public Aux, public Base
{
public:
    Derived(std::string const &name);
};
#endif