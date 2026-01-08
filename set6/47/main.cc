#include "main.h"

// A struct that is used to customize the increment step 
// used a struct because i did not see the need for any 
// of the extra features of a class
struct customIncrement
{
    unsigned value;
    unsigned step;

    customIncrement &operator++()
    {
        value += step;
        return *this;
    }

    operator unsigned() const
    {
        return value;
    }
};

int main()
{
    vector<unsigned> vs(10);

    //filling the vector with values starting from 0 and incrementing by 2
    iota(vs.begin(), vs.end(), customIncrement{0,2});
    
    for (auto v : vs)
        cout << v << ' ';

    cout << '\n';
}