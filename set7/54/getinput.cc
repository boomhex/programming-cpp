#include "main.ih"

void getInput(istream &in, Storage &strg)
{
    string line;
    while (true)
    {
        cout << "? ";

        if (not getline(cin, line))
        {
            strg.finished();
            return;
        }
        if (line.empty())
        {
            strg.finished();
            return;
        }
        strg.push(line);
    }
}
