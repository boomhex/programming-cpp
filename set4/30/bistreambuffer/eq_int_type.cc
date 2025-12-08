#include "bistreambuffer.ih"


bool BiStreamBuffer::bi_eq_int_type(int putReturn1, int putReturn2)
{
    return traits::eq_int_type(putReturn1, traits::eof()) or
    traits::eq_int_type(putReturn2, traits::eof());
}
