#include "main.ih"

int main()
{
    std::set<std::string> words;
    std::string word;

    while (std::cin >> word)    // read input
        words.insert(word);

    for (std::string const &w : words)  // print sorted different words
        std::cout << w << '\n';
}
