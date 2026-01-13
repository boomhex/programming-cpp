#include "main.ih"

bool divisibleBy(size_t num, vector<size_t> const &primes)
{
    for (size_t prime : primes)
        if (num % prime == 0)
            return true;
    return false;
}
