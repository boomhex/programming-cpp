#include "taskthreads.ih"

void TaskThreads::runSequentially()
{
    for (Task &task: d_tasks)
        task();
}