#include "bistream.ih"


BiStream::BiStream(std::ostream &one, std::ostream &two)
:
    std::ostream(nullptr),      // base constructed with no buffer yet
    d_buffer(one, two)          // construct our buffer
{
    rdbuf(&d_buffer);           // install the buffer into the ostream
}
