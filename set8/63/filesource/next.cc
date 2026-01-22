#include "filesource.ih"

bool FileSource::next(string &out)
{
    namespace fs = std::filesystem;

    while (std::getline(d_in, d_line))
    {
        if (d_line.empty())
            continue;

        fs::path p(d_line);
        if (p.extension() != ".cc")
            continue;

        out = d_line;
        return true;
    }

    return false;
}
