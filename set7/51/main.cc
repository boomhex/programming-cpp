#include "main.ih"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    string arg = argv[1];
    auto now = chrono::system_clock::now();
    time_t tim = chrono::system_clock::to_time_t(now);
    printTimes(tim);
    auto input = calcTime(arg);
    auto newTime = now + input;
    time_t newT = chrono::system_clock::to_time_t(newTime);
    printTimes(newT);
}