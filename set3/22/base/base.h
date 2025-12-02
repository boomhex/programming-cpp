#ifndef _INCLUDED_BASE_
#define _INCLUDED_BASE_

#include <iosfwd>

class Base
{
    public:
        void hello();   // insert text into cout
        virtual ~Base() = default;   // needed for safe dynamic_cast
};

#endif