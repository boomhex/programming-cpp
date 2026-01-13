#include "main.ih"

vector<size_t> sieve(size_t amount)
{
    vector<size_t> primeVec{ 2 };

    if (amount == 1)
        return primeVec;
    
    size_t next = 3;
    while (primeVec.size() < amount)
    {
        if (not divisibleBy(next, primeVec))
            primeVec.push_back(next);
        ++next;
    }
    return primeVec;
}
