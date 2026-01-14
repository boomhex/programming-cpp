#include "interactive.ih"

istream &operator>>(istream &in, Interactive::Record &record)
{
    std::string clock;

    return in >> record.domain
           >> record.fields.nFake
           >> record.fields.lastTime
           >> record.fields.lastDate
           >> clock;                    // Ignore time since not required by ex
}
