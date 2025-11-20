#ifndef INCLUDED_NUMBERS_H_
#define INCLUDED_NUMBERS_H_

#include <initializer_list>
#include <iosfwd>

class Numbers
{
    size_t d_size = 0;
    int *d_nums = 0;

    public:
        friend bool operator==(Numbers const &lhs,      // equal.cc
                               Numbers const &rhs);
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

        // members of the public interface, like accessors
        size_t size()   const;
        int &operator[](size_t index);                  // operindex1.cc
        int const &operator[](size_t index)  const;     // operindex2.cc

    private:
        // support members for this class, if any
        int &safeAt(size_t index)  const;
        bool boundary(size_t index) const;
        bool isEqual(Numbers const &other)    const;
};

std::ostream &operator<<(std::ostream &out, Numbers const &numbers);    // operinsert.cc
bool operator!=(Numbers const &lhs,      // inline
                Numbers const &rhs);


inline size_t Numbers::size()   const
{
    return d_size;
}

inline bool operator==(Numbers const &lhs, Numbers const &rhs)
{
    return lhs.isEqual(rhs);
}

inline bool operator!=(Numbers const &lhs,  
                       Numbers const &rhs)
{
    return not (lhs == rhs);    // inverse of equal
}

#endif