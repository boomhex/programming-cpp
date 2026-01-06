#include "main.ih"

int main()
{
    set<string> words;
    string wordIn;

    while (cin >> wordIn)    // read input
        words.insert(wordIn);

    for (auto const &word : words)  // print sorted different words
        cout << word << '\n';
}
