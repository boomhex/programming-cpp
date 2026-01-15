#include "main.ih"

int main()
{
    Storage storage;

    thread inputThread(&getInput, ref(cin), ref(storage));
    thread outputThread(&writeOutput, "./out", ref(storage));

    inputThread.join();
    outputThread.join();
}
