#ifndef _INCLUDED_FORK_
#define _INCLUDED_FORK_

#include <sys/types.h>

class Fork
{
    pid_t d_pid = -1;

    public:
        Fork() = default;
        virtual ~Fork() = default;

        // delete all copy/move constructors and assignement
        Fork(Fork const &) = delete;
        Fork &operator=(Fork const &) = delete;
        Fork(Fork &&) = delete;
        Fork &operator=(Fork &&) = delete;

        void fork();

    protected:
        pid_t pid() const;
        int waitForChild() const;

        virtual void parentProcess();
        virtual void childProcess() = 0;
};


inline pid_t Fork::pid() const
{
    return d_pid;
}

#endif