#ifndef INCLUDED_SHRINK_
#define INCLUDED_SHRINK_

#include <iosfwd>
#include <string>
#include <vector>


class Shrink
{
    using FunPtr = void (*)(std::vector<std::string> &);

    std::ostream &d_out;

    std::string d_str;
    size_t d_size;
    std::vector<std::string> d_vect;

    public:
        Shrink(std::ostream &out, size_t size);
        void process(std::string const &msg, FunPtr fun);

        static void copySwap(std::vector<std::string> &vect);
        static void moveSwap(std::vector<std::string> &vect);
        static void moveFails(std::vector<std::string> &vect);
        static void handmadeMove(std::vector<std::string> &vect);

    private:
        void time(FunPtr fun);
        void report() const;
        void reset();
};

#endif
