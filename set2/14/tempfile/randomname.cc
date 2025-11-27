#include "tempfile.ih"


fs::path TempFile::randomName(size_t nchars)    const
{
    static std::mt19937_64 engine{ std::random_device{}() };
    static char alphabet[] = "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

    std::uniform_int_distribution<std::size_t> dist(0, sizeof(alphabet) - 2);
    // -2 bc of \0

    std::string name{};

    for (std::size_t index = 0; index != nchars; ++index)
        name += alphabet[dist(engine)];

    return fs::path{ name + ".tmp"};
}
