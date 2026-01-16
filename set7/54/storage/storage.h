#ifndef INCLUDED_STORAGE
#define INCLUDED_STORAGE

#include <string>
#include <queue>
#include <mutex>

class Storage
{
    std::queue<std::string> d_queue;
    mutable std::mutex d_qmutex;
    bool d_finished;

    public:
        Storage();

        bool pop(std::string &str);     // changed signature, see descr1.txt
        void push(std::string string);
        bool empty()    const;
        void finished();
};

#endif