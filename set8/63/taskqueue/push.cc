#include "taskqueue.ih"

void TaskQueue::push(Task &&task)
{
    {
        lock_guard<mutex> lg(d_mtx);
        d_queue.push(std::move(task));
    }
    d_condition.notify_one();
}