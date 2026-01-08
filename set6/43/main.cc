#include "main.h"

size_t multiples(vector<size_t> const &vs)
{
    size_t result = 0;

    for (auto it = vs.begin(); it != vs.end(); )
    {
        //count how many times the current element appears (excluding the first) and add that to the result
        result += count(it, vs.end(), *it) - 1;
        //move the iterator to the next different element
        it = upper_bound(it, vs.end(), *it);
    }

    return result;
}

int main()
{
    vector<size_t> vs{ 1, 2, 2, 3, 4, 4, 4, 5 };
    cout << multiples(vs) << " multiples were found\n";
}
