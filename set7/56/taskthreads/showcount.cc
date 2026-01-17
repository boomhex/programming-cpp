#include "taskthreads.ih"

void TaskThreads::showCount() const
{
    for (Task task: d_tasks)
        cout << task.label() << ": " << task.count() << '\n';
}