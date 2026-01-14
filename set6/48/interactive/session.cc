#include "interactive.ih"

void Interactive::session()
{
    string line{};
    while (true)
    {
        cout << "? ";
        if (not getline(cin, line))
            return;     // No entry.

        if (line.empty())
            return;

        FieldsMap wip = d_map;

        if (isNumber(line))
        {
            size_t minFakes = stoull(line);
            auto it = wip.begin();
            while (it != wip.end())
            {
                if (it->second.nFake < minFakes)
                    it = wip.erase(it);   // erase returns next iterator
                else
                    ++it;
            }
        }
        else if (isDate(line))
        {
            auto it = wip.begin();
            while (it != wip.end())
            {
                if (it->second.lastDate != line)
                    it = wip.erase(it);   // erase returns next iterator
                else
                    ++it;
            }
        }
        else
        {
            cout << "Please enter date or min. fake mails\n";
            continue;
        }
        show(wip);
    }
}