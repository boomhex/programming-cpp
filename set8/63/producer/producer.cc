#include "producer.ih"

Producer::Producer(string const &listFile,
                TaskQueue &queue, string const &outDir)
:
    d_compiler(),
    d_taskQ(queue),
    d_outDir(outDir),
    d_fileSource(listFile)
{}