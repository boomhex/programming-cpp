#include "bistreambuffer.ih"


int BiStreamBuffer::overflow(int ch)
{
    if (traits::eq_int_type(ch, traits::eof()))
        return traits::not_eof(ch);

    char c = static_cast<char>(ch);

    int putReturn1 = d_buf1->sputc(c);  // write to both buffers
    int putReturn2 = d_buf2->sputc(c);

    // error check
    if (bi_eq_int_type(putReturn1, putReturn2))
        return traits::eof();   // error in one of the sinks

    return ch;
}
