#include "main.ih"

void dots()
{
    while (true)
    {
        cerr << "." << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
}
