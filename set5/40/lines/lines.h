#ifndef INCLUDED_LINES_
#define INCLUDED_LINES_

#include <iosfwd>
#include <string>
#include <vector>


class Lines
{
    public:
        Lines(std::istream &in);
        ~Lines();
        std::vector<std::string> const &get();
        std::vector<std::string> const &get(size_t idx);
};

#endif