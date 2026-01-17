#ifndef INCLUDE_TASKTHREADS_
#define INCLUDE_TASKTHREADS_

#include "../task/task.h"
#include <thread>
#include <chrono>

class TaskThreads
{
    
    std::thread d_threads[4];
    std::string d_file;
    bool d_parallel;

    using Clock = std::chrono::system_clock;
    Clock::time_point d_start;
    Clock::time_point d_stop;


    public:
        TaskThreads(int argc, char **argv);
        void run();

    private:
        static bool isVowel(unsigned char ch);
        static bool isDigit(unsigned char ch);
        static bool isHex(unsigned char ch);
        static bool isPunc(unsigned char ch);

        Task d_tasks[4] = 
        {
            Task(&TaskThreads::isVowel, "vowels"),
            Task(&TaskThreads::isDigit, "digits"),
            Task(&TaskThreads::isHex, "hexadecimal digits"),
            Task(&TaskThreads::isPunc, "punctuation characters")
        };

        void runParallel();
        void runSequentially();
        void showCount() const;
        void showTime() const;
};

inline bool TaskThreads::isVowel(unsigned char ch)
{
    switch(ch)
    {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
        return true;
    default:
        return false;
    }
}

inline bool TaskThreads::isDigit(unsigned char ch)
{
    return std::isdigit(ch) != 0;
}

inline bool TaskThreads::isHex(unsigned char ch)
{
    return std::isxdigit(ch) != 0;
}

inline bool TaskThreads::isPunc(unsigned char ch)
{
    return std::ispunct(ch) != 0;
}

#endif