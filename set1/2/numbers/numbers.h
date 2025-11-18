#ifndef INCLUDED_NUMBERS_H_
#define INCLUDED_NUMBERS_H_

#include <initializer_list>
#include <iosfwd>

class Numbers
{
    size_t d_size = 0;
    int *d_nums = 0;

    public:
        friend bool operator==(Numbers const &lhs, Numbers const &rhs);

        explicit Numbers(size_t size);
    
        Numbers(size_t size, int value);
        Numbers(size_t size, int *values);
        Numbers(std::initializer_list<int> iniList);
        Numbers(Numbers const &other);
        Numbers(Numbers &&tmp);
        ~Numbers();

        Numbers &operator=(Numbers const &other);
        Numbers &operator=(Numbers &&tmp);

        // members of the public interface, like accessors
        size_t size()   const;
        int &operator[](size_t index);
        int const &operator[](size_t index)  const;

        Numbers &operator+=(Numbers const &other)       &;      // opadd1.cc
        Numbers &&operator+=(Numbers const &other)      &&;     // opadd2.cc
        Numbers &operator-=(Numbers const &other)       &;      // opsub1.cc
        Numbers &&operator-=(Numbers const &other)      &&;     // opsub2.cc
        Numbers &operator*=(int scalar)       &;      // opmult.cc
        Numbers &operator/=(int divisor)       &;      // opdiv.cc

    private:
        // support members for this class, if any
        int &safeAt(size_t index)               const;
        void boundary(size_t index)             const;
        bool isEqual(Numbers const &other)      const;
        void swap(Numbers &other);

        void add(Numbers const &other);
        void mult(int scalar);
        void div(int divisor);
        void sub(Numbers const &other);

        bool equalSize(Numbers const &other);
        bool zeroDivisionError(int divisor);
};

std::ostream &operator<<(std::ostream &out, Numbers const &numbers);    // operinsert.cc
bool operator!=(Numbers const &lhs, Numbers const &rhs);

Numbers operator+(Numbers const &lhs, Numbers const &rhs);      // opadd3.cc
Numbers operator+(Numbers &&tmp, Numbers const &rhs);           // opadd4.cc

Numbers operator-(Numbers const &lhs, Numbers const &rhs);      // opsub3.cc
Numbers operator-(Numbers &&tmp, Numbers const &rhs);           // opsub4.cc

Numbers operator*(Numbers const &lhs, int scalar);              // opmult1.cc 
Numbers operator*(int scalar, Numbers const &rhs);              // opmult2.cc

Numbers operator/(Numbers const &lhs, int divisor);      // opdiv1.cc


inline size_t Numbers::size()   const
{
    return d_size;
}

inline bool operator!=(Numbers const &lhs,  
                       Numbers const &rhs)
{
    return not (lhs == rhs);    // inverse of equal
}

inline Numbers &Numbers::operator/=(int divisor)    &
{
    div(divisor);
    return *this;
}

inline Numbers &Numbers::operator*=(int scalar)     &
{
    mult(scalar);
    return *this;
}

#endif