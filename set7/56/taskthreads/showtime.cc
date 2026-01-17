#include "taskthreads.ih"

void TaskThreads::showTime() const
{
    using namespace std::chrono;

    auto ms = duration_cast<microseconds>(d_stop - d_start).count();
    std::cout << "time: " << ms << " micro seconds\n";
}