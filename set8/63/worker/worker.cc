#include "worker.ih"

Worker::Worker(TaskQueue &queue,
                  std::atomic_bool &stop,
                  std::mutex &failMtx,
                  FirstFailure &firstFail)
:
    d_taskQ(queue),
    d_stop(stop),
    d_failMtx(failMtx),
    d_firstFail(firstFail)
{}
