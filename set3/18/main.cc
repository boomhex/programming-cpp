#include "main.ih"

int main()
{
    cout << "Default construction\n";
    Derived d1;

    cout << "Copy construction\n";
    Derived d2 = d1;

    cout << "Move construction\n";
    Derived d3 = move(d1);

    // The following code is so I use the classes. and dont get a warning.
    cout << " &d2 = " << &d2 << '\n';
    cout << " &d3 = " << &d3 << '\n';

}