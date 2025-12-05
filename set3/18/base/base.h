#ifndef _INCLUDED_BASE_
#define _INCLUDED_BASE_
class Base
{
    public:
        Base();                     // default
        Base(Base const &other);    // copy
        Base(Base &&other);         // move
};

#endif