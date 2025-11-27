#include "tempfile.ih"


void TempFile::open()
{
    d_file.open(d_filename, std::ios::in | std::ios::out | std::ios::binary);
    if (!d_file) {
        throw string{ "TempFile: cannot open file: " + d_filename.string() };
    }
}
