#include "fork.ih"

void Fork::fork()
{
    pid_t pid = ::fork();

    if (pid == -1)                  // fork failed
        throw runtime_error("fork() failed");

    d_pid = pid;

    if (d_pid == 0)
    {
        childProcess();             // implemented by derived class
        _exit(0);
    }
    else
    {
        parentProcess();
    }
}