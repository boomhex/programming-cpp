#include "fork.ih"

void Fork::fork()
{
    pid_t pid = ::fork();

    if (pid == -1)                  // fork failed
        throw runtime_error("fork() failed");

    d_pid = pid;

    if (d_pid == 0)                 // child process
    {
        childProcess();             // implemented by derived class

        // When childProcess() returns, the child must terminate
        _exit(0);                   // avoid flushing stdio twice
    }
    else                            // parent process
    {
        parentProcess();            // default: does nothing
    }
}