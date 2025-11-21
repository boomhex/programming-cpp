#include "msg.h"

// bit-wise OR 
Msg operator|(Msg lhs, Msg rhs)
{
    return static_cast<Msg>(
        static_cast<int>(lhs) |
        static_cast<int>(rhs)
    );
}

// bit-wise AND
Msg operator&(Msg lhs, Msg rhs)
{
    return static_cast<Msg>(
        static_cast<int>(lhs) &
        static_cast<int>(rhs)
    );
}

// bit-wise XOR
Msg operator^(Msg lhs, Msg rhs)
{
    return static_cast<Msg>(
        static_cast<int>(lhs) ^
        static_cast<int>(rhs)
    );
}

// bit-wise NOT
Msg operator~(Msg value)
{
    return static_cast<Msg>(
        ~static_cast<int>(value) &
        static_cast<int>(Msg::ALL)
    );
}

// bit-wise OR assign
Msg &operator|=(Msg &lhs, Msg rhs)
{
    lhs = lhs | rhs;
    return lhs;
}

// bit-wise AND assign 
Msg &operator&=(Msg &lhs, Msg rhs)
{
    lhs = lhs & rhs;
    return lhs;
}

// bit-wise XOR assign
Msg &operator^=(Msg &lhs, Msg rhs)
{
    lhs = lhs ^ rhs;
    return lhs;
}

// logical NOT
bool operator!(Msg value)
{
    return value == Msg::NONE;
}
