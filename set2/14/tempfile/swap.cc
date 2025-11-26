#include "tempfile.ih"


void TempFile::swap(TempFile &other)
{
    std::swap(d_filename, other.d_filename);
    std::swap(d_file, other.d_file);
}
