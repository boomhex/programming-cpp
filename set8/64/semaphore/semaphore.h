#ifndef INCLUDE_SEMAPHORE_
#define INCLUDE_SEMAPHORE_

#include <mutex>
#include <atomic>

class Semaphore
{
    mutable std::mutex d_mutex;     // mutable because of its use in
                                    // 'size_t size() const'
    std::condition_variable d_condition;
    std::atomic_size_t d_nAvailable;
    public:
        Semaphore(size_t nAvailable);
        void notify();
        void notify_all();
        size_t size() const;
        void wait();
        bool wait_for(size_t seconds);
        void set(size_t const nAvailable);
};

inline size_t Semaphore::size() const
{
    return d_nAvailable.load(std::memory_order_acquire);
}

#endif