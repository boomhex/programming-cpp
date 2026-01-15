#include "storage.ih"

bool Storage::empty() const
{
    lock_guard<mutex> lk(d_qmutex);
    return d_finished and d_queue.empty();
}
