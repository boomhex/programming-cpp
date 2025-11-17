#include <iostream>
#include <string>

using namespace std;

bool promptGet(istream &in, string &str)
    {
        cout << "Enter a line or ^D\n";     // ^D signals end-of-input

        return static_cast<bool>(getline(in, str));
    }

void process(const string &line)
{
    // For now, just echo the line back
    cout << "You entered: " << line << '\n';
}

int main()
{
    string str;  // Declare the variable you pass to promptGet

    while (promptGet(cin, str))
        process(str);

    return 0;
}