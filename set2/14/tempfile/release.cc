#include "tempfile.ih"


fstream TempFile::release()
{
    // Unlink the file if we still have a name
    if (not d_filename.empty())
    {
        remove();
        d_filename.clear();           // signal: nothing left to remove
    }
    return std::move(d_file);
}
