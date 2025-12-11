#ifndef _INCLUDED_BASE_
#define _INCLUDED_BASE_

#include <iosfwd>
#include <iostream>

class Base
{
    public:
        void hello(std::ostream &out)   const;
        virtual ~Base();
    private:
        virtual void vHello(std::ostream &out)  const;
};

inline Base::~Base()
{
    std::cout << "dtor from Base\n";
}

inline void Base::hello(std::ostream &out)  const
{
    vHello(out);
}

inline void Base::vHello(std::ostream &out) const
{
    out << "hello from Base\n";
}



#endif