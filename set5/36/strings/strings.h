#ifndef _INCLUDED_STRINGS_
#define _INCLUDED_STRINGS_

#include <iosfwd>
#include <memory>
#include <string>

class Strings
{
    size_t d_size;
    size_t d_cap;
    std::unique_ptr<std::string[]> d_str;

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
    return d_str.at(index);
}

inline size_t Strings::size()
{
    return d_str.size();
}

inline size_t Strings::capacity()
{
    return d_str.capacity();
}

inline void Strings::resize(size_t size)
{
    d_str.resize(size);
}

inline void Strings::reserve(size_t num)
{
    d_str.reserve(num);
}

inline std::string &Strings::operator[](size_t index)
{
    return d_str.at(index);
}


#endif