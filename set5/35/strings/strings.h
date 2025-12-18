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

        size_t size()       const;
        size_t capacity()   const;

        void reserve(size_t num);
        void resize(size_t size);

        std::string &at(size_t index);

        Strings &operator+=(std::string const &str);     // oppluseq.cc
    
    private:
        size_t count(char **environlike);
        void fill(char **environlike);
        void add(std::string const &str);
};

inline size_t Strings::size()   const
{
    return d_strings.size();
}

inline size_t Strings::capacity()   const
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

#endif