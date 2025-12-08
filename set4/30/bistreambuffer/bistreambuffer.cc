#include "bistreambuffer.ih"

// using std::streambuf;

BiStreamBuffer::BiStreamBuffer(std::ostream &one, std::ostream &two)
:
    d_buf1(one.rdbuf()),    // get the buffers and set them as
    d_buf2(two.rdbuf())     // the datamembers
{}
