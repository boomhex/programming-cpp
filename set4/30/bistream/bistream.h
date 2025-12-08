#ifndef _INCLUDED_BISTREAM_
#define _INCLUDED_BISTREAM_

#include "../bistreambuffer/bistreambuffer.h"
#include <fstream>

class BiStream: public std::ostream
{
    BiStreamBuffer d_buffer;

    public:
        BiStream(std::ostream &one, std::ostream &two);
};


#endif