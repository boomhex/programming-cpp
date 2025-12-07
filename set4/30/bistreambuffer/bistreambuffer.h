#ifndef _INCLUDED_BISTREAMBUF_
#define _INCLUDED_BISTREAMBUF_

#include <streambuf>

class BiStreamBuffer: public std::streambuf
{
    std::streambuf *d_buf1;
    std::streambuf *d_buf2;

  public:
    BiStreamBuffer(std::ostream &one, std::ostream &two);

  protected:
    int overflow(int ch) override;
    int sync() override;
};

#endif