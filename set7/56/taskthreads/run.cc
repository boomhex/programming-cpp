#include "taskthreads.ih"

void TaskThreads::run()
{
    d_start = chrono::system_clock().now();
    if (d_parallel)
        runParallel();
    else
        runSequentially();
    d_stop = chrono::system_clock().now();
    showCount();
    showTime();
}