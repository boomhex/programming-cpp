#include "main.ih"

int main(int argc, char **argv)
{
    string listFile = argv[1];

    // Output directory for object files (demo choice)
    string outDir = "./tmp";
    TempDirHandler tempDirHandler(outDir);

    TaskQueue queue;
    atomic_bool stop{false};
    mutex failMtx;
    FirstFailure firstFail;

    unsigned int nThreads = thread::hardware_concurrency();
    if (nThreads == 0)
        nThreads = 1;

    vector<thread> workers;
    workers.reserve(nThreads);

    for (unsigned int i = 0; i != nThreads; ++i)
        workers.emplace_back(Worker(queue, stop, failMtx, firstFail));

    Producer producer(listFile, queue, outDir);
    producer.produce();

    for (auto &thr : workers)
        thr.join();

    // report failure
    if (firstFail.hasFailure)
    {
        cerr << "Compilation failed.\n";
        cerr << firstFail.result.stdErrText;    // prints ONLY first failure stderr
        return 1;
    }

    cout << "All compilations succeeded.\n";
    return 0;
}
