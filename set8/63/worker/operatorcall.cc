#include "worker.ih"

void Worker::operator()()
{
    Task task;

    while (not d_stop.load(std::memory_order_relaxed))
    {
        // pop blocks until a task is available or the queue is finished+empty
        if (not d_taskQ.pop(task))
            return;                         // no more work

        // If a stop was requested while we were waiting, exit without running it
        if (d_stop.load(std::memory_order_relaxed))
            return;

        // Run the packaged task
        task();

        // Get result (shared_future is stored inside Task per your design)
        CompileResult res = task.result().get();

        if (not res.success)
        {
            // First failing compilation wins
            {
                lock_guard<mutex> lg(d_failMtx);
                if (not d_firstFail.hasFailure)
                {
                    d_firstFail.hasFailure = true;
                    d_firstFail.result = std::move(res);
                    d_stop.store(true, std::memory_order_relaxed);
                }
            }

            // Stop after failure (even if we were not the first, stop is now true)
            return;
        }
    }
}