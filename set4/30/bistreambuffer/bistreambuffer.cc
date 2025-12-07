#include "bistreambuffer.ih"

using std::ostream;
using std::streambuf;

BiStreamBuffer::BiStreamBuffer(ostream &one, ostream &two)
:
    d_buf1(one.rdbuf()),        // remember underlying buffers
    d_buf2(two.rdbuf())
{}

// called when a single character is written (e.g. via operator<<)
int BiStreamBuffer::overflow(int ch)
{
    using traits = std::streambuf::traits_type;

    if (traits::eq_int_type(ch, traits::eof()))
        return traits::not_eof(ch);

    char c = static_cast<char>(ch);

    int r1 = d_buf1->sputc(c);  // write to first buffer
    int r2 = d_buf2->sputc(c);  // write to second buffer

    if (traits::eq_int_type(r1, traits::eof()) ||
        traits::eq_int_type(r2, traits::eof()))
        return traits::eof();   // error in one of the sinks

    return ch;
}

// called when stream is flushed (<< std::endl or .flush())
int BiStreamBuffer::sync()
{
    int s1 = d_buf1->pubsync();
    int s2 = d_buf2->pubsync();

    return (s1 == 0 && s2 == 0) ? 0 : -1;
}

