#ifndef _INCLUDED_DERIVED_
#define _INCLUDED_DERIVED_

#include "base.h"
#include <string>
#include <iostream>

class Derived: public Base
{
    std::string d_str;

    public:
        Derived(std::string const &str);

    private:
        void vHello(std::ostream &out) const override;
};

inline Derived::Derived(std::string const &str)
:
    d_str(std::string{ str })
{}

inline void Derived::vHello(std::ostream &out)  const
{
    out << d_str;
}


#endif