#include "taskqueue.ih"

bool TaskQueue::pop(Task &task)
{
    unique_lock<mutex> lk(d_mtx);

    // Wait until there is work, or until we are finished.
    d_condition.wait(lk, 
        [&]
        {
            return d_finished or not d_queue.empty();
        }
    );

    if (d_queue.empty())          // must be finished here
        return false;

    task = move(d_queue.front());
    d_queue.pop();
    return true;
}
