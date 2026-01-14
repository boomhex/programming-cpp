#include "main.ih"



bool divisibleBy(size_t num, vector<size_t> const &primes)
{
    return any_of(primes.begin(), primes.end(),
                    [num](size_t by)
                    {
                        return num % by == 0;
                    }
                );
}
