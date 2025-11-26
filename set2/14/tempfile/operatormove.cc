#include "tempfile.ih"


TempFile &TempFile::operator=(TempFile &&tmp)
{
    destroy();
    swap(tmp);
    return *this;
}
