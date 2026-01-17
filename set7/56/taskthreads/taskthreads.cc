#include "taskthreads.ih"

TaskThreads::TaskThreads(int argc, char **argv)
{
    if (argc < 2)
        return;
    
    d_file = argv[1];
    d_parallel = (argc == 2);

    for (Task &task: d_tasks)
        task.setFile(d_file);
}