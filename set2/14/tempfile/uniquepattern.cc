#include "tempfile.ih"


fs::path TempFile::uniquePattern(fs::path const &dir,
    fs::path const &filename_pattern)    const
{

    fs::path pattern = dir / filename_pattern;  // return if default is valid
    std::error_code errCode;
    if (!fs::exists(pattern, errCode))               
            return pattern;

    for (size_t start = 0;
        start != 1000000000;
        ++start)    // avoid eternal searching
    {
        fs::path rand = dir / randomName(8);
        if (!fs::exists(rand, errCode))     // return if valid name is found
            return rand;
    }
    throw std::runtime_error("could not create unique name."s);
}
