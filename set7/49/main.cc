#include "main.ih"

int main(int argc, char **argv)
{
    if (argc != 2)
        usage();

    size_t nPrimes = stoull(argv[1]);

    thread thread(dots);
    sieve();
}