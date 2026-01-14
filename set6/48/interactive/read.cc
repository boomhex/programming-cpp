#include "interactive.ih"

void Interactive::read()
{
    ifstream in(d_filename);
    if (not in)
        throw std::runtime_error("Cannot open data file");

    std::istream_iterator<Record> begin(in), end;       // Use iterator since >> is defined

    std::for_each(begin, end,                           // add record to d_map
        [&](Record const &record)
        {
            d_map[record.domain] = record.fields;
        }
    );
}
