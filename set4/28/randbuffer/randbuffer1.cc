#include "randbuffer.ih"

RandBuffer::RandBuffer(int min, int max, size_t seed)
: 
    d_min(min),
    d_range(max - min + 1),
    d_end(RAND_MAX - RAND_MAX % d_range), // multiple of d_range
    d_buffer(0)
{
    srandom(seed);
    setg(0, 0, 0); // no buffer initially
}
