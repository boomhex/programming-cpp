#ifndef COMPILEJOBQUEUE_H
#define COMPILEJOBQUEUE_H

#include "../task/task.h"
#include <queue>
#include <condition_variable>

class TaskQueue
{
    std::queue<Task> d_queue;

    bool d_finished;

    mutable std::mutex d_mtx;
    std::condition_variable d_condition;

    public:
        TaskQueue();

        bool pop(Task &task);
        void push(Task &&task);
        bool empty()    const;
        void finished();
};

#endif