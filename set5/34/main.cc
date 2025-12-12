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

    for (map<string, size_t>::iterator it = words.begin();
            it != words.end(); ++it)
        cout << it->first << " " << it->second << '\n';
}
