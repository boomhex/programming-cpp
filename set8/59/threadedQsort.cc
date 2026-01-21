#include "main.ih"

void threadedQsort(int *beg, int *end)
{
    if (end - beg <= 1)
        return;

    int lhs = *beg;
    int *mid = partition(beg + 1, end, 
        [&](int arg)
        {
            return arg < lhs;
        }
    );

    swap(*beg, *(mid - 1));

    // move one, the other can use current thread.
    auto fut = async(launch::async, threadedQsort, beg, mid);
    threadedQsort(mid, end);
    fut.get();
}
