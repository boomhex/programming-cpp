#include "tempfile.ih"


TempFile::TempFile(TempFile &&tmp)
:
    d_filename(std::move(tmp.d_filename)),
    d_file(std::move(tmp.d_file))
{
    tmp.d_filename.clear();
}
