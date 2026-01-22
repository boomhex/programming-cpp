#include "tempdirhandler.ih"

void TempDirHandler::createPath()
{
    error_code ec;

    if (filesystem::exists(d_path, ec))
    {
        return;
    }

    filesystem::create_directories(d_path, ec);
    if (ec)
        throw filesystem::filesystem_error(
            "TempDirHandler: cannot create directory",
            d_path, ec
        );

    d_created = true;
}
