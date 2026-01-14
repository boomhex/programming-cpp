#include "main.ih"

int main()
{
    vector<unsigned> vs(10);

    iota(vs.begin(), vs.end(), customIncrement(0, 2));

    for (auto val : vs)
        cout << val << ' ';

    cout << '\n';
}
