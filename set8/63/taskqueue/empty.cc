#include "taskqueue.ih"

bool TaskQueue::empty() const
{
    lock_guard<mutex> lg(d_mtx);
    return d_finished && d_queue.empty();
}
