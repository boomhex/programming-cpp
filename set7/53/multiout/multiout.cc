#include "multiout.ih"

MultiOut::MultiOut(char const *nThreads)
:
    d_nthreads(stoull(nThreads))
{}