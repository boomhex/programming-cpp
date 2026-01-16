#include "semaphore.ih"

void Semaphore::wait()
{
    std::unique_lock<std::mutex> lk(d_mutex);   // get the lock
    while (d_nAvailable == 0)
        d_condition.wait(lk);   // internally releases the lock
                                // and waits, on exit
                                // acquires the lock again
    --d_nAvailable;              // dec. available
}   // the lock is released
