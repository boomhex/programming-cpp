#include "main.ih"

void writeOut(string const &fileName, Storage &strg)
{
    ofstream out(fileName);
    if (not out)
        throw runtime_error("Could not open file");

    while (not strg.empty())
    {
        string line;
        if (strg.pop(line))
            out << line << '\n';
        else
            this_thread::sleep_for(chrono::seconds(1));
    }
}
