#include "taskthreads.ih"

void TaskThreads::runParallel()
{
    for (size_t idx = 0; idx != 4; ++idx) 
        d_threads[idx] = thread(ref(d_tasks[idx]));
    
    for (thread &thr: d_threads)
        thr.join();
} 