#ifndef _INCLUDED_OBJ_
#define _INCLUDED_OBJ_

#include <iosfwd>

class Obj
{
    size_t d_ident;
    size_t d_copy;
    public:
        Obj(size_t ident);      // obj.cc
        Obj(Obj const &other);  // objcopy.cc
        size_t copyNo()     const;
};

inline size_t Obj::copyNo()     const
{
    return d_copy;
}

#endif