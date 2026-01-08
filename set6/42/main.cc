#include <algorithm>
#include <iostream>
#include <iterator>
#include <strings.h> 

using namespace std;

int main(int argc, char **argv)
{
    //sorts the arguments in ascending order
    sort(argv + 1, argv + argc,
         [](char const *a, char const *b) { return strcmp(a, b) < 0; });
    //prints the sorted arguments
    copy(argv + 1, argv + argc, ostream_iterator<char const *>(cout, " "));

    cout << '\n';

    //sorts the arguments in descending order
    sort(argv + 1, argv + argc,
         [](char const *a, char const *b) { return strcmp(a, b) > 0; });
    //prints the sorted arguments
    copy(argv + 1, argv + argc, ostream_iterator<char const *>(cout, " "));

    cout << '\n';
}
