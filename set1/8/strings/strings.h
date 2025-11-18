#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <string>

class Strings
{
    size_t d_size = 0;
    std::string *d_str = 0;
    size_t *d_shared;  // pointer to shared reference count

    public:
        class Proxy
        {
            public:
                Proxy &operator=(std::string const &value);
                operator std::string const &() const;   // for reading
            private:
                Strings &d_owner;
                size_t   d_index;

                Proxy(Strings &owner, size_t index);
                friend class Strings;
                friend std::ostream &operator<<(std::ostream &out,
                                                Proxy const &proxy);
        };

        Strings();
        Strings(int argc, char **argv);    // 2.cc
        Strings(char **environLike);       // 3.cc

        Strings(Strings const &other);      // see part 1: allocation
        Strings(Strings &&tmp);             // see part 1: allocation

        ~Strings();

        Strings &operator=(Strings const &rhs); // see part 1: allocation
        Strings &operator=(Strings &&rhs);      // see part 1: allocation

        Strings &operator+=(std::string const &next);

        std::string const &operator[](size_t idx) const;
        Proxy operator[](size_t idx);  // non-const version

        void swap(Strings &other);              

        size_t size() const;

    private:
        std::string *duplicateAndEnlarge();
        void cow();
};

inline size_t Strings::size() const         // potentially dangerous practice:
{                                           // inline accessors
    return d_size;
}

inline Strings::Proxy Strings::operator[](size_t idx)
{
    return Proxy(*this, idx);
}

inline std::string const &Strings::operator[](size_t idx) const
{
    return d_str[idx];
}



        
#endif

