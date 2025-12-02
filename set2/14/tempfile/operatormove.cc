#include "tempfile.ih"


TempFile &TempFile::operator=(TempFile &&tmp)
{
    swap(tmp);
    return *this;
}
