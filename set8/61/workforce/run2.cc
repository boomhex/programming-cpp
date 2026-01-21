#include "workforce.ih"

void WorkForce::run(istream &input, ostream &output)
{
    vector<thread> admin;
    admin.reserve(d_admin);
    for (size_t idx = 0; idx != d_admin; ++idx)
        admin.emplace_back(&WorkForce::administation, this, ref(output));

    vector<thread> workers;
    workers.reserve(d_workers);
    for (size_t idx = 0; idx != d_workers; ++idx)
        workers.emplace_back(&WorkForce::worker, this);

    for (string line; getline(input, line); )
    {
        lock_guard<mutex> lg(d_workMutex);
        d_workQueue.push(line);
        rawLines.notify_all();
    }

    d_producerDone.store(true, memory_order_release);

    for (size_t idx = 0; idx != d_workers; ++idx)
        rawLines.notify();

    for (auto &th : workers)
        th.join();
    
    for (size_t idx = 0; idx != d_admin; ++idx)
        reverseLines.notify();

    for (auto &th : admin)
        th.join();
}