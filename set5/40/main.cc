#include "main.ih"

    // argv[1] is the name of the file to process

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        return 1;
    } 
    
    ifstream in{ argv[1] };

    if (not in)
    {
        cout << "can't open " << argv[1] << '\n';
        return 1;
    }

    Lines lines1{ in };

    cout << "Lines1's lines:\n";
    for (string const &line: lines1.get())      // lines1's lines
        cout << line << '\n';

    {            
        Lines lines2{ in };
        cout << "Lines2's lines:\n";
        for (string const &line: lines1.get(1))     // lines2's lines via lines1
            cout << line << '\n';
    }

    cout << "Lines2 doesn't exist anymore. lines1.get(1) shows:\n";
    for (string const &line: lines1.get(1))     // lines2's lines via lines1
        cout << line << '\n';

    cout << "\n"
            "Non-existing 3rd Lines object's lines:\n";
    for (string const &line: lines1.get(3))
        cout << line << '\n';
}
