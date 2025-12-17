#ifndef _INCLUDED_STRINGS_
#define _INCLUDED_STRINGS_


#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

class Strings
{
    std::vector<std::shared_ptr<std::string>> d_vsp;

    public:
        Strings();                      // 1.cc
        Strings(size_t argc,            // 2.cc
                char **argv);  
        Strings(char **environlike);    // 3.cc

        size_t size()       const;
        size_t capacity()   const;

        void reserve(size_t num);
        void resize(size_t num);

        std::string &at(size_t index);                  // 1.cc
        std::string const &at(size_t index)     const;  // 2.cc

        Strings &operator+=(std::string const &str);     // oppluseq.cc

        std::string &operator[](size_t index);
        std::string const &operator[](size_t index)     const;

    private:
        static size_t count(char **environlike);
        void fill(char **environlike);

        void add(std::string const &str);
        void copyIdx(size_t index);     // used for COW

        std::string &safeat(size_t index)   const;
};

inline size_t Strings::size()   const
{
    return d_vsp.size();
}

inline void Strings::reserve(size_t num)
{
    d_vsp.reserve(num);
}

inline size_t Strings::capacity()   const
{
    return d_vsp.capacity();
}

inline std::string &Strings::operator[](size_t index)
{
    return at(index);
}

inline std::string const &Strings::operator[](size_t index) const
{
    return at(index);
}

inline Strings &Strings::operator+=(std::string const &str)
{
    add(str);
    return *this;
}


#endif