#include "bistreambuffer.ih"


int BiStreamBuffer::sync()
{
    int s1 = d_buf1->pubsync();
    int s2 = d_buf2->pubsync();

    int flag = (s1 == 0 and s2 == 0) ? 0 : -1;
    return flag;
}
