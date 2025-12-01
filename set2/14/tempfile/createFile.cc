#include "tempfile.ih"


void TempFile::createFile(std::filesystem::path const &dir,
                std::filesystem::perms permissions)
{
    std::error_code errCode;
    fs::create_directories(dir, errCode);

    std::ofstream tmp{ d_filename };              // create empty file
    if (not tmp)
        throw std::runtime_error(
            "TempFile: cannot create file: " + d_filename.string());

    fs::permissions(d_filename, permissions, errCode);
}
