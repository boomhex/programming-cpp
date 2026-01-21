#include "workforce.ih"

void WorkForce::administation(ostream &output)
{
    while (true)
    {
        reverseLines.wait();

        string line;
        {
            lock_guard<mutex> lg(d_paperworkMutex);

            if (d_paperworkQueue.empty())
            {
                if (d_workerDone.load(memory_order_acquire) == d_workers)
                    return;
            }
            line = move(d_paperworkQueue.front());
            d_paperworkQueue.pop();
        }
        output << line << '\n';
    }
}