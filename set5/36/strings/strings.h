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
        static size_t count(char **environlike);
        void fill(char **environlike);
        void add(std::string const &str);
        void enlarge();

        std::unique_ptr<std::string[]> Strings::rawStrings(std::size_t n);
};


inline std::string &Strings::at(size_t index)
{
    return d_str[index];
}

inline size_t Strings::size()
{
    return d_size;
}

inline size_t Strings::capacity()
{
    return d_cap;
}



inline std::string &Strings::operator[](size_t index)
{
    return at(index);
}


#endif