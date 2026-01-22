#ifndef TASK_H
#define TASK_H

#include "../compiler/compiler.h"
#include <future>
#include <string>

using PackagedTask = std::packaged_task<CompileResult (std::string const &source,
                                                    std::string const &object)>;

class Task
{
    std::string  d_source;
    std::string  d_object;
    PackagedTask d_task;
    std::shared_future<CompileResult> d_future;

    public:
        Task() = default;
        Task(Compiler &compiler, std::string const &source,
            std::string const &object);

        void operator()();
        std::shared_future<CompileResult> result() const;
};

inline void Task::operator()()
{
    d_task(d_source, d_object);
}

inline std::shared_future<CompileResult> Task::result() const
{
    return d_future;    
}

#endif