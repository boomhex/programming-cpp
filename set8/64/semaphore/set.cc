#include "semaphore.ih"

void Semaphore::set(size_t const nAvailable)
{
    {
        lock_guard<mutex> lg(d_mutex);
        d_nAvailable.store(nAvailable, memory_order_release);
    }
}
