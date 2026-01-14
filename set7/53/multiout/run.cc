#include "multiout.ih"

void MultiOut::run()
{
    vector<jthread> threads;    // Use vec to intertweave the other threads
    threads.reserve(d_nthreads);

    for (size_t threadNo = 0; threadNo != d_nthreads; ++threadNo)
        threads.emplace_back(&MultiOut::handler, threadNo);
}
