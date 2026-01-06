#include "main.ih"

int main()
{
    map<string, size_t> words;
    string word;

    while (cin >> word)                 // read input
        ++words[word];                  // increment value at index
                                        // default value of size_t == 0, so
                                        // if key not present, it will create
                                        // correctly

    for (auto const &[word, count] : words)
        cout << word << " " << count << '\n';
}
