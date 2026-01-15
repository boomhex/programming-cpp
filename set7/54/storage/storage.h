#ifndef INCLUDED_STORAGE
#define INCLUDED_STORAGE

#include <string>
#include <queue>
#include <mutex>

class Storage
{
    std::queue<std::string> d_data;
    mutable std::mutex d_mtx;
    bool d_finished;

    public:
        Storage();

        std::string const &pop();
        std::string const &front();
        void push(std::string string);
};

#endif