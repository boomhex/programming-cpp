#include "tempfile.ih"


void TempFile::remove() noexcept
{
    if (!d_filename.empty())    // remove safely         noexcept func
    {  
        std::error_code errCode;
        std::filesystem::remove(d_filename, errCode);   // noexcept func
    }
}
