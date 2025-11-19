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
inline Msg operator|(Msg lhs, Msg rhs)
{
	return static_cast<Msg>(
		static_cast<int>(lhs) |
		static_cast<int>(rhs)
	);
}

// bit-wise AND
inline Msg operator&(Msg lhs, Msg rhs)
{
	return static_cast<Msg>(
		static_cast<int>(lhs) &
		static_cast<int>(rhs)
	);
}

// bit-wise XOR
inline Msg operator^(Msg lhs, Msg rhs)
{
	return static_cast<Msg>(
		static_cast<int>(lhs) ^
		static_cast<int>(rhs)
	);
}

//bit-wise NOT
inline Msg operator~(Msg value)
{
	return static_cast<Msg>(
		~static_cast<int>(value) &
		static_cast<int>(Msg::ALL)
	);
}

//bit-wise OR assign
inline Msg &operator|=(Msg &lhs, Msg rhs)
{
	lhs = lhs | rhs;
	return lhs;
}

//bit-wise AND assign 
inline Msg &operator&=(Msg &lhs, Msg rhs)
{
	lhs = lhs & rhs;
	return lhs;
}

//bit-wise XOR assign
inline Msg &operator^=(Msg &lhs, Msg rhs)
{
	lhs = lhs ^ rhs;
	return lhs;
}

inline bool operator!(Msg value)
{
	return value == Msg::NONE;
}

#endif
