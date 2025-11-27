#include "tempfile.ih"



TempFile::operator std::fstream&&()
{
    // Unlink the file if we still have a name
    if (!d_filename.empty()) {
        remove();
        d_filename.clear();           // signal: nothing left to remove
    }

    // Move the stream out. The caller now owns the fstream.
    return std::move(d_file);
}
