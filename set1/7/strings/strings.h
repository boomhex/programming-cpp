#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <string>

class Strings
{
    size_t d_size = 0;
    std::string *d_str = 0;

    void (*d_manip)(std::ostream &, Strings const &, size_t) = &Strings::stdSeparator;
    std::string d_sep = "\n";

    public:
        friend std::ostream &operator<<(std::ostream &out, Strings const &strings);

        Strings() = default;
        Strings(int argc, char **argv);    // 2.cc
        Strings(char **environLike);       // 3.cc

        Strings(Strings const &other);      // see part 1: allocation
        Strings(Strings &&tmp);             // see part 1: allocation

        //~Strings();

        Strings &operator=(Strings const &rhs); // see part 1: allocation
        Strings &operator=(Strings &&rhs);      // see part 1: allocation

        void swap(Strings &other);              

        size_t size() const;

        std::string const &at(size_t idx) const;
        std::string &at(size_t idx);

        void add(std::string const &next);          // add another element
        Strings const operator()(                   // operparen.cc
            void (*manip)(std::ostream &, Strings const &, size_t)
        );
        Strings const operator()(char const *sep);    // operparen1.cc

    private:
        std::string *duplicateAndEnlarge();
        std::ostream &insertInto(std::ostream &out) const;

        static void stdSeparator(std::ostream &out, Strings const &strings, size_t index);
};

void only2(std::ostream &out, Strings const &strings, size_t index);

inline size_t Strings::size() const         // potentially dangerous practice:
{                                           // inline accessors
    return d_size;
}

inline std::string const &Strings::at(size_t idx) const
{
    return d_str[idx];
}

inline std::string &Strings::at(size_t idx)
{
    return d_str[idx];
}

        
#endif

