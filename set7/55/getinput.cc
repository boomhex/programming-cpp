#include "main.ih"

void getInput(istream &in, Storage &strg)
{
    string line;
    while (true)
    {
        cout << "? ";

                                        // getline processed b4 line.empty()
        if (not getline(cin, line) or line.empty())
        {
            strg.finished();
            return;
        }
        strg.push(line);
    }
}
