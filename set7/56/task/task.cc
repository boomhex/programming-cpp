#include "task.ih"

Task::Task(Func func, char const *label)
:
    d_func{func},
    d_label{label},
    d_count{0},
    d_file{nullptr}
{

}