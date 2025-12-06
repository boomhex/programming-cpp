#ifndef _INCLUDED_MESSAGE_
#define _INCLUDED_MESSAGE_

#include "base.h"
#include <iostream>

class Message
{
    Base &d_base;

    public:
        Message(Base &base);
        void show();
};

inline Message::Message(Base &base)
:
    d_base(base)
{}

inline void Message::show()
{
    d_base.hello(std::cout);
}

#endif