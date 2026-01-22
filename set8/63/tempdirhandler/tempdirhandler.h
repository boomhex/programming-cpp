#ifndef TEMPDIR_H
#define TEMPDIR_H

#include <string>
#include <filesystem>

class TempDirHandler
{
    std::filesystem::path d_path;
    bool d_created;

    public:
        TempDirHandler(std::string const &dir);

        // define move and copy since dtor is defined.
        TempDirHandler(TempDirHandler const &) = delete;
        TempDirHandler &operator=(TempDirHandler const &) = delete;

        TempDirHandler(TempDirHandler &&) noexcept = default;
        TempDirHandler &operator=(TempDirHandler &&) noexcept = default;

        ~TempDirHandler();

    private:
        void createPath();
        void destroyPath();
};

#endif