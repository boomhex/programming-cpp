#include "main.ih"

int main()
{
    Storage storage;

    thread inputThread(&getInput, ref(cin), ref(storage));
    inputThread.join();
}
