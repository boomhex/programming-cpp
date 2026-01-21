#include "storage.ih"

void Storage::finished()
{
    lock_guard<mutex> lk(d_qmutex);
    d_finished = true;
}
