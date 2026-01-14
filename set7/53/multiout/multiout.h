#ifndef INCLUDED_MULTIOUT
#define INCLUDED_MULTIOUT

#include <cstddef>

class MultiOut
{
    size_t d_nthreads;

    public:
        MultiOut(char const *nThreads);
        void run();
    private:
        static void handler(size_t threadNo);
};

#endif