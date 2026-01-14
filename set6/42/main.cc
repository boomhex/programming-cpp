#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>

using namespace std;

int main(int argc, char **argv)
{
    sort(argv + 1, argv + argc,
         bind(less<int>(), 
              bind(strcmp, placeholders::_1, placeholders::_2), 0
             )
        );
    copy(argv + 1, argv + argc, ostream_iterator<char const *>(cout, " "));
    cout << '\n';

    sort(argv + 1, argv + argc,
         bind(greater<int>(), 
              bind(strcmp, placeholders::_1, placeholders::_2), 0
             )
        );
    copy(argv + 1, argv + argc, ostream_iterator<char const *>(cout, " "));
    cout << '\n';
}