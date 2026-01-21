#include "main.ih"

int main()
{
    int intArr[] = {
        2, 5, 2, 5, 7, 2, 6, 8, 2, 6, 8
    };
    threadedQsort(intArr, intArr + 11);
    for (auto &el : intArr)
        cout << el << '\n';
}
