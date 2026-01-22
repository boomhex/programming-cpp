#include "producer.ih"

void Producer::produce()
{
    // Enqueue compile tasks from the file source provider
    string src;
    while (d_fileSource.next(src))
    {
        filesystem::path srcPath(src);
        string obj = srcToObj(srcPath);

        // Requires: Task(Compiler&, std::string source, std::string object)
        d_taskQ.push(Task(d_compiler, src, obj));
    }
    d_taskQ.finished();
}
