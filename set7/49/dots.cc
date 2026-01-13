#include "main.ih"

void dots(stop_token stop)
{
    while (not stop.stop_requested())
    {
        cerr << "." << flush;           // flush to immediatly display
        this_thread::sleep_for(chrono::seconds(1));
    }
    cerr << "\n" << flush;
}
