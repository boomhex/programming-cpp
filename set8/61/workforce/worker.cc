#include "workforce.ih"

void WorkForce::worker()
{
    while (true)
    {
        rawLines.wait();
        string line;
        {
            lock_guard<mutex> lg(d_workMutex);

            if (d_workQueue.empty())
            {
                if (d_producerDone.load(memory_order_acquire))
                {
                    size_t idx = d_workerDone.load(memory_order_acquire);
                    d_workerDone.store(++idx, memory_order_release);
                    return;
                }
                continue;
            }

            line = move(d_workQueue.front());
            d_workQueue.pop();
        }

        reverse(line.begin(), line.end());

        {
            lock_guard<mutex> lg(d_paperworkMutex);
            d_paperworkQueue.push(move(line));
        }

        reverseLines.notify();
    }
}