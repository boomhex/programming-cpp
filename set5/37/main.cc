#include "main.ih"

int main()
{
    set<string> uniq;
    string word;

    while (cin >> word)
        uniq.insert(word);

    vector<string> words;
    for (string const &w: uniq)
        words.push_back(w);

    cout << "Initial\n"
         << "size=" << words.size()
         << " capacity=" << words.capacity() << '\n';

    
    words.push_back("word");        // Add one additional word:

    cout << "After adding word\n"
         << "size=" << words.size()
         << " capacity=" << words.capacity() << '\n';


    vector<string>(words).swap(words);

    cout << "After shedding excess capacity:\n"
         << "size=" << words.size()
         << " capacity=" << words.capacity() << '\n';

    Words wordsClass;
    for (string const &w: uniq)
        wordsClass.add(w);

    cout << "Initial\n"
         << "size=" << wordsClass.size()
         << " capacity=" << wordsClass.capacity() << '\n';

    
    wordsClass.add("word");        // Add one additional word

    cout << "After adding word\n"
         << "size=" << wordsClass.size()
         << " capacity=" << wordsClass.capacity() << '\n';


    Words{wordsClass}.swap(wordsClass);

    cout << "After shedding excess capacity:\n"
         << "size=" << wordsClass.size()
         << " capacity=" << wordsClass.capacity() << '\n';
    

}