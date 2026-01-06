#ifndef _INCLUDED_STRINGS_
#define _INCLUDED_STRINGS_

#include <memory>
#include <string>
#include <iosfwd>
#include <exception>


class Strings
{
    size_t d_size;
    size_t d_cap;
    std::unique_ptr<std::string[]> d_strings;

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
        void enlarge();
};

inline size_t Strings::size()   const
{
    return d_size;
}

inline size_t Strings::capacity()   const
{
    return d_cap;
}

#endif