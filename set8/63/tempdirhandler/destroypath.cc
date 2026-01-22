#include "tempdirhandler.ih"

void TempDirHandler::destroyPath()
{
    if (not d_created)
        return;

    error_code ec;
    filesystem::remove_all(d_path, ec);
    d_created = false;
}