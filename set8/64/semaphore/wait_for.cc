#include "semaphore.ih"

bool Semaphore::wait_for(size_t sec)
{
    unique_lock<mutex> lk(d_mutex);          // get the lock

    time_point<system_clock> deadline = system_clock::now() + seconds{sec};

    while (d_nAvailable == 0)
    {
        // wait_until returns cv_status::timeout if the deadline is reached
        if (d_condition.wait_until(lk, deadline) == cv_status::timeout)
        {
            return false;                // timed out without acquiring
        }
    }

    --d_nAvailable;                          // acquired one permit
    return true;
}
