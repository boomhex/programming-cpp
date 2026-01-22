#include "filesource.ih"

FileSource::FileSource(string const &listFile)
:
    d_in(listFile),
    d_line{}
{
    if (not d_in)
        throw runtime_error("Could not open listfile");
}