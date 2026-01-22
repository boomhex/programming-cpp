#include "task.ih"

Task::Task(Compiler &compiler, string const &source, string const &object)
:
    d_source(source),
    d_object(object),
    d_task([&compiler](std::string const &src, std::string const &obj)
            {
                return compiler.compile(src, obj);
            }
    ),
    d_future(d_task.get_future().share())
{}