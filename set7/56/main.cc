#include "taskthreads/taskthreads.h"

int main(int argc, char **argv)
{
    TaskThreads tt(argc, argv);
    tt.run();
}