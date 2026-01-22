#ifndef PRODUCER_H
#define PRODUCER_H

#include "../filesource/filesource.h"
#include "../compiler/compiler.h"
#include "../taskqueue/taskqueue.h"

#include <string>
#include <filesystem>

class Producer
{
    Compiler d_compiler;
    TaskQueue &d_taskQ;
    std::filesystem::path d_outDir;
    FileSource d_fileSource;

    public:
        Producer(std::string const &listFile,
                TaskQueue &queue, std::string const &outDir);

        void produce();
    private:
        std::string srcToObj(std::filesystem::path &src) const;
};


#endif