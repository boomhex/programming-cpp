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

    std::mutex workMutex;

    std::queue<std::string> d_workQueue;
    std::queue<std::string> d_paperworkQueue;

    Semaphore workers{d_workers};
    Semaphore admin{d_admin};


    public:
        WorkForce();
        void run(std::string const &input, std::string const &output); // run1
        void run(std::istream &input, std::ostream &output);    //run2
};

#endif