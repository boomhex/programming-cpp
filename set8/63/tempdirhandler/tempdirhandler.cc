#include "tempdirhandler.ih"

TempDirHandler::TempDirHandler(string const &dir)
:
    d_path(dir),
    d_created(false)
{
    createPath();
}
