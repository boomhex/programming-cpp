#ifndef _INCLUDED_TEMPFILE_
#define _INCLUDED_TEMPFILE_


#include <fstream>
#include <filesystem>

class TempFile
{
    std::filesystem::path d_filename;
    std::fstream d_file;
    public:
        TempFile(std::filesystem::path const &directory
                = std::filesystem::temp_directory_path(),
                std::filesystem::path const &filename_pattern
                = "XXXXXXXX.tmp",
                std::filesystem::perms permissions
                = std::filesystem::perms::owner_read
                | std::filesystem::perms::owner_write);
                                        // avoid copy for duplicate streams
        TempFile(TempFile const &other) = delete; 
        TempFile(TempFile &&tmp);
        TempFile &operator=(TempFile const &other) = delete;
        TempFile &operator=(TempFile &&tmp);

        ~TempFile();

        std::filesystem::path const &name() const;  // inline
        std::fstream &stream();

        operator std::fstream&&();
    private:
        void createFile(std::filesystem::path const &dir,
            std::filesystem::perms permissions);

        void close();
        void remove() noexcept;
        void open();
        void destroy();
        void swap(TempFile &other);

        std::filesystem::path uniquePattern(std::filesystem::path const &dir,
            std::filesystem::path const &filename_pattern) const;
        std::filesystem::path randomName(size_t nchars) const;
};


inline std::filesystem::path const &TempFile::name()  const
{
    return d_filename;
}


#endif