#ifndef INCLUDE_TASK_
#define INCLUDE_TASK_

#include <string>

class Task
{
    using Func = bool (*)(unsigned char);
    Func d_func;
    char const *d_label;
    size_t d_count;
    std::string const *d_file;
    public:
        Task(Func func, char const *label);
        size_t count() const;
        void setFile(std::string const &file);
        void operator()();
        std::string label() const;
};

inline size_t Task::count() const
{
    return d_count;
}

inline std::string Task::label() const
{
    return d_label;
}

#endif