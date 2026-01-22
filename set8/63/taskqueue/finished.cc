#include "taskqueue.ih"

void TaskQueue::finished()
{
    {
        lock_guard<mutex> lg(d_mtx);
        d_finished = true;
    }
    d_condition.notify_all();
}
