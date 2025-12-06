#ifndef _INCLUDED_BASE_
#define _INCLUDED_BASE_

#include <iosfwd>

class Base
{
    public:
        void hello(std::ostream &out);
    
    protected:
        virtual void vHello(std::ostream &out);
};

#endif