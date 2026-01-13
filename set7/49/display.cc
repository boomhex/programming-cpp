#include "main.ih"

void display(ostream &out, vector<size_t> const &primes)
{
    out << '{';
    bool first = true;
    for (auto &prime : primes)          // auto for readability
    {
        if (not first)
            out << ", ";
        out << prime;
        first = false;
    }
    out << "}\n";
}
