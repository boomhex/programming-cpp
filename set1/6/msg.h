#ifndef MSG_H
#define MSG_H

enum class Msg
{
    NONE    = 0,
    DEBUG   = 1 << 0,
    INFO    = 1 << 1,
    NOTICE  = 1 << 2,
    WARNING = 1 << 3,
    ERR     = 1 << 4,
    CRIT    = 1 << 5,
    ALERT   = 1 << 6,
    EMERG   = 1 << 7,
    ALL     = (1 << 8) - 1
};

// bit-wise OR
Msg operator|(Msg lhs, Msg rhs);

// bit-wise AND
Msg operator&(Msg lhs, Msg rhs);

// bit-wise XOR
Msg operator^(Msg lhs, Msg rhs);

// bit-wise NOT
Msg operator~(Msg value);

// bit-wise OR assign
Msg &operator|=(Msg &lhs, Msg rhs);

// bit-wise AND assign
Msg &operator&=(Msg &lhs, Msg rhs);

// bit-wise XOR assign
Msg &operator^=(Msg &lhs, Msg rhs);

// logical NOT
bool operator!(Msg value);

#endif 
