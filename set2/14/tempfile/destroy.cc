#include "tempfile.ih"


void TempFile::destroy()
{
    close();
    remove();
}
