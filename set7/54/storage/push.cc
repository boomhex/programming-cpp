#include "storage.ih"

void Storage::push(string str)
{
    lock_guard<mutex> lg(d_qmutex);
    d_queue.push(move(str));
}
