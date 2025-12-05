#ifndef _INCLUDED_STRING2_
#define _INCLUDED_STRING2_

#include <string>

class String2 : public std::string
{
public:
    using std::string::string;
    String2(std::size_t count, std::string const &str);
};
#endif