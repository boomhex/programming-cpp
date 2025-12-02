#include "tempfile.ih"


fstream &TempFile::stream()
{
    return d_file;
}
