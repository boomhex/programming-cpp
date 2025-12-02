#include "tempfile.ih"


TempFile::~TempFile()
{
    close();
    remove();
}
