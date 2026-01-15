#include "storage.ih"

void Storage::finished()
{
    std::lock_guard<std::mutex> lk(d_qmutex);
    d_finished = true;
}
