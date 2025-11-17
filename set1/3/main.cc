#include <filesystem>

int main(int argc, char *argv[])
{
    namespace fs = std::filesystem;
    fs::path src = argv[1];
    fs::path dest = argv[2];
    fs::copy(src, dest); 
}