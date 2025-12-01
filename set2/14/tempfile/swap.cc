#include "tempfile.ih"


void TempFile::swap(TempFile &other)
{
    d_filename.swap(d_filename);
    d_file.swap(d_file);
}
