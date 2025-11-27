#include "tempfile.ih"

void TempFile::close()
{
    if (d_file.is_open())       // close before removing
        d_file.close();
}
