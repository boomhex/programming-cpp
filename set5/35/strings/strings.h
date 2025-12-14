#ifndef _INCLUDED_STRINGS_
#define _INCLUDED_STRINGS_

#include <vector>
#include <string>
#include <iosfwd>
#include <exception>


class Strings
{
    std::vector<std::string> d_strings;

    public:
        Strings();                      // 1.cc
        Strings(size_t argc,            // 2.cc
            char **argv);  
        Strings(char **environlike);    // 3.cc

        size_t size();
        size_t capacity();

        void reserve(size_t num);
        void resize(size_t size);

        std::string &at(size_t index);

        Strings &operator+=(std::string const &str);     // oppluseq.cc
        std::string &operator[](size_t index);
    
    private:
        size_t count(char **environlike);
        void fill(char **environlike);
};

inline std::string &Strings::at(size_t index)
{
    return d_strings.at(index);
}

inline size_t Strings::size()
{
    return d_strings.size();
}

inline size_t Strings::capacity()
{
    return d_strings.capacity();
}

inline void Strings::resize(size_t size)
{
    d_strings.resize(size);
}

inline void Strings::reserve(size_t num)
{
    d_strings.reserve(num);
}

inline std::string &Strings::operator[](size_t index)
{
    return d_strings.at(index);
}


#endif