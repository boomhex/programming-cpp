#include "tempfile.ih"

// static
fs::path TempFile::randomName(size_t nchars)
{
    static std::mt19937_64 engine{ std::random_device{}() };
    static char alphabet[] = "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

    std::uniform_int_distribution<std::size_t> dist(0, sizeof(alphabet) - 2);
    // -2 bc of \0

    std::string name{};

    while (nchars-- != 0)    // do nchars times
        name += alphabet[dist(engine)];

    return fs::path{ name + ".tmp"};
}
