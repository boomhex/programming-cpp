#ifndef INCLUDED_HANDLER
#define INCLUDED_HANDLER

#include <iosfwd>

class Handler
{
    public:
        void shift(std::ostream &out, std::string const &text);

};

#endif