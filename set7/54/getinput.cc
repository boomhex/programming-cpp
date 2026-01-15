#include "main.ih"

void getInput(istream &in, Storage &storage)
{
    string line;
    while (true)
    {
        if (not getline(cin, line))
            return;

        if (line.empty())
            return;
        
        storage.push(line);
    }
}
