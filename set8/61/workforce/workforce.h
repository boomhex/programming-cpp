#ifndef INCLUDED_WORKFORCE_
#define INCLUDED_WORKFORCE_

#include "../../57/semaphore/semaphore.h"

#include <string>
#include <iosfwd>
#include <mutex>
#include <queue>

class WorkForce
{
    size_t d_workers;
    size_t d_admin;

    std::mutex d_workMutex;
    std::mutex d_paperworkMutex;

    std::queue<std::string> d_workQueue;
    std::queue<std::string> d_paperworkQueue;

    Semaphore rawLines{0};
    Semaphore reverseLines{0};

    std::atomic_bool d_producerDone{false};
    std::atomic_size_t d_workerDone{0};

    public:
        WorkForce();
        void run(std::string const &input, std::string const &output); // run1
        void run(std::istream &input, std::ostream &output);    //run2
    
    private:
        void administation(std::ostream &output);
        void worker();
};

#endif