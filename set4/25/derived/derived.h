#ifndef _INCLUDED_DERIVED_
#define _INCLUDED_DERIVED_

#include "../base/base.h"
#include <string>

class Derived: public Base
{
    std::string d_str;

    public:
        Derived(std::string const &str);

    private:
        void vHello(std::ostream &out) override;
};


#endif