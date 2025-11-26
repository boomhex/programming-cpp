#include "tempfile.ih"


TempFile::TempFile(std::filesystem::path const &directory,
             std::filesystem::path const &filename_pattern,
             std::filesystem::perms permissions)
:
    d_filename(uniquePattern(directory, filename_pattern))
{
    try
    {
        createFile(directory, permissions);
        open();
    }
    catch (string const &msg)
    {
        remove();
        throw;  // throw safely
    }
}
