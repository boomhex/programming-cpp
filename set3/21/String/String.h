#ifndef INCLUDED_STRING_
#define INCLUDED_STRING_

#include <string>

class String : public std::string
{
public:
    using std::string::string;
    
    using std::string::insert;     // Make base-class insert overloads visible

    String &insert(std::string const &text);

};

inline String &String::insert(std::string const &text)
{
    std::string::insert(0, text);
    return *this;
}

inline bool operator==(String const &leftString,
                       String const &rightString)
{
    return static_cast<std::string const &>(leftString) ==
           static_cast<std::string const &>(rightString);
}

inline bool operator!=(String const &leftString,
                       String const &rightString)
{
    return !(leftString == rightString);
}

inline bool operator<(String const &leftString,
                      String const &rightString)
{
    return static_cast<std::string const &>(leftString) <
           static_cast<std::string const &>(rightString);
}

inline bool operator<=(String const &leftString,
                       String const &rightString)
{
    return !(rightString < leftString);
}

inline bool operator>(String const &leftString,
                      String const &rightString)
{
    return rightString < leftString;
}

inline bool operator>=(String const &leftString,
                       String const &rightString)
{
    return !(leftString < rightString);
}

#endif