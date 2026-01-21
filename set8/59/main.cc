#include "main.ih"

int main()
{
    int intArr[] = {
        2, 5, 2, 5, 7, 2, 6, 8, 2, 6, 8
    };
    threadedQsort(intArr, intArr + 11);

    cout << "ordered array:\t{";
    bool first = true;
    for (auto &el : intArr)
    {
        if (not first)
            cout << ", ";
        cout << el;
        first = false;
    }
    cout << "}\n";
}
