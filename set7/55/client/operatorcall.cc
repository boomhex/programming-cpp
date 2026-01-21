#include "client.ih"

void Client::operator()()
{
    ofstream out(d_fileName);

    if (not out)
        throw runtime_error("Could not open file");

    while (not d_storage.empty())
    {
        string line;
        if (d_storage.pop(line))
        {
            out << line << '\n' << flush;
            ++d_count;
        }
        else
            this_thread::sleep_for(chrono::seconds(1));
    }
}
