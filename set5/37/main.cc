#include "main.ih"

int main()
{
    set<string> uniq;
    string word;

    while (cin >> word)
        uniq.insert(word);

    vector<string> words;
    for (string const &word: uniq)
        words.push_back(word);

    cout << "Initial\n";
    printWords(words);

    
    words.push_back("word");        // Add one additional word:

    cout << "After adding word\n";
    printWords(words);


    vector<string>(words).swap(words);

    cout << "After shedding excess capacity:\n";
    printWords(words);

    Words wordsClass;
    for (string const &word: uniq)
        wordsClass.add(word);

    cout << "Initial\n";
    printWords(wordsClass);

    
    wordsClass.add("word");        // Add one additional word

    cout << "After adding word\n";
    printWords(wordsClass);


    Words{wordsClass}.swap(wordsClass);

    cout << "After shedding excess capacity:\n";
    printWords(wordsClass);
    

}