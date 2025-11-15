#ifndef INCLUDED_NUMBERS_H_
#define INCLUDED_NUMBERS_H_

#include <initializer_list>
#include <iosfwd>

class Numbers
{
    size_t d_size = 0;
    int *d_nums = 0;

    public:
        explicit Numbers(size_t size);
    
        Numbers(size_t size, int value);
        Numbers(size_t size, int *values);
        Numbers(std::initializer_list<int> iniList);
        Numbers(Numbers const &other);
        Numbers(Numbers &&tmp);
        ~Numbers();

        void swap(Numbers &other);
        Numbers &operator=(Numbers const &other);
        Numbers &operator=(Numbers &&tmp);
        int &operator[](size_t index);     // operindex1.cc
        int const &operator[](size_t index)  const;     // operindex2.cc


        // members of the public interface, like accessors
        size_t size()   const;

        friend bool operator==(Numbers const &lhs, Numbers const &rhs);    // equal.cc
        friend bool operator!=(Numbers const &lhs, Numbers const &rhs);    // inline   
    
    private:
        // support members for this class, if any
        int &operatorIndex(size_t index)  const;
        void boundary(size_t index) const;
};



inline size_t Numbers::size()   const
{
    return d_size;
}

inline bool operator!=(Numbers const &lhs, Numbers const &rhs)  // inverse of equal
{
    return not (lhs == rhs);
}

#endif 