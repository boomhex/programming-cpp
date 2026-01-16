#include "storage.ih"

bool Storage::pop(string &str)
{
    lock_guard<mutex> lg(d_qmutex);

    if (d_queue.empty())
        return false;

    str = move(d_queue.front());        // avoid copy
    d_queue.pop();
    return true;
}
