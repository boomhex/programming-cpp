#include "bistream.ih"


BiStream::BiStream(std::ostream &one, std::ostream &two)
:
    d_buffer(one, two)
{
    rdbuf(&d_buffer);   // set stream buffer
}
