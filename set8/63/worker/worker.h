#ifndef WORKER_H
#define WORKER_H

#include "../taskqueue/taskqueue.h"
#include "../compiler/compiler.h"       // only for CompileResult

struct FirstFailure
{
    bool hasFailure = false;
    CompileResult result;
};

class Worker
{
    TaskQueue &d_taskQ;

    std::atomic_bool &d_stop;      // set to true on first failure
    std::mutex &d_failMtx;         // protects d_firstFail
    FirstFailure &d_firstFail;
    public:
        Worker(TaskQueue &queue,
               std::atomic_bool &stop,
               std::mutex &failMtx,
               FirstFailure &firstFail);

        void operator()();
};

#endif