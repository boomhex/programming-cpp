#include "main.ih"

int main(int argc, char **argv)
try
{
    char const *childPath = argv[1];
    char const *nLines = argv[2];

    bool useTimeout = (argc == 4);
    size_t timeoutSeconds = 0;
    if (useTimeout)
        timeoutSeconds = stoul(argv[3]);

    pid_t childPid = fork();
    if (childPid == 0)
    {
        execl(childPath, childPath, nLines);
    }
    Semaphore done{0};
    int status = 0;
    thread waiter([&]{
        while (true)
        {
            pid_t r = waitpid(childPid, &status, 0);
            if (r == childPid)
                break;

            if (r < 0 && errno == EINTR)
                continue;

            break;
        }
        done.notify();
    });
    bool endedNormally = true;

    if (useTimeout)
    {
        bool finished = done.wait_for(static_cast<size_t>(timeoutSeconds));
        if (!finished)
        {
            endedNormally = false;

            kill(childPid, SIGKILL);
        }
    } 
    else
    {
        done.wait();
    }
    waiter.join();

    if (endedNormally)
        cout << "Program ended normally\n";
    else
        cout << "Program ended at timeout\n";
    
}
catch (...)
{
    cout << argv[0] << " needs a non-negative integral first argument\n";
}