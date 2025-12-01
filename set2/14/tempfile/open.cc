#include "tempfile.ih"


void TempFile::open()
{
    d_file.open(d_filename, std::ios::in | std::ios::out | std::ios::binary);
    if (!d_file)
        throw std::runtime_error( 
            "TempFile: cannot open file: "s + d_filename.string() );
}
