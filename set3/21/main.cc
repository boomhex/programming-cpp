#include "main.ih"

int main()
{
    // Show new insert function
    String string1("world");
    cout << "Initial stringObject: " << string1 << '\n';

    string1.insert(string("hello "));
    cout << "After prepend insert: " << string1 << "\n\n";

    // Show other insert function
    String string2("example");
    cout << "Initial stringObject: " << string2 << '\n';

    // string::insert(size_t, size_t, char)
    string2.insert(0, 3, '*');
    cout << "After insert(0, 3, '*'): " << string2 << "\n\n";

    // Demonstrate all comparison operators
    String leftString("alpha");
    String rightString("beta");

    cout << "All comparisons:\n";


    cout << "leftString == rightString: "
         << (leftString == rightString) << '\n';
    cout << "leftString != rightString: "
         << (leftString != rightString) << '\n';
    cout << "leftString < rightString:  "
         << (leftString < rightString) << '\n';
    cout << "leftString <= rightString: "
         << (leftString <= rightString) << '\n';
    cout << "leftString > rightString:  "
         << (leftString > rightString) << '\n';
    cout << "leftString >= rightString: "
         << (leftString >= rightString) << '\n';

    String stringObject("alpha");

    cout << "stringObject == stringObject: "
         << (stringObject == leftString) << '\n';
    cout << "stringObject <= stringObject: "
         << (stringObject <= leftString) << '\n';
    cout << "stringObject >= stringObject: "
         << (stringObject >= leftString) << '\n';
}